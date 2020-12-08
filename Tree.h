#pragma once
#include "SFML/Graphics.hpp"
#include "Entry.h"
#include<iostream>

using namespace std;

struct Node {
	int key;
	Person person;
	struct Node* right, * left;
};
class Tree
{
private:
	Node* root;
	int keys[MAX_SIZE];
public:
	Node* newNode(int, Person);
	Node* createNLevelTree(int arr[], Person*, int);
	bool isBST(Node*, int, int);
	// Returns tree if given array of size n can 
	// represent a BST of n levels. 
	bool canRepresentNLevelBST(int arr[], Person*, int);
	void inOrder(Node*);
	Person Search(Node*, int);
	void createTree(Entry&);
	Person searchTree(int);	
};

