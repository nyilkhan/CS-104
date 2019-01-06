#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool FatalistHypothesis(std::vector<std::pair<int,int> > grades);

//helper function to sort the vector of pairs
bool sortSec(const pair<int,int> &a,const pair<int,int> &b) {
	return (a.second < b.second);
}

bool FatalistHypothesis(std::vector<std::pair<int,int> > grades) {
	bool fatal = true;
	size_t sz = grades.size();

	if (grades.empty()) {
		return true;
	}
	//sorting by first element
	sort(grades.begin(),grades.end());
	for (size_t i = 0;i<sz-1;i++) {
		if (grades[i].first < grades[i+1].first) {
			if (grades[i].second > grades[i+1].second) {
				fatal = false;
				return fatal;
			}
		}
	}

	//sorting by second element
	sort(grades.begin(), grades.end(),sortSec);
	for (size_t i=0;i<sz-1;i++) {
		if (grades[i].second < grades[i+1].second) {
			if (grades[i].first > grades[i+1].first) {
				fatal = false;
				return fatal;
			}
		}
	}
	return fatal;

}

