//bai 1 chuong 2: DS KO CO THU TU
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
#define MAX 100

// cau 1.2 
void input(int a[], int& n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << " ]=";
		cin >> a[i];
	}
}
// cau 1.3
void output(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
// cau 1.4
int search(int a[], int& n, int x)
{
	int i = 0;
	while ((i < n) && (a[i] != x))
		i++;
	if (i == n)
		return -1;
	return i;
}
// cau1.5
void themPTCuoi(int a[], int& n, int x)
{
	a[n] = x;
	n++;
}
// cau 1.6
void xoaPTCuoi(int a[], int& n, int x)
{
	n--;
}

// cau 1.7
void xoa1so(int a[], int& n, int index)
{
	for (int i = index + 1; i < n; i++)
		a[i - 1] = a[i];
	n--;
}
// cau 1.8 
int search_delete(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			xoa1so(a, n, i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int a[MAX];
	int chon = 0;
	int x, i, n;
	bool in = false;
	do {
		system("cls");
		cout << "====== MENU ====="
			<< "1. Nhap danh sach" << endl
			<< "2. Xuat danh sach" << endl
			<< "3. Tim mot phan tu trong danh sach" << endl
			<< "4. Them mot phan tu trong danh sach" << endl
			<< "5. Xoa phan tu cuoi danh sach" << endl
			<< "6. Xoa phan tu vi tri thu i" << endl
			<< "7. Tim mot phan tu, neu thay thi xoa" << endl;
		cin >> chon;
		switch (chon)
		{
		case 1:
			input(a, n);
			in = true;
			break;
		case 2:
			if (in == true)
				output(a, n);
			else cout << "Thuc hien buoc 1" << endl;
			break;
		case 3:
			if (in == true)
			{
				int x;
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				int index = search(a, n, x);
				if (index != -1)
					cout << "Vi tri cua " << x << "la: " << index << endl;
				else
					cout << "Thuc hien buoc 1" << endl;
			}
			break;
		case 4:
			if (in == true)
			{
				int x;
				cout << "Nhap gia tri ban muon them: ";
				cin >> x;
				themPTCuoi(a, n, x);
				cout << "Thanh cong!" << endl;
			}
			else
				cout << "Thuc hien buoc 1" << endl;
			break;
		case 5:
			if (in == true)
			{
				//xoaPTCuoi(a,n);
				cout << "Thanh cong!" << endl;
			}
			else
				cout << "Thuc hien buoc 1" << endl;
			break;
		case 6:
			if (in == true)
			{
				int index;
				cout << "Nhap vi tri ban muon xoa: ";
				cin >> index;
				xoa1so(a, n, index);
				cout << "Da xoa thanh cong" << endl;
			}
			else
				cout << "Thuc hien buoc 1" << endl;
			break;
		case 7:
			if (in == true)
			{
				int x;
				cout << "Nhap gia tri ma ban muon tim va xoa: ";
				cin >> x;
				int i = search_delete(a, n, x);
				if (i == 1)
					cout << "Da xoa thanh cong" << endl;
				else
					cout << "Xoa khong thanh cong" << endl;

			}
			else cout << "Thuc hien buoc 1" << endl;
			break;
		default:
			cout << "TAM BIET" << endl;
			break;
		}
	} while (chon >= 1 && chon <= 7);
	return 0;
}