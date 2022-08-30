#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 100

//Cau 1.1
int a[MAX];
int n;

//Cau 1.2
void input(int a[], int& n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}

//Cau 1.3
void output(int a[], int n)
{
	cout << "Xuat danh sach" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= " << a[i] << "\t";
	}
	cout << endl;
}

//Cau 1.4
int search(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) return 1;
	}
	return 0;
}

//Cau 1.5
int add(int a[], int& n, int& x)
{
	cout << "Nhap gia tri ban muon them vao cuoi danh sach: ";
	cin >> x;
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}

//Cau 1.6
int delete_last(int a[], int& n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	else
		return 0;
}

//Cau 1.7
int delete_at_pos(int a[], int& n, int x)
{
	if (x >= 0 && x < n)
	{
		for (int i = x; i < n; i++)
			a[i] = a[i + 1];

		n--;
		return 1;
	}
	else
		return 0;
}

//Cau 1.8
int search_and_delete(int a[], int& n, int x)
{
	cout << "Nhap gia tri phan tu ban muon tim va xoa trong danh sach: ";
	cin >> x;
	for (int j = 0; j < n; j++)
	{
		if (a[j] == x)
		{
			delete_at_pos(a, n, j);
			return 1;
		}
		else
			cout << "Khong tim thay phan tu " << x << " trong danh sach nen khong the xoa" << endl;
	}
	return 0;
}
int main()
{
	int c;
	bool ip = false;
	int x = 0;
	do {
		do {
			system("cls");
			cout << "----------------------------------MENU----------------------------------" << endl;
			cout << "1. Nhap danh sach " << endl;
			cout << "2. Xuat danh sach " << endl;
			cout << "3. Tim 1 phan tu trong danh sach " << endl;
			cout << "4. Them 1 phan tu vao cuoi danh sach " << endl;
			cout << "5. Xoa phan tu cuoi danh sach " << endl;
			cout << "6. Xoa phan tu tai vi tri thu i " << endl;
			cout << "7. Tim 1 phan tu trong danh sach va xoa phan tu do neu tim thay " << endl;
			cout << "8. Ket thuc chuong trinh " << endl;
			cout << "Chon MENU(1-8): ";
			cin >> c;
			if (c < 1 || c > 8) cout << "Loi gia tri vui ong nhap lai" << endl;
		} while (c < 1 || c > 8);

		switch (c)
		{
		case 1:
			input(a, n);
			ip = true;
			break;
		case 2:
			if (ip == true)
			{
				output(a, n);
			}
			else
				cout << "Vui long nhap du lieu truoc" << endl;
			break;
		case 3:
			if (ip == true)
			{
				cout << "Nhap x can tim: ";
				cin >> x;
				if (search(a, n, x) == 1)
					cout << "Tim thay " << x << " trong danh sach" << endl;
				else
					cout << "Khong tim thay " << x << " trong danh sach" << endl;
			}
			else
				cout << "Vui long nhap du lieu truoc" << endl;
			break;
		case 4:
			if (ip == true)
			{
				add(a, n, x);
			}
			else
				cout << "Vui long nhap du lieu truoc" << endl;
			break;
		case 5:
			if (ip == true)
			{
				delete_last(a, n);
			}
			else
				cout << "Vui long nhap du lieu truoc" << endl;
			break;
		case 6:
			if (ip == true)
			{
				cout << "Nhap vi tri phan tu ban muon xoa trong danh sach: ";
				cin >> x;
				delete_at_pos(a, n, x);
			}
			else
				cout << "Vui long nhap du lieu truoc" << endl;
			break;
		case 7:
			if (ip == true)
			{
				search_and_delete(a, n, x);
			}
			else
				cout << "Vui long nhap du lieu truoc" << endl;
			break;
		default:
			cout << "KET THUC CHUONG TRINH" << endl;
			break;
		}
		system("pause");
	} while (c > 0 && c < 8);
	return 0;
}