#pragma once
#include <vector>
#include "TextItem.hpp"

class MaxHeap {
 public:
  MaxHeap(int n);
  ~MaxHeap();
  bool empty() const;
  bool full() const;
  int size() const;
  TextItem& top();
  TextItem deleteMax();
  void insert(TextItem const& item);

 private:
  TextItem *data;
  int numItems;
  int maxCapacity;  
  void swapDown(int i);
  void swapUp(int i);

};