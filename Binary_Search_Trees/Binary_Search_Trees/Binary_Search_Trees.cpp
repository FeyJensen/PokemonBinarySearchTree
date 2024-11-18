/* @file    Binary_Search_Tree.cpp
* @author   Fey Jensen
* @version 1.0
*
*CS260 - 01 - Assignment 3
* A  binary search tree class that includes the logic to create,
* destroy, and copy binary search trees as well as
* methods to insert nodes, delete nodes, and traverse the tree.
*------------------------------------------------------------ */
#include <iostream>
#include "binarySearchTree.h"

int main()
{
	std::cout << "CS 260 Assignment 3 - Binary Search Trees" << std::endl;
	std::cout << "Fey Jensen" << std::endl;

	binarySearchTree* pokemonTree = new binarySearchTree;

	pokemonTree->insert("Jynx");
	pokemonTree->insert("Charmander");
	pokemonTree->insert("Snorlax");
	pokemonTree->insert("Clefairy");
	pokemonTree->insert("Diglet");
	pokemonTree->insert("Kakuna");
	pokemonTree->insert("Meowth");
	pokemonTree->insert("Nidorino");
	pokemonTree->insert("Pikachu");
	pokemonTree->insert("Blastoise");
	pokemonTree->insert("Squirtle");
	pokemonTree->insert("Ivysaur");
	pokemonTree->insert("Bulbasaur");
	pokemonTree->insert("Abra");

	binarySearchTree* pokemonCopy = pokemonTree->copy();

	pokemonTree->inOrderPrint(pokemonTree->getRoot());

	std::cout << std::endl;

	pokemonTree->deleteData(pokemonTree->getRoot(), "Squirtle");
	pokemonTree->inOrderPrint(pokemonTree->getRoot());
	std::cout << std::endl;

	pokemonTree->deleteData(pokemonTree->getRoot(), "Meowth");
	pokemonTree->inOrderPrint(pokemonTree->getRoot());
	std::cout << std::endl;

	pokemonTree->deleteData(pokemonTree->getRoot(), "Blastoise");
	pokemonTree->inOrderPrint(pokemonTree->getRoot());
	std::cout << std::endl;

	pokemonTree->deleteData(pokemonTree->getRoot(), "Jynx");
	pokemonTree->inOrderPrint(pokemonTree->getRoot());
	std::cout << std::endl;
	
	//inOrder
	pokemonCopy->inOrderPrint(pokemonCopy->getRoot());
	std::cout << std::endl;

	//PostOrder
	pokemonCopy->postOrderPrint(pokemonCopy->getRoot());
	std::cout << std::endl;

	//perOrder
	pokemonCopy->preOrderPrint(pokemonCopy->getRoot());
	std::cout << std::endl;

	//removeAll
	pokemonCopy->removeAll(pokemonCopy->getRoot());

	//reprint copy (should print nothing)
	pokemonCopy->inOrderPrint(pokemonCopy->getRoot());

	return 0;
}

