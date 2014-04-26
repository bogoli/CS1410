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
	BSTree(const BSTree &); 	// copy constructor
	~BSTree();  // TO DO in your assignment

	void Insert (string s);
	void Delete (string s);  
	bool Search (string s);
	int Size();
	int Height();
	string Traverse();

private:	

	void RInsert (string s, TreeNodeptr& ptr);
	void RDelete (string s, TreeNodeptr& ptr);
	bool RSearch (string s, TreeNodeptr& ptr);
	string RTraverse (TreeNodeptr ptr);

	void copySubtree(TreeNode *);
	int sizeOfTree(TreeNode *);
	int heightOfTree(TreeNode *);

	void destroySubtree(TreeNode *tree);
    void DelNode (TreeNodeptr& ptr);
    void DeleteSuccessor(TreeNodeptr ptr, string & s);  // s will be returned to the called via reference.
};
#endif
