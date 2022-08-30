#include<iostream>
#include<stdio.h>
#include<ctime>
using namespace std;
#define MAX 5000
//1.1 Khai bao cau truc danh sach 
int a[MAX];
int n;
//1.2 Nhap danh sach
void input(int a[], int& n)
{
	cout<<"Nhap so luong phan tu cua danh sach: ";
	cin>>n;
	cout<<"Nhap cac phan tu cua danh sach: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}
//1.2 Nhap danh sach tu dong
void init(int a[], int& n)
{
	cout<<"Nhap so luong phan tu cua danh sach: ";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		a[i]=rand()% 10000+1;
	}
	cout<<"Danh sach them vao ngau nhien la: "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<< " ";
	}
}
//1.3 Xuat danh sach
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<< " ";
	}
	cout<<endl;
}
//Copy array
void CoppyArray(int a[], int b[], int n)
{
	for(int i = 0; i < n; i++)
	{
		b[i]=a[i];
	}
}
//Swap
void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}
//1.4 Insertion Sort
void InsertionSort(int a[], int n)
{
	int i, key, j;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}

}
//1.5 Selection Sort
void SelectionSort(int a[], int n)
{
	int i, j, min_pos;
	for(i = 0; i < n-1; i++)
	{
		min_pos=i;
		for(j = i + 1; j < n; j++)
			if(a[j]<a[min_pos])
			{
				min_pos=j;
			}
			swap(a[i], a[min_pos]);
	}
}
//1.6 Interchange Sort
void InterchangeSort(int a[], int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = i + 1 ; j < n; j++)
			if(a[i] > a[j])
				swap(a[i],a[j]);			
}
//1.7 Bubble Sort
void BubbleSort(int a[], int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = n - 1 ; j > i; j--)
			if(a[j-1] > a[j])
				swap(a[j],a[j-1]);	
}
//1.8 Quick Sort
void QuickSort(int a[], int l, int r)
{
	int x=a[(l+r)/2];
	int i=l;
	int j=r;
	while(i<j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if(l<j)
		QuickSort(a,l,j);
	if(i<r)
		QuickSort(a,i,r);
}
//1.9 Heap Sort
void shift(int a[], int i, int n)
{
	int j=2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
		shift(a,j,n);
	}
}
void HeapSort(int a[], int n)
{
	int i=(n/2)-1;
	while(i>=0)
	{
		shift(a,i,n);
		i--;
	}
	int r=n-1;
	while(r>0)
	{
		swap(a[0],a[r]);
		r--;
		if(r>0)
			shift(a,0,r);
	}
}
//1.10 Tim kiem tuan tu
int searchSequence(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i]!=x){
		i++;
	}
	if(i==n){
		cout<<"Khong tim thay";
	}else{
		cout<<"Tim thay tai vi tri "<<i;
	}
  return -1;
}
//1.11 Tim kiem nhi phan
int searchBinary(int a[], int l, int r, int x){
	if(r>=l){
		int mid=l+(r-1)/2;// Tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn
		//Nếu a[mid]=x, trả về chỉ số và kết thúc.
		if(a[mid]==x)
			return mid;
		//Nếu a[mid]>x, thực hiện tìm kiếm nửa trái của mảng
		if(a[mid]>x)
			return searchBinary(a, l, mid-1, x);
		//Nếu a[mid]<x, thực hiện tìm kiếm nửa phải của mảng
		return searchBinary(a, l, mid+1, x);
	}
	// Nếu không tìm thấy
	return -1;
}

int main()
{
	int x,i, choice;
	int b[MAX];
	clock_t start;
	double duration;
	system("cls");
	cout<<"=====BAI TAP 1 CHUONG 3======"<<endl;
	cout<<"0.Khoi tao danh sach ngau nhien "<<endl;
	cout<<"1. Nhap danh sach cac phan tu "<<endl;
	cout<<"2. Xuat danh sach cac phan tu "<<endl;
	cout<<"3. Xep thu tu Selection Sort"<<endl;
	cout<<"4. Xep thu tu Insertion Sort"<<endl;
	cout<<"5. Xep thu tu Bubble Sort"<<endl;
	cout<<"6. Xep thu tu Interchange Sort"<<endl;
	cout<<"7. Xep thu tu Quick Sort"<<endl;
	cout<<"8. Xep thu tu Heap Sort"<<endl;
	cout<<"9. Danh sach tim kiem x tuan tu"<<endl;
	cout<<"10.Danh sach tim kiem x nhi phan"<<endl;
	cout<<"11. Thoat"<<endl;
	
	do{
		cout<<"\n Vui long lua chon lenh de thuc hien:";
		cin>>choice;
		switch (choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a,n);
			break;
		case 2:
			cout<<"Danh sach dang co la: "<<endl;
			output(a, n);
			break;
		case 3:
			CoppyArray(a, b, n);
			start=clock();
			SelectionSort(b,n);
			duration=(clock()-start)/ (double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi sap xep voi SELECTION SORT la"<<endl;
				output(b,n);
			}
			if(duration > 0)
			{
				cout<<"Thoi gian SELECTION SORT la "<<duration * 1000000<<"Miliseconds"<<endl;
			}
			break;
		case 4:
			CoppyArray(a,b,n);
			start=clock();
			InsertionSort(b,n);
			duration=(clock()-start)/ (double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi sap xep voi INSERTION SORT la"<<endl;
				output(b,n);
			}
			if(duration > 0)
			{
				cout<<"Thoi gian INSERTION SORT la "<<duration * 1000000<<"Miliseconds"<<endl;
			}
			break;
		case 5:
			CoppyArray(a,b,n);
			start=clock();
			BubbleSort(b,n);
			duration=(clock()-start)/ (double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi sap xep voi BUBBLE SORT la"<<endl;
				output(b,n);
			}
			if(duration > 0)
			{
				cout<<"Thoi gian BUBBLE SORT la "<<duration * 1000000<<"Miliseconds"<<endl;
			}
			break;
		case 6:
			CoppyArray(a,b,n);
			start=clock();
			InterchangeSort(b,n);
			duration=(clock()-start)/ (double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi sap xep voi INTERCHANGE SORT la"<<endl;
				output(b,n);
			}
			if(duration > 0)
			{
				cout<<"Thoi gian INTERHANGE SORT la "<<duration * 1000000<<"Miliseconds"<<endl;
			}
			break;
		case 7:
			CoppyArray(a,b,n);
			start=clock();
			QuickSort(b, 0, n-1);
			duration=(clock()-start)/ (double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi sap xep voi QUICK SORT la"<<endl;
				output(b,n);
			}
			if(duration > 0)
			{
				cout<<"Thoi gian QUICK SORT la "<<duration * 1000000<<"Miliseconds"<<endl;
			}
			break;
		case 8:
			CoppyArray(a,b,n);
			start=clock();
			HeapSort(b,n);
			duration=(clock()-start)/ (double)CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi sap xep voi HEAP SORT la"<<endl;
				output(b,n);
			}
			if(duration > 0)
			{
				cout<<"Thoi gian HEAP SORT la "<<duration * 1000000<<"Miliseconds"<<endl;
			}
			break;
		case 9:
			cout<<"Vui long nhap gia tri x=";
			cin>>x;
			start=clock();
			searchSequence(a, n, x);
			duration=(clock()-start)/ (double)CLOCKS_PER_SEC;
			if(duration > 0)
			{
				cout<<"\n-Thoi gian tim kiem tuan tu la "<<duration * 1000000<<"Miliseconds"<<endl;
			}
			break;
		case 10:
			cout<<"Vui long nhap gia tri x=";
			cin>>x;
			start=clock();
			i=searchBinary(b, 0, n, x);
			duration=(clock()-start)/ (double)CLOCKS_PER_SEC;
			if(i==-1)
				cout<<"Khong tim thay x="<<x<<" trong day!"<<endl;
			else
				cout<<"Tim thay x="<<x<<"tai vi tri i="<<i<<endl;
			if(duration > 0)
			{
				cout<<"\n-Thoi gian tim kiem tuan tu la "<<duration * 1000000<<"Miliseconds"<<endl;
			}
			break;
		case 11:
			cout<<"Ket thuc chuong trinh"<<endl;
			break;
		default:
			break;
		}
	}while(choice!=11);
	system("pause");
	return 0;
}