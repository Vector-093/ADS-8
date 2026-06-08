// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include "bst.h"

void makeTree(BST<std::string>& bst, const char* fname) {
  std::ifstream infile(fname);
  if (!infile.is_open()) return;

  std::string w;
  char c;

  while (infile.get(c)) {
    if (std::isalpha(static_cast<unsigned char>(c))) {
      w += std::tolower(static_cast<unsigned char>(c));
    } else {
      if (!w.empty()) {
        bst.insert(w);
        w.clear();
      }
    }
  }

  if (!w.empty()) {
    bst.insert(w);
  }

  infile.close();
}

void printFreq(BST<std::string>& bst) {
  std::cout << "Tree size: " << bst.size() << std::endl;
  std::cout << "Tree depth: " << bst.depth() << std::endl;
}
