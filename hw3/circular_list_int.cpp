#include <iostream>
#include <sstream>
#include <cstring>
#include "circular_list_int.h" 

using namespace std;

CircularListInt::CircularListInt() {

}

CircularListInt::~CircularListInt() {
	int sz = size();
	for (int i=0;i<sz;i++) {
		remove(0);
	}
}

/*
Item * CircularListInt::findItem() {
	
}
*/

int CircularListInt::get(size_t index) const {
	Item* temp = head;
	if (empty()==true) {
		return 0;
	}
	for (size_t i=0;i<index;i++) {
		temp = temp->next;
	}
	int val = temp->value;
	return val;
}

size_t CircularListInt::size() const {
	return count;
}

bool CircularListInt::empty() const {
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}

void CircularListInt::push_back(int value) {
	//Item* temp = head;
	if (empty()==true) {
		Item* guy = new Item(value);
		head = guy;
		head->next=head;
		head->prev=head;
	}
	else if (head->prev == head) {
		Item* guy = new Item(value);
		head->next = guy;
		head->prev = guy;
		guy->next = head;
		guy->prev = head;
	}
	else {
		Item* guy = new Item(value);
		Item* tempprev = head->prev;
		head->prev->next = guy;
		head->prev = guy;
		guy->next = head;
		guy->prev = tempprev;
	}
	count++;
}

void CircularListInt::set(size_t index, int value) {
	Item* temp = head;
	for (size_t i=0;i<index;i++) {
		temp = temp->next;
	}
	temp->value = value;
}

void CircularListInt::remove(size_t index) {
	Item* temp = head;
	for (size_t i=0;i<index;i++) {
		temp = temp->next;
	}
	if (head == temp) {

		head = temp->next;
	}

	else {
		Item* n = temp->next;
		Item* p = temp->prev;
		temp->prev->next = n;
		temp->next->prev = p;
	}
	delete temp;
	count--;
}