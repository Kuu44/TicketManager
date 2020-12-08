#include "Tree.h"
Node* Tree::newNode(int num, Person person)
{
	Node* temp = new Node;

	temp->person = person;

	temp->key = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
// To create a Tree with n levels. 
Node* Tree::createNLevelTree(int arr[], Person* persons, int n)
{
	Node* root = newNode(arr[0], persons[0]);
	Node* temp = root;
	for (int i = 1; i < n; i++) {
		if (temp->key > arr[i]) {
			temp->left = newNode(arr[i], persons[i]);
			temp = temp->left;
		}
		else {
			temp->right = newNode(arr[i], persons[i]);
			temp = temp->right;
		}
	}
	return root;
}
bool Tree::isBST(Node* root, int min, int max)
{
	if (root == NULL)
		return true;

	if (root->key < min || root->key > max)
		return false;

	// Allow only distinct values 
	return (isBST(root->left, min,
		(root->key) - 1)
		&& isBST(root->right,
			(root->key) + 1, max));
}
// Returns tree if given array of size n can 
	// represent a BST of n levels. 
bool Tree::canRepresentNLevelBST(int arr[], Person* persons, int n)
{
	Node* root = createNLevelTree(arr, persons, n);
	return isBST(root, INT_MIN, INT_MAX);
}
void inOrder(Node* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << "\n" << root->person.name << " " << root->person.age << " " << root->person.seat_no << " ";
		inOrder(root->right);
	}
}
Person Tree::Search(Node* root, int data)
{
	if (root->key == data) {
		return root->person;
	}
	else if (data <= root->key) return Search(root->left, data);
	else return Search(root->right, data);
}
void Tree::createTree(Entry& data) {
	root = NULL;
	for (int i = 0; i < (data.getSize() - 1); i++) {
		keys[i] = data.entries[0].seat_no;
	}
	root = createNLevelTree(keys, data.entries, (data.getSize() - 1));
	inOrder(root);
}
Person Tree::searchTree(int seatNum) {
	bool notHere = true;
	for (int i = 0; i < 3; i++) {
		if (seatNum == keys[i]) notHere = false;
	}
	if (notHere) {
		Person notFound;
		notFound.seat_no = -1;
		return notFound;
	}
	return Search(root, seatNum);
}