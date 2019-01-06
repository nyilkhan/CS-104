#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

void ropeCheck() {
	string input;
	cout << "Enter an input" << endl;

	getline(cin,input);
	stack <char> stk;

	unsigned int sz = input.length();

	for (unsigned int i=0;i<sz;i++) {
		if (input[i]=='n') {
			if ((!stk.empty()) && stk.top()=='s') {
				stk.pop();
			}
			else {
				stk.push(input[i]);
			}
		}
		else if (input[i]=='e') {
			if ((!stk.empty()) && stk.top()=='w') {
				stk.pop();
			}
			else {
				stk.push(input[i]);
			}
		}
		else if (input[i]=='s') {
			if ((!stk.empty()) && stk.top()=='n') {
				stk.pop();
			}
			else {
				stk.push(input[i]);
			}
		}
		else if (input[i]=='w') {
			if ((!stk.empty()) && stk.top()=='e') {
				stk.pop();
			}
			else {
				stk.push(input[i]);
			}
		}
		else {
			cout << "invalid" << endl;
			return;
		}
	}
	if (stk.empty()) {
		cout << "rolled up" << endl;
 	}
 	else {
 		cout << "not rolled up" << endl;
 	}
 	return ;
}

int main() {
	ropeCheck();
	return 0;
}