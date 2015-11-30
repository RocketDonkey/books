// CTCI - Chapter 1 (Arrays and Strings)
//
// 1.1 - Implement an algorithm to determine if a string has all unique
//       characters.
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

#include <assert.h>


// Determine if a string has all unique characters.
bool AllUnique(std::string word) {
  // Create a map that will map letters to their counts.
  std::map<char, int> char_counts;

  for (char& c : word) {
    if (char_counts.find(c) != char_counts.end()) {
      return false;
    }
    char_counts[c] = 1;
  }
  return true;
}


// Determine if a string has all unique characters without using a supplemental
// data structure. This sorts the string and then returns false as soon as it
// identifies two identical consecutive characters.
bool AllUniqueNoDataStructure(std::string word) {
  std::string sorted_word = word;
  std::sort(sorted_word.begin(), sorted_word.end());

  char& current = sorted_word.at(0);
  for (int i = 1; i < sorted_word.length(); ++i) {
    if (current == sorted_word.at(i)) {
      return false;
    }
    current = sorted_word.at(i);
  }
  return true;
}


int main() {
  std::string my_word = "thishasrepeats";
  assert (AllUnique(my_word) == false);
  assert (AllUniqueNoDataStructure(my_word) == false);
  return 0;
}
