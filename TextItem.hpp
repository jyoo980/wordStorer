#pragma once
#include <string>
#include <ostream>
#include <iostream>
using namespace std;

struct TextItem {
	string word;  
	int freq;    
	bool operator==(TextItem const& other) const;
};

ostream& operator<<(std::ostream& out, TextItem const& item);