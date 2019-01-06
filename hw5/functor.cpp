#include <iostream>
#include "functor.h"

using namespace std;

int main() {
  string s1 = "Blue";
  string s2 = "Red";

  string s3 = "aBc";
  string s4 = "cd9";
  AlphaStrComp comp1;
  LengthStrComp comp2;
  NumStrComp comp3;


  // Here comp1(s1,s2) is calling comp1.operator() (s1, s2);
  cout << "Blue compared to Red using AlphaStrComp yields " << comp1(s1, s2) << endl;

  // Here comp2(s1,s2) is calling comp2.operator() (s1, s2);
  cout << "Blue compared to Red using LenStrComp yields " << comp2(s1, s2) << endl;

  DoStringCompare(s3,s4,comp3);

  return 0;
}
