#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <string>
#include <map>
using namespace std;

struct HuffmanNode {
  HuffmanNode(char character, int frequency) : 
    character(character), frequency(frequency), 
    left(NULL), right(NULL) {}

  HuffmanNode(int frequency) : 
    character('*'), frequency(frequency), 
    left(NULL), right(NULL) {}

  ~HuffmanNode() {
    delete left;
    delete right;
    left = right = NULL;
  }
  
  char character;
  int frequency;
  HuffmanNode *left, *right;
};

class HuffmanTree {
public:
  HuffmanTree() : root(NULL), message("") {}
  ~HuffmanTree() {delete this->root;}

  void construct(const string message);
  void destruct() {delete this->root; this->root=NULL; message="";}
  void print_tree(HuffmanNode* node, string code, map<char, string> code_map);
  void print(); // I have changed the initial decleratino of this function to remove the const keywork as it does not allow for a map to be created for encoding

private:

  HuffmanNode *root;
  string message;
};

#endif
