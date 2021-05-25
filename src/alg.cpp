// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string res_word;
  char register_difference = 'a' - 'A';
  char symbol;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
      if (symbol >= 'A' && symbol <= 'Z') {
        symbol += register_difference;
      }
      res_word += symbol;
    } else if (res_word != "") {
      Tree.add(res_word);
      word = "";
    }
  }
  file.close();
  return Tree;
}
