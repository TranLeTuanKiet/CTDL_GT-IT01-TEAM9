#include <iostream>
#include <stdio.h>
using namespace std;

#define COUNT 10

struct Node
{
	int info;
	Node* left;
	Node* right;
};
Node* root;

void init()
{
	root = NULL;
}
int Insert_Node_Recursive(int x, Node* q)
{
	if (q->info == x)
		return 0;
	else if (q->info > x)
	{
		if (q->left == NULL)
		{
			Node* p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->left = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->left);
	}
	else
	{
		if (q->right == NULL)
		{
			Node* p = new Node;
			p->info = x;
			p->left = NULL;
			p->right = NULL;
			q->right = p;
			return 1;
		}
		else
			return Insert_Node_Recursive(x, q->right);
	}
}
void InsertNode(Node*& p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else if (p->info > x)
			return InsertNode(p->left, x);
		else
			return InsertNode(p->right, x);
	}
}
Node* SearchNodeNoRec(Node* root, int x) {
	//tao va gan node p bang node goc
	Node* p = root;
	//duyet tu node goc den het cay
	while (p != NULL) {
		//neu co data cua node p dang xet bang x can tim
		if (p->info == x) {
			//tra ve node dang duoc xet
			return p;
		}
		else {
			//neu phan tu x can tim nho hon data cua node dang xet
			if (x < p->info) {
				//tim kiem theo cay con trai
				p = p->left;
			}
			else {//nguoc lai neu phan tu x can tim lon hon data cua node dang xet
			   //tim kiem theo cay con phai
				p = p->right;
			}
		}
	}
	//neu khong tim thay node co data bang x thi tra ve rong
	return NULL;
}

void SearchStandFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		SearchStandFor(p, q->left);
}
int Delete(Node*& T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node* p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else
			SearchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);
}

void DuyetLNR(Node* p)
{
	if (p != NULL)
	{
		DuyetLNR(p->left);
		cout << p->info << " ";
		DuyetLNR(p->right);
	}
}
void DuyetNLR(Node* p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}
void DuyetLRN(Node* p)
{
	if (p != NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info << " ";
	}
}
void print2DUtil(Node* p, int space)
{
	if (p == NULL)
		return;
	space += COUNT;
	print2DUtil(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	print2DUtil(p->left, space);
}
void Process_Tree()
{
	print2DUtil(root, 0);
}
int main()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "---Bai tap 2.4 chuong 4---" << endl;
	cout << "1. Khoi tao cay NPTK rong" << endl;
	cout << "2. Them phan tu vao cay NPTK" << endl;
	cout << "3. Tim phan tu co gia tri x trong cay NPTK" << endl;
	cout << "4. Xoa phan tu co gia tri x trong cay NPTK" << endl;
	cout << "5. Duyet cay NPTK theo LNR" << endl;
	cout << "6. Duyet cay NPTK theo NLR" << endl;
	cout << "7. Duyet cay NPTK theo LRN" << endl;
	cout << "8. Xuat cay NPTK" << endl;
	cout << "9. Thoat" << endl;
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong" << endl;
			break;
		case 2:
			cout << "Vui long nhap gia tri x can them: ";
			cin >> x;
			InsertNode(root, x);
			cout << "Cay NPTK sau khi them la: ";
			Process_Tree();
			break;
		case 3:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			p = SearchNodeNoRec(root, x);
			if (p != NULL)
				cout << "Tim thay x= " << x << " trong cay NPTK" << endl;
			else
				cout << "Khong tim thay x= " << x << " trong cay NPTK" << endl;
			break;
		case 4:
			cout << "Vui long nhap gia tri x can xoa: ";
			cin >> x;
			i = Delete(root, x);
			if (i == 0)
				cout << "Khong tim thay x= " << x << " de xoa " << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu x= " << x << " trong cay NPTK" << endl;
				cout << "Cay NPTK sau khi xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout << "Cay NTPK duyet theo LNR la: ";
			DuyetLNR(root);
			break;
		case 6:
			cout << "Cay NTPK duyet theo NLR la: ";
			DuyetNLR(root);
			break;
		case 7:
			cout << "Cay NTPK duyet theo LRN la: ";
			DuyetLRN(root);
			break;
		case 8:
			cout << "Cay NTPK nhu sau: ";
			Process_Tree();
			break;
		case 9:
			cout << "Godd bye" << endl;
			break;
		default:
			break;
		}
	} while (choice != 9);
	return 0;
}