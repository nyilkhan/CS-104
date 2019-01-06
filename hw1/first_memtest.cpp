#include <iostream>
#include <stdlib.h>
#include "simpleCharManager.h"
using namespace std;

int main(int argc, char *argv[])
{
  simpleCharManager simplest_mem_manager;

  /*write driver code as described in the assignment to replace this */
  char* c1 = simplest_mem_manager.alloc_chars(13);
  c1[0]='H';
  c1[1]='e';
  c1[2]='l';
  c1[3]='l';
  c1[4]='o';
  c1[5]=' ';
  c1[6]='W';
  c1[7]='o';
  c1[8]='r';
  c1[9]='l';
  c1[10]='d';
  c1[11]='!';
  c1[12]='\n';

  for (int i=0;i<13;i++) {
  	cout << c1[i];
  }
  char* p = c1;
  p +=  6;
  simplest_mem_manager.free_chars(p);

  char* c2 = simplest_mem_manager.alloc_chars(10);

  c2[0]='m';
  c2[1]='o';
  c2[2]='o';
  c2[3]='n';
  c2[4]='!';
  c2[5]='B';
  c2[6]='y';
  c2[7]='e';
  c2[8]='.';
  c2[9]='\n';

  /*for (int i=0;i<14;i++) {
  	cout << c1[i];
  }*/

  //std::cout << "Hello world!\n" ;
  
  return 0;
}

