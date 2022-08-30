#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 100
void in(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
void out(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
}
void swap(int& a, int& b)
{
	int  c;
	c = a;
	a = b;
	b = c;
}
void SelectionSort(int a[], int n)
{
	int  min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
void InsertionSort(int a[], int n)
{
	int x, i, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			swap(a[i], a[j]);
				i++; j--;
		}
	}
	if (left < j) QuickSort(a, left, j);
	if (i < right) QuickSort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n) 
		return;
	if (j + 1 < n) 
		if (a[j] < a[j + 1])
			j++;

	if (a[i] >= a[j])
		return;
	else {
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n - 1);
		i--;
	}
	int right = n - 1; 
	while (right > 0)
	{
		swap(a[0], a[right]); 
		right--;
		if (right > 0) 
			shift(a, 0, right); 
	}
}
int main() {
	int a[MAX];
	int n, choice;
	system("cls");
	cout << "Chuong 3 bai 1" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Insertion Sort" << endl;
	cout << "4. Selection Sort" << endl;
	cout << "5. Interchange Sort" << endl;
	cout << "6. Bubble Sort" << endl;
	cout << "7. Quick Sort" << endl;
	cout << "8. Heap Sort" << endl;
	cout << "9. Thoat" << endl;
	do
	{
		cout << "Chon so : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "nhap so phan tu: ";
			cin >> n;
			in(a, n);
			cout << "nhap thanh cong" << endl;
			break;
		case 2:
			cout << "xuat danh sach: " << endl;
			out(a, n);
			break;
		case 3:
			cout << "Insertion Sort" << endl;
			InsertionSort(a, n);
			cout << "danh sach sau khi sap xep: " << endl;
			out(a, n);
			break;
		case 4:
			cout << "Selection Sort" << endl;
			SelectionSort(a, n);
			cout << "danh sach sau khi sap xep: " << endl;
			out(a, n);
			break;
		case 5:
			cout << "Interchange Sort" << endl;
			InterchangeSort(a, n);
			cout << "danh sach sau khi sap xep: " << endl;
			out(a, n);
			break;
		case 6:
			cout << "Bubble Sort" << endl;
			BubbleSort(a, n);
			cout << "danh sach sau khi sap xep: " << endl;
			out(a, n);
			break;
		case 7:
			cout << "Quick Sort" << endl;
			QuickSort(a, 0, n - 1);
			cout << "danh sach sau khi sap xep: " << endl;
			out(a, n);
			break;
		case 8:
			cout << "Heap Sort" << endl;
			HeapSort(a, n);
			cout << "danh sach sau khi sap xep: " << endl;
			out(a, n);
			break;
		case 9:
			cout << "Good bye!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 9);
	system("pause");
	return 0;
}