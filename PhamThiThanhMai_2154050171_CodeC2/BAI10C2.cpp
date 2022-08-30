#include <iostream>
#include <stdio.h>
using namespace std;
struct Node
{
	int info;
	Node* link;
};
Node* sp;
void init()
{
	sp = NULL;
}
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
int Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
	return 1;
}
int Pop(int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
void Process_stack()
{
	Node* p = sp;
	do {
		cout << p->info << " <-- ";
		p = p->link;
	} while (p != NULL);
	cout << endl;
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "---BAI TAP 5 CHUONG 2---" << endl;
	cout << "1. Khoi tao stack rong" << endl;
	cout << "2. Them phan tu vao stack" << endl;
	cout << "3. Lay phan tu ra khoi stack" << endl;
	cout << "4. Kiem tra stack co rong hay khong?" << endl;
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
				Process_stack();
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
				Process_stack();
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
			Process_stack();
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}