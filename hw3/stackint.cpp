#include <iostream>
#include "stackint.h"

using namespace std;

StackInt::StackInt() {

}
StackInt::~StackInt() {
	int len = list.size();
	size_t tlen = (size_t)len;
	for (size_t i=0;i<tlen;i++) {
		list.remove(0);
	}
}

bool StackInt::empty() const {
	if (list.empty()==true) {
		return true;
	}
	else {
		return false;
	}
}

void StackInt::push(const int& val) {
	list.push_back(val);
}

int StackInt::top() const {
	int len = list.size();
	size_t tlen = ((size_t)len)-1;
	return list.get(tlen);
	}

void StackInt::pop() {
	int len = list.size();
	size_t tlen = ((size_t)len)-1;
	list.remove(tlen);
}

