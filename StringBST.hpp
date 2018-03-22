#pragma once
#include <memory>
#include <stdexcept>
#include <stack>
#include "TextItem.hpp"
using namespace std;

typedef string TreeKey;

struct NodeT {
  TextItem data;
  NodeT* left;
  NodeT* right;
}

class StringBST {
 public:
  struct NodeT;
  StringBST();
  ~StringBST();
  bool empty() const;
  void insert(TreeKey const& key);
  void display() const;
  int size() const;
  int WordFrequency(TreeKey const& key) const;
  NodeT* GetRoot() const;
  
 private:  
  NodeT* root;
  int num_nodes;  
  void insertHelper(NodeT*& n, TreeKey const& key);
  void printInOrder(NodeT* n) const;
  void remove(NodeT*& n);
  
}; 