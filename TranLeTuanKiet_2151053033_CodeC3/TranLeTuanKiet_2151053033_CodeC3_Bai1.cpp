#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdio.h>
#define MAX 100
using namespace std;
void input(int a[], int &n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		 a[i] = rand() % 1000 + 1;
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n;i++)
	{
		int x = a[i];
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
		for (int j = n - 1; j > i; j--)
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
void maxHeap(int a[], int n)
{
	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		int jmax = 2 * i + 1;
		if (n > (2 * i + 2) && a[2 * i + 2] > a[jmax])
			jmax = 2 * i + 2;
		if (a[i] < a[jmax])
			swap(a[i], a[jmax]);
	}
}
void HeapSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		maxHeap(a, n - i);
		swap(a[0], a[n - i - 1]);
	}
}
int search(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}
int binarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x) return mid;
		if (x > a[mid]) // Truong hop mang duoc sap xep tang dan
			left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
int main()
{
	int a[MAX], b[MAX], n, choice,x;
	clock_t start;
	double duration;
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
			<< "7. Sap xep mang tang dan bang QuickSort" << endl
			<< "8. Sap xep mang tang dan bang HeapSort" << endl
			<< "9. Tim kiem mot phan tu  trong danh sach co thu tu ( Tim kiem tuan tu)" << endl
			<< "10. Tim kiem mot phan tu trong danh sach co thu tu ( Tim kiem nhi phan)" << endl
			<< "11. Thoat " << endl
			<< "Vui long chon so: ";
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
				CopyArray(a, b, n);
				start = clock();
				InsertionSort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
					output(b, n);
				if (duration > 0)
					cout << "Thoi gian INSERTION SORT la " << duration * 1000000 << " Microseconds" << endl;
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 4:
			if (in)
			{
				CopyArray(a, b, n);
				start = clock();
				SelectionSort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
					output(b, n);
				if (duration > 0)
					cout << "Thoi gian SELECTION SORT la " << duration * 1000000 << " Microseconds" << endl;
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 5:
			if (in)
			{
				CopyArray(a, b, n);
				start = clock();
				InterchangeSort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
					output(b, n);
				if (duration > 0)
					cout << "Thoi gian INTERCHANGE SORT la " << duration * 1000000 << " Microseconds" << endl;
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 6:
			if (in)
			{
				CopyArray(a, b, n);
				start = clock();
				BubbleSort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
					output(b, n);
				if (duration > 0)
					cout << "Thoi gian BUBBLE SORT la " << duration * 1000000 << " Microseconds" << endl;
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 7:
			if (in)
			{
				CopyArray(a, b, n);
				start = clock();
				QuickSort(b, 0, n - 1);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
					output(b, n);
				if (duration > 0)
					cout << "Thoi gian QUICK SORT la " << duration * 1000000 << " Microseconds" << endl;
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 8:
			if (in)
			{
				CopyArray(a, b, n);
				start = clock();
				HeapSort(b, n);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				if (n < 100)
					output(b, n);
				if (duration > 0)
					cout << "Thoi gian HEAP SORT la " << duration * 1000000 << " Microseconds" << endl;
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 9:
			if (in)
			{
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				int index = search(a, n, x);
				if (index != -1)
					cout << "Vi tri x duoc tim thay: " << index << endl;
				else
					cout << "Gia tri cua x khong ton tai trong mang" << endl;
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		case 10:
			if (in)
			{
				CopyArray(a, b, n);
				InterchangeSort(b, n);
				cout << "Nhap gia tri can tim: ";
				cin >> x;
				int index = binarySearch(a, n, x);
				if (index != -1)
					cout << "Vi tri x duoc tim thay: " << index << endl;
				else
					cout << "Gia tri cua x khong ton tai trong mang" << endl;
			}
			else
				cout << "Vui long nhap mang truoc" << endl;
			break;
		default:
			cout << "Chao tam biet" << endl;
			break;
		}
		_getch();
	} while (choice >= 1 && choice <= 10);
	return 0;
}