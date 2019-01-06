#include "trie.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//hullo frends, this just imports dictionary into a trie, then does tests on it. enjoi.


//compile: g++ -g -Wall -std=c++11 test.cpp Trie.cpp -o test
//run: ./test dictionary.txt
//valgrind: valgrind --track-origins=yes --tool=memcheck --leak-check=yes ./test dictionary.txt



int main(int argc, char* argv[])
{
	TrieSet* testTrie = new TrieSet();
	ifstream dictionaryfile(argv[1]);

	//initialize wordList in lowercase alphabetical order
	string word;
	while(dictionaryfile >> word)
	{
		//convert to uppercase for uniformity
		for(int i = 0; i<(int)word.size(); i++)
		{
			word[i] = toupper(word[i]);
			if(isspace(word[i]))
			{
				break;
			}
		}
		testTrie->insert(word); //in lowercase alphabetical order at this point
		//consume rest of line
		getline(dictionaryfile, word);
	}

	//"a" is a word, and removing "a" should still give us access to the word "aahed" as that word still exists/was inserted
	testTrie->remove("a");
	cout << "Test 1: This should be true: " << (testTrie->prefix("aahed") != NULL) << endl;

	//tests whether sailboat is still a valid one after removing sailboats
	testTrie->remove("sailboats");
	cout << "Test 2: This should be true: " << (testTrie->prefix("sailboat") != NULL) << endl;

	//tests whether sailboats is still a valid one after removing sailboats
	testTrie->remove("sailboats");
	cout << "Test 3: This should be true: " << (testTrie->prefix("sailboats") == NULL) << endl;

	//this should not seg fault
	cout << "Test 4: This should not seg fault: ";
	testTrie->remove("sailboatss");
	cout << "... nais" << endl;

	//remove saharan and then check that it is actually removed (no words that include saharan as prefix exist)
	testTrie->remove("saharan");
	cout << "Test 5: This should be true: " << (testTrie->prefix("saharan") == NULL) << endl;

	//remove sanskrit and then check that it is actually removed (no words that include sanskrit as prefix exist)
	testTrie->remove("sanskrit");
	cout << "Test 6: This should be true: " << (testTrie->prefix("sanskrit") == NULL) << endl;

	//regular test they suggested, no such prefix exists
	cout << "Test 7: This should be true: " << (testTrie->prefix("xz") == NULL) << endl;

	delete testTrie;
}