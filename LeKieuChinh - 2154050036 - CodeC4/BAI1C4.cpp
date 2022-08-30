//DUNG DE QUY
#include <iostream>
#include <stdio.h>
#include <conio.h>
#define COUNT 10
using namespace std;
struct Node
{
	int value;
	Node* left;
	Node* right;
};
Node* createNode(int x)
{
	Node* p = new Node;
	p->value = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void tree_empty(Node* root)
{
	root = NULL;
}
void InsertNode(Node*& p, int x)
{
	if (p == NULL)
		p = createNode(x);
	else
		if (p->value == x)
			return;
		else if (p->value < x)
			InsertNode(p->right, x);
		else InsertNode(p->left, x);
}
Node* search(Node* p, int x)
{
	if (p != NULL)
	{
		if (p->value == x)
			return p;
		else
			if (x > p->value)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;
}
void searchStandFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p->value = q->value;
		p = q;
		q = q->right;
	}
	else searchStandFor(p, q->left);
}
int Delete(Node*& t, int x)
{
	if (t == NULL) return 0;
	if (t->value == x)
	{
		Node* p = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		else searchStandFor(p, t->right);
		delete p;
		return 1;
	}
	if (t->value < x) return Delete(t->right, x);
	if (t->value > x) return Delete(t->left, x);
}
void duyetNLR(Node* p)
{
	if (p != NULL)
	{
		cout << p->value << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
void duyetLNR(Node* p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->value << " ";
		duyetLNR(p->right);
	}
}
void duyetLRN(Node* p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->value << " ";
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
	int choice, x;
	Node* root = NULL;
	bool in = false;
	do
	{
		system("cls");
		cout << "------- Bai 1 chuong 4 -------" << endl
			<< "1. Khoi tao cay rong" << endl
			<< "2. Them mot phan tu vao cay" << endl
			<< "3. Tim mot phan tu trong cay" << endl
			<< "4. Xoa mot node trong cay" << endl
			<< "5. Duyet cay theo thu tu LNR" << endl
			<< "6. Duyet cay theo thu tu NLR" << endl
			<< "7. Duyet cay theo thu tu LRN" << endl
			<< "8. Xuat cay NPTK" << endl
			<< "9. Thoat" << endl
			<< "Ban chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			tree_empty(root);
			cout << "Ban vua khoi tao cau nptk thanh cong!" << endl;
			break;
		}
		case 2:
		{
			cout << "Vui long nhap gia tri x can them: ";
			cin >> x;
			InsertNode(root, x);
			cout << "Cay NPTK sau khi them la: ";
			Process_Tree(root);
			break;
		}
		case 3:
		{
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			Node* p = search(root, x);
			if (p != NULL)
				cout << "Tim thay x = " << x << " trong cay NPTK" << endl;
			else
				cout << "Khong tim thay gia tri x" << endl;
			break;
		}
		case 4:
		{
			cout << "Vui long nhap gia tri x can xoa: ";
			cin >> x;
			int i = Delete(root, x);
			if (i == 0)
				cout << "Khong tim thay x = " << x << " de xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu x=" << x << " trong cay NPTK" << endl;
				cout << "CAY NPTK sau khi xoa la: ";
				Process_Tree(root);
			}
			break;
		}
		case 5:
		{
			cout << "Cau NPTK duyet theo LNR la: ";
			duyetLNR(root);
			break;
		}
		case 6:
		{
			cout << "Cau NPTK duyet theo NLR la: ";
			duyetNLR(root);
			break;
		}
		case 7:
		{
			cout << "Cau NPTK duyet theo LRN la: ";
			duyetLRN(root);
			break;
		}
		case 8:
		{
			cout << "Cay NPTK nhu sau: ";
			Process_Tree(root);
			break;
		}
		default:
		{
			cout << "Chao tam biet" << endl;
			break;
		}
		}
		_getch();
	} while (choice >= 1 && choice <= 8);
	return 0;
}