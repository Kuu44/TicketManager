#include<iostream>
using namespace std;
struct Person 
{
	int age;
	int seatnum;
	string name;
	
};
// structure for Binary Node 
struct Node {
	int key;
	Person person;
	struct Node* right, * left;
};

Node* newNode(int num,int age,string name)
{
	Node* temp = new Node;
	temp->person.age = age;
	temp->person.seatnum = num;
	temp->person.name = name;
	temp->key = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// To create a Tree with n levels. We always 
// insert new node to left if it is less than 
// previous value. 
Node* createNLevelTree(int arr[],int age[],string name[], int n)
{
	Node* root = newNode(arr[0],age[0],name[0]);
	Node* temp = root;
	for (int i = 1; i < n; i++) {
		if (temp->key > arr[i]) {
			temp->left = newNode(arr[i],age[i],name[i]);
			temp = temp->left;
		}
		else {
			temp->right = newNode(arr[i],age[i],name[i]);
			temp = temp->right;
		}
	}
	return root;
}

bool isBST(Node* root, int min, int max)
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
bool canRepresentNLevelBST(int arr[],int age[],string name[], int n)
{
	Node* root = createNLevelTree(arr,age,name, n);
	return isBST(root, INT_MIN, INT_MAX);
}
void inOrder(Node* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}
bool Search(Node* root, int data)
{
	
	if (root->key == data)
	{
		cout << "age" << root->person.age << endl;
		cout << "name" << root->person.name << endl;
		return true;
	}
		else if (data <= root->key)
		{
			return Search(root->left, data);
		}
		else
		{
			return Search(root->right, data);
		}
	
}

// Driver code 
int main()
{	
	Node* root = NULL;
	int arr[] = { 512, 330, 78, 11, 8 };
	int age[] = { 18,20,11,16,19 };
	string name[] = { "laxman","ram","aakash","Ak","LM10" };
	//int seat[]={1,2,3,4,5};

	int n = sizeof(arr) / sizeof(arr[0]);

	if (canRepresentNLevelBST(arr,age,name, n))
		cout << "Yes";
	else
		cout << "No";
	root = createNLevelTree(arr,age,name, n);
	cout << "the tree is" << endl;
	inOrder(root);
	int number;
	cout << "Enter number be searched\n";
	cin >> number;
	//If number is found, print "FOUND"
	if (Search(root, number) == true) cout << "Found\n";
	else cout << "Not Found\n";

	return 0;
}
