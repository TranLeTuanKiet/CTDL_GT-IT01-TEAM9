#include<iostream>
using namespace std;


//Khai báo cấu trúc stack
#define MAX 100

//Khởi tạo stack rỗng
void init(int a[], int& sp)
{
	sp = -1;
}

//Kiểm tra stack rỗng
int ktRong(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

//Kiểm tra stack đầy
int ktDay(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}

//Thêm một phần tử vào stack
int themPhanTu(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

//Lấy một phần tử trong stack
int layPhanTu(int a[], int& sp, int& x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

//Xuất stack
void process_stack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
		cout << a[i] << " <-- ";
	cout << endl;
}
int main()
{
	int choice = 0;
	int a[MAX];
	int sp;
	int x;
	system("cls");
	cout << "--------------------------------- BT 5: STACK DAC ---------------------------------" << endl;
	cout << "1. Khoi tao stack rong" << endl;
	cout << "2. Kiem tra stack rong" << endl;
	cout << "3. Kiem tra stack day" << endl;
	cout << "4. Them mot phan tu vao stack" << endl;
	cout << "5. Lay mot phan tu ra khoi stack" << endl;
	cout << "6. Thoat" << endl;

	do {
		cout << "Vui long chon Menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, sp);
			cout << "Ban vua khoi tao thanh cong stack" << endl;
			break;
		case 2:
			if (ktRong(a, sp) == 1)
				cout << "Stack rong" << endl;
			else
				cout << "Stack da co phan tu" << endl;
			break;
		case 3:
			if (ktDay(a, sp) == 1)
				cout << "Stack day" << endl;
			else
				cout << "Stack chua day" << endl;
			break;
		case 4:
			cout << "Nhap gia tri can them vao stack x = ";
			cin >> x;
			themPhanTu(a, sp, x);
			cout << "Stack sau khi them la: ";
			process_stack(a, sp);
			break;
		case 5:
			layPhanTu(a, sp, x);
			cout << "Phan tu duoc lay ra khoi stack la: " << x << endl;
			cout << "Stack sau khi duoc ra la: ";
			process_stack(a, sp);
			break;
		case 6:
			cout << "Ket thuc chuong trinh" << endl;
			break;
		default:
			break;
		}
		system("pause");

	} while (choice >= 1 && choice <= 5);
	return 0;
}