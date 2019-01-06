#include "bst.h"

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <string>
#include <algorithm>
#include <climits>

template <typename Key, typename Value>
class rotateBST:public BinarySearchTree<Key, Value>
{
public:
	bool sameKeys(const rotateBST& t2) const;
	void transform(rotateBST& t2) const;
protected:
	void leftRotate(Node<Key, Value>* r);
	void rightRotate(Node<Key,Value>* r);
private:
	void transHelper(rotateBST& t2, Node<Key, Value>* uno, Node<Key, Value>* dos) const;
};

// template <typename Key, typename Value>
// rotateBST<Key, Value> 

template <typename Key, typename Value>
bool rotateBST<Key, Value>::sameKeys(const rotateBST& t2) const {
	
	bool same = true;
	const rotateBST<Key, Value>* compBST = &(t2);

	//creates iterators for the start and end of each tree
	typename rotateBST<Key, Value>::iterator origIt(this->getSmallestNode());
	typename rotateBST<Key, Value>::iterator compIt(compBST->getSmallestNode());

	//goes through until we hit a NULL
	while (origIt !=NULL || compIt!=NULL) {
		if (origIt->first != compIt->first) {
			same = false;
			return same;
		}
		++origIt;
		++compIt;
	}
	//if there is still something left in one of the iterators, then they are not the same
	if (origIt!=NULL || compIt!=NULL) {
		same = false;
	}
	return same;
}


template <typename Key, typename Value>
void rotateBST<Key, Value>::transform(rotateBST& t2) const {
	
	//if the two BSTs have the same keys
	if (sameKeys(t2)) {
		transHelper(t2, this->mRoot, t2.mRoot);
	}
	//if they do not contain the same keys, we do nothing
	else {
		return;
	}
}

template <typename Key, typename Value>
void rotateBST<Key, Value>::transHelper(rotateBST& t2, Node<Key, Value>* uno, Node<Key, Value>* dos) const {

	if (dos==NULL) {
		return;
	}

	//if this is the root node
	if (uno == this->mRoot && dos == t2.mRoot) {
		while (t2.mRoot->getLeft()!=NULL){
			t2.rightRotate(t2.mRoot);
		}

		Node<Key,Value>* temp3 = t2.mRoot;

		//t2.print();

		while (temp3->getRight()!=NULL) {
			while (temp3->getRight()->getLeft()!=NULL){
				t2.rightRotate(temp3->getRight());
			}
			temp3 = temp3->getRight();
		}

		//t2.print();

		while (t2.mRoot->getKey() != this->mRoot->getKey()) {
			t2.leftRotate(t2.mRoot);
		}


		//if dos Node has something to the left
		if (t2.mRoot->getLeft()!=NULL){
			transHelper(t2,uno->getLeft(),t2.mRoot->getLeft());
		}
		if (t2.mRoot->getRight()!=NULL){
			transHelper(t2,uno->getRight(),t2.mRoot->getRight());
		}
	}


	//all other cases, when we call it recursively
	else {
		Node<Key, Value>* parent = dos->getParent();
		//if dos is left child
		if (parent->getLeft()==dos) {
			while (parent->getLeft()->getLeft()!=NULL) {
				t2.rightRotate(parent->getLeft());
			}
			Node<Key, Value>* temp3 = parent->getLeft();

			while (temp3->getRight()!=NULL) {
				while (temp3->getRight()->getLeft()!=NULL){
					t2.rightRotate(temp3->getRight());
				}
				temp3 = temp3->getRight();
			}
			while (parent->getLeft()->getKey() != uno->getKey()) {
				t2.leftRotate(parent->getLeft());
			}

			//make recursive calls
			if (parent->getLeft()->getLeft()!=NULL) {
				transHelper(t2, uno->getLeft(),parent->getLeft()->getLeft());
			}
			if (parent->getLeft()->getRight()!=NULL) {
				transHelper(t2, uno->getRight(),parent->getLeft()->getRight());
			}
		}
		//if dos is the right child
		else {
			while (parent->getRight()->getLeft()!=NULL) {
				t2.rightRotate(parent->getRight());
			}
			Node<Key, Value>* temp3 = parent->getRight();

			while (temp3->getRight()!=NULL) {
				while (temp3->getRight()->getLeft()!=NULL){
					t2.rightRotate(temp3->getRight());
				}
				temp3 = temp3->getRight();
			}
			while (parent->getRight()->getKey() != uno->getKey()) {
				t2.leftRotate(parent->getRight());
				// std::cout<< parent->getRight()->getKey() << std::endl;
				// t2.print();
			}

			//make recursive calls
			if (parent->getRight()->getLeft()!=NULL) {
				transHelper(t2, uno->getLeft(),parent->getRight()->getLeft());
			}
			if (parent->getRight()->getRight()!=NULL) {
				transHelper(t2, uno->getRight(),parent->getRight()->getRight());	
			}
		}
	}
}

template <typename Key, typename Value>
void rotateBST<Key, Value>::leftRotate(Node<Key, Value>* r) {
	Node<Key, Value>* z = r;
	//if r has no right children
	if (z->getRight()==NULL){
		return;
	}
	else {
		Node<Key,Value>* y = z->getRight();

		//if r is the root node
		if (z->getParent()==NULL){
			this->mRoot = y;
			y->setParent(NULL);
		}

		//if r is not the root node
		else {
			Node<Key, Value>* parent = z->getParent();
			//if r is the left child
			if (parent->getLeft()==z){
				parent->setLeft(y);
				y->setParent(parent);
			}
			//if r is the right child
			else {
				parent->setRight(y);
				y->setParent(parent);
			}
		}

		//sets y as the parent of z
		z->setParent(y);

		Node<Key, Value>* yChild = y->getLeft();
		//////check this again!!!
		if (yChild!=NULL) {
			z->setRight(yChild);
			y->getLeft()->setParent(z);
		}
		else{
			z->setRight(NULL);
		}

		//sets z as the left child of y
		y->setLeft(z);
	}
}

template <typename Key, typename Value>
void rotateBST<Key, Value>::rightRotate(Node<Key,Value>* r) {
	Node<Key, Value>* z = r;
	//if r has no left children
	if (z->getLeft()==NULL){
		return;
	}
	else{
		Node<Key,Value>* y = z->getLeft();

		//if r is the root node
		if (z->getParent()==NULL){
			this->mRoot = y;
			y->setParent(NULL);
		}

		//if r is not the root node
		else {
			Node<Key,Value>* parent = z->getParent();
			//if r is the left child
			if (parent->getLeft()==z){
				parent->setLeft(y);
				y->setParent(parent);
			}
			//if r is the right child
			else {
				parent->setRight(y);
				y->setParent(parent);
			}
		}
		//sets y as the parent of z
		z->setParent(y);

		//reassigns the child of y
		Node<Key,Value>* yChild = y->getRight();
		if (yChild!=NULL){
			z->setLeft(yChild);
			y->getRight()->setParent(z);
		}
		else {
			z->setLeft(NULL);
		}

		//reassigns z as a child of y
		y->setRight(z);
	}
}