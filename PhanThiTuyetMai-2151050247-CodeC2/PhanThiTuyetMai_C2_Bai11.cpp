#include<iostream>
#include<stdio.h>
using namespace std;
//Khai báo cấu trúc Queue
struct Node
{
	int info;
	Node* link;
};
Node *front, *rear;
//Khỏi tạo queue rỗng
void init()
{
	front = NULL;
	rear = NULL;
}
//Kiểm tra queue rỗng
int isEmpty()
{
	if (front == NULL && rear == NULL)
		return 1;
	return 0;
}
//Thêm phần tử vào queue
int Push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
	return 1;
}
//Lấy ra 1 phần tử từ queue
int pop(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//Xuất stack
void process_queue()
{
	Node* p = front;
	do 
	{
		cout << p->info << " <-- ";
		p = p->link;
	} 
	while (p != NULL);
	cout <<endl;
}
int main()
{
	int choice = 0;
	int sp;
	int x;
	system("cls");
	cout << "----------------BAI 11 CHUONG 2 QUEUE( DSLK) --------------" << endl;
	cout << "1. Khoi tao queue rong" << endl;
	cout << "2. Kiem tra queue rong" << endl;
	cout << "3. Them mot phan tu vao queue" << endl;
	cout << "4. Lay mot phan tu ra khoi queue" << endl;
	cout << "5. Ket thuc chuong trinh" << endl;
	do {
		cout << "Vui long chon Menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao Queue thanh cong !!!" << endl;
			break;
		case 2:
			if (isEmpty() == 1)
				cout << "Queue rong" << endl;
			else
				cout << "Queue khong rong" << endl;
			break;
		case 3:
			cout << "Nhap gia tri can them vao Queue x = ";
			cin >> x;
			Push(x);
			cout << "Queue sau khi duoc them la: ";
			process_queue();
			break;
		case 4:
			pop(x);
			cout << "Phan tu duoc lay ra khoi Queue la: " << x << endl;
			cout << "Queue sau khi duoc ra la: ";
			process_queue();
			break;
		case 5:
			cout << "Chuong trinh ket thuc!!" << endl;
			break;
		default:
			break;
		}
	}
	while (choice!=5);
	system("pause");
	return 0;
}