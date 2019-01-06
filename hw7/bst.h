#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <string>
#include <algorithm>
#include <climits>


/**
* A templated class for a Node in a search tree. The getters for parent/left/right are virtual so that they
* can be overridden for future kinds of search trees, such as Red Black trees, Splay trees, and AVL trees.
*/
template <typename Key, typename Value>
class Node
{
public:
	Node(const Key& key, const Value& value, Node<Key, Value>* parent);
	virtual ~Node();

	const std::pair<Key, Value>& getItem() const;
	std::pair<Key, Value>& getItem();
	const Key& getKey() const;
	const Value& getValue() const;
	Key& getKey();
	Value& getValue();

	virtual Node<Key, Value>* getParent() const;
	virtual Node<Key, Value>* getLeft() const;
	virtual Node<Key, Value>* getRight() const;

	void setParent(Node<Key, Value>* parent);
	void setLeft(Node<Key, Value>* left);
	void setRight(Node<Key, Value>* right);
	void setValue(const Value &value);

protected:
	std::pair<Key, Value> mItem;
	Node<Key, Value>* mParent;
	Node<Key, Value>* mLeft;
	Node<Key, Value>* mRight;
};

/*
	-----------------------------------------
	Begin implementations for the Node class.
	-----------------------------------------
*/

/**
* Explicit constructor for a node.
*/
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent)
	: mItem(key, value)
	, mParent(parent)
	, mLeft(NULL)
	, mRight(NULL)
{

}

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed within the deleteAll() helper method in the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node()
{

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<Key, Value>& Node<Key, Value>::getItem() const
{
	return mItem;
}

/**
* A non-const getter for the item.
*/
template<typename Key, typename Value>
std::pair<Key, Value>& Node<Key, Value>::getItem()
{
	return mItem;
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const
{
	return mItem.first;
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const
{
	return mItem.second;
}

/**
* A non-const getter for the key.
*/
template<typename Key, typename Value>
Key& Node<Key, Value>::getKey()
{
	return mItem.first;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
	return mItem.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const
{
	return mParent;
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const
{
	return mLeft;
}

/**
* An implementation of the virtual function for retreiving the right child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const
{
	return mRight;
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent)
{
	mParent = parent;
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left)
{
	mLeft = left;
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right)
{
	mRight = right;
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value)
{
	mItem.second = value;
}

/*
	---------------------------------------
	End implementations for the Node class.
	---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree
{
	public:
		BinarySearchTree(); //TODO
		virtual ~BinarySearchTree(); //TODO
  		virtual void insert(const std::pair<Key, Value>& keyValuePair); //TODO
        virtual void remove(const Key& key); //TODO
  		void clear(); //TODO
  		void print() const;
  		bool isBalanced() const; //TODO

	public:
		/**
		* An internal iterator class for traversing the contents of the BST.
		*/
		class iterator
		{
			public:
				iterator(Node<Key,Value>* ptr);
				iterator();

				std::pair<Key,Value>& operator*() const;
				std::pair<Key,Value>* operator->() const;

				bool operator==(const iterator& rhs) const;
				bool operator!=(const iterator& rhs) const;
				iterator& operator=(const iterator& rhs);

				iterator& operator++();

			protected:
				Node<Key, Value>* mCurrent;

				friend class BinarySearchTree<Key, Value>;
		};

	public:
		iterator begin() const;
		iterator end() const;
		iterator find(const Key& key) const;
		Node<Key, Value>* mRoot;

	protected:
		Node<Key, Value>* internalFind(const Key& key) const; //TODO
		Node<Key, Value>* getSmallestNode() const; //TODO
		void printRoot (Node<Key, Value>* root) const;

	protected:
		//Node<Key, Value>* mRoot;

	public:
		void print() {this->printRoot(this->mRoot);}
		void deleteAll(Node<Key, Value>* root);
		int ht(Node<Key,Value>* root) const;
		bool balanceHelper(Node<Key, Value>* root) const;

};

/*
	---------------------------------------------------------------
	Begin implementations for the BinarySearchTree::iterator class.
	---------------------------------------------------------------
*/

/**
* Explicit constructor that initializes an iterator with a given node pointer.
*/
template<typename Key, typename Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value>* ptr): mCurrent(ptr)
{

}

/**
* A default constructor that initializes the iterator to NULL.
*/
template<typename Key, typename Value>
BinarySearchTree<Key, Value>::iterator::iterator()
	: mCurrent(NULL)
{

}

/**
* Provides access to the item.
*/
template<typename Key, typename Value>
std::pair<Key, Value>& BinarySearchTree<Key, Value>::iterator::operator*() const
{
	return mCurrent->getItem();
}

/**
* Provides access to the address of the item.
*/
template<typename Key, typename Value>
std::pair<Key, Value>* BinarySearchTree<Key, Value>::iterator::operator->() const
{
	return &(mCurrent->getItem());
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::iterator::operator==(const BinarySearchTree<Key, Value>::iterator& rhs) const
{
	return this->mCurrent == rhs.mCurrent;
}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::iterator::operator!=(const BinarySearchTree<Key, Value>::iterator& rhs) const
{
	return this->mCurrent != rhs.mCurrent;
}

/**
* Sets one iterator equal to another iterator.
*/
template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator &BinarySearchTree<Key, Value>::iterator::operator=(const BinarySearchTree<Key, Value>::iterator& rhs)
{
	this->mCurrent = rhs.mCurrent;
	return *this;
}

/**
* Advances the iterator's location using an in-order traversal.
*/
template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator& BinarySearchTree<Key, Value>::iterator::operator++()
{
	if(mCurrent->getRight() != NULL)
	{
		mCurrent = mCurrent->getRight();
		while(mCurrent->getLeft() != NULL)
		{
			mCurrent = mCurrent->getLeft();
		}
	}
	else if(mCurrent->getRight() == NULL)
	{
		Node<Key, Value>* parent = mCurrent->getParent();
		while(parent != NULL && mCurrent == parent->getRight())
		{
			mCurrent = parent;
			parent = parent->getParent();
		}
		mCurrent = parent;
	}
	return *this;
}

/*
	-------------------------------------------------------------
	End implementations for the BinarySearchTree::iterator class.
	-------------------------------------------------------------
*/

/*
	-----------------------------------------------------
	Begin implementations for the BinarySearchTree class.
	-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree():mRoot(NULL)
{
	// TODO
	//mRoot = NULL;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree()
{
	// TODO
	deleteAll(mRoot);
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{
	printRoot(mRoot);
	std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/
template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::begin() const
{
	BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());
	return begin;
}

/**
* Returns an iterator whose value means INVALID
*/
template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::end() const
{
	BinarySearchTree<Key, Value>::iterator end(NULL);
	return end;
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/
template<typename Key, typename Value>
typename BinarySearchTree<Key, Value>::iterator BinarySearchTree<Key, Value>::find(const Key& key) const
{
	Node<Key, Value>* curr = internalFind(key);
	BinarySearchTree<Key, Value>::iterator it(curr);
	return it;
}

/**
* An insert method to insert into a Binary Search Tree. The tree will not remain balanced when
* inserting.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<Key, Value>& keyValuePair)
{
	// TODO

	Key k = keyValuePair.first;
	Value v = keyValuePair.second;

	Node<Key, Value>* currNode = mRoot;
	Node<Key, Value>* newNode = new Node<Key, Value>(k,v,NULL);

	newNode->setRight(NULL);
	newNode->setLeft(NULL);

	//if this is the first thing we are adding
	if (currNode==NULL) {
		mRoot = newNode;
	}
	//if we already have nodes in the BST
	else {
		while (currNode!=NULL) {
			//if we should traverse to the right
			if (k > currNode->getKey()) {
				if (currNode->getRight()==NULL) {
					newNode->setParent(currNode);
					currNode->setRight(newNode);
					break;
				}
				else {
					currNode = currNode->getRight();
				}
			}
			//if we should traverse to the left
			else if (k < currNode->getKey()) {
				if (currNode->getLeft()==NULL) {
					newNode->setParent(currNode);
					currNode->setLeft(newNode);
					break;
				}
				else {
					currNode = currNode->getLeft();
				}
			}
			//if the key is already in the BST
			else if (k == currNode->getKey()) {
				currNode->setValue(v);
				delete newNode;
				break;
			}
		}
	}

}

/**
* An remove method to remove a specific key from a Binary Search Tree. The tree may not remain balanced after
* removal.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::remove(const Key& key)
{
	// TODO
	Node<Key, Value>* NodeRem = internalFind(key);

	if (NodeRem==NULL) {
		return;
	}
	//finds number of children for node we want to remove
	int children = 0;
	if (NodeRem->getLeft()!=NULL) {
		children++;
	}
	
	if (NodeRem->getRight()!=NULL) {
		children++;
	}


	//if the Removal Node has no children
	if (children==0) {
		//if we delete the only Node in the BST (Root)
		if (NodeRem->getParent()==NULL) {
			deleteAll(mRoot);
			mRoot = NULL;
		}
		//if it is not a root Node
		else {
			Node<Key, Value>* parent = NodeRem->getParent();
			if (parent->getLeft()==NodeRem) {
				parent->setLeft(NULL);
			}
			else if (parent->getRight()==NodeRem) {
				parent->setRight(NULL);
			}
			delete NodeRem;
		}
	}

	//if the removal Node has one child
	else if (children==1) {
		//if the node is the root node
		if (NodeRem->getParent()==NULL) {
			//if it only has a left child
			if (NodeRem->getLeft()!=NULL) {
				NodeRem->getLeft()->setParent(NULL);
				mRoot = NodeRem->getLeft();
			}
			//if it only has a right child
			else {
				NodeRem->getRight()->setParent(NULL);
				mRoot = NodeRem->getRight();
			}
			delete NodeRem;
		}
		//if it is not a root node
		else {
			Node<Key, Value>* parent = NodeRem->getParent();
			
			//if it only has a left child
			if (NodeRem->getLeft()!=NULL) {
				NodeRem->getLeft()->setParent(parent);
				if (parent->getLeft() == NodeRem) {
					parent->setLeft(NodeRem->getLeft());
				}
				else {
					parent->setRight(NodeRem->getLeft());
				}
			}
			//if it only has a right child
			else {
				NodeRem->getRight()->setParent(parent);
				if (NodeRem->getParent()->getLeft() == NodeRem) {
					parent->setLeft(NodeRem->getRight());
				}
				else {
					parent->setRight(NodeRem->getRight());
				}
			}
			delete NodeRem;
		}
	}
	//if the removal Node has two children
	else if (children==2) {
		Node<Key, Value>* pred = NodeRem->getLeft();
		Node<Key,Value>* left = NodeRem->getLeft();
		Node<Key,Value>* right = NodeRem->getRight();

		
		//finds the predecesor
		while(pred->getRight() != NULL) {
			pred = pred->getRight();
		}

		if (pred==left) {
			//if it is root node
			if (NodeRem->getParent()==NULL){
				pred->setParent(NULL);
				mRoot = pred;
			}
			//if it is not root node
			else {
				//if it is the parents left node
				if (NodeRem->getParent()->getLeft()==pred){
					NodeRem->getParent()->setLeft(pred);
				}
				//if it is the parents right node
				else {
					NodeRem->getParent()->setRight(pred);
				}
				pred->setParent(NodeRem->getParent());
			}
			pred->setRight(right);
			right->setParent(pred);
		}
		else {
			Node<Key,Value>* predParent = pred->getParent();
			
			//if the predecessor has a child
			if (pred->getLeft()!=NULL) {
				//sets the childs parent
				pred->getLeft()->setParent(predParent);
				//sets the parent to the new child
				predParent->setRight(pred->getLeft());
			}
			else {
				predParent->setRight(NULL);
		
			}

			//if removed node is not root node
			if (NodeRem->getParent()!=NULL){
				Node<Key,Value>* parent = NodeRem->getParent();
				//sets the removal Nodes Parents Children nodes
				if (parent->getLeft()==NodeRem) {
					parent->setLeft(pred);
				}
				else {
					parent->setRight(pred);
				}
				pred->setParent(parent);
			}

			//if removed node is root
			else {
				pred->setParent(NULL);
				mRoot = pred;
			}

			pred->setLeft(left);
			left->setParent(pred);
			pred->setRight(right);
			right->setParent(pred);
		}

		//reassigns all of the pointers from the removed Node
		NodeRem->setParent(NULL);
		NodeRem->setRight(NULL);
		NodeRem->setLeft(NULL);

		delete NodeRem;

	}	
}

/**
* A method to remove all contents of the tree and reset the values in the tree
* for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
	// TODO
	deleteAll(mRoot);
	mRoot = NULL;
}

/**66
* A helper function to find the smallest node in the tree.
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::getSmallestNode() const
{
	// TODO
	Node<Key, Value>* currNode = mRoot;
	while (currNode->getLeft() != NULL) {
		currNode = currNode->getLeft();
	}
	return currNode;
}

/**
* Helper function to find a node with given key, k and
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const
{
	// TODO
	//starts at root and continues until we find what we are looking for
	Node<Key, Value>* currNode = mRoot;
	while (currNode != NULL) {
		if (currNode->getKey() == key ) {
			return currNode;
		}
		else if (currNode->getKey() > key) {
			currNode = currNode->getLeft();
		}
		else if (currNode->getKey() < key) {
			currNode = currNode->getRight();
		}
	}
	return NULL;
}

/**
 * Return true iff the BST is an AVL Tree.
 */
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalanced() const
{
	Node<Key, Value>* root = mRoot;
	return balanceHelper(root);
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::ht(Node<Key,Value>* root) const {
	if (root == NULL){
		return 0;
	}
	return 1 + std::max(ht(root->getLeft()),ht(root->getRight()));
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::balanceHelper(Node<Key,Value>* root) const {
	int lhs;
	int rhs;

	if (root==NULL) {
		return true;
	}
	lhs = ht(root->getLeft());
	rhs = ht(root->getRight());
	if (abs(lhs-rhs)<=1 && balanceHelper(root->getLeft()) && balanceHelper(root->getRight())) {
		return true;
	}
	return false; 
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::deleteAll(Node<Key, Value>* root) 
{
	if (root == NULL) {
		return;
	}
	else {
		deleteAll(root->getLeft());
		deleteAll(root->getRight());
		delete root;
	}
}


/**
 * Lastly, we are providing you with a print function, BinarySearchTree::printRoot().
   Just call it with a node to start printing at, e.g:
   this->printRoot(this->mRoot)

   It will print up to 5 levels of the tree rooted at the passed node, in ASCII graphics format.
   We hope it will make debugging easier!
  */

// include print function (in its own file because it's fairly long)
#include "print_bst.h"

/*
	---------------------------------------------------
	End implementations for the BinarySearchTree class.
	---------------------------------------------------
*/

#endif
