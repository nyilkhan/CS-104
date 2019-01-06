#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "stackint.h"

using namespace std;

void shift(StackInt &stk, int &x);

void emptystk(StackInt &stk);


int main(int argc, char** argv) {
	if(argc < 2){
		cout << "Please provide a string of characters." << endl;
		return 0;
	}
  	//read in the file
	ifstream ifile(argv[1]);

	//creates variables to put into the stack
	const int OPEN_P = -1;
	const int OPEN_A = -3;
	const int CLOSE_A = -4;
	const int MULT = -5;
	const int ADD = -6;
  	//keeps track of whether the statment is malformed or not
	bool mal = false;
  	//creates the stack
	StackInt stk;


	string fileTemp;  	

	int retval =0;
	//keeps going while there are still lines from the file to be read
	while (getline(ifile, fileTemp)){
		//puts the string into a string stream
		stringstream ss(fileTemp);
		//temprary string to combine multi digit numbers
		string temp = "";
		char st;
		bool paren = false;
		//will keep track of the total number of parenthesis
		int numO = 0;
		int numC = 0;
		while (ss>>st) {
  			//checks if it is a number
			if (isdigit(st)) {
				//if the temprary string is empty, or if it is the first digit
				if (temp == "") {
					temp += st;
					stk.push((int)st-48);
				}
				//if it is after the first digit of the number
				else {
					stk.pop();
					temp += st;
					stk.push(stoi(temp));
				}
			}
			//if the character is anything other than a digit
			else{
				temp = "";
				if (st=='(') {
					stk.push(OPEN_P);
					paren = true;
					numO+=1;
				}
				else if (st=='<') {
					stk.push(OPEN_A);
				}
				else if (st=='>') {
					stk.push(CLOSE_A);
				}
				else if (st=='*') {
					stk.push(MULT);
				}
				else if (st == '+') {
					stk.push(ADD);
				}
				else if (st==')') {
					numC+=1;
					int count = 0;
					int result = stk.top();
					int op = -10;
					int tempOp = 10;
					//checks to see if it is "(3)"
 					if (stk.top() >=0 ){
 						int tcheck = stk.top();
 						stk.pop();
 						if (stk.top() == -1) {
 							mal = true;
 							return 0;
 						}
 						else {
 							stk.push(tcheck);
 						}
 					}
					while (stk.top() != OPEN_P) {
						if (stk.top() < 0 && count==0) {
							mal = true;
							break;
						}
						if (count ==0) {
							stk.pop();
						}
						//checks to see shifts
						shift(stk, result);

  						//checks to see if there is no operator, so it is malformed
						if ((stk.top() != MULT && stk.top() != ADD) && stk.top() != OPEN_P) {
							mal = true;
							break;
						}

						op = stk.top();
						//will keep track of the original operator
						if (count==0) {
							tempOp = op;
						}
						stk.pop();
						if (op == OPEN_P) {
							break;
						}
						//makes sure we have the same operator throughout
						if (op == tempOp) {
							if (stk.top() < 0) {
								mal = true;
								break;
							}
							int int2 = stk.top();
							stk.pop();
							shift(stk, int2);
							if (op == MULT) {
								result *= int2;
								count +=1;
							}
							else if (op == ADD) {
								result += int2;
								count +=1;
							}
							else if (op == OPEN_P) {
								stk.pop();
								break;
							}
						}
						else {
							if (op == OPEN_P) {
								stk.pop();
								break;
							}
							else {
								mal = true;
								break;
							}
						}
					}
					//if there is a parenthesis on top it pops it off
					if (stk.top() == -1) {
						stk.pop();
					}
					//checks for any more shifts
					shift(stk , result);
					stk.push(result);
				}
			}
		}
		//if the number of parenthesis don't match
		if (numC != numO) {
			mal = true;
		}
		//if there are no parentheses in the entire line
		if (paren == false) {
			if (stk.top()>=0) {
 				retval = stk.top();
 				int t = stk.top();
				stk.pop();
				shift(stk, t);
				if (stk.empty() == true) {
					cout << t << endl;
					return 0;
				}
				if (stk.top()==-2 || stk.top()==-3 || stk.top()==-1) {
					mal = true;
				}
				retval = t;
			}
			else {
				mal = true;
			}
		}
		else {
		//checks for extra parenthesis
			retval = stk.top();
			stk.pop();
			shift(stk,retval);
			if (stk.top() == -1 || stk.top() == /*-3*/-5 || stk.top() == -/*4*/ -6) {
					mal = true;
			}

			//checks if there are extra things in the stack left over
			if (!stk.empty()) {
				mal = true;
			}
		}
		if (mal == true) {
			cout << "Malformed" << endl;
		}
		else {
			cout << retval;
		}
		emptystk(stk);
	
	}
	ifile.close();
	return 0;
}
//shift function
void shift(StackInt &stk, int &x) {
	while (stk.top() == -3 || stk.top() == -4) {
		if (stk.top() == -3) {
			x *= 2;
			stk.pop();
		}
		if (stk.top() == -4) {
			x = x/2;
			stk.pop();
		}
	}
}
//function to empty the stack afterwards
void emptystk(StackInt &stk) {
	while (stk.empty() == false) {
		stk.pop();
	}
}