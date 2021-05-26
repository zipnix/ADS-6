// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  std::string res_word = "";
  char symbol;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
      if (symbol >= 'A' && symbol <= 'Z') {
        symbol += 32;
      }
      res_word += symbol;
    } else if (res_word != "") {
      Tree.add(res_word);
      res_word = "";
    }
  }
  file.close();
  return Tree;
}
