#include "Move.h"
#include <stdexcept>


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;




/*
if(foo){
	throw std::invalid_argument("error: invalid argument")
}
if(foo){
	throw std::logic_error("error: logic error")
}

try(){
	do stuff
}
catch(exception &e){
	std::cerr << e.what() << std::endl;
}
*/





//static means you dont need an object to call this function
Move * Move::parseMove(std::string moveString, Player &p) {


	Move* retMove;
	stringstream ss(moveString);
	string chosenMove = "";
	ss >> chosenMove;
	transform(chosenMove.begin(), chosenMove.end(), chosenMove.begin(), ::tolower);
	if (chosenMove == "pass") {
		retMove = new PassMove(&p);
	}
	else if (chosenMove == "place") {
		char direction;
		size_t row;
		size_t column;
		string tString;
		ss >> direction >> row >> column >> tString;
		//checks if the words will be played horizontally
		bool horizontal = false;
		if (direction == '-') {
			horizontal = true;
		}
		retMove = new PlaceMove(column, row, horizontal, tString, &p);
	}
	else if (chosenMove == "exchange") {
		string tString;
		ss >> tString;
		retMove = new ExchangeMove(tString, &p);
	}
	else {
		cout << "Did not enter a valid string" << endl;
	}
//delete them in player or board
	return retMove;
}

Move::Move(Player * player) {
	_player = player;
	valid = true;
}

Move::~Move() {
	delete this;
}

/* Constructs a pass move. */
PassMove::PassMove(Player * player):Move(player) {

}

PassMove::~PassMove() {

}



	/* Executes this move, whichever type it is.
	   This may throw exceptions; students: it's up to you to
	   decide (and document) what exactly it throws*/
void PassMove::execute(Board & board, Bag & bag, Dictionary & dictionary,bool first) {

}

	//Add more public/protected/private functions/variables here.


ExchangeMove::ExchangeMove(std::string tileString, Player * p):Move(p)  {
	_tstring = tileString;
}

ExchangeMove::~ExchangeMove() {

}

/* Executes this move, whichever type it is.
   This may throw exceptions; students: it's up to you to
   decide (and document) what exactly it throws*/
void ExchangeMove::execute(Board & board, Bag & bag, Dictionary & dictionary, bool first) {
	size_t len = _tstring.length();

	//checks if the user has the specified tiles
	bool hasIt = _player->hasTiles(_tstring,false);
	//if the player does not have the tiles
	if (!hasIt) {
		valid = false;
		cout << "error: player doesn't have this tile " << endl;
		return;
	}

	//gets rid of the specified tiles from the players hand
	vector<Tile*> tempVec = _player->takeTiles(_tstring, false);
	vector<Tile*> drawnTiles = bag.drawTiles(len);
	_player->addTiles(drawnTiles);

	bag.addTiles(tempVec);
}

	//Add more public/protected/private functions/variables here.



PlaceMove::PlaceMove (size_t x, size_t y, bool horizontal, std::string tileString, Player * p):Move(p) {
	_x = x;
	_y = y;
	_horiz = horizontal;
	_tString = tileString;
	size_t len = _tString.length();
	_quest = false;
	
	for (size_t i=0;i<len;i++) {
		if (_tString[i]=='?') {
			_quest = true;
		}
	}
	_isValid = _player->hasTiles(_tString,_quest);


}

PlaceMove::~PlaceMove() {
}
	/* Returns the vector of tiles associated with a PLACE/EXCHANGE move.
	   Return value could be arbitrary for PASS moves. */

std::vector<Tile*> const & PlaceMove::tileVector () const {
	vector<Tile*> retVec;
	retVec = _player->takeTiles(_tString,_quest);

}

	/* Executes this move, whichever type it is.
	   This may throw exceptions; students: it's up to you to
	   decide (and document) what exactly it throws*/
void PlaceMove::execute(Board & board, Bag & bag, Dictionary & dictionary, bool first) {
	//vector of tiles to use
	int score = 0;

	bool origin = false;
	//checks if the player has the given tiles
	if (!_isValid) {
		//throw invalid_argument("Player does not have the given tiles for the move");
		valid = false;
		cout << "Player does not have the given tiles for the move" << endl;
		return;
	}

	//checks if it is velid (THROW EXCEPTIONS)
	size_t len = _tString.length();

	//will check if the word will be connected to anything already on the board
	bool connected = false;
	
	bool isValidWord;

	//if it is horizontal, it checks all of the words the givn move will make
	if (_horiz) {
		size_t endX = _x;
		string check = "";
		size_t tempX = _x;
		size_t numSpaces = len;
		//sets the ending index for our word
		for (size_t i = 0; i < numSpaces;i++) {
			if (tempX + i < board.getColumns()) {
				if ((board.getSquare(tempX+i,_y))->isOccupied()) {
					connected = true;
					numSpaces++;
					endX++;
					score += (board.getSquare(tempX+i,_y))->getScore();
				}
				else {
					endX++;                    
				}
			}
		}
		endX--;
		//if the final tile is not part of the string
		while (endX+1 < board.getColumns() && (board.getSquare(endX+1,_y))->isOccupied()) {
			connected = true;
			score += ((board.getSquare(endX+1,_y))->getScore());
			endX++;
		}
		
		//checks to the left of the word to see if it is connected
		if (_x-1 >= 0 && (board.getSquare(_x-1,_y))->isOccupied()) {
			connected = true;
			tempX--;
			//score += (board.getSquare(_x-1,_y))->getScore();
			while (tempX -1 > 0 &&(board.getSquare(tempX-1,_y))->isOccupied()) {
				score += ((board.getSquare(tempX-1,_y))->getScore());
				tempX--;
			}	
		}

		//creates the string based off what is on the board and what is being played
		int countString = 0;
		for (size_t i = 0; i < endX-tempX + 1;i++) {
			if ((board.getSquare(tempX+i,_y))->isOccupied()) {
				check += (board.getSquare(tempX+i,_y))->getLetter();
			}
			else {
				if (_tString[countString]=='?') {
					check += _tString[countString+1];
					countString+=2;
					endX--;
				}
				else {
					check += _tString[countString];
					countString++;
				}
			} 
		}
		
		isValidWord = dictionary.isLegalWord(check);
		if (isValidWord==false) {
			//throw invalid_argument("Given word is not a legal word");
			valid = false;
			cout << "Given word is not a legal word" << endl;
			return;
			//cout << "Given word " << check <<" is not a legal word " << endl;
			//return;
		}

		//checks all the letters to the top and bottom
		for (size_t i = 0;i< endX-tempX+1;i++) {
			
			if (!(board.getSquare(_x+i,_y))->isOccupied()) {
				
				//if the square to the top has anything
				if (_y-1 >= 0 &&(board.getSquare(_x+i,_y-1))->isOccupied()) {
					//score += (board.getSquare(_x+i,_y-1))->getScore();
					string horCheck = "";
					connected = true;
					size_t startY = _y;
					size_t endYY = _y;
					while (startY-1 >=0 && (board.getSquare(_x+i,startY-1))->isOccupied()) {
						score += (board.getSquare(_x+i,startY-1))->getScore();
						startY--;
					}
					while (endYY+1 < board.getRows() && (board.getSquare(_x+i,endYY+1))->isOccupied()) {
						score += (board.getSquare(_x+i,endYY+1))->getScore();
						endYY++;
					}
					int skip;

					if (startY != endYY) {
						for (size_t j = 0; j < endYY-startY+1;i++) {
							if (board.getSquare(_x+i,startY+j)->isOccupied()) {
								horCheck += (board.getSquare(_x+i,startY+j))->getLetter();
							}
							else if (_tString[i]=='?') {
								skip++;
								horCheck+= _tString[i+skip];
							}
							else {
								horCheck += _tString[i+skip];
							}
						}
						isValidWord = dictionary.isLegalWord(horCheck);
						if (!isValidWord) {
							//throw invalid_argument("Not a vlid move");
							valid = false;
							cout << "Not a vlid move" << endl;
							return;
							//cout << "Not a valid move " << endl;
							//return;
						}
					}

				}
				//checks square to the bottom has anything
				else if (_y+1 < board.getRows() && (board.getSquare(_x+i,_y+1))->isOccupied()) {
					//score += (board.getSquare(_x+i,_y+1))->getScore();
					string horCheck = "";
					connected = true;
					size_t startY = _y;
					size_t endYY = _y;
					while ( endYY+1 < board.getRows() && (board.getSquare(_x+i,endYY+1))->isOccupied()) {
						score += (board.getSquare(_x+i,endYY+1))->getScore();
						endYY++;
					}
					int skip;
					if (startY != endYY) {
						for (size_t j =0; j< endYY - startY +1;j++) {
							if (board.getSquare(_x+i,startY+j)->isOccupied()) {
								horCheck += (board.getSquare(_x+i,startY+j))->getLetter();
							}
							else if (_tString[i]=='?') {
								skip++;
								horCheck+= _tString[i+skip];
							}
							else {
								horCheck += _tString[i+skip];
							}
						}
						isValidWord = dictionary.isLegalWord(horCheck);
						if (!isValidWord) {
							//throw invalid_argument("Not a vlid move");
							valid = false;
							cout << "Not a vlid move" << endl;
							return;
							//cout << "Not a valid move " << endl;
							//return;
						}
					}
				}
			}
		}
	}

	//is it is being played vertically	
	else {
		size_t endY = _y;
		string check = "";
		size_t tempY = _y;
		size_t numSpaces = len;
		//sets the ending index for our word
		for (size_t i = 0; i < numSpaces;i++) {
			if (tempY+i < board.getRows()) {
				if ((board.getSquare(_x,tempY+i))->isOccupied()) {
					score += (board.getSquare(_x,tempY+i))->getScore();
					connected = true;
					numSpaces++;
					endY++;
				}
				else {
					endY++;
				}
			}
		}
		endY--;
		//if the final tile is not part of the string
		while (endY+1 < board.getRows() && ((board.getSquare(_x,endY+1))->isOccupied())) {
			connected = true;
			score += (board.getSquare(_x,endY+1))->getScore();
			endY++;
		}

		//checks above the word
		if (_y-1 >= 0 && (board.getSquare(_x,_y-1))->isOccupied()) {
			//score += (board.getSquare(_x,_y-1))->getScore();
			connected = true;
			tempY--;
			//check for seg faults
			while (tempY -1 >= 0 && (board.getSquare(_x,tempY-1))->isOccupied()) {
				score += (board.getSquare(_x,tempY-1))->getScore();
				tempY--;
			}
		}

		//creates the string based off what is on the board and what is being played
		int countString = 0;


		for (size_t i = 0; i < endY-tempY + 1;i++) {
			if ((board.getSquare(_x,tempY+i))->isOccupied()) {
				check += (board.getSquare(_x,tempY+i))->getLetter();
			}
			else {
				if (_tString[countString]=='?') {
					check += _tString[countString+1];
					countString+=2;
					endY--;
			}
				else {
					check+= _tString[countString];
					countString++;
				}
			} 
		}


		isValidWord = dictionary.isLegalWord(check);
		if (isValidWord == false) {
			//throw invalid_argument("Not a vlid move");
			valid = false;
			cout << "Not a vlid move" << endl;
			return;
			//cout << "Given word " << check <<" is not a legal word " << endl;
			//return;
		}

		
		//checks all the letters to the right and left 
		for (size_t i = 0;i < endY-tempY+1;i++) {
			
			if (!(board.getSquare(_x,_y+i))->isOccupied()) {
				//if the square to the left has anything
				if (_x-1 >= 0 && (board.getSquare(_x-1,_y+i))->isOccupied()) {
					//score += (board.getSquare(_x-1,_y+i))->getScore();
					string horCheck = "";
					connected = true;
					size_t startX = _x;
					size_t endXX = _x;
					while (startX-1 >= 0 && (board.getSquare(startX-1,_y+i))->isOccupied()) {
						score += (board.getSquare(startX-1,_y+i))->getScore();
						startX--;
					}
					while (endXX+1 < board.getColumns() &&(board.getSquare(endXX+1,_y+i))->isOccupied()) {
						score += (board.getSquare(endXX+1,_y+i))->getScore();
						endXX++;
					}
					int skip = 0;

					if (startX != endXX) {
						for (size_t j = 0; j < endXX-startX+1;j++) {
					
							if (board.getSquare(startX+j,_y+i)->isOccupied()) {
								horCheck += (board.getSquare(startX+j,_y+i))->getLetter();
								
							}
							
							else if (_tString[i]=='?') {
								skip++;
								horCheck += _tString[i+1];

							}
							else {
								horCheck += _tString[i];
							}

						}
						isValidWord = dictionary.isLegalWord(horCheck);
						if (!isValidWord) {
							//throw invalid_argument("Not a vlid move");
							valid = false;
							cout << "Not a vlid move" << endl;
							return;
						}
					}
				}
				//checks square to the right has anything
				else if (_x+1 < board.getColumns() &&(board.getSquare(_x+1,_y+i))->isOccupied()) {
					//score += (board.getSquare(_x+1,_y+i))->getScore();
					string horCheck = "";
					connected = true;
					size_t startX = _x;
					size_t endXX = _x;
					while ( endXX+1 < board.getColumns() && (board.getSquare(endXX+1,_y+i))->isOccupied()) {
						score += ((board.getSquare(endXX+1,_y+i)))->getScore();
						endXX++;
					}
					int skip;
					if (startX !=endXX) {
						for (size_t j =0; j< endXX - startX +1;j++) {
							if (board.getSquare(startX+j,_y+i)->isOccupied()) {
								horCheck += (board.getSquare(startX+j,_y+i))->getLetter();
								
							}
							else if (_tString[i]=='?') {
								skip++;
								horCheck += _tString[i+skip];

							}
							else {
								horCheck += _tString[i+skip];
							}
						}
						isValidWord = dictionary.isLegalWord(horCheck);
						if (!isValidWord) {
							//throw invalid_argument("Not a vlid move");
							valid = false;
							cout << "Not a vlid move" << endl;
						}
					}
				}

			}
		}
	}

	
	
	if (first == true) {
		if (_horiz) {
			for (size_t i = 0;i<len;i++) {
				if (_x+i == board.startW && _y == board.startH) {
					origin = true;
				}
			}
		}
		else {
			for (size_t i = 0;i<len;i++) {
				if (_x == board.startW && _y+i == board.startH) {
					origin = true;
				}
			}
		}
	}
	if (origin == false && first == true) {
		//throw invalid_argument("did not place on first tile");
		valid = false;
		cout << "Did not place on first tile" << endl;
		return;
	}
	//if the word does not connect on the board
	if (connected == false && first == false) {
		//throw invalid_argument("Word is not connected to anything on the board");
		valid = false;
		cout << "Word is not connected to anything on the board" << endl;
		return;
		//cout << "Word is not connected to anything on the board " << endl;
		//return;
	}

	vector<Tile*> retVec = _player->takeTiles(_tString,_quest);
	//splits up the move into two different cases and then places the tiles if it is possible
	if (_horiz == true) {
		


		//checks if the word will go off the board
		if (_x+len-1 > board.getColumns()) {
			//throw invalid_argument("Word is too long");
			valid = false;
			cout << "Word is too long" << endl;
			return;
		}
		//if we are good to go, then we place the tiles
		int skip = 0;
		for (size_t i=0;i<len;i++) {
			if ((board.getSquare(_x+i,_y))->isOccupied()) {
				skip++;
				len++;
			}
			if (!(board.getSquare(_x+i,_y))->isOccupied()) {
				if ((retVec[i-skip]->getLetter()) == '?') {
					len--;
				}
				(board.getSquare(_x+i,_y))->placeTile(retVec[i-skip]);
				score += (retVec[i-skip])->getPoints();
			}
		}
	}

	else {
		//checks if the word will go off the board
		if (_y+len-1 > board.getRows()) {
			//throw invalid_argument("Not a vlid move");
			valid = false;
			cout << "Not a vlid move" << endl;
			return;
			//cout << "Word is too long " << endl;
			//return;
		}
		//if we are good to play, it places the tiles on the board
		int skip = 0;
		for (size_t i=0;i<len;i++) {
			if ((board.getSquare(_x,_y+i))->isOccupied()) {
				skip++;
				len++;
			}
			if (!(board.getSquare(_x,_y+i))->isOccupied()) {
				if ((retVec[i-skip]->getLetter())=='?') {
					len--;
				}

				(board.getSquare(_x,_y+i))->placeTile(retVec[i-skip]);
				score += (retVec[i-skip])->getPoints();
			}
		}
	}


	size_t TTD = len;
	/*
	for (size_t i = 0;i < len;i++) {
		if (_tString[i]=='?') {
			TTD--;
		}
	}
*/
	vector<Tile*> repTiles = bag.drawTiles(TTD);
	_player->addTiles(repTiles);
	//throw expections 	
	_player->_points+=score;
}
//Add more public/protected/private functions/variables here.
