#include <iostream>
#include <sstream>
#include <cstring>
#include "selection_sort.h" 

using namespace std;

Item* findMin(Item * head) {
	if (head==nullptr) {
		return nullptr;
	}
	Item* temp = head;
	int min =  head->getValue();
	Item* minI = temp;
	while (temp->next != nullptr) {
		//std::cout << "Wrong" << std::endl;
		
		if (temp->next->getValue()<min) {
			min = temp->next->getValue();
			minI = temp->next;
		}
		
		temp = temp->next;
	}
	return minI;
}
Item* LLSelectionSort(Item * head) {
	//creates a temprary Item* to store the head
	Item* temp = head;
	if (temp==nullptr) {
		return nullptr;
	}
	int count =0;
	//keeps going until we get to the end of the list
	while (temp!=nullptr) {
		//use the counter to find the new first item in the list
		if (count==0) {
			Item* min = findMin(temp);
			//if the new min is not equal to the current Item then they swap
			if (min->getValue() != temp->getValue()) {
				swap(temp,min);
			}
			//assigns the new head
			if (count==0) {
				count++;
				head = min;
			}
			temp = min->next;
		}
		//for all Items after the new head
		else {
			Item* min = findMin(temp);
			if (min->getValue() != temp->getValue()) {
				swap(temp,min);
			}
			temp = min->next;
		}
	}
	return head;

}

void swap(Item* first,Item* second) {

	//Checks if the two items are right next to each other
	if (first->next == second) {
		//if it is just two items in the list
		if (first->prev==nullptr && second->next==nullptr) {
			Item* temp = second->next;
			first->next = temp;
			first->prev = second;
			second->prev = nullptr;
			second->next = first;
		}
		//if the first item is the first thing in the list
		else if (first->prev == nullptr) {
			Item* temp = second->next;
			first->next = second->next;
			first->prev = second;
			temp->prev = first;
			second->prev = nullptr;
			second->next = first;

		}
		//if the second item is the last thing in the list
		else if (second->next==nullptr) {
			Item* temp = first->prev;
			first->next = nullptr;
			temp->next = second;
			second->prev = temp;
			first->prev = second;
			second->next = first;
		}
		//for all other cases
		else {
			Item* temp = first->prev;
			Item* temp2 = second->next;
			first->next = temp2;
			temp->next = second;
			second->prev = temp;
			first->prev = second;
			temp2->prev = first;
			second->next = first;
		}
	}
	//If the items are not right next to each other
	else {
		//If the two items are at the ends of the list
		if (first->prev == nullptr && second->next == nullptr) {
			Item* temp = first->next;
			Item* temp2 = second->prev;
			temp->prev = second;
			temp2->next = first;
			second->next = temp;
			first->next = nullptr;
			first->prev = temp2;
			second->prev = nullptr;	
		}
		//if the first item is the first item in the list
		else if (first->prev == nullptr) {
			Item* temp = first->next;
			Item* temp2 = second->next;
			Item* temp3 = second->prev;
			temp->prev= second;
			first->next = temp2;
			first->prev = temp3;
			temp3->next = first;
			temp2->prev= first;
			second->prev = nullptr;
			second->next = temp->next;
		}
		//if the second item is the last thing in the list
		else if (second->next == nullptr) {
			Item* temp = first->prev;
			Item* temp2 = first->next;
			Item* temp3 = second->prev;
			temp->next = second;
			temp3->next = first;
			temp2->prev = second;
			first->next = second->next;
			first->prev = second->prev;
			second->prev = temp;
			second->next = temp2;
		}
		//for all other caes
		else {
			Item* temp = second->next;
			Item* temp2 = second->prev;
			Item* temp3 = first->prev;
			Item* temp4 = first->next;
			temp->prev = first;
			temp2->next = first;
			temp3->next = second;
			temp4->prev = second;
			first->next = temp;
			first->prev = temp2;
			second->prev = temp3;
			second->next = temp4;
		}
	}
}

