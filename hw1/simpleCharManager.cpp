#include <cstddef>
#include "simpleCharManager.h"



simpleCharManager::simpleCharManager(){
	free_place = &(buffer[0]);
	for (int i=0;i<=9999;i++) {
		buffer[i]='\0';
	}
}

simpleCharManager::~simpleCharManager(){}
             
char* simpleCharManager::alloc_chars(int n){
	int len = (buffer + BUF_SIZE) - free_place;
	if (n > len) {
        return '\0';
	}
	else {
		char* temp = free_place;
		free_place += n;
		return temp;
	}
}

void simpleCharManager::free_chars(char* p){
	int space = (buffer + BUF_SIZE) - p;
	free_place=p;
	for (int i=0;i<space;i++) {
		p[i]='\0';
	}
}         

