#include <string>
#include <map>
#include <vector>
#include <utility>

#include "Move.h"
#include "Dictionary.h"
#include "Board.h"
#include "Player.h"
#include "Square.h"
#include "Util.h"

class masterAI:public Player{
public:
	masterAI(std::string const & name, size_t maxTiles, Board* gameboard, Dictionary* dick, int CPUnum);

	~masterAI();

	void anchor();

	void buildLeft(std::string partial, std::string moveStr, TrieNode* currNode, int startR, int startC,int row, int col);

	void buildRight(std::string partial,std::string moveStr, TrieNode* currNode, int startR, int startC , int row, int col);

	void buildUp(std::string partial,std::string moveStr, TrieNode* currNode, int startR, int startC , int row, int col);

	void buildDown(std::string partial,std::string moveStr, TrieNode* currNode, int startR, int startC , int row, int col); 

	bool isLegalMove(std::string givenWord, int x, int y, bool horiz);

	//finds all of the possibel startign positions and returns a vector of those squares
	// std::vector<Square*> startPosV();

	// std::vector<Square*> startPosH();

	// //returns a vector of the tiles to place
	// std::vector<Tile*> tilesPlace();

	Board* board;
	Dictionary* dic;

	std::vector<char> AItiles;

	std::vector<std::pair<std::string, Square*>> possibleMoveVec;

};

