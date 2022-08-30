#include <iostream>
#include <conio.h>
#define MAX 100
using namespace std;
void init(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}
int isEmpty(int a[], int front, int rear)
{
	if (rear == front)
		return 1;
	return 0;
}
int isFull(int a[], int front, int rear)
{
	if ((front==0 && rear == MAX - 1) || (front - rear == 1))
		return 1;
	return 0;
}
int Push(int a[], int& front, int &rear, int x)
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
	return 0;
}
int Pop(int a[], int& front, int &rear, int& x)
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
void out(int a[], int front, int rear)
{
	cout << "front= " << front << "	rear= " << rear << endl;
	if (front <= rear && front != -1)
	{
		for (int i = front; i < rear + 1; i++)
			cout << a[i] << " <-- ";
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int a[MAX];
	int front, rear, choice, i, x;
	bool in = false;
	do
	{
		system("cls");
		cout << "-------- Bai 7 chuong 2 - QUEUE -------- " << endl
			<< "1. Khoi tao QUEUE" << endl
			<< "2. Kiem tra QUEUE rong" << endl
			<< "3. Kiem tra QUEUE day" << endl
			<< "4. Them mot phan tu vao QUEUE" << endl
			<< "5. Xoa mot phan tu trong QUEUE" << endl
			<< "6. Xuat danh sach QUEUE" << endl
			<< "7. Thoat" << endl
			<< "Vui long chon so thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, front, rear);
			in = true;
			cout << "Khoi tao danh sach thanh cong!" << endl;
			break;
		case 2:
			if (in)
			{
				i = isEmpty(a, front, rear);
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
				i = isFull(a, front, rear);
				if (i == 1)
					cout << "Danh sach day" << endl;
				else
					cout << "Danh sach chua day" << endl;
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		case 4:
			if (in)
			{
				cout << "Nhap vao gia tri muon them: ";
				cin >> x;
				i = Push(a, front, rear, x);
				if (i == 1)
				{
					cout << "Them x vao danh sach thanh cong" << endl;
					out(a, front, rear);
				}

				else
					cout << "Danh sach da day!" << endl;
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		case 5:
			if (in)
			{
				i = Pop(a,front, rear, x);
				if (i == 1)
					cout << "Xoa 1 phan tu thanh cong, trong do x = " << x << endl;
				else
					cout << "Danh sach rong!" << endl;
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		case 6:
			if (in)
			{
				out(a, front, rear);
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		default:
			cout << "CHAO TAM BIET!" << endl;
			break;
		}
		_getch();
	} while (choice >= 1 && choice <= 6);
	return 0;
}