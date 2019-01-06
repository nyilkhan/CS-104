//26ary tree
//establishing the tree as you build the dictionary
//now the dictionary is a trie
//tri nodes are the platforms you can jump on
//tri set is the entire structure together
#include <string>

struct TrieNode {
  TrieNode();

  TrieNode *parent;
  TrieNode *children[26]; // one child for each letter of the alphabet.
  bool caboose;   // Is this node the end of a string in your dictionary? Is the end of a word
  char c;
};

class TrieSet {
public:
  TrieSet (); // a constructor for an empty trie
  ~TrieSet (); // destructor

  void destructHelp(TrieNode* t);

  void insert (std::string input);
   /* Add this string to the set.
      Do nothing if the string is already in the set. */

  void remove (std::string input);
   /* Removes this string from the set.
      Do nothing if the string is not already in the set. */

  TrieNode* prefix(std::string px); 
   /* returns the TrieNode matching the provided string, or returns NULL 
      if it is not the prefix of a word in the Trie. */
  
  //empty root node
  TrieNode* origin;
};