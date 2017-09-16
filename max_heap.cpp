/*
 * File: max_heap.cpp
 *
 * This file provides the implementation for the functions specified
 * in the max_heap.hpp header file.
 *
 * */

#include "max_heap.hpp"
#include <stdexcept>
using namespace std;
/**
 * Constructor for max_heap
 * @param: n, max capacity of this heap
 */
max_heap::max_heap(int n) {
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

/*
 * Destructor for max_heap*
 */
max_heap::~max_heap() { 
	delete [] data;
}

/**
 * Return true if heap contains no items
 */
bool max_heap::empty() const {
	return (numItems == 0);
}

/**
 * Return true if heap is at full capacity
 */
bool max_heap::full() const {
	return (numItems == max_capacity);
}

/**
 * Returns the size of the heap
 */
int max_heap::size() const {
	return numItems;
}	

/**
 * Returns the top item in the heap (the root)
 */
text_item& max_heap::top() {
	if (empty()) {
		throw logic_error("Heap is empty, can't access top!");
	} else {
    return data[0];
  }
}

/**
 * If empty: throw logic error
 * else: return the top item of the heap, maintaining order *
 */
text_item max_heap::delete_max() {
	if (empty()) {
		throw logic_error("Cannot delete, heap is empty!");
	} else {
     text_item returnItem = data[0];    
	   data[0] = data[numItems - 1];
	   numItems--;
	   swap_down(0);

		 return returnItem;
	}
}

/**
 * Swap down algorithm
 */
void max_heap::swap_down(int i) {
	int j = i;
	int left = (2 * i) + 1;    // index of left child
 	int right = left + 1;      // index of right child

  if (left < numItems && data[left].freq > data[j].freq) {  // if the left child key > current
       j = left;                                            // we are now at the left child
  }
  if (right < numItems && data[right].freq > data[j].freq) {    // if the right child key > current
   		 j = right;                                              // we are now at the right child
  }
  if (j != i) {
     text_item tmp = data[i];    // our original node
     data[i] = data[j];          // swap our original node with the node with higher key
     data[j] = tmp;              // node that had higher key has now lower key
     swap_down(j);               // recurse
  }
}

/**
 * Inserting into a max_heap, maintaining ordering
 */
void max_heap::insert(const text_item & item) {
	if (full()) {
		throw logic_error("Cannot insert, heap array is full!");
	} else {
		if (empty()) {
		   data[0] = item;
		   numItems++;
    } else {
		  data[numItems] = item;
		  swap_up(numItems);
		  numItems++;
	  }
	}
}

/**
 * Swap-up algorithm
 */
void max_heap::swap_up(int i) {
  int swap_index = (i - 1)/2;
  if (swap_index < 0) {
	    return;
  } else if ( data[swap_index].freq < data[i].freq ) {
	    text_item tmp = data[swap_index];
	    data[swap_index] = data[i];
	    data[i] = tmp;
	    swap_up(swap_index);
  }
}
