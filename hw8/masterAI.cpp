#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


#include "masterAI.h"

using namespace std;

masterAI::masterAI(std::string const & name, size_t maxTiles, Board* gameboard, Dictionary* dictionary, int CPUnum):  Player(name, maxTiles) {
	board = gameboard;
	//set AI 
	AI = CPUnum;
	this->dic = dictionary;


}

masterAI::~masterAI() {

}
//finds all possible anchor spaces, where we can start to make words
void masterAI::anchor() {

	//clears the vector of possible moves
	possibleMoveVec.clear();


	//initialize our vector of chars
	//set<Tile*> tilesHand = this->getHandTiles();
	multimap<char, Tile*>::iterator iter;

	//std::set<Tile*>::iterator it;

	for (iter = _hand.begin(); iter != _hand.end(); ++iter) {
		AItiles.push_back(tolower(iter->first));
	}


	//iterates through the entire board and finds all spots that are adjacent to any tiles already on board
	int rows = board->getRows();
	int cols = board->getColumns();
	bool found = false;
	for (int i = 1; i<=rows; i++) {
		for (int j =1;j<=cols;j++) {
			found = false;
			if (!(board->getSquareM(i,j)->isOccupied())) {
				if (i-1>0) {
					if (board->getSquareM(i-1,j)->isOccupied()) {
						board->getSquareM(i,j)->setAnchor(true);
						found = true;
					}
				}
				if (i+1<=rows) {
					if (board->getSquareM(i+1,j)->isOccupied()) {
						board->getSquareM(i,j)->setAnchor(true);
						found = true;
					}
				}
				if (j-1>0) {
					if (board->getSquareM(i,j-1)->isOccupied()) {
						board->getSquareM(i,j)->setAnchor(true);
						found = true;
					}
				}
				if (j+1<=cols) {
					if (board->getSquareM(i,j+1)->isOccupied()) {
						board->getSquareM(i,j)->setAnchor(true);
						found = true;
					}
				}
			}
			else {
				board->getSquareM(i,j)->setAnchor(false);
			}
			if (found==false) {
				board->getSquareM(i,j)->setAnchor(false);
			}
		}
	}
}
//builds up the left part of the word recursively, and in turn build up the right
void masterAI::buildLeft(string partial, string moveStr, TrieNode* currNode, int startR, int startC,int row, int col) {
	//if we are off of the board
	if (startR <= 0 || startR > (int)board->getRows() || startC <= 0 || startC > (int)board->getColumns()) {
		return;
	}
	//if the string is not empty we do a seperate build right
	if (partial !="" ) {
		buildRight(partial, moveStr, currNode, startR, startC, row+1, col+1);
	}

	makeLowercase(partial);

	//creates a char where we can later save values	
	char remT;

	//automatically calls build right so we can build each word at a tiem recursively
	buildRight(partial, partial, currNode, row, col, row, col+1);


	//basecase, if we have hit hit another Anchor space and it is not the first point
	if (board->getSquareM(row,col)->isAnchor() && currNode != dic->wordsT->origin) {
		
		return;
	}
	else {
		//for each letter
		for (size_t i = 0; i<26;i++) {
			
			//if the letter exists in our Trie (in the dictionary)
			if (currNode->children[i]!=NULL) {
				//a string that contains the char we are currently looking for
				string currChar = string(1,currNode->children[i]->c);

				//creates an iterator that we can use to go through our tiles in our hand
				std::vector<char>::iterator it = find(AItiles.begin(),AItiles.end(),currNode->children[i]->c);

				//anytime we have the tiles
				if (it!= AItiles.end()) {
					//removes the given tile in order to go into the next recursive call properly
					remT = AItiles.at((int)distance(AItiles.begin(), it));

					moveStr += currChar;
					//adds it to the partial string
					string tempStr = currChar+partial;
			
					
					buildLeft(tempStr, moveStr, currNode->children[i],startR, startC-1, row,col);
					
					moveStr = moveStr.substr(0,moveStr.size()-1);
					AItiles.push_back(remT);
				}
			}
		}
	}
}
//builds up the right part of the word
void masterAI::buildRight(string partial, string moveStr, TrieNode* currNode, int startR, int startC , int row, int col) {
	//make the word lowercase
	makeLowercase(partial);
	//a char that will later be used
	char remT;

	//make sure we are not off the board
	if (row < 0 || row >= (int)board->getRows() || col < 0 || col >= (int)board->getColumns()) {
		return;
	}

	//if there is not something already on the board
	if (!board->getSquareM(row, col)->isOccupied()) {
		
		if (currNode->caboose==true && moveStr != "") {
			
			if (isLegalMove(moveStr, startR+1, startC+1,true)) {
				possibleMoveVec.push_back(make_pair(partial, board->getSquareM(startR,startC)));
				
			}
		}

		//checks if the letter is there in the TrieSet
		for (int i =0; i < 26; i++) {
	

			if (currNode->children[i] != NULL) {
				//a string which contains the current character we are looking for
				string currChar = string(1,currNode->children[i]->c);

				vector<char>::iterator it = find(AItiles.begin(), AItiles.end(), currNode->children[i]->c);
				
				if (it !=AItiles.end()) {
					
					//removes the tiles from our rack
					remT = AItiles.at((int)distance(AItiles.begin(),it));
					AItiles.erase(it);
					//adds the letter the the move and partial strings
					//we use two seperate ones because the Move object does not take in letters that are already on the board,
					//but those are necessary for my other functions to work
					moveStr += currNode->children[i]->c;
					string tempString = partial + currNode->children[i]->c;
					//recursively calls to build right with the letter we are at
					buildRight(tempString, moveStr, currNode->children[i], startR, startC, row, col+1);
					//gets rid of the last letter since that did not work, and we want to continue building words
					//using the moveStr
					moveStr = moveStr.substr(0,moveStr.size()-1);
					//adds back the tiles we erased
					AItiles.push_back(remT);
				}
			}
			else {
				return;
			}
		}
	}

	//if there is something on the board already we check
	else {
		char l = board->getSquareM(row,col)->getLetter();
		l = tolower(l);
		string tempString = partial + l;
		//we check if it creates a legal move on the baord
		if (isLegalMove(moveStr,startR+1,startC+1,true)) {
			possibleMoveVec.push_back(make_pair(tempString,board->getSquareM(startR,startC)));

		}
		//we continue to the next node, based on the letter in the current square on the board
		if (currNode->children[l-'a'] != NULL) {
			//recursively calls build right on the next Node with the modified string
			buildRight(tempString,moveStr, currNode->children[l-'a'],startR,startC,row,col+1);
		}
	}
}


void masterAI::buildUp(string partial, string moveStr, TrieNode* currNode, int startR, int startC , int row, int col) {
	//if we are off of the board
	if (startR <= 0 || startR > (int)board->getRows() || startC <= 0 || startC > (int)board->getColumns()) {
		return;
	}

	if (partial !="" ) {
		buildDown(partial, moveStr, currNode, startR, startC, row+1, col+1);
	}

	makeLowercase(partial);
	//creates a vector where we can push our tiles to
	
	char remT;
	
	buildRight(partial, partial, currNode, row, col, row+1, col);


	//basecase, if we have hit hit another Anchor space and it is not the first point
	if (board->getSquareM(row,col)->isAnchor() && currNode != dic->wordsT->origin) {
		
		return;
	}
	else {
		//for each letter
		for (size_t i = 0; i<26;i++) {
			
			//if the letter exists in our Trie
			if (currNode->children[i]!=NULL) {
				
				//a string that contains the char we are currently looking for
				string currChar = string(1,currNode->children[i]->c);

				std::vector<char>::iterator it = find(AItiles.begin(),AItiles.end(),currNode->children[i]->c);

				//anytime we have the tiles
				if (it!= AItiles.end()) {
					//removes the given tile in order to go into the next recursive call properly
					remT = AItiles.at((int)distance(AItiles.begin(), it));

					moveStr += currChar;
					//adds it to the partial string
					string tempStr = currChar+partial;
			
					
					buildLeft(tempStr, moveStr, currNode->children[i],startR-1, startC, row,col);
					
					moveStr = moveStr.substr(0,moveStr.size()-1);
					AItiles.push_back(remT);
				}
			}
		}
	}
}

void masterAI::buildDown(string partial, string moveStr, TrieNode* currNode, int startR, int startC , int row, int col) {
	//make the word lowercase
	makeLowercase(partial);


	//a char to hold our 
	char remT;

	//make sure we are not off the board
	if (row < 0 || row >= (int)board->getRows() || col < 0 || col >= (int)board->getColumns()) {
		//if it makes a word then we can add it to the possible move vector
		

		//if is legal move

		return;
	}

	//if there is not something already on the board
	if (!board->getSquareM(row, col)->isOccupied()) {
		
		if (currNode->caboose==true && moveStr != "") {
			
			if (isLegalMove(moveStr, startR+1, startC+1,false)) {
				possibleMoveVec.push_back(make_pair(partial, board->getSquareM(startR,startC)));
				
			}
		}

		//checks if the letter is there in the TrieSet
		for (int i =0; i < 26; i++) {
	

			if (currNode->children[i] != NULL) {
				

				//a string which contains the current character we are looking for
				string currChar = string(1,currNode->children[i]->c);

				vector<char>::iterator it = find(AItiles.begin(), AItiles.end(), currNode->children[i]->c);
				
				if (it !=AItiles.end()) {
					
					//removes the tiles from our rack
					remT = AItiles.at((int)distance(AItiles.begin(),it));
					AItiles.erase(it);

					moveStr += currNode->children[i]->c;
					
					string tempString = partial + currNode->children[i]->c;

					buildDown(tempString, moveStr, currNode->children[i], startR, startC, row+1, col);

					moveStr = moveStr.substr(0,moveStr.size()-1);

					AItiles.push_back(remT);

				}
			}
			else {
				return;
			}
		}
	}

	//if there is something on the board already we check
	else {
		char l = board->getSquareM(row,col)->getLetter();

		l = tolower(l);

		string tempString = partial + l;

		if (isLegalMove(moveStr,startR+1,startC+1,false)) {
			possibleMoveVec.push_back(make_pair(tempString,board->getSquareM(startR,startC)));

		}
		if (row+1 > (int)board->getRows()) {
			return;
		}

		if (currNode->children[l-'a'] != NULL) {
			
			buildDown(tempString,moveStr, currNode->children[l-'a'],startR,startC,row+1,col);
		}
	}
}




//helper function to check if playing a given word will result in a legal move on the board
bool masterAI::isLegalMove(string givenWord, int row, int col, bool horiz) {
	bool goodMove = true;

	//creates a move with the given string
	PlaceMove* proposed = new PlaceMove(col,row,horiz, givenWord, this);


	//creates a vector of all the words that are made from playing the given move
	vector<std::pair<std::string, unsigned int>> vec = this->board->getPlaceMoveResults(*proposed);
	
	for (int i = 0;i < (int)vec.size();i++) {
		
		if (!(this->dic->isLegalWord(vec[i].first))) {
		
			goodMove = false;

			proposed->failSilently();
			delete proposed;
		
			return goodMove;
		}
	}

	proposed->failSilently();
	delete proposed;
	return goodMove;
}



