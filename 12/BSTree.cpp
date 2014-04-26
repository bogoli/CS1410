// BSTree.cpp

#include "BSTree.h"

// Constructors for the TreeNode class
TreeNode::TreeNode(){
	ptrLeft = NULL;
	ptrRight = NULL;
}

TreeNode::TreeNode(string s){
	name = s;
	ptrLeft = NULL;
	ptrRight = NULL;
}

BSTree::BSTree(){
	root = NULL;
}

// copy constructor
BSTree::BSTree(const BSTree& orig){
	root = NULL;
	copySubtree(orig.root);
}

void BSTree::copySubtree(TreeNode * origNode){
	if(origNode){
		Insert(origNode->name);
		copySubtree(origNode->ptrLeft);
		copySubtree(origNode->ptrRight);
	}
}

void BSTree::destroySubtree(TreeNode *tree){
	if(!tree){
		return;
	}
	destroySubtree(tree->ptrLeft);
	destroySubtree(tree->ptrRight);
	delete tree;
}

BSTree::~BSTree(){	
	cout << "calling deconstructor...\n";
	destroySubtree(root);
}

int BSTree::Size(){
	return sizeOfTree(root);
}

int BSTree::sizeOfTree(TreeNode *tree){
	int count = 1;
	if(!tree){
		return count;
	}

	if (tree->ptrLeft != NULL){
		count += sizeOfTree(tree->ptrLeft);	
	} 
	if (tree->ptrRight != NULL){
		count += sizeOfTree(tree->ptrRight);	
	} 

return count;
}

int BSTree::Height(){
	return heightOfTree(root);
}

int BSTree::heightOfTree(TreeNode *tree){

	if(!tree){
		return 0;
	}

	int l = heightOfTree(tree->ptrLeft);
	int r = heightOfTree(tree->ptrRight);

	if(l > r) return l+1;
	else return r+1;
}

void BSTree::Insert (string s){	
	RInsert (s, root);
}

void BSTree::Delete (string s){   
	RDelete (s, root);
}

bool BSTree::Search (string s){
	return RSearch(s, root);
}

string BSTree::Traverse (){	
	// cout << "Postoder traversal " << endl;
	return RTraverse(root);
}

void BSTree::RInsert (string s, TreeNodeptr& ptr){	
	if (ptr == NULL){  // Base Case
		ptr = new TreeNode(s);
	}
	else{
		if (s <= ptr->name){
			RInsert (s, ptr->ptrLeft);  // Recursive Case
		}
		else{ // s > ptr->name
			RInsert (s, ptr->ptrRight);  // Recursive Case
		}
	}
}

bool BSTree::RSearch (string s, TreeNodeptr& ptr){
	if (ptr == NULL)
		return false;
	else if (s == ptr->name)
		return true;
	else if (s > ptr->name)
		return RSearch(s, ptr->ptrRight);
	else // s <= ptr->name
		return RSearch(s, ptr->ptrLeft);
}

void BSTree::RDelete (string s, TreeNodeptr& ptr){	
	if (ptr != NULL){	
		if (s == ptr->name){
			DelNode(ptr);
		}
		else if (s <= ptr->name){
			RDelete(s, ptr->ptrLeft);
		}
		else{ // s > ptr->name
			RDelete(s, ptr->ptrRight);
		}
	}
}

string BSTree::RTraverse (TreeNodeptr ptr){	
	string ls, rs;
	
	if (ptr == NULL){
		return " ";
	}
	else{	
		ls = RTraverse(ptr->ptrLeft);
		cout << "  " << ptr->name << endl;
		rs = RTraverse(ptr->ptrRight);
		return (ls + ptr->name + " " + rs);
	}	
}

void BSTree::DelNode(TreeNodeptr& ptr){	
	if (ptr->ptrLeft == NULL && ptr->ptrRight == NULL){	// delete a leaf node	
		delete ptr;			
		ptr = NULL;
	}

	else if (ptr->ptrLeft == NULL){	// delete a node with one right child
		TreeNodeptr here = ptr;
		ptr = ptr->ptrRight;
		delete here;	
	}

	else if (ptr->ptrRight == NULL){	// delete a node with one left child
		TreeNodeptr here = ptr;
		ptr = ptr->ptrLeft;
		delete here;
	}

	else{							// delete a node with two children
		string successor;
		DeleteSuccessor (ptr, successor);
		ptr->name = successor;
	}
}

void BSTree::DeleteSuccessor(TreeNodeptr ptr, string& s) {	
	TreeNodeptr parent = ptr;

	ptr = ptr->ptrRight;		// one to the right
	int count = 0;
	while (ptr->ptrLeft != NULL){	
		count ++;
		parent = ptr;
		ptr = ptr->ptrLeft;		// all the way to the left
	}
	s = ptr->name;
	cout << "The node used to replace value in the removed node contains the value of ";
	cout << s << endl;

	if (count == 0) {// the smallest node in the right subtree of the deleted node is 
		// the deleted node's right child
		parent->ptrRight = ptr->ptrRight;
		delete ptr;
		ptr = NULL;
	}
	else{
		parent->ptrLeft = ptr->ptrRight;  // attach the right subtree
		delete ptr;
		ptr = NULL;
	}
}
