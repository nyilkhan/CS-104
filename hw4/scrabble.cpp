#include "Player.h"
#include "Square.h"
#include "Bag.h"
#include "Board.h"
#include "ConsolePrinter.h"
#include "Dictionary.h"
#include "Exceptions.h"
#include "Move.h"
#include "Tile.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
	if(argc < 2){
		cout << "Please provide a string of characters." << endl;
		return 0;
	}
	ifstream ifile(argv[1]);

	//to set up all of the other files
	int handsize = 0;
	string board = "";
	string tiles = "";
	string dictionary = "";
	uint32_t seed = 0;

	string fileTemp;

	//reads in the config file
	while (getline(ifile, fileTemp)) {
		stringstream ss(fileTemp);
		char first;
		ss >> first;

		if (first == 'H') {
			char semi = 'A';
			while (semi != ':') {
				ss >> semi;
			}
			ss >> handsize;
		}
		else if (first == 'T') {
			char semi = 'A';
			while (semi != ':') {
				ss >> semi;
			}
			ss >> tiles;
		}
		else if (first == 'D') {
			char semi = 'A';
			while (semi != ':') {
				ss >> semi;
			}
			ss >> dictionary;
		}
		else if (first == 'B') {
			char semi = 'A';
			while (semi != ':') {
				ss >> semi;
			}
			ss >> board;
		}
		else if (first == 'S') {
			char semi = 'A';
			while (semi != ':') {
				ss >> semi;
			}
			int temp = 0;
			ss >> seed;
		}
	}

	srand(seed);

	//creates the dictionary
	Dictionary dic(dictionary);
	//creates the gameboard
	Board gameboard(board);

	ConsolePrinter::printBoard(gameboard);



//Starting the actual game
	cout << "How many players are playing? (1-8)" << endl;


	size_t numPlayers;
	cin >> numPlayers;
	//checks to make sure there are enough players
	while (numPlayers>8 || numPlayers < 1) {
		cout << "How many players are playing? (1-8)" << endl;
		cin >> numPlayers;
	}

	//creates our vector of player*
	vector<Player*> players;
	for (size_t i=0;i<numPlayers;i++) {
		string name;
		cout << "Enter the name of Player " << i+1 << endl;
		cin >> name;
		Player* pl = new Player(name, handsize);
		players.push_back(pl);
	}
	//initializes the bag
	Bag bag(tiles, seed);


	//pick tiles for all the players
	for (size_t i=0;i<numPlayers;i++) {
		vector<Tile*> tilesToAdd = bag.drawTiles(handsize);
		players[i]->addTiles(tilesToAdd);
	}

	bool gameGo = true;

	int turn = 0;

	//in order to bring in the command
	cin.ignore();
	string pal;
	bool first = true;

	while (gameGo) {
		if (turn > 4) {
			gameGo = false;
		}
		for (size_t i =0 ;i<numPlayers;i++) {
			ConsolePrinter::printBoard(gameboard);

			ConsolePrinter::printHand(*(players[i]));

			cout << "PLAYER: " << i+1 << " ENTER MOVE " << endl;
			string pal = "";

			//getline(cin,pal);
			bool validMove = false;
			while (!validMove) {
				exception e;
				getline(cin,pal);
				validMove = true;
				Move* move = Move::parseMove(pal,*players[i]);
				if (move->valid == false) {
					validMove = false;
					cout << "DId not enter valid string " << endl;
					continue;
				}
				move->execute(gameboard,bag,dic,first);
				if (move->valid == false) {
					validMove = false;
					cout << "Please enter a new move " << endl;
				}
				else {
					if (move->isWord()) {
						first = false;
					}
				}

			}
			cout << "PLayer " << i+1 << " Points " <<  players[i]->_points << endl;
		}
		turn++;
		
	}
	//prints final game board
	ConsolePrinter::printBoard(gameboard);

	return 0;


}