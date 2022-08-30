#include <iostream>
#include <stdio.h>
#include <ctime>
#include <time.h>
using namespace std;
#define MAX 5000
int a[MAX];
int n;
void input(int a[], int &n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	cout << endl;
	cout << "Vui long nhap cac phan tu trong mang:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a["<<i<<"]: ";
		cin >> a[i];
	}
}
void init(int a[], int& n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10000 + 1;
	}
	cout << "Danh sach them vao ngau nhien la: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void output(int a[], int n)
{
	cout << "Mang da nhap la: " << endl;
	for (int i=0; i<n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void Copyarray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
void InsertionSort(int a[], int n) //line 51 j=i-1
{
	int x, i, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i-1;
		while(0 <= j && x < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void swap(int& a, int& b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void SelectionSort(int a[], int n)
{
	int min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n)
		return;
	if (j+1 < n)
		if (a[j] < a[j+1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}
void HeapSort(int a[], int n)// line 136 i = n/2;
{
	int i = (n / 2) - 1;
	while (i >= 0)
	{
		shift(a, i, n);
		i--;
	}
	int right= n - 1;
	while (right>0)
	{
		swap(a[0], a[right]);
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}
int Search(int a[], int n, int X)
{
	int i = 0;
	while (i < n && a[i] != X)
		i++;
	if (i < n)
		return i; // x trong danh sách a, và nằm ở vị trí i
	return -1; // không tìm thấy x trong danh sách a;
}
void searchSequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		cout << "Khong tim thay";
	else
		cout << "Tim thay tai vi tri" << i;
}
int BinarySearch(int a[], int n, int X)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == X)
			return mid;
		if (X > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1; // không tìm thấy x trong danh sách a;
}
int searchBinary(int a[], int l, int r, int x)
{
	if (r >= 1)
	{
		int mid = l + (r - 1) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return searchBinary(a, l, mid - 1, x);
		return searchBinary(a, mid + 1, r, x);
	}
	return -1;
}
int main()
{
	int b [MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	system("cls");
	cout << "---BAI TAP 1 CHUONG 3---" << endl;
	cout << "0. Khoi tao danh sach ngau nhien" << endl;
	cout << "1. Nhap danh sach tu ban phim" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Thuc hien Insertion Sort" << endl;
	cout << "4. Thuc hien Selection Sort" << endl;
	cout << "5. Thuc hien Interchange Sort" << endl;
	cout << "6. Thuc hien Bubble Sort" << endl;
	cout << "7. Thuc hien Quick Sort" << endl;
	cout << "8. Thuc hien Heap Sort" << endl;
	cout << "9. Thuc hien tim x theo searhcSequenece" << endl;
	cout << "10. Thuc hien tim x theo searchBinary" << endl;
	cout << "11. Thoat" << endl;
	do
	{
		cout << "\nVui long chon lenh thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			output(a, n);
			break;
		case 3:
			Copyarray(a, b, n);
			start = clock();
			InsertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep: " << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian selection sort la: " << duration * 1000000 << "miliseconds" << endl;
			}
			break;
		case 4:
			Copyarray(a, b, n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep: " << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian selection sort la: " << duration * 1000000 << "miliseconds" << endl;
			}
			break;
		case 5:
			Copyarray(a, b, n);
			start = clock();
			InterchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep: " << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian selection sort la: " << duration * 1000000 << "miliseconds" << endl;
			}
			break;
		case 6:
			Copyarray(a, b, n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep: " << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian selection sort la: " << duration * 1000000 << "miliseconds" << endl;
			}
			break;
		case 7:
			Copyarray(a, b, n);
			start = clock();
			QuickSort(b, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep: " << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian selection sort la: " << duration * 1000000 << "miliseconds" << endl;
			}
			break;
		case 8:
			Copyarray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi sap xep: " << endl;
				output(b, n);
			}
			if (duration > 0)
			{
				cout << "Thoi gian selection sort la: " << duration * 1000000 << "miliseconds" << endl;
			}
			break;
		case 9:
			cout << "Vui long nhap gia tri x: ";
			cin >> x;
			start = clock();
			searchSequence(a, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
			{
				cout << "Thoi gian tim kiem tuan tu la: " << duration * 1000000 << "miliseconds" << endl;
			}
			break;
		case 10:
			cout << "Vui long nhap gia tri x: ";
			cin >> x;
			start = clock();
			Copyarray(a, b, n);
			i = searchBinary(b, 0, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x= " << x << " trong day" << endl;
			else
				cout << "Tim thay x= " << x << " tai vi tri i= " << i << endl;
			if (duration > 0)
			{
				cout << "Thoi gian tim kiem nhi phan la: " << duration * 1000000 << "miliseconds" << endl;
			}
			break;
		case 11:
			cout << "BYE" << endl;
			break;
		default:
			break;
		}
	}while (choice != 11);
	system("pause");
	return 0;
}