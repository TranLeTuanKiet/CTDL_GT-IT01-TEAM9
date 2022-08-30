#include <iostream>
#include <conio.h>
#define MAX 100
using namespace std;
void input(int a[], int& n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	cout << "Nhap mang: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void InsertionSort(int a[], int n)
{
	int x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_pos = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int l = left;
	int r = right;
	do
	{
		while (a[l] < x) l++;
		while (a[r] > x) r--;
		if (l <= r)
		{
			swap(a[l], a[r]);
			l++;
			r--;
		}
	} while (l <= r);
	if (left < r)
		QuickSort(a, left, r);
	if (right > l)
		QuickSort(a, l, right);
}
//1.10
void searchSequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if (i == n)
	{
		cout << "Khong tim thay!";
	}
	else cout << "Tim thay tai vi tri: " << i;
}
//1.11
int searchBinary(int a[], int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = 1 + (r - 1) / 2; // tương duong (1+r)/2 nhưng tránh tràn số khi l,r lớn)
		// nếu a[mid] = x, tra ve chi so va ket thuc
		if (a[mid] == x)
			return mid;
		//neu a[mid] > x thuc hien tim kiem nua trai cua mang
		if (a[mid] > x)
			return searchBinary(a, l, mid - 1, x);
		//neu a[mid] < x, thuc hien tim kiem nua phai
		return searchBinary(a, l, mid + 1, x);
		//neu ko tim thay
		return -1;
	}

	
}
int main()
{
	int a[MAX], n, choice, x;
	bool in = false;
	do
	{
		system("cls");
		cout << "------ Bai 1 Chuong 3 -----" << endl
			<< "1. Nhap mang" << endl
			<< "2. Xuat mang" << endl
			<< "3. Sap xep mang tang dan bang InsertionSort" << endl
			<< "4. Sap xep mang tang dan bang SelectionSort" << endl
			<< "5. Sap xep mang tang dan bang InterchangeSort" << endl
			<< "6. Sap xep mang tang dan bang BubbleSort" << endl
			<< "7. Sap xep mang tang dan bang QuickSort"
			<< "8. Vui long chon so: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			input(a, n);
			in = true;
			break;
		case 2:
			if (in)
				output(a, n);
			else
				cout << "Mang rong!" << endl;
			break;
		case 3:
			if (in)
			{
				InsertionSort(a, n);
				output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 4:
			if (in)
			{
				SelectionSort(a, n);
				output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 5:
			if (in)
			{
				InterchangeSort(a, n);
				output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 6:
			if (in)
			{
				BubbleSort(a, n);
				output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 7:
			if (in)
			{
				QuickSort(a, 0, n - 1);
				output(a, n);
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		default:
			cout << "Chao tam biet" << endl;
			break;
		

		}
		_getch();
	} while (choice >= 1 && choice <= 7);
	return 0;
}