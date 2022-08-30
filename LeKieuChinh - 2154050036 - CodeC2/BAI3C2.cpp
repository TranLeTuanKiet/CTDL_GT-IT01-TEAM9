// DSLK DON // SO PHAN TU KHA LON
#include <iostream>
#include <stdio.h>
using namespace std;
//3.1
struct Node
{
	int info;
	Node* link;
};
Node* first;
//3.2
void init()
{
	first = NULL;
}
//3.3
void Process_list()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
//3.4
Node* Search(int x)
{
	Node* p = first;
	while ((p != NULL) && (p->info != x))
		p = p->link;
	return p;
}
//3.5
void Insert_first(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
//3.6
int Delete_first()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
//3.7
void Insert_last(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node* q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
//3.8
int Delete_last()
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = NULL;
		if (p != NULL)
			while (p->link != NULL)
			{
				q = p;
				p = p->link;
			}
		if (p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//3.9
void DeleteX(int x)
{
	if (first != NULL)
	{
		Node* p = first;
		Node* pre = NULL;
		while (p != NULL && p->info != x)
		{
			pre = p;
			p = p->link;
		}
		if (p != NULL)
		{
			if (pre == NULL)
				first = p->link;
			//Delete_first();
			else
			{
				pre->link = p->link;
				p->link = NULL;
				delete(p);
			}
		}
	}
}
void Search_Delte(int x)
{
	Node* p = first;
	while (p != NULL)
	{
		if (p->info == x)
		{
			DeleteX(x);
			break;
		}
		p = p->link;
	}
}
//3.10

int main()
{
	Node* first;
	init();
	int choice = 0;
	int search, inf, inl, x;
	cout << "BAI 3 CHUONG 2\n";
	cout << "1. Khoi tao danh sach rong.\n";
	cout << "2. Xuat cac phan tu trong danh sach\n";
	cout << "3. Tim mot phan tu trong danh sach\n";
	cout << "4. Them mot phan tu vao dau danh sach\n";
	cout << "5. Xoa mot phan tu o dau danh sach\n";
	cout << "6. Them mot phan tu vao cuoi danh sach\n";
	cout << "7. Xoa mot phan tu o cuoi danh sach\n";
	cout << "8. Tim phan tu trong danh sach, neu tim thay thi xoa phan tu do\n";
	cout << "9. Chuyen thanh danh sach co thu tu\n";
	cout << "10. Thoat\n";
	do {
		cout << "Chon so: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Tao danh sach rong thanh cong.\n";
			break;
		case 2:
			Process_list();
			break;
		case 3:
			cout << "Moi ban nhap so muon tim: ";
			cin >> search;
			cout << "Dia chi cua " << search << "la: " << Search(search) << endl;
			break;
		case 4:
			cout << "Ban muon them so may o dau: ";
			cin >> inf;
			Insert_first(inf);
			cout << "Them thanh cong\n";
			break;
		case 5:
			Delete_first();
			cout << "Xoa thanh cong\n";
			break;
		case 6:
			cout << "Ban muon them so may o cuoi: ";
			cin >> inl;
			Insert_last(inl);
			cout << "Them thanh cong\n";
			break;
		case 7:
			Delete_last();
			cout << "Xoa thanh cong\n";
			break;
		case 8:
			cout << "Ban muon tim va xoa so may trong danh sach: ";
			cin >> x;
			Search_Delte(x);
			cout << "Tim va xoa thanh cong\n";
			break;
		default:
			break;
		}
	} while (choice != 10);
	system("pause");
	return 0;
}