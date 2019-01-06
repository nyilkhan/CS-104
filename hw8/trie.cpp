#include "trie.h"
#include "Util.h"

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

TrieNode::TrieNode() {
	this->parent = NULL;
	
	for (int i=0;i<26;i++) {
		this->children[i]=NULL;
	}
	caboose = false;
	c = ' ';
}


TrieSet::TrieSet() {
	//create source node
	this->origin = new TrieNode();
}

//in dictionary destructor, open file, iterate through it, and remove on every single one
//that way, when we destruct trueSet all thats left is origin

TrieSet::~TrieSet() {
	destructHelp(this->origin);
}

void TrieSet::destructHelp(TrieNode* t) {
	if (t==NULL) {
		return;
	}
	for (size_t i = 0;i<26;i++) {
		destructHelp(t->children[i]);
	}
	delete t;
}


void TrieSet::insert(string input) {
	string temp = input;
	makeLowercase(temp);

	//start at the first node 
	TrieNode* tempNode = this->origin;

	//iterate through all the letter and create new nodes if they do not exist
	for (size_t i =0;i<temp.length();i++) {
		char curr = temp[i];
		//if the letter Node does not exist, we create it
		if (tempNode->children[curr-97]==NULL) {
			tempNode->children[curr-97] = new TrieNode();
			//sets all of the values of the new node
			tempNode->children[curr-97]->parent = tempNode;
			tempNode->children[curr-97]->c = curr;
		}
		//move on the the next letter node
		tempNode = tempNode->children[curr-97];
	}
	//we are finished with the word
	tempNode->caboose = true;
}


//!!!!!!!!!!!!!!!!!!!!!!!!!!!//
void TrieSet::remove(string input) {
	
	stack<TrieNode*> stkNode;


	makeLowercase(input);


	stack<int> stkInt;
	size_t sz = input.size();
	makeLowercase(input);

	TrieNode* temp = origin;

	for (size_t i = 0; i < sz; i ++) {
		char currChar = input[i];
		//if we do not have a word at any point
		if (temp->children[currChar-97] == NULL) {
			return;
		}
		temp = temp->children[currChar-97];
		stkNode.push(temp);
		stkInt.push(int(currChar-97));
		//if it is the end of a word
		if (temp->caboose == true && i<sz-1) {
			while (!stkNode.empty()) {
				stkNode.pop();
				stkInt.pop();
			}
		}
		for (size_t j =0;j<26;j++) {
			if (temp->children[j] != NULL) {
				while (!stkNode.empty()) {
					stkNode.pop();
					stkInt.pop();
				}
				break;
			}
		}
	}
	for (size_t i =0;i< 26;i++) {
		if (temp->children[i] != NULL) {
			temp->caboose = false;
			return;
		}
	}
	while (!stkNode.empty()) {
		TrieNode* tempNode = stkNode.top();
		int tempInt = stkInt.top();
		tempNode->parent->children[tempInt] = NULL;
		tempNode->parent = NULL;
		delete tempNode;
		stkNode.pop();
		stkInt.pop();
	}
}

TrieNode* TrieSet::prefix(string px) {
	string temp = px;
	transform(temp.begin(),temp.end(),temp.begin(), ::tolower);


	TrieNode* tempNode = this->origin;

	for (size_t i =0; i < temp.length();i++) {
		char curr = temp[i];

		tempNode = tempNode->children[curr-97];
		if (tempNode == NULL) {
			return NULL;
		}
	}
	return tempNode;
}

