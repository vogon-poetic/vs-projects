#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/* 
This encoder can analyze data and create a proper huffman encoding 
binary tree data structure which follows these specific rules:

- The most frequent atom is put closest to the root node.
- The if two atoms appear the same number of times, they will be placed in
  the same level of the binary tree in some consistent order (alpha, numeric, etc).
- For now we will use chars as the element type

Example usage may look something like this: 

	char* data = "Let's use a string."
	HuffmanTree *tree = new HuffmanTree(data);

	char most_freq = tree->most_freq();
	char least_freq = tree->least_freq();

	// actually prints the ASCII representation of the tree to an ostream
	tree->display(); 

*/

class HuffmanTree {
private: 
	typedef map<char, int> mapping_t;

	struct Node {
		pair<char,unsigned int> data; 
		Node* right;
		Node* left;
		bool isLeaf;
	};

	// a map of elements to codewords
	Node* root;
	mapping_t * mapping;

public:
	HuffmanTree() {
		this->root = NULL;
		this->mapping = new mapping_t();  // map of atoms to codewords
	}

	HuffmanTree(string input) {
		this->root = NULL;
		this->mapping = new mapping_t();
		updateFrequencies(input, this->mapping);
	}

	~HuffmanTree() {
		delete(this->root);
		delete(this->mapping);
	}

	static void updateFrequencies(const string data, mapping_t *freqs) {
		for (auto atom : data) {
			// if atom isn't found in map of frequencies.
			if ((*freqs).find(atom) == freqs->end()) {
				freqs->insert(make_pair(atom, 1));
			} else {
				// bump the atom's frequency in the map
				(*freqs).find(atom)->second++;
			}
		}

		qsort(freqs, freqs->size, sizeof(*(freqs->begin())), cmp);
	}

	static bool isLeaf(Node* p) {
		// lol nested ternary 
		return (!p) ? false : // else 
			(p->right || p->left) ? false : // else 
			true;
	}

	static bool cmp(mapping_t::const_iterator *a, mapping_t::const_iterator *b) {
		return (**a > **b);
	}

	void print() {
		// map is empty
		if (this->mapping == NULL) 
			return;
		
		for (auto i : *(this->mapping)) {
			cout << i.first << " " << i.second << endl;
		}
	}

	char most_frequent() {
	}

	char least_frequent() {
	}
};

int main(void) 
{
	HuffmanTree *tree = new HuffmanTree("This is example input.");
	tree->print();
	cin.get();
	return 0;
}
