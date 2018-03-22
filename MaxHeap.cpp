
#include "MaxHeap.hpp"
#include <stdexcept>
using namespace std;

MaxHeap::MaxHeap(int n) {
	data = new TextItem[n];
	numItems = 0;
	maxCapacity = n;
}

MaxHeap::~MaxHeap() {
	delete [] data;
}

bool MaxHeap::empty() const {
	return numItems == 0;
}

bool MaxHeap::full() const {
	return numItems == maxCapacity;
}

int MaxHeap::size() const {
	return numItems;
}	

TextItem& MaxHeap::top() {
	if(!empty()) {
		return data[0];
	} else {
		throw logic_error("Empty heap, cannot access top.");
	}
}

TextItem MaxHeap::deleteMax() {
	if (!empty) {
		TextItem max = data[0];
		data[0] = data[numItems - 1];
		numItems--;
		return max;
	} else {
		throw logic_error("Empty heap, cannot delete.");
	}
}

void MaxHeap::swapDown(int i) {
	int j = i;
	int left = (2 * i) + 1;
	int right = left + 1;

	if (left < numItems && data[left].freq > data[j].freq) {
		j = left;
	}
	if (right < numItems && data[right].freq > data[j].freq) {
		j = right;
	}
	if (j != i) {
		TextItem temp = data[i];
		data[i] = data[j];
		data[j] = temp;
		swapDown(j);
	}
}

void MaxHeap::insert(const TextItem& item) {
	if (!full()) {
		if (empty()) {
			data[0] = item;
			numItems++;
		} else {
			data[numItems] = item;
			swapUp(numItems);
			numItems++;
		}
	} else 
		throw logic_error("Heap full, cannot insert");
}

void MaxHeap::swapUp(int i) {
	int swapIndex = (i - 1) / 2;
	if (swapIndex  >= 0) {
		if (data[swapIndex].freq < data[i].freq) {
			TextItem temp = data[swapIndex];
			data[swapIndex] = data[i];
			data[i] = temp;
			swapUp(swapIndex);
		}
	}
}