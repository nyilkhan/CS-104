#include "Player.h"


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


Player::Player (std::string const & name, size_t maxTiles) {
	_pName = name;
	_maxT = maxTiles;
	_points = 0;

}

Player::~Player () {

}

set<Tile*> Player::getHandTiles() const {
	set<Tile*> tileSet;
	size_t sz= _currHand.size();
	for (size_t i=0;i<sz;i++) {
		tileSet.insert(_currHand[i]);
	}
	return tileSet;
}


bool Player::hasTiles(std::string const & move, bool resolveBlanks) const {
	//makes the move string all lowercase
	string temp = move;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

	bool has = true;
	string tempLetters = "";
	size_t sz = _currHand.size();

	//copies all of the letters into a string
	for (size_t i=0; i<sz; i++) {
		tempLetters += (_currHand[i])->getLetter();
	}
	

	size_t len = temp.length();
	size_t strSize = tempLetters.length();

	bool foundLetter = false;
	//iterates through the move string each letter at a time
	for (size_t i=0;i<len;i++) {
		//if there is a question mark in the move string
		foundLetter = false;
		if (resolveBlanks == true && temp[i]=='?') {
			i++;
			for (size_t j=0;j<strSize;j++) {
				if (tempLetters[j]=='?') {
					foundLetter = true;
					tempLetters.erase(j,1);
					strSize--;
					break;
				}
			}
		}
		else {
		//iterates through the letters we currenty have
			for (size_t j=0;j<strSize;j++) {
				if (temp[i]==tempLetters[j]) {
					foundLetter = true;
					tempLetters.erase(j,1);
					strSize--;
					break;
				}
			}
		}
		//if the letter is not found
		if (foundLetter == false) {
			has = false;
			return has;
		}
	}
	return has;
}


vector<Tile*> Player::takeTiles (string const & move, bool resolveBlanks) {
	string temp = move;

	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

	vector<Tile*> retVec;


	string templetters = "";
	size_t tempsize = temp.size();
	size_t vecSize = _currHand.size();

	for (size_t i=0;i<tempsize;i++) {
		if (temp[i]=='?' && resolveBlanks == true) {
			i++;
			//finds the '?' in the hand and deletes it
			for (size_t j=0;j<vecSize;j++) {
				if (_currHand[j]->getLetter() == '?') {
					_currHand[j]->useAs(temp[i]);
					retVec.push_back(_currHand[j]);
					_currHand.erase(_currHand.begin() + j);
					vecSize--;
					break;
				}
			}
		}
		else {
			for (size_t j=0;j<vecSize;j++) {
				if (_currHand[j]->getLetter() == temp[i]) {
					retVec.push_back(_currHand[j]);
					_currHand.erase(_currHand.begin() + j);
					vecSize--;
					break;
				}
			}
		}
	}
	return retVec;
}


void Player::addTiles (vector<Tile*> const & tilesToAdd) {
	int sz = tilesToAdd.size();
	for (int i=0;i<sz;i++) {
		_currHand.push_back(tilesToAdd[i]);
	}
}

size_t Player::getMaxTiles() const {
	size_t mx = this->_maxT;
	return mx;
}

string Player::getName() const {
	return _pName;
}