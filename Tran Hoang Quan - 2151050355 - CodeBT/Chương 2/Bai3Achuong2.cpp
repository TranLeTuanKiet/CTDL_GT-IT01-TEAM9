#include <stdio.h>
#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node* next, *previous;
};
Node* first, *last;
void init()
{
	first = NULL;
	last = NULL;
}
void Process_list()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info <<"\t";
		p = p->next;
	}
	cout << endl;
}
Node* Search(int x)
{
	Node* p;
	p = first;
	while ((p != NULL) && (p->info != x))
		p = p->next;
	return p;
}
void Insert_first(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
		first->previous = p;
	else
		last = p;
	first = p;
}
int Delete_first()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->next;
		delete p;
		if (first != NULL)
			first->previous = NULL;
		else
			last = NULL;
		return 1;
	}return 0;
}
void Insert_last(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if (last != NULL)
		last->next = p;
	else
		first = p;
	last = p;
}
int Delete_last()
{
	if (last != NULL)
	{
		Node* p = last;
		last = last->previous;
		if (last != NULL)
			last ->next= NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int SearchAndDelete(int x)
{
	Node* p = Search(x);
	if (p != NULL)
	{
		if (p->previous == NULL)
		{
			Delete_first();
			return 1;
		}
		if (p->next == NULL)
		{
			Delete_last();
			return 1;
		}
		p->previous->next = p->next;
		p->next->previous = p->previous;
		p->previous = NULL;
		p->next = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int main1()
{
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "Chuong 2, BT3A" << endl;
	cout << "1. Khoi tao danh sach rong" << endl;
	cout << "2. Them ptu vao dau danh sach" << endl;
	cout << "3. Them ptu vao cuoi danh sach" << endl;
	cout << "4. Xoa ptu o dau danh sach" << endl;
	cout << "5. Xoa ptu o cuoi danh sach" << endl;
	cout << "6. Xuat DSLK don" << endl;
	cout << "7. Tim phan tu gia tri x trong DSLK don" << endl;
	cout << "8. Tim va xoa ptu gia tri x trong DSLK don" << endl;
	cout << "9. Thoat" << endl;
	do
	{
		cout << "chon so thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "khoi tao thanh cong" << endl;
			break;
		case 2:
			cout << "nhap x: ";
			cin >> x;
			Insert_first(x);
			cout << "sau khi them dau danh sach voi x=" << x << " la: ";
			Process_list();
			break;
		case 3:
			cout << "nhap x: ";
			cin >> x;
			Insert_last(x);
			cout << "sau khi them dau danh sach voi x=" << x << " la: ";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if (i == 0)
				cout << "xoa khong thanh cong, danh sach rong" << endl;
			else
			{
				cout << "xoa thanh cong ptu dau danh sach, danh sach sau khi xoa: " << endl;
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if (i == 0)
				cout << "xoa khong thanh cong, danh sach rong" << endl;
			else
			{
				cout << "xoa thanh cong ptu dau danh sach, danh sach sau khi xoa: " << endl;
				Process_list();
			}
			break;
		case 6:
			cout << "DSLK hien tai: " << endl;
			Process_list();
			break;
		case 7:
			cout << "can tim x=";
			cin >> x;
			p = Search(x);
			if (p == NULL)
				cout << "khong tim thay x=" << x << " trong DSLK" << endl;
			else
				cout << "tim thay x=" << x << " trong DSLK" << endl;
			break;
		case 8:
			cout << "can tim x=";
			cin >> x;
			i = SearchAndDelete(x);
			if (i == 0)
				cout << "khong tim thay x=" << x << " trong DSLK" << endl;
			else
			{
				cout << "tim thay x=" << x << " trong DSLK; DS sau khi xoa: " << endl;
				Process_list();
			}
			break;
		case 9:
			cout << "thoat";
			break;
		default:
			break;
		}
	} while (choice < 10);
	return 0;
}
