#pragma once
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

struct treeNode {
	std::string data;
	treeNode* left;
	treeNode* right;
};

class binarySearchTree {
public:
	/*
    * Constructor
    * @param NA
    * @return NA
    */
	binarySearchTree() {
		root = NULL;
	};

	
	/*
	* Destructor
	* @param NA
	* @return NA
	*/
	~binarySearchTree() {
		removeAll(this->root);
	};

	/*
	* inserts nodes into the binary tree
	* @param string to be inserted
	* @return root
	*/
	treeNode* insert(std::string stringToBeInserted) {
		if (root == NULL) {
			root = new treeNode;
			root->data = stringToBeInserted;
			root->left = NULL;
			root->right = NULL;
			return root;
		}
		return insert(root, stringToBeInserted);
	}
	
	/*
	* Creates a copy of our binary tree
	* @param NA
	* @return our new binary tree
	*/
	binarySearchTree* copy() const {
		binarySearchTree* treeCopy = new binarySearchTree;
	
		if (root == NULL)
			treeCopy->root = NULL;
		else {
			
			copyNodes(root, treeCopy->root);
		}
		return treeCopy;

	}

	/*
	* creates a copy of a node to be used in our copy() function
	* @param treeRoot, treeRootCopy
	* @return NA
	*/
	void copyNodes(treeNode* const treeRoot,  treeNode* &treeRootCopy) const {
		if (treeRoot == NULL)
			treeRootCopy=NULL;
		else if (treeRoot != NULL)
		{
			treeRootCopy = new treeNode;
			treeRootCopy->data = treeRoot->data;
			copyNodes(treeRoot->left, treeRootCopy->left);
			copyNodes(treeRoot->right, treeRootCopy->right);
		}
	}

	/*
	* Traverses the tree to delete all nodes in the tree
	* @param root of tree
	* @return NA
	*/
	void removeAll(treeNode* root) {
		if (root != NULL) {
			removeAll(root->left);
			removeAll(root->right);
			std::cout << "DELETING: " << root->data << "\n";
			delete root;
			root = NULL;
			this->root = root;
		}
	}
	
	/*
	* adds nodes/data into the tree
	* @param current, stringToBeInserted
	* @return current tree node
	*/
	treeNode* insert(treeNode* current, std::string stringToBeInserted) {

		if (current == NULL) {
			current = new treeNode;
			current->data = stringToBeInserted;
			current->left = NULL;
			current->right = NULL;
			return current;
		}
		
		else if (stringToBeInserted < current->data) {
				current->left = insert(current->left, stringToBeInserted);
				return current;
		}
		else {
				current->right = insert(current->right, stringToBeInserted);
				return current;
		}
		
	}
	
	/*
	* Deletes data in the binary tree
	* @param root, stringToBeDeleted
	* @return root
	*/
	treeNode* deleteData(treeNode* root, std::string stringToBeDeleted) {
		//base case
		if (root == NULL) {
			return root;
		}
		//traversal left and right
		if (stringToBeDeleted < root->data) {
			root->left = deleteData(root->left, stringToBeDeleted);
		}
		else if (stringToBeDeleted > root->data){
			//root right becomes root and data is compared
			root->right = deleteData(root->right, stringToBeDeleted);
		}
		//if data matches
		else{
			//if left child is null
			if (root->left == NULL) {
				treeNode* newNode = root->right;
				delete root;
				return newNode;
			}

			// When right child is null
			if (root->right == NULL) {
				treeNode* newNode = root->left;
				delete root;
				return newNode;
			}
			// if children on left and right exist
			root = root->right;
			while (root != NULL && root->left != NULL)
				root = root->left;
			treeNode* child = root;
			root->right = deleteData(root->right, child->data);
		}
		return root;
	}
	
	/*
	* prints data in order
	* @param root
	* @return NA
	*/
	void inOrderPrint(treeNode* root) {
		if (root != nullptr)
		{
			// traverse left sub-tree
			inOrderPrint(root->left);
			// visit node
			std::cout << root->data << "(" << this->height(root) << ")" << std::endl;
			// traverse right sub-tree
			inOrderPrint(root->right);
		}
	}

	/*
	* prints data in post order
	* @param root
	* @return NA
	*/
	void postOrderPrint(treeNode* root) {
		if (root == NULL) {
			return;
		}
		postOrderPrint(root->left);
		postOrderPrint(root->right);
		std::cout << root->data << "(" << this->height(root) << ")"  << std::endl;
	}

	/*
	* prints data in preOrder
	* @param root
	* @return NA
	*/
	void preOrderPrint(treeNode* root) {
		if (root == nullptr) {
			return;
		}
		std::cout << root->data << "(" << this->height(root) << ")" << std::endl; // Visit the root
		preOrderPrint(root->left); // Traverse left subtree
		preOrderPrint(root->right); // Traverse right subtree
	}
	
	/*
	* calculates the hight of the node
	* @param root
	* @return the height of the node in the tree as an int
	*/
	int height(treeNode* theRoot) {
		if (theRoot == nullptr) // base case, we have reached a null node so there's nothing to count!
			return 0;
		else // count this node and add it to the height of whichever is larger: the left or right sub-tree
			return (1 + max(height(theRoot->left), height(theRoot->right)));
	}

	/*
	* gets root
	* @param NA
	* @return root
	*/
	treeNode* getRoot() {
		return root;
	}

private:
	treeNode* root;
};