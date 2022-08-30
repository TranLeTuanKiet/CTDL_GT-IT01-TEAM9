#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int value;
	Node* next;
};
void init(Node*& front, Node*& rear)
{
	front = NULL;
	rear = NULL;
}
Node* createNode(int x)
{
	Node* p = new Node;
	p->next = NULL;
	p->value = x;
	return p;
}
int isEmpty(Node* front, Node* rear)
{
	if (front == NULL && rear == NULL)
		return 1;
	return 0;
}
void Push(Node *&front, Node*& rear, int x)
{
	Node* p = createNode(x);
	if (rear == NULL)
		front = p;
	else
		rear->next = p;
	rear = p;
}
int Pop(Node*& front, Node*& rear, int& x)
{
	if ( front != NULL)
	{
		Node* p = front;
		x = p->value;
		front = p->next;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void output(Node* front)
{
	Node* p = front;
	while (p != NULL)
	{
		cout << p->value << " --> NULL";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	Node* front = NULL ;
	Node* rear = NULL ;
	int choice, i, x;
	bool in = false;
	do
	{
		system("cls");
		cout << "-------- Bai 11 chuong 2 - QUEUE&DSLK  -------- " << endl
			<< "1. Khoi tao danh sach queue" << endl
			<< "2. Kiem tra danh sach queue rong" << endl
			<< "3. Them mot phan tu vao " << endl
			<< "4. Xoa mot phan tu trong " << endl
			<< "5. Xuat danh sach " << endl
			<< "6. Thoat" << endl
			<< "Vui long chon so thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(front,rear);
			in = true;
			cout << "Khoi tao danh sach thanh cong!" << endl;
			break;
		case 2:
			if (in)
			{
				i = isEmpty(front,rear);
				if (i == 1)
					cout << "Danh sach rong" << endl;
				else
					cout << "Danh sach da co phan tu" << endl;
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		case 3:
			if (in)
			{
				cout << "Nhap vao gia tri muon them: ";
				cin >> x;
				Push(front, rear , x);
				cout << "Them x vao danh sach thanh cong" << endl;
				output(front);
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		case 4:
			if (in)
			{
				i = Pop(front, rear , x);
				if (i == 1)
				{
					cout << "Xoa 1 phan tu thanh cong, trong do x = " << x << endl;
					output(front);
				}
					
				else
					cout << "Danh sach rong!" << endl;
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		case 5:
			if (in)
			{
				output(front);
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		default:
			cout << "CHAO TAM BIET!" << endl;
			break;
		}
		_getch();
	} while (choice >= 1 && choice <= 5);
	return 0;
}