#include <iostream>
#include <conio.h>
#define COUNT 10
using namespace std;
struct Node {
	int value;
	Node* left;
	Node*right;
};
void treeEmpty( Node *root) {
	root = NULL;
}
Node* createNode(int x)
{
	Node* p = new Node;
	p->value = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
// Them node khong de quy
void insertNode_NoRe(Node*& root,  int x)
{
	if (root == NULL)
		root = createNode(x);
	else
	{
		Node* p = root;
		Node* parent = NULL;
		while (p != NULL && p->value != x)
		{
			parent = p;
			if (p->value > x)
				p = p->left;
			else
				p = p->right;
		}
		if (p == NULL)
		{
			p = createNode(x);
			if (parent->value < x)
				parent->right = p;
			else
				parent->left = p;
		}
	}
}
void print2DUtil(Node* p, int space)
{
	//Base case
	if (p == NULL)
		return;
	//Increase distance between levels
	space += COUNT;
	//Process right child first
	print2DUtil(p->right, space);
	//Print current node after space
	//count 
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->value << endl;
	//Process left child
	print2DUtil(p->left, space);
}
void Process_Tree(Node* root)
{
	print2DUtil(root, 0);
}
int main()
{
	Node* root = NULL;
	Node* p = new Node;
	int x, tiep = 0;
	treeEmpty(root);
	do
	{
		system("cls");
		cout << "Nhap gia tri ban muon them vao cay: ";
		cin >> x;
		insertNode_NoRe(root, x);
		Process_Tree(root);
		cout << "Ban co muon tiep tuc (1/0): ";
		cin >> tiep;
		_getch();
	} while (tiep == 1);
	return 0;
}