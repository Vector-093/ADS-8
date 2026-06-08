// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <algorithm>

template<typename T>
class BST {
 public:
  BST() : root(nullptr), count(0) {}

  ~BST() {
    clear(root);
  }

  void insert(const T& val) {
    insert(root, val);
  }

  int search(const T& val) const {
    return search(root, val);
  }

  int depth() const {
    return depth(root) - 1;
}

  bool empty() const {
    return root == nullptr;
  }

  int size() const {
    return count;
  }

 private:
  struct Node {
    T info;
    int freq;
    Node* left;
    Node* right;
    explicit Node(const T& val) : info(val), freq(1), left(nullptr), right(nullptr) {}
  };

  Node* root;
  int count;

  void insert(Node*& cur, const T& val) {
    if (cur == nullptr) {
      cur = new Node(val);
      count++;
      return;
    }
    if (val < cur->info) {
      insert(cur->left, val);
    } else if (val > cur->info) {
      insert(cur->right, val);
    } else {
      cur->freq++;
    }
  }

  int search(Node* cur, const T& val) const {
    if (cur == nullptr) return 0;
    if (val == cur->info) return cur->freq;
    if (val < cur->info) return search(cur->left, val);
    return search(cur->right, val);
  }

  int depth(Node* cur) const {
    if (cur == nullptr) return 0;
    int leftHt = depth(cur->left);
    int rightHt = depth(cur->right);
    return std::max(leftHt, rightHt) + 1;
}

  void clear(Node* cur) {
    if (cur == nullptr) return;
    clear(cur->left);
    clear(cur->right);
    delete cur;
  }
};

#endif  // INCLUDE_BST_H_
