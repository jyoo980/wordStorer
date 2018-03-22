#pragma once
#include <memory>
#include <stdexcept>
#include <stack>
#include "TextItem.hpp"
using namespace std;

typedef string TreeKey;

class StringBST {
 public:
  struct node_t;

  struct node_t {
  TextItem data;
  node_t* left;
  node_t* right;
  };

  StringBST();
  ~StringBST();
  bool empty() const;
  void insert(TreeKey const& key);
  void display() const;
  int size() const;
  int WordFrequency(TreeKey const& key) const;
  node_t* GetRoot() const;
  
 private:  
  node_t* root;
  int numNodes;  
  void insertHelper(node_t*& node, TreeKey const& key);
  void printInOrder(node_t* node) const;
  void remove(node_t*& node);
  
}; 