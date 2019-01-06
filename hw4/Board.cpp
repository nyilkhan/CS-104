#include "Board.h"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


Board::Board(string board_file_namey) {


	ifstream ifile(board_file_namey);

	ifile >> _width;
	ifile >> _height;

	ifile >> startW;
	ifile >> startH;

	_vec.resize(_height,vector<Square*>(_width,0));

	//iterates through each row one character at a time, and then goes down the column
	for (size_t i=0;i<_height;i++) {
		for (size_t j=0;j<_width;j++) {
			char curr = 'z';
			ifile >> curr;
			//creates the square based on the text file
			Square* sq;
			if (curr == 't') {
				if (i==startH-1 && j == startW-1) {
					sq = new Square(1,3,true);
				}
				else {
					sq = new Square(1,3,false);
				}
			}
			else if (curr == 'd') {
				if (i==startH-1 && j == startW-1) {
					sq = new Square(1,2,true);
				}
				else {
					sq = new Square(1,2,false);
				}
			}
			else if (curr == '2') {
				if (i==startH-1 && j == startW-1) {
					sq = new Square(2,1,true);
				}
				else {
					sq = new Square(2,1,false);
				}
			}
			else if (curr == '3') {
				if (i==startH-1 && j == startW-1) {
					sq = new Square(3,1,true);
				}
				else {
					sq = new Square(3,1,false);
				}
			}
			else if (curr == '.') {
				if (i==startH-1 && j == startW-1) {
					sq = new Square(1,1,true);
				}
				else {
					sq = new Square(1,1,false);
				}
			}
			_vec[i][j] = (sq);
		}
	}
}

Board::~Board() {
	for (size_t i=0;i<_height;i++) {
		for (size_t j=0;j<_width;j++) {
			delete _vec[i][j];
		}
	}
}
/*
vector<pair<string, unsigned int> > Board::getPlaceMoveResults(const PlaceMove &m) const {

}
/*
void Board::executePlaceMove (const PlaceMove & m) {

}
*/
Square * Board::getSquare (size_t x, size_t y) const {
	return _vec[x-1][y-1];
}

size_t Board::getRows() const {
	return _width;
}

size_t Board::getColumns() const {
	return _height;
}