#include "trie.h"

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	TrieSet* myset = new TrieSet();

	TrieNode* temp = myset->origin;

	myset->insert("Apple");
	myset->insert("Aligator");
	myset->insert("Application");


	for (int i =0;i<3;i++) {
		cout << temp->children[0]->children[i] << endl;
	}


	delete myset;
	return 0;
}