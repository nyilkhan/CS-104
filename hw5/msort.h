#include <iostream>
#include <vector>
#include <string>

template <class T, class Comparator>
  void merge(std::vector<T>& myArray,std::vector<T>& temp,int k, 
  	Comparator comp, std::vector<std::pair<int,int> > range,int arrLen,int start) {
  	
  	//creates a second temporary vector of pairs that we can modify, while keeping track of the original indices
  	std::vector<std::pair<int,int>> tempRange(range);
  	
  	int begin = tempRange[0].first;

  	for (int i=begin ; i<begin+arrLen ;i++) {
  		int count = 0;
  		int curInd = -1;
  		int it = 0;

  		//makes sure that we look at the correct indices, and adjusts it accordingly
  		while (tempRange[it].second<tempRange[it].first) {
  			it++;
  		}

  		curInd = tempRange[it].first;
  		count = it;

  		for (int j=0;j<k;j++) {
  			//if that subgroupstill has something in it to compare
  			if (tempRange[j].first<=tempRange[j].second) {
  				//compares the values
  				if (comp(myArray[tempRange[j].first],myArray[curInd])) {
  					count = j;
  					curInd = tempRange[j].first;
  				}
  			}
  		}
  		temp[i]=myArray[curInd];
  		//increments the index in tthe subgroup we just looked at
  		tempRange[count].first++;
  	}
  	//assigns the values in our array from temp array
  	for (int i=0+start;i<start+arrLen;i++) {
  		myArray[i]=temp[i];
  	}
  }

template <class T, class Comparator>
  void mergeHelp(std::vector<T>& myArray,std::vector<T>& temp,int k,Comparator comp, int start, int end) {
  	//keeps track of the start and ending indices of the subgroups
  	std::vector<std::pair<int,int> > range;
  	//keeps track of size of each of groups 
  	std::vector<int> groups;

  	int arrayLen = (end - start +1);

  	if (start<end) {
  		//selection sort if the group is less than size k
  		if (end-start+1 < k) {
  			for (int i=start;i<end;i++) {
  				for (int j=i+1;j<=end ;j++) {
  					if (comp((myArray[j]),myArray[i])) {
  						T tempVal = myArray[j];
  						myArray[j] = myArray[i];
  						myArray[i] = tempVal;
  					}
  				}
  			}
  		}
  		//if the group can be broken down more, it is
  		else {
	  		int sz = (end-start +1)/k;
	  		int rem = (end-start +1)%k;

	  		int permRem = (end-start+1)%k;

	  		for (int i=0;i<k;i++) {
	  			groups.push_back(sz);
	  		}

	  		if (rem!=0) {
		  		for (int i=0;i<rem;i++) {
		  			groups[i]++;
		  		}
		  	}
	  		for (int i=0;i<k;i++) {
	  			if (rem>0) {
	  				std::pair<int,int> pr = std::make_pair((start)+i*groups[i],(start)+((i+1)*groups[i])-1);
	  				range.push_back(pr);
	  				rem--;
	  			}
	  			else {
	  				std::pair<int,int> pr = std::make_pair((start)+i*groups[i]+permRem,((start)+(i+1)*groups[i])-1+permRem);
	  				range.push_back(pr);
	  			}
	  		}
	  		//runs the merge recursively, k times
	  		for (int i=0;i<k;i++) {
	  			mergeHelp(myArray,temp,k,comp,range[i].first,range[i].second);
	  		}
	  		merge(myArray,temp,k,comp,range,arrayLen,start);
	  	}
  	}
  }

template <class T, class Comparator>
  void mergeSort(std::vector<T>& myArray, int k, Comparator comp) {
  	//creates a second vector that is a copy
  	std::vector<T> temp(myArray);
  	//calculates total size of the array
  	int totSz = myArray.size();

  	mergeHelp(myArray,temp,k,comp,0,totSz-1);
  }