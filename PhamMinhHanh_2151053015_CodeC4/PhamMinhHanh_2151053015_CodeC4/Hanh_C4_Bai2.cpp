#include<iostream>
using namespace std;
#define COUNT 10
struct Node
{
	int key;
	Node *left;
	Node *right;
};
// khởi tạo cây rỗng
Node *root;
void init(Node *root)
{
	root=NULL;
}
Node *createNode(int x)
{
	Node *p = new Node;
	p->key = x;
	p->left = NULL;
	p->right = NULL;

	return p;
}
// thêm phần tử không dùng đệ quy
void InsertNode( Node *&root , int x)
{
	if(root==NULL)
		root= createNode(x);
	else
	{
		Node *p=root;
		Node *parent= NULL;
		while (p!= NULL && p->key != x)
		{
			parent=p;
			if(p->key > x)
				p=p->left;
			else 
				p=p->right;
		}
		if(p==NULL)
		{
			p=createNode(x);
			if (parent->key<x)
				parent->right = p;
			else 
				parent ->left=p;
		}
	}
}
// tìm phần tử không dùng đệ quy
Node *Search(Node *root , int x)
{
	Node *p=root;
	while (p!=NULL && p->key != x)
	{
		if(p->key > x)
			p=p->left;
		else 
			p=p->right;
	}
	return p;
}
void SearchStandFor(Node*& p, Node*& q)
{
	if (q->left == NULL)
	{
		p->key = q->key;
		p = q;
		q = q->right;
	}
	else
		SearchStandFor(p, q->left);
}
// xóa phần tử dùng đệ quy
int Delete(Node*& root, int x)
{
	if (root == NULL)
		return 0;
	if (root->key == x)
	{
		Node* p = root;
		if (root->left == NULL)
			root = root->right;
		else if (root->right == NULL)
			root = root->left;
		else
			SearchStandFor(p, root->right);
		delete p;
		return 1;
	}
	if (root->key< x) return Delete(root->right, x);
	if (root->key > x) return Delete(root->left, x);
}
// NLR
void NLR(Node* p)
{
	if (p != NULL)
	{
		cout << p->key << " ";
		NLR(p->left);
		NLR(p->right);
	}
}
// 2.7 duyệt cây theo LNR ( dùng stack )
#define Max 100
struct Stack
{
	Node *a[Max];
	int top;
};
void inits(Stack &s)
{
	s.top = -1;
}
void push(Stack &s, Node *x)
{
	s.a[++s.top] = x;
}
Node* pop(Stack &s)
{
	return s.a[s.top--];
}
bool isEmpty(Stack s)
{
	return s.top <0;
}
void LNR(Node *root, Stack &s)
{
	if(root!=NULL)
	{
		Node *p=root;
		while(p!=NULL)
		{
			while(p !=NULL)
			{
				push(s,p);
				p=p->left;
			}
			if(!isEmpty(s))
			{
				Node *r=pop(s);
				cout<<r->key<<"\t";
				if(r->right!=NULL)
				{
					p=r->right;
				}
			}
		}
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
	cout << p->key << endl;
	print2DUtil(p->left, space);
}
void Process_Tree()
{
	print2DUtil(root, 0);
}


// LRN(dùng queue)
struct node
{
	int data;
	node *link;
	node *left;
	node *right;
};
node * front, *rear;
void initq(int a[], int &front, int &rear)
{
	front = NULL;
	rear = NULL;
}
void Push(int x)
{
	node *p;
	p = new node;
	p->data = x;
	p->link = NULL;	
	if (rear == NULL)
		front =p;
	else
		rear->link = p;
	rear = p;
}
int Pop(int &x)
{
	if (front!= NULL)
	{
		node *p = front;
		x = p -> data;
		front = front ->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;	
}
void LRN(node *root)
{
	if(root!=NULL)
	{
		node *p=root;
		while(p->left !=NULL)
		{
			Push(p->data);
			p=p->left;
		}
		if(!isEmpty())
		{
			cout<<p->data<<", ";
			if(p->right!=NULL)
			{
				p=p->right;
			}
		}
	}
}

int main()
{
	Stack s;
	inits(s);
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "---Bai tap 2 chuong 4---" << endl;
	cout << "1. Khoi tao cay NPTK rong" << endl;
	cout << "2. Them phan tu vao cay NPTK" << endl;
	cout << "3. Tim phan tu co gia tri x trong cay NPTK" << endl;
	cout << "4. Xoa phan tu co gia tri x trong cay NPTK" << endl;
	cout << "5. Duyet cay NPTK theo NLR" << endl;
	cout << "6. Duyet cay NPTK theo LNR" << endl;
	cout << "7. Duyet cay NPTK theo LRN" << endl;
	cout << "8. Xuat cay NPTK" << endl;
	cout << "9. Thoat" << endl;
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(root);
			cout << "Khoi tao thanh cong" << endl;
			break;
		case 2:
			cout << "Vui long nhap gia tri x can them: ";
			cin >> x;
			InsertNode(root,x);
			cout << "Cay NPTK sau khi them la: ";
			Process_Tree();
			break;
		case 3:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			
			if (p != NULL)
				cout << "Tim thay x= " << x << " trong cay NPTK" << endl;
			else
				cout << "Khong tim thay x= " << x << " trong cay NPTK" << endl;
			break;
		case 4:
			cout << "Vui long nhap gia tri x can xoa: ";
			cin >> x;
			i = Delete(root,x);
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
			cout << "Cay NTPK duyet theo NLR la: ";
			NLR(p);
			break;
		case 6:
			cout << "Cay NTPK duyet theo LNR la: ";
			LNR(root,s);
			break;
		case 7:
			cout << "Cay NTPK duyet theo LRN la: ";
			node *root;
			LRN(root);
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