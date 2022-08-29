#include<iostream>
#include<queue>
using namespace std;
struct Node
{
	int data;
	Node *link;
	Node *left;
	Node *right;
};
Node * front, *rear;
void init(int a[], int &front, int &rear)
{
	front = NULL;
	rear = NULL;
}
void Push(int x)
{
	Node *p;
	p = new Node;
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
		Node *p = front;
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

void LRN(Node *root)
{
	if(root!=NULL)
	{
		Node *p=root;
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
	Node* root = NULL;
	int choice,x;
	do
	{
		cout<<"--------------MENU-------------------"<<endl;
		cout<<"1. Kiem tra rong "<<endl;
		cout<<"2. Them phan tu vao QUEUE "<<endl;
		cout<<"3. Sap xep cay nhi phan theo LRN "<<endl;
		cout<<"4. Thoat chuong trinh "<<endl;
		cout<<"Moi ban chon menu: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			isEmpty();
			break;
		case 2:
			cout<<"Moi ban nhap phan tu: ";
			cin>>x;
			Push(x);
			break;
		case 3:
			cout<<"Sau khi sap xep la: ";
			LRN(root);
			break;
		case 4:
			cout<<"Ket thuc chuong trinh "<<endl;
			break;
		default:
			break;
		}
	}
	while(choice != 4);
	system("pause");
	return 0;
}
