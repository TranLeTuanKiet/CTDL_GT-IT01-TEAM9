#include <iostream>
#include <stdio.h>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
Node* front, *rear;
void init()
{
	front = NULL;
	rear = NULL;
}
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}
int Push(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
	return 1;
}
int Pop(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
void Process_Queue() {
	Node* p = front;
	while (p) {
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
int main4()
{
	int choice,front, rear, x, i;
	system("cls");
	cout << "---BAI TAP 5 CHUONG 2---" << endl;
	cout << "1. Khoi tao stack rong" << endl;
	cout << "2. Them phan tu vao stack" << endl;
	cout << "3. Lay phan tu ra khoi stack" << endl;
	cout << "4. Kiem tra stack co ring hay khong?" << endl;
	cout << "5. Xuat stack" << endl;
	cout << "6. Thoat" << endl;
	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap x can them: ";
			cin >> x;
			i = Push(x);
			if (i == 1)
			{
				cout << "Them thanh cong" << endl;
				cout << "Stack sau khi them la: " << endl;
				Process_Queue();
			}
			else
				cout << "Them khong thanh cong" << endl;
			break;
		case 3:
			i = Pop(x);
			if (i == 1)
			{
				cout << "Lay thanh cong" << endl;
				cout << "Stack sau khi lay ra la: " << endl;
				Process_Queue();
			}
			else
				cout << "Lay ra khong thanh cong" << endl;
			break;
		case 4:
			i = isEmpty();
			if (i == 1)
				cout << "Queue dang rong" << endl;
			else
				cout << "Queue khong rong" << endl;
			break;
		case 5:
			Process_Queue();
			break;
		case 6:
			cout << "GODD BYE" << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}