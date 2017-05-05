/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{ 
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}	

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions: 


text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
		// ADD CODE HERE
		
		// Fix this so it correctly deletes
		// and maintains the heap-order property
		// required for a max-heap 
	     text_item returnItem = data[0];    
	     data[0] = data[numItems - 1];
	     numItems--;
	     swap_down(0);

		return returnItem;
	}
}

void max_heap::swap_down(int i) {
	// ADD CODE HERE		
	// Fix this so it correctly swaps
	int j = i;
    	int left = 2*i + 1;     //index of left child
    	int right = left + 1;   //index of right child

    	if (left < numItems && data[left].freq > data[j].freq)      //if the left child key > current
       		 j = left;                                               // we are now at the left child
   	 if (right < numItems && data[right].freq > data[j].freq)    //if the right child key > current
       		 j = right;                                              //we are now at the right child

    if (j != i) {
        text_item tmp = data[i];    //Our original node
        data[i] = data[j];          //swap our original node with the node with higher key
        data[j] = tmp;              //node that had higher key has now lower key
        swap_down(j);               //recurse
    }
}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {
		// ADD CODE HERE
		
		// Fix this so it correctly inserts
		// and maintains the heap-order property
		// required for a max-heap
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

void max_heap::swap_up(int i) {
	// ADD CODE HERE
	// Fix this so it correctly swaps
    if ( (i-1)/2 < 0) {
	return;
    } else if ( data[(i-1)/2].freq < data[i].freq ) {
	text_item tmp = data[(i-1)/2];
	data[(i-1)/2] = data[i];
	data[i] = tmp;
	
	swap_up((i-1)/2);
	
   } else
	return;

}
