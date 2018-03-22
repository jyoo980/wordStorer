#include "StringBST.hpp"
using namespace std;

StringBST::StringBST() {
	root = NULL;
	numNodes = 0;
}

StringBST::~StringBST() { 
	remove(root);
}

void StringBST::remove(node_t*& node) {
	if (node != NULL) {
		remove(node->left);
		remove(node->right);
		delete node;
		node = NULL;
	}
}

bool StringBST::empty() const { 
   	return root == 0;
}

StringBST::node_t* StringBST::GetRoot() const {
	return root;
}

int StringBST::size() const {
	return numNodes;
}

void StringBST::insert(const TreeKey& key) {
   	insertHelper(root, key);
}

void StringBST::insertHelper(node_t *& node, TreeKey const& key) {
	if (node == NULL) {
		node = new node_t{TextItem{key, 1}, NULL, NULL};
		numNodes++;
 	} else if (node->data.word == key) {
		 node->data.freq++;
	 } else if (key < node->data.word) {
		 insertHelper(node->left, key);
	 } else {
		 insertHelper(node->right, key);
	 }
}

void StringBST::display() const {
   printInOrder(root);
   cout << endl;
}

void StringBST::printInOrder(node_t* node) const {
	if (node != NULL) {
		printInOrder(node->left);
		cout << node->data.word << ":" << node->data.freq << ", ";
		printInOrder(node->right);
	}
}

int StringBST::WordFrequency(const TreeKey &key) const {
   if (root == NULL) return 0;
   if (root->data.word == key) {
       return root->data.freq;
   }

   if (key < root->data.word) {
      return wordFreqHelper(key, root->left);
   } else 
      return wordFreqHelper(key, root->right);
}

int wordFreqHelper(const TreeKey &key, StringBST::node_t *root) {
    if (root == NULL) return 0;
    if (root->data.word == key) {
        return root->data.freq;
    }
    
    if (key < root->data.word) {
        return wordFreqHelper(key, root->left);
    } else
        return wordFreqHelper(key, root->right);
}