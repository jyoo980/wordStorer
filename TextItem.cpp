#include "TextItem.hpp"
using namespace std;

bool TextItem :: operator==(TextItem const& other) const {
	return freq == other.freq && word == other.word;
}

ostream& operator<<(ostream& out, TextItem const& item) {
	out << "TextItem{\"" << item.word << "\"," << item.freq << "}";
}