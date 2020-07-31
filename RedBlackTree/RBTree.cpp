#include <iostream>
#include <algorithm>
#include "RBTree.h"
using namespace std;
RBTree::RBTree()
{
	root = NULL;
}
bool RBTree::insert(int key, string gender, int height, int weight) 
{
	//std::cout << "hi" <<std::endl;
	RBTreeNode *y = new RBTreeNode(key, gender, height, weight);
//	cout << "key: " << y->key << endl;
//	cout << "gender: " << y->gender << endl;
//	cout << "weight: " << y->weight << endl;
//	y->gender = gender;
//	y->height = height;
//	y->weight = weight;
//	y->color = RED;
//	RBTreeNode *searchNode;
/*	
	root = BSTInsert(root, y);
	insert_fixup(root, y);
	cout << "key: " << y->key << endl;
	cout << "weight: " << y->weight << endl;
	cout << "Gender: " <<y->gender << endl;
	cout << "color: " << y->color <<endl;
	cout << "Root: " << root->key << endl;
	return true;
	*/
	RBTreeNode *ptr = root;
	RBTreeNode *ptr1 = NULL;

	if(root == NULL){
		//root = y;
		y->parent = NULL;
		y->left = NULL;
		y->right = NULL;
//		y->left->color = BLACK;
//		y->right->color = BLACK;
		root = y;
	}
	else{
		while(ptr != NULL){
			ptr1 = ptr;
			//cout << "now im inside while loop" << endl;
			if(ptr->key < y->key){
				ptr = ptr->right;
			//	cout << "ptr_value < root, so right node" << endl;
			}
			else if (ptr->key > y->key){
				ptr = ptr->left;
				//cout << "left node " << endl;
			}
			else if(ptr->key == y->key){
				//cout << "key is same! false" << endl; 
				return false;
			}
		}
	//	cout << "outside while" << endl;
		y->parent = ptr1;
		//cout << "parent; " << y->parent->key << endl;
		if(ptr1->key < y->key){
			ptr1->right = y;
		}
		else{
			ptr1->left = y;
		}
	}
//	cout << "let's go to insert-fixup" << endl;
	insert_fixup(root, y);
	//cout << "finished" << endl;
//	cout <<"key" << y->key << " " <<  y->weight << endl;
//	cout <<"key" << y->key << " " <<  y->gender << endl;
	
//	cout << "color:" << y->color <<endl;
//	cout << "Root: " << root->key << endl;
//	cout << "left key: " << root->left->key << endl;
//	cout << "right key: " << root->right->key << endl;
	return true;
	
}
void RBTree::LeftRotate (RBTreeNode *&root, RBTreeNode *&pt){
//	cout << "im in left Rotate" << endl;
	RBTreeNode *pt_right = pt->right;
 
    pt->right = pt_right->left;
 
    if (pt->right != NULL)
        pt->right->parent = pt;
 //	cout << " hi" << endl;
    pt_right->parent = pt->parent;
 //	cout << " hi1" << endl;
    if (pt->parent == NULL)
        root = pt_right;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
 
    else
        pt->parent->right = pt_right;
 //	cout << "hello";
    pt_right->left = pt;
    pt->parent = pt_right;
}
void RBTree::RightRotate (RBTreeNode *&root, RBTreeNode *&pt){

	RBTreeNode *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->parent = pt;
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_left;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
 
    else
        pt->parent->right = pt_left;
 
    pt_left->right = pt;
    pt->parent = pt_left;

}
void RBTree::insert_fixup(RBTreeNode *&root, RBTreeNode *&pt){
	RBTreeNode *parent_pt = NULL;
    RBTreeNode *grand_parent_pt = NULL;
 
    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED))
    {
 
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
 
        if (parent_pt == grand_parent_pt->left)
        {
 
            RBTreeNode *uncle_pt = grand_parent_pt->right;
 
            if (uncle_pt != NULL && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
 
            else
            {
                if (pt == parent_pt->right)
                {
                    LeftRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                RightRotate(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
 
        else
        {
            RBTreeNode *uncle_pt = grand_parent_pt->left;
 
            if ((uncle_pt != NULL) && (uncle_pt->color == RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                if (pt == parent_pt->left)
                {
                    RightRotate(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                LeftRotate(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
 
    root->color = BLACK;
}

RBTreeNode& RBTree::operator[](const int key){

	RBTreeNode *ptr = NULL;
	RBTreeNode *ptr_root = root;
	if(ptr_root == NULL){
		return *ptr_root;
	}
	while(ptr_root != NULL){
	//	cout<<"aaaa"<<endl;
		ptr = ptr_root;
		if(ptr_root->key < key){
			ptr_root = ptr_root->right;
		}
		else if(ptr_root->key > key){
			ptr_root =ptr_root->left;
		}
		else if(ptr_root->key == key){
		//	cout << "return key" << endl;
			return *ptr_root;//ask
		}
	}
}
