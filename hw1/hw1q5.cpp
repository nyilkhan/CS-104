#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring> 

using namespace std;

int main (int argc, char* argv[]) {
	if(argc < 2){
    	cerr << "Please provide a string of characters." << endl;
    	return 1;
  	}

	ifstream myfile;
	myfile.open(argv[1]);
	if (myfile.fail()) {
		cout << "File did not read in correctly";
		return 0;
	} 
	int size;
	myfile >> size;
	string *words = NULL;
	words = new string[size];

	for (int i=0;i<size;i++) {
		string word1;
		myfile >> word1;
		words[i] = word1;
	}

	for (int i=size-1;i>=0;i--) {
		cout << words[i] << endl;
	}
	delete [] words;

	myfile.close();
}