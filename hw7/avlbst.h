#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "rotateBST.h"

/**
* A special kind of node for an AVL tree, which adds the height as a data member, plus 
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
	// Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int getHeight() const;
    void setHeight(int height);

    // Getters for parent, left, and right. These need to be redefined since they 
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int mHeight;

};

/*
--------------------------------------------
Begin implementations for the AVLNode class.
--------------------------------------------
*/

/**
* Constructor for an AVLNode. Nodes are initialized with a height of 0.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent)
    : Node<Key, Value>(key, value, parent)
    , mHeight(0)
{

}

/**
* Destructor.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* Getter function for the height. 
*/
template<typename Key, typename Value>
int AVLNode<Key, Value>::getHeight() const
{
    return mHeight;
}

/**
* Setter function for the height. 
*/
template<typename Key, typename Value>
void AVLNode<Key, Value>::setHeight(int height)
{
    mHeight = height;
}

/**
* Getter function for the parent. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key,Value>*>(this->mParent);
}

/**
* Getter function for the left child. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key,Value>*>(this->mLeft);
}

/**
* Getter function for the right child. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key,Value>*>(this->mRight);
}

/*
------------------------------------------
End implementations for the AVLNode class.
------------------------------------------
*/

/**
* A templated balanced binary search tree implemented as an AVL tree.
*/
template <class Key, class Value>
class AVLTree : public rotateBST<Key, Value>
{
public:
	// Methods for inserting/removing elements from the tree. You must implement
	// both of these methods. 
    virtual void insert(const std::pair<Key, Value>& keyValuePair) override;
    void remove(const Key& key);

private:
	/* Helper functions are strongly encouraged to help separate the problem
	   into smaller pieces. You should not need additional data members. */
    void insertHelp(AVLNode<Key,Value>* parent, AVLNode<Key,Value>* childNode);
};

/*
--------------------------------------------
Begin implementations for the AVLTree class.
--------------------------------------------
*/

/**
* Insert function for a key value pair. Finds location to insert the node and then balances the tree. 
*/
template<typename Key, typename Value>
void AVLTree<Key, Value>::insert(const std::pair<Key, Value>& keyValuePair)
{
    // TODO
    Key k = keyValuePair.first;
    Value v = keyValuePair.second;

    AVLNode<Key, Value>* newNode = new AVLNode<Key, Value>(k,v,NULL);
    Node<Key, Value>* currNode = this->mRoot;

    newNode->setRight(NULL);
    newNode->setLeft(NULL);
    newNode->setHeight(0);


    //inserting new node
    if (currNode==NULL) {
        this->mRoot = newNode;
        return;
    }
    else {
        while (currNode!=NULL) {
            //if we should traverse to the right
            if (k > currNode->getKey()) {
                //
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
            else if (k == currNode->getKey()) {
                currNode->setValue(v);
                delete newNode;
                return;
            }
        }


        //balancing the tree afterwards
        AVLNode<Key, Value>* dynNode = dynamic_cast<AVLNode<Key,Value>*>(currNode);
        //if the node is already balanced
        if (dynNode->getHeight()==0) {
            //if the new node is the left child
            if (dynNode->getLeft()==newNode) {
                dynNode->setHeight(-1);
            }
            //if the new node is the right child
            else {
                dynNode->setHeight(1);
            }
            insertHelp(dynNode, newNode);
        }
        //if the current node already has a node, then it becomes balanced
        else {
            dynNode->setHeight(0);
        }        
    } 
}
template<typename Key, typename Value>
void AVLTree<Key, Value>::insertHelp(AVLNode<Key, Value>* parent, AVLNode<Key, Value>* childNode) {
    //basecase; we are all the way up the tree
    if (parent->getParent()==NULL || parent==NULL) {
        return;
    }

    
    AVLNode<Key, Value>* gparent = parent->getParent();


    int gHeight = gparent->getHeight();
    //if the grandparent is already balanced
    if (gHeight == 0) {
        if (gparent->getRight() == parent) {
            gparent->setHeight(1);
            insertHelp(gparent,parent);
        }
        else {
            gparent->setHeight(-1);
            insertHelp(gparent,parent);

        }
    }
    //if the grandparent has left balance
    else if(gHeight == -1) {
        if (gparent->getRight() == parent) {
            //it is balanced
            gparent->setHeight(0);
            return;
        }
        else {
            gparent->setHeight(-2);
            //zig ziz
            if (parent->getLeft()==childNode) {
                this->rightRotate(gparent);
            }
            //zig zag 
            else {
                this->leftRotate(parent);
                this->rightRotate(gparent);

                if (childNode->getHeight() == 0) {
                    gparent->setHeight(0);
                    parent->setHeight(0);
                }
                //if the child has a left balance
                else if (childNode->getHeight()==-1) {
                    gparent->setHeight(0);
                    parent->setHeight(1);
                }
                //if the child has a right balance
                else {
                    gparent->setHeight(-1);
                    parent->setHeight(0);
                }
                childNode->setHeight(0);
            }
        }
    }
    //if the grandparent has right balance
    else {
        if (gparent->getRight() == parent) {
            gparent->setHeight(2);
            //zig zag
            if (parent->getLeft()==childNode) {
                this->rightRotate(parent);
                this->leftRotate(gparent);
                //if child node is balanced
                if (childNode->getHeight()==0) {
                    gparent->setHeight(0);
                    parent->setHeight(0);
                }
                //if the child has a left balance
                else if (childNode->getHeight()==-1) {
                    gparent->setHeight(0);
                    parent->setHeight(1);
                }
                //if the child has a right balance
                else {
                    gparent->setHeight(-1);
                    parent->setHeight(0);
                }

            }
            //zig zig
            else {
                this->leftRotate(gparent);
                gparent->setHeight(0);
                parent->setHeight(0);
            }
            childNode->setHeight(0);
        }
        else {
            //it is balanced
            gparent->setHeight(0);
            return;
        }
    }
  
}

/**
* Remove function for a given key. Finds the node, reattaches pointers, and then balances when finished. 
*/
template<typename Key, typename Value>
void AVLTree<Key, Value>::remove(const Key& key)
{
   // TODO
    AVLNode<Key, Value>* NodeRem= dynamic_cast<AVLNode<Key,Value>*>(this->internalFind(key));

    //did not find node with given value
    if (NodeRem == NULL) {
        return;
    }
    //counts the number of children for the node to remove
    int numChild = 0;
    if (NodeRem->getLeft()!=NULL) {
        numChild++;
    }
    if (NodeRem->getRight()!=NULL) {
        numChild++;
    }
    int ht;
    
    //if the node to remove has no children
    if (numChild==0){
        //if the node is a root node
        if (NodeRem->getParent()==NULL) {
            this->deleteAll(this->mRoot);
            this->mRoot = NULL;
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
    //if the node to remove has 1 child
    else if (numChild==1) {
        //if it is a root node
        if (NodeRem->getParent()==NULL) {
            //if it only has a left child
            if (NodeRem->getLeft()!=NULL) {
                NodeRem->getLeft()->setParent(NULL);
                this->mRoot = NodeRem->getLeft();
            }
            //if it only has a right child
            else {
                NodeRem->getRight()->setParent(NULL);
                this->mRoot = NodeRem->getRight();
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

    //if the node to remove has 2 children
    else if (numChild==2){
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
                this->mRoot = pred;
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
                this->mRoot = pred;
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




/*
------------------------------------------
End implementations for the AVLTree class.
------------------------------------------
*/

#endif
