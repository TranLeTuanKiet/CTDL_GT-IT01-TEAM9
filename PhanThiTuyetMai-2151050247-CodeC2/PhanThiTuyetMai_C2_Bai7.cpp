#include<iostream>
using namespace std;


//Khai báo cấu trúc queue
#define MAX 100

//Khởi tạo queue rỗng
void init(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}

//Kiểm tra queue rỗng
int ktRong(int a[], int front, int rear)
{
	if (front == rear)
		return 1;
	return 0;
}

//Kiểm tra queue đầy
int ktDay(int a[], int front, int rear)
{
	if ((front == 0 && rear == MAX - 1) || (front - rear == 1))
		return 1;
	return 0;
}

//Thêm một phần tử vào queue
int themPhanTu(int a[], int& front, int& rear, int x)
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
}

//Lấy một phần tử trong queue
int layPhanTu(int a[], int& front, int& rear, int& x)
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

//Xuất queue
void process_queue(int a[], int front, int rear)
{
	cout << "front = " << front << " " << "\t rear = " << rear << endl;
	if (front <= rear && front != -1)
	{
		cout << " <-- ";
		for (int i = front; i < rear + 1; i++)
			cout << a[i] << " <-- ";
		cout << endl;
	}
}
int main()
{
	int choice = 0;
	int a[MAX];
	int front;
	int rear;
	int x;
	system("cls");
	cout << "--------------------------------- BT 5: QUEUE DAC ---------------------------------" << endl;
	cout << "1. Khoi tao queue rong" << endl;
	cout << "2. Kiem tra queue rong" << endl;
	cout << "3. Kiem tra queue day" << endl;
	cout << "4. Them mot phan tu vao queue" << endl;
	cout << "5. Lay mot phan tu ra khoi queue" << endl;
	cout << "6. Thoat" << endl;

	do {
		cout << "Vui long chon Menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, front, rear);
			cout << "Ban vua khoi tao thanh cong queue" << endl;
			break;
		case 2:
			if (ktRong(a, front, rear) == 1)
				cout << "Queue rong" << endl;
			else
				cout << "Queue da co phan tu" << endl;
			break;
		case 3:
			if (ktDay(a, front, rear) == 1)
				cout << "Queue day" << endl;
			else
				cout << "Queue chua day" << endl;
			break;
		case 4:
			cout << "Nhap gia tri can them vao Queue x = ";
			cin >> x;
			themPhanTu(a, front, rear, x);
			cout << "Queue sau khi them la: ";
			process_queue(a, front, rear);
			break;
		case 5:
			layPhanTu(a, front, rear, x);
			cout << "Phan tu duoc lay ra khoi queue la: " << x << endl;
			cout << "Queue sau khi duoc ra la: ";
			process_queue(a, front, rear);
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