//
// Dictionary class implementation from Jamie's solution
//

#include <string>
#include <fstream>

#include "Dictionary.h"
#include "Exceptions.h"
#include "Util.h"

using namespace std;

Dictionary::Dictionary(std::string dictionary_file_name):
words()
{
	std::ifstream dictFileStream(dictionary_file_name);

	wordsT = new TrieSet();

	if(!dictFileStream)
	{
		throw FileException("DICTIONARY");
	}

	while(!dictFileStream.eof())
	{
		std::string word;
		dictFileStream >> word;

		if (dictFileStream.eof() && word.empty())
		{
			break;
		}

		//adds the words to the dictionary
		makeLowercase(word);
		
		wordsT->insert(word);

		words.insert(word);
	}
}

Dictionary::~Dictionary()
{
	// default destructor is OK
}

bool Dictionary::isLegalWord(std::string const &word) const
{
	//why do they lower it twice??????
	std::string lowercaseWord(word);
	makeLowercase(lowercaseWord);

	TrieNode* temp = wordsT->prefix(lowercaseWord);

	//could not find the word in the dictionary
	if (temp==NULL) {
		return false;
	}
	//not the end of the word
	if (temp->caboose == false) {
		return false;
	}
	else {
		return true;
	}
	
	return true;
}