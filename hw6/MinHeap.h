#include <vector>
#include <stdexcept>
#include <iostream>

template <class T>
class MinHeap {
	public: 
		//constructor that builds a d-ary heap for d>=2
		MinHeap (int d);
		~MinHeap();
		void add(T item,int priority);
		//returns element with the smallest priority
		const T & peek() const;
		//throw exception if heap is empty
		void remove();
		bool isEmpty();
	private:
		std::vector<std::pair<T,int>> vec;
		void down(int x);
		void up(int x);
		int dee;
};

template<class T>
MinHeap<T>::MinHeap(int d) {
	if (d>=2) {
		dee = d;
	}
}

template<class T>
MinHeap<T>::~MinHeap(){}

template<class T>
void MinHeap<T>::add(T item, int priority) {
	if (int(vec.size())==0) {
		vec.push_back(std::make_pair(item,priority));
		return;
	}
	vec.push_back(std::make_pair(item,priority));
	up(vec.size()-1);
	
}

template<class T>
const T& MinHeap<T>::peek() const {
	if (vec.empty()) {
		throw std::logic_error("Empty Heap");
	}
	return vec[0].first;
}

template<class T>
void MinHeap<T>::remove() {
	if (vec.empty()) {
		throw std::logic_error("Empty Heap");
	}
	if (int(vec.size())==1) {
		vec.erase(vec.begin()+0);
		return;
	}
	if (int(vec.size())==2) {
		int currInd = vec.size()-1;
		vec[0] = vec[currInd];
		vec.pop_back();
		return;
	}
	int currInd = vec.size()-1;
	vec[0] = vec[currInd];
	vec.pop_back();
	down(0);
}

template<class T>
bool MinHeap<T>::isEmpty() {
	return (vec.empty());
}

template<class T>
void MinHeap<T>::down(int index) {
	int min = index*dee+1;
	int it = index;
	int sz = int(vec.size());
	//basecase for the down function
	if (min>=sz){
		return;
	}
	else {
		for (int i=1;i<=dee;i++) {
			if ((index*dee)+i >= sz) {
				break;
			}
			else {
				if (vec[(index*dee)+i].second < vec[min].second) {
					min = (index*dee)+i;
				}
			}
		}
		if (vec[min].second < vec[index].second) {
			std::iter_swap(vec.begin()+min,vec.begin()+it);
		}
		else {
			return;
		}
	}
	//recursively calls down until we hit the base case
	down(min);
}

template<class T>
void MinHeap<T>::up(int ind) {
	//int currInd2 = vec[vec.size()-1].second;
	int parent = (ind-1)/dee;
	if (ind<=0) {
		return;
	}
	else {
		if (vec[ind].second<=vec[parent].second) {
		std::iter_swap(vec.begin()+ind,vec.begin()+parent);
		}	
	}
	up(parent);
}