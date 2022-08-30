#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;

void init(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}
int Push(int a[], int& front, int& rear, int x)
{
	if (rear - front == MAX - 1)
		return 0;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == MAX - 1)
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}
int Pop(int a[], int& front, int& rear, int& x)
{
	if (front == -1)
		return 0;
	else
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}

int isFull(int a[], int front, int rear)
{
	if ((front == 0 && rear == MAX - 1) || (front - rear == 1))
		return 1;
	return 0;
}
int isEmpty(int a[], int front, int rear)
{
	if (rear == front)
		return 1;
	return 0;
}
void Process_Queue(int a[], int front, int rear)
{
	cout << "front= " << front << "\t rear= " << rear << endl;
	if (front <= rear && front != 1)
	{
		cout << " <-- ";
		for (int i = front; i < rear + 1; i++)
			cout << a[i] << " <-- ";
		cout << " <-- " << endl;
	}
}
int main2()
{
	int a[MAX];
	int choice, front, rear, x, i;
	system("cls");
	cout << "---BAI TAP 5 CHUONG 2---" << endl;
	cout << "1. Khoi tao queue rong" << endl;
	cout << "2. Them phan tu vao queue" << endl;
	cout << "3. Lay phan tu ra khoi stack" << endl;
	cout << "4. Kiem tra stack co ring hay khong?" << endl;
	cout << "5. Kiem tra stack co day hay khong" << endl;
	cout << "6. Xuat stack" << endl;
	cout << "7. Thoat" << endl;
	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, front, rear);
			cout << "Khoi tao thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap x can them: ";
			cin >> x;
			i = Push(a, front, rear, x);
			if (i == 1)
			{
				cout << "Them thanh cong" << endl;
				cout << "Stack sau khi them la: " << endl;
				Process_Queue(a, front, rear);
			}
			else
				cout << "Them khong thanh cong" << endl;
			break;
		case 3:
			i = Pop(a, front, rear, x);
			if (i == 1)
			{
				cout << "Lay thanh cong" << endl;
				cout << "Stack sau khi lay ra la: " << endl;
				Process_Queue(a, front, rear);
			}
			else
				cout << "Lay ra khong thanh cong" << endl;
			break;
		case 4:
			i = isEmpty(a, front, rear);
			if (i == 1)
				cout << "Queue dang rong" << endl;
			else
				cout << "Queue khong rong" << endl;
			break;
		case 5:
			i = isFull(a, front, rear);
			if (i == 1)
				cout << "Queue dang day" << endl;
			else
				cout << "Queue khong day" << endl;
			break;
		case 6:
			Process_Queue(a, front, rear);
			break;
		case 7:
			cout << "GOOD BYE" << endl;
			break;
		default:
			break;
		}
	} while (choice != 7);
	system("pause");
	return 0;
}