#include "flexCharManager.h"

flexCharManager::flexCharManager(){
	used_memory = new Mem_Block*[2];
	free_mem = BUF_SIZE;
	active_requests = 0;
	used_mem_size = 2;

}

flexCharManager::~flexCharManager(){
	for (int i=0;i<used_mem_size;i++) {
		delete (used_memory[i]);
	}
	delete [] used_memory;
}
             
char* flexCharManager::alloc_chars(int n){
    bool ok = false;
    bool good[10000];
    for (int i=0;i<10000;i++) {
    	good[i] = true;
    }
    for (int i=0;i<BUF_SIZE;i++){
    	if (good[i]==true) {
    		for (int j=0;j<n;j++) {
    			if (good[i+j]==true) {
    				ok = true;
    			}
    			else if (good[i+j]!=true) {
    				ok = false;
    				break;
    			}
    		}
    		if (ok == true) {
    			char* temp = &(buffer[i]);
    			if (used_mem_size>0) {
    				free_mem-=n;
	    			used_memory[active_requests] = new Mem_Block(n, temp);
	    			active_requests+=1;
	    			used_mem_size-=1;
	    			for (int z=0;z<n;z++) {
	    				good[i+z]=false;
	    			}
	    			return temp;
    			}
    			else {
    				Mem_Block** temporary = new Mem_Block*[used_mem_size*2];
    				for (int i=0;i<used_mem_size;i++) {
    					temporary[i] = used_memory[i];
    				}
    				used_memory = temporary;
    				delete [] temporary;
    				used_mem_size *= 2;
    				

    				free_mem -= n;
    				used_memory[active_requests] = new Mem_Block(n,temp);
    				active_requests+=1;
    				used_mem_size-=1;
    				for (int z=0;z<n;z++) {
	    				good[i+z]=false;
	    			}
    				return temp;
    			}
    		}
    	}
    	return '\0';
    }

}

void flexCharManager::free_chars(char* p){
	for (int i=0;i<used_mem_size;i++) {
		if (used_memory[i]->physical_location==p) {
			int sz = used_memory[i]->size;
			for (int j=0;j<sz;j++){
				used_memory[i+j]->physical_location = '\0';
			}
			active_requests -= 1;
			for (int z=active_requests-1;z>i;z--) {
				used_memory[z]=used_memory[z+1];
			}
			delete used_memory[i];
			free_mem+=1;

		}
	}
}         
