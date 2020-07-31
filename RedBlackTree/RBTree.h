#ifndef RBTree_H
#define RBTree_H

#include <string>
using namespace std;

enum Color {RED, BLACK};
struct RBTreeNode{
  string gender;
  int height, weight, key;
  bool color; // red  = 0 or black = 1
  RBTreeNode *right;
  RBTreeNode *left;
  RBTreeNode *parent;
  RBTreeNode *root;
  RBTreeNode()
  {
  	left = NULL;
  	right = NULL;
  	parent = NULL;
  }
  RBTreeNode (int key, string gender, int height, int weight){
  	this->key = key;
  	this->gender = gender;
  	this->height = height;
  	this->weight = weight;
  	left = NULL;
  	right = NULL;
  	parent = NULL;
  	color = RED;
  }
  string getGender() {
    return gender;
  }
  
  int getHeight() {
    return height;
  }

  int getWeight() {
    return weight;
  }
};

class RBTree{
	public:
		RBTree();
		bool insert(int key, string gender, int height, int weight);
		void LeftRotate (RBTreeNode *&root, RBTreeNode *&x);
		void RightRotate (RBTreeNode *&root, RBTreeNode *&x);
		void insert_fixup(RBTreeNode *&root, RBTreeNode *&x);
		RBTreeNode& operator[](const int key);
	private:
		RBTreeNode *root;
};
#endif
