#include <string>
#include <algorithm>
#include <iostream>

struct AlphaStrComp {
  bool operator() (const std::string& lhs, const std::string& rhs)
  { // Uses string's built in operator<
    // to do lexicographic (alphabetical) comparison
    return (lhs < rhs);
  }
};

struct LengthStrComp {
  bool operator()(const std::string& lhs, const std::string& rhs)
  { // Compares strings by size;
    // Breaks ties by lexicographic comparison
    return (   (lhs.size() < rhs.size())
            || (lhs.size() == rhs.size() && lhs < rhs));
  }
};

struct NumStrComp {
  bool operator()(const std::string& lhs, const std::string& rhs) {
    size_t llen = lhs.length();
    size_t rlen = rhs.length();
    int lval = 0;
    int rval = 0;
    //makes score for left side
    for (size_t i=0;i<llen;i++) {
      if (int(lhs[i])>=int('0') && int(lhs[i])<=int('9')){
        lval += int(lhs[i]) - 48;
      }
      else if (int(lhs[i])>=int('a') && int(lhs[i]<=int('z'))) {
        lval += int(lhs[i])- 87;
      }
      else if (int(lhs[i])>=int('A') && int(lhs[i]<=int('Z'))) {
        lval += int(lhs[i]) - 55;
      }
    }
    
    //makes score for right side
    for (size_t i=0;i<rlen;i++) {
      if (int(rhs[i])>=int('0') && int(rhs[i])<=int('9')){
        rval += int(rhs[i]) - 48;
      }
      else if (int(rhs[i])>=int('a') && int(rhs[i]<=int('z'))) {
        rval += int(rhs[i])- 87;
      }
      else if (int(rhs[i])>=int('A') && int(rhs[i]<=int('Z'))) {
        rval += int(rhs[i]) - 55;
      }
    }
    return (lval<rval || ((lval==rval) && lhs<rhs));
  }
};

template <class Comparator>
void DoStringCompare(const std::string& s1, const std::string& s2, Comparator comp)
{
  std::cout << comp(s1, s2) << std::endl;  // calls comp.operator()(s1,s2);
}

