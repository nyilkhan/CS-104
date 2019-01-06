#include "bst.h"
#include "rotateBST.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	
	rotateBST<int, int> myTree1;

	rotateBST<int,int> myTree2;


	myTree2.insert(make_pair(3, 3));

	myTree2.insert(make_pair(4,4));

	myTree2.insert(make_pair(1,1));

	myTree2.insert(make_pair(6,6));

	myTree2.insert(make_pair(14,14));

	myTree2.insert(make_pair(5,5));

	myTree2.insert(make_pair(2, 2));

	myTree2.insert(make_pair(10, 10));



	myTree1.insert(make_pair(5,5));

	myTree1.insert(make_pair(2, 2));

	myTree1.insert(make_pair(4, 4));

	myTree1.insert(make_pair(10, 10));

	myTree1.insert(make_pair(3, 3));

	myTree1.insert(make_pair(14,14));

	myTree1.insert(make_pair(1,1));

	myTree1.insert(make_pair(6,6));


	//print both trees
	
	myTree1.BinarySearchTree::print();
	myTree2.print();


	
	myTree1.transform(myTree2);


	
	myTree1.BinarySearchTree::print();
	myTree2.print();




	return -1;
}