// CTCI - Chapter 1 (Arrays and Strings)
//
// 1.1 - Implement an algorithm to determine if a string has all unique
//       characters.
//
// Compile with:
//   g++ -Wall -g -std=c++11 <file> -o <output>
#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

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
  for (size_t i = 1; i < sorted_word.length(); ++i) {
    if (current == sorted_word.at(i)) {
      return false;
    }
    current = sorted_word.at(i);
  }
  return true;
}

// Determine if the provided string contains all unique characters.
int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <word>" << std::endl;
    return 1;
  }

  // The word itself.
  std::string my_word = argv[1];

  // Hacky way of setting the proper text.
  std::string unique_text = "";
  if (AllUniqueNoDataStructure(my_word) == false) {
    unique_text = "not ";
  }
  std::cout << "Word '" << my_word << "' does "<< unique_text << "contain all "
            << "unique characters." << std::endl;
  return 0;
}
