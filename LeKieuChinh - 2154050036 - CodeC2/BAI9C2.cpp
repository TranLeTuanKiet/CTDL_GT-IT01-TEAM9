//SD STACK, BAI TOAN THAP HA NOI
#include<iostream>
#include<stdio.h>
using namespace std;
//Khai bao cau truc STACK
struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;
//Khoi tao STACK rong
void init()
{
	front = NULL;
	rear = NULL;
}
//Kiem tra STACK rong
int isEmty()
{
	if (front == NULL && rear == NULL)
		return 1;
	return 0;
}
//Them phan tu vao STACK
int Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
	return 1;
}
//Lay ra mot phan tu tu STACK
int Pop(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		p->info = x;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//Xuat STACK
void Process_STACK()
{
	Node* p = front;
	do
	{
		cout << p->info << "<--";
		p = p->link;
	} while (p != NULL);
	cout << endl;
}
//Thap Ha Noi
void thapHaNoi(int n, char nguon, char trunggian, char dich)
{
	if (n == 1)
		cout << nguon << ' ' << char(26) << ' ' << dich << endl;
	else
	{
		thapHaNoi(n - 1, nguon, dich, trunggian);
		thapHaNoi(1, nguon, trunggian, dich);
		thapHaNoi(n - 1, trunggian, nguon, dich);
	}
}



int main()
{
	int choice, x;
	system("cls");
	cout << "=====BAI TAP 9 CHUONG 2 =====" << endl;
	cout << "1. Khoi tao STACK rong" << endl;
	cout << "2. Them mot phan tu vao Stack" << endl;
	cout << "3. Lay mot phan tu ra khoi Stack" << endl;
	cout << "4. Kiem tra STACK co rong hay khong" << endl;
	cout << "5. Xuat STACK" << endl;
	cout << "6. Thap Ha Noi" << endl;
	cout << "7. Ket thuc chuong trinh" << endl;
	do
	{
		cout << "\nVui long nhap so de thuc hien ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao STACK rong thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap phan tu can them x=";
			cin >> x;
			Push(x);
			cout << "STACK sau khi them la:";
			Process_STACK();
			break;
		case 3:
			Pop(x);
			cout << "STACK sau khi them la:";
			Process_STACK();
			break;
		case 4:
			if (isEmty() == 1)
				cout << "STACK rong" << endl;
			else
				cout << "STACK da co phan tu!" << endl;
			break;
		case 5:
			Process_STACK();
		case 6:
			thapHaNoi(3, 'A', 'B', 'C');
		case 7:
			cout << "Ket thuc chuong trinh" << endl;
			break;
		}
	} while (choice != 7);
	system("pause");
	return 0;
}