#include <iostream>
#include <stdio.h>
#define MAX 100
using namespace std;

void init(int a[], int& sp)
{
	sp = -1;
}
int Push(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int Pop(int a[], int& sp, int& x)
{
	if (sp != -1) // khi stack khác rỗng
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
void Process_Stack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
		cout << a[i] << " <--";
	cout << endl;
}
int main1()
{
	int a[MAX];
	int choice, sp, x, i;
	system("cls");
	cout << "---BAI TAP 5 CHUONG 2---";
	cout << "Khoi tao stack rong" << endl;
	cout << "2. Them phan tu vao stack" << endl;
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
			init(a, sp);
			cout << "Khoi tao thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap x can them: ";
			cin >> x;
			i = Push(a, sp, x);
			if (i == 1)
			{
				cout << "Them thanh cong" << endl;
				cout << "Stack sau khi them la: " << endl;
				Process_Stack(a, sp);
			}
			else
				cout << "Them khong thanh cong" << endl;
			break;
		case 3:
			i = Pop(a, sp, x);
			if (i == 1)
			{
				cout << "Lay thanh cong" << endl;
				cout << "Stack sau khi lay ra la: " << endl;
				Process_Stack(a, sp);
			}
			else
				cout << "Lay ra khong thanh cong" << endl;
			break;
		case 4:
			i = isEmpty(a, sp);
			if (i == 1)
				cout << "Stack dang rong" << endl;
			else
				cout << "Stack khong rong" << endl;
			break;
		case 5:
			i = isFull(a, sp);
			if (i == 1)
				cout << "Stack dang day" << endl;
			else
				cout << "Stack khong day" << endl;
			break;
		case 6:
			Process_Stack(a, sp);
			break;
		case 7:
			cout << "GODD BYE" << endl;
			break;
		default:
			break;
		}
	} while (choice != 7);
	system("pause");
	return 0;
}