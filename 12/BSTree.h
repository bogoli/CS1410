// BSTree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <string>
#include <iostream>
using namespace std;

class TreeNode{  
public:
	string name;
	TreeNode *ptrLeft, *ptrRight;

	TreeNode();
	TreeNode(string s);
};
			
typedef TreeNode* TreeNodeptr;

class BSTree{
private:
	TreeNodeptr root;

public:	
	BSTree();
	~BSTree();  // TO DO in your assignment

	void Insert (string s);
	void Delete (string s);  
	bool Search (string s);
	string Traverse();

private:	
	// Recursive Functions
	// These recursive functions require the functions' arguments to be references to the pointer
	// The reason is that these functions want to change the pointer, i.e., where it points to.

	void RInsert (string s, TreeNodeptr& ptr);
	void RDelete (string s, TreeNodeptr& ptr);
	bool RSearch (string s, TreeNodeptr& ptr);
	string RTraverse (TreeNodeptr ptr);

    void DelNode (TreeNodeptr& ptr);
    void DeleteSuccessor(TreeNodeptr ptr, string & s);  // s will be returned to the called via reference.
};
#endif
