#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include "duck_duck_goose.h" 

using namespace std;

int main(int argc, char** argv) {
	if(argc < 3){
    cerr << "Please provide a string of characters." << endl;
    return 0;
  	}

  	ifstream ifile(argv[1]);
  	unsigned int seed;
  	int numPlayers;
  	srand(seed);

	GameData* game = new GameData();

  	ifile>>seed;
  	ifile>>numPlayers;
  	ifile>> game->itPlayerID;


  	//creates all of the player IDs in the game
  	for (int i=0;i<numPlayers;i++) {
  		int val;
  		ifile>>val;
  		game->playerList.push_back(val);
  	}

  	//create the file to output to
  	ofstream ofile(argv[2]);

  	while (game->playerList.size()>0) {
  		simulateDDGRound(game, ofile); 
  	}

  	ifile.close();
  	ofile.close();
  	
  	delete game;

	return 0;
}

void simulateDDGRound(GameData * gameData, std::ostream & output) {
	int itplayer = gameData->itPlayerID;

	int numPlayers = (int)(gameData->playerList.size());

	int goose = rand() % (4*numPlayers);

	for (int i=0;i<goose;i++) {
		int playerid = gameData->playerList.get(i);
		output << playerid << " is a Duck." << endl<< "\n";
	}
	

	int gooseid = gameData->playerList.get(goose);
	output << gooseid << " is a Goose!" << endl<< "\n";

	int itnum = rand() % 50;
	int goosenum = rand() % 50;

	while (itnum == goosenum) {
		itnum = rand() % 50;
		goosenum = rand() % 50;
	}
	if (itnum > goosenum) {
		output<< itplayer << " took " << gooseid << "'s spot!" << endl << "\n";
		gameData->itPlayerID = gooseid;
		gameData->playerList.set((size_t)gooseid,itplayer);
	}
	else {
		output << itplayer << " is out!" << endl<< "\n";
		gameData->playerList.remove(itplayer);
		if (gameData->playerList.size() >1) {
			int randomnew = rand() % (int)(gameData->playerList.size());
			while (randomnew == gooseid) {
				randomnew = rand() % (int)(gameData->playerList.size());
			}
			gameData->itPlayerID = randomnew;
			output << randomnew << " was chosen as the new it." << endl << "\n";
		}
	}
	if (gameData->playerList.size() == 1) {
		output << "Winner is " << gooseid << "!" << endl<< "\n";
		//gameData->playerList.remove(0);
	}
}