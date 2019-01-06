#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

struct Node{
	Node(char c){
		this->c = c;
		color = -1;
	}
	char c;
	int color;

	//creates a set of all of the neighbors
	vector<Node*> neighbors;
};


struct Total_map{
	Total_map(vector<vector<char>>& char_map,size_t countries) {
		for(size_t i =0;i<countries;i++) {
			//Node n(char(i+65));
			neighbor_list.push_back(new Node(char(i+65)));
		}
	}
	~Total_map() {
		for (size_t i =0;i<neighbor_list.size();i++) {
			delete neighbor_list[i];
		}
	}
	vector<Node*> neighbor_list;

	//connects two nodes at index1 and index2
	void connect(int index1, int index2) {
		bool exists = false;

		for (size_t i = 0 ;i<neighbor_list[index1]->neighbors.size();i++) {
			if (neighbor_list[index1]->neighbors[i]->c == neighbor_list[index2]->c) {
				exists = true;
			}
		}
		for (size_t i = 0;i<neighbor_list[index2]->neighbors.size();i++) {
			if (neighbor_list[index2]->neighbors[i]->c == neighbor_list[index1]->c) {
				exists = true;
			}
		}
		if (!exists) {
			neighbor_list[index1]->neighbors.push_back(neighbor_list[index2]);
			neighbor_list[index2]->neighbors.push_back(neighbor_list[index1]);
		}
	}

	//finds a node with the given character assigned to it
	int find_node(char nodeC) {
		for(size_t i = 0;i<neighbor_list.size();i++) {
			if (neighbor_list[i]->c==nodeC) {
				return i;
			}
		}
		return -1;
	}
};

//function to check if a Node has a legal coloring (no neighbors have the same color)
bool legalColor(Node n) {
	int col = n.color;
	if (col == -1) {
		return false;
	}
	for (size_t i = 0;i < n.neighbors.size();i++) {
		if (n.neighbors[i]->color == col) {
			return false;
		}
	}
	return true;
}
//colors the graph, and returns true if it is colored
bool color_graph(vector<Node*>& neighbor_list,size_t it) {
	//Basecase for the recursive Backtrace
	if (it == neighbor_list.size()) {
		return true;
	}

	else {
		//goes through all of the colors and tries to assign one
		for (size_t i = 1;i<=4;i++) {
			neighbor_list[it]->color = i;
			if (legalColor(*(neighbor_list[it]))) {
				if (color_graph(neighbor_list,it+1)) {
					return true;
				} 
				//if no colors work, we reassign the color and backtrack
				else	{
					if (neighbor_list[it]->color==4) {
						neighbor_list[it]->color = -1;
						return false;
					}
				}
			}
			else {
				neighbor_list[it]->color = -1;
			}
		}
		//last statement used for backtracking, in case that none of the colors work
		if (!legalColor(*(neighbor_list[it]))) {
			return false;
		}
	}
}


int main(int argc, char** argv) {
	if(argc < 2){
		cout << "Please provide a string of characters." << endl;
		return 0;
	}
	ifstream ifile(argv[1]);
	string fileTemp;
	//reads in all of the information from the file
	
	size_t countries;
	size_t rows;
	size_t cols;
	ifile >> countries;
	ifile >> rows;
	ifile >> cols;

	//creates our three 
	vector<vector<char>> char_map;
	vector<vector<Node>> node_map;
	vector<vector<bool>> discovered;

	//gets rid of extra whitespace
	string temp_waste;
	getline(ifile,temp_waste);

	vector<Node> individual_chars;
	for (size_t i =0;i < countries; i++) {
		Node n(char(i+65));
		individual_chars.push_back(n);
	}


	//creates the char and discovered vectors
	for (size_t i =0;i < rows;i++) {
		string temp_char;
		getline(ifile,temp_char);
		//reads in the characters in the row into the 2d vector
		vector<char> tempvec;
		vector<bool> temp_bool;
		for (size_t j=0;j<cols;j++) {
			tempvec.push_back(temp_char[j]);
			temp_bool.push_back(false);
		}
		char_map.push_back(tempvec);
		discovered.push_back(temp_bool);
	}

	//creates the map of Nodes
	for (size_t i =0;i<rows;i++) {
		vector<Node> tempnode;
		for (size_t j=0;j<cols;j++) {
			for (size_t x=0;x<countries;x++) {
				if (char_map[i][j]==char(x+65)) {
					//pushes back each of the nodes
					tempnode.push_back(individual_chars[x]);
				}
			}
		}
		node_map.push_back(tempnode);
	}


	Total_map Map(char_map, countries);
	
	//goes through our 2d vector of chars and find all the borders of each of the countries
	for (size_t i = 0;i<rows;i++) {
		for (size_t j =0;j<cols;j++) {
			char base_char = (node_map[i][j]).c;
			//checks below the Node
			if (i+1 < rows) {
				char compare_char1 = (node_map[i+1][j].c);
				if (base_char != compare_char1) {
					int one = Map.find_node(base_char);
					int two = Map.find_node(compare_char1);
					Map.connect(one, two);
				}
			}
			//checks to the right of the Node
			if (j+1 < cols) {
				char compare_comp2 = (node_map[i][j+1].c); 
				if (base_char != char_map[i][j+1]) {
					int one = Map.find_node(base_char);
					int two = Map.find_node(compare_comp2);
					Map.connect(one, two);
				}
			}
		}
	}

	bool colored = color_graph(Map.neighbor_list,0);
	//prints out the final colors
	for (size_t i =0;i<countries;i++) {
		cout << Map.neighbor_list[i]->c << " ";
		cout << Map.neighbor_list[i]->color << endl;
	}

	return 0;
}
