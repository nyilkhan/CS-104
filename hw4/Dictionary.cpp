#include "Dictionary.h"

#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;

Dictionary::Dictionary(string dictionary_file_name) {
	
	ifstream ifile(dictionary_file_name);
	string currWord = "";

	while (getline(ifile,currWord)) {
		_vec.push_back(currWord);
	}
	sort(_vec.begin(),_vec.end());
}

Dictionary::~Dictionary() {

}

bool Dictionary::isLegalWord(string const & word) const {
	string temp = word;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	
	return binary_search(_vec.begin(), _vec.end(),temp);
}