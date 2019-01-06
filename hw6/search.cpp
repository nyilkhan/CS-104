#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>


using namespace std;


struct Node{
	Node(int x, int y, char c){
		this->x = x;
		this->y = y;
		this->c = c;
	}
	int x;
	int y;
	char c;
};

int size(vector<vector<bool>>& found,vector<vector<char>> map, char c, Node start) {
	int sz =0;
	queue<Node> q;
	q.push(start);
	found[start.y][start.x] = true;
	sz++;
	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		if (temp.x>0) {
			if (found[temp.y][temp.x-1]==false && map[temp.y][temp.x-1]==c) {
				q.push(Node(temp.x-1,(temp.y),c));
				found[temp.y][temp.x-1] = true;
				sz++;
			}	
		}
		if (temp.y>0) {
			if (found[temp.y-1][temp.x]==false && map[temp.y-1][temp.x]==c) {
				q.push(Node((temp.x),temp.y-1,c));
				found[temp.y-1][temp.x] = true;
				sz++;

			}
		}
		if (temp.x<found[0].size()-1) {
			if (found[temp.y][temp.x+1]==false && map[temp.y][temp.x+1]==c) {
				q.push(Node(temp.x+1,(temp.y),c));
				found[temp.y][temp.x+1] = true;
				sz++;
			}
		}
		if (temp.y<found.size()-1) {
			if (found[(temp.y+1)][temp.x]==false && map[temp.y+1][temp.x]==c) {
				q.push(Node((temp.x),temp.y+1,c));
				found[temp.y+1][temp.x] = true;
				sz++;
			}
		}
	}
	return sz;
}


int main(int argc, char** argv) {
	if(argc < 2){
		cout << "Please provide a string of characters." << endl;
		return 0;
	}
	ifstream ifile(argv[1]);

	string fileTemp;
	//reads in all of the information from the file
	size_t letters;
	size_t rows;
	size_t cols;
	ifile >> letters;
	ifile >> rows;
	ifile >> cols;

	int max = 0;

	//initializes the map vector
	vector<vector<char>> map;
	
	//initializes a vector of bools to see when things are found
	vector<vector<bool>> found;

	//gets rid of the whitespace
	string temptemp;
	getline(ifile,temptemp);
	
	//gets all of the characters and fills the map
	for (size_t i =0;i < rows;i++) {
		string rowtemp;
		getline(ifile,rowtemp);
		//reads in the characters in the row into the 2d vector
		vector<char> tempvec;
		for (size_t j=0;j<cols;j++) {
			tempvec.push_back(rowtemp[j]);
		}
		map.push_back(tempvec);
	}

	 //creates and fills the bool vector
	 for (size_t i=0; i<rows;i++) {
	 	vector<bool> tempvec2;
	 	for (size_t j=0;j<cols;j++) {
	 		tempvec2.push_back(false);
	 	}
	 	found.push_back(tempvec2);
	 }
	//finds the maximum size and saves it
	for (size_t i =0; i<rows;i++) {
		for (size_t j=0;j<cols;j++) {
			if (found[i][j]==false) {
				int tempMax = size(found,map,map[i][j],Node(j,i,map[i][j]));
				if (tempMax>max) {
					max = tempMax;
				}
			}
		}	
	}
	cout << max << endl;
	return 0;
}