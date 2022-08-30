#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int value;
	Node* next;
};
void init(Node*& head)
{
	head = NULL;
}
Node* createNode(int x)
{
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}
void output(Node* head)
{
	Node* p = head;
	while (p != NULL)
	{
		cout << p->value;
		if (p->next != NULL)
			cout << " ----> ";
		p = p->next;
	}
}
int deleteFirst(Node*& head)
{
	if (head != NULL)
	{
		Node* p = head;
		head = p->next;
		p->next = NULL;
		delete(p);
		return 1;
	}
	return 0;

}
int deleteLast(Node*& head)
{
	if (head != NULL)
	{
		Node* last = head;
		Node* prev = NULL;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		if (prev == NULL) //ds chi co 1 phan tu
			deleteFirst(head);
		else
		{
			prev->next = NULL;
			delete(last);
		}
		return 1;
	}
	return 0;
}
void add(Node*& head, int v)
{
	Node* p = head;
	Node* q = createNode(v);
	if (p == NULL)
	{
		head = q;
		return;
	}
	if (p != NULL && p->next == NULL)
	{
		p->next = q;
		return;
	}
		
	if (p->value < p->next->value) //tang dan
	{
		if (v < p->value)
		{
			q->next = p;
			head = q;
			return;
		}
		while (p->next != NULL && v > p->next->value)
			p = p->next;
		if ( p->next != NULL || (p->next == NULL && v > p->value))
		{
			q->next = p->next;
			p->next = q;
		}
	}
	else {
		if (v > p->value)
		{
			q->next = p;
			head = q;
			return;
		}
		while (p->next != NULL && v < p->next->value)
			p = p->next;
		if (p->next != NULL || (p->next == NULL && v < p->value))
		{
			q->next = p->next;
			p->next = q;
		}
	}
}
Node* search(Node* head, int x)
{
	Node* p = head;
	while (p != NULL && p->value != x)
		p = p->next;
	return p;
}
int SearchAndDelete(Node*& head, int x)
{
	if (head != NULL)
	{
		Node* q = head;
		Node* p = head;
		while (p->value != x && p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		if (p != head && p->next != NULL)
		{
			//ptu o giua
			q->next = p->next;
			delete p;
			return 1;
		}
		else if (p == head && p->value == x)
		{
			deleteFirst(head);
			return 1;
		}
		else if (p->next == NULL && p->value == x)
		{
			//ptu cuoi danh sach
			q->next = NULL;
			delete p;
			return 1;
		}
	}
	return 0;
}
int main()
{
	//khoi tao node
	Node* head = NULL;
	int choice, v;
	bool input = false;
	do
	{
		system("cls");
		cout << "------- Bai 4 Chuong 2 ------" << endl
			<< "1. Khoi tao danh sach rong" << endl
			<< "2. Them 1 phan tu vao danh sach" << endl
			<< "3. Xuat danh sach" << endl
			<< "4. Tim mot phan tu trong danh sach" << endl
			<< "5. Tim va xoa 1 phan tu trong danh sach" << endl
			<< "6. Thoat" << endl
			<< "Chon so: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(head);
			input = true;
			cout << "Khoi tao thanh cong" << endl;
			break;
		case 2:
			if (input)
			{
				cout << "Nhap gia tri phan tu ban muon them: ";
				cin >> v;
				add(head, v);
				output(head);
			}
			else
				cout << "Vui long khoi tao danh sach!" << endl;
			break;
		case 3:
			if (input)
			{
				output(head);
			}
			else
				cout << "Vui long khoi tao danh sach!" << endl;
			break;
		case 4:
			if (input)
			{
				cout << "Nhap gia tri can tim: ";
				cin >> v;
				Node* p = search(head, v);
				if (p != NULL)
					cout << "Dia chi cua gia tri x: " << p << endl;
				else
					cout << "Khong ton tai x trong danh sach" << endl;
			}
			else
				cout << "Vui long khoi tao danh sach!" << endl;
			break;
		case 5:
			if (input)
			{
				cout << "Nhap gia tri can tim va xoa: ";
				cin >> v;
				int i = SearchAndDelete(head, v);
				if (i == 1)
					output(head);
				else
					cout << "Khong tim thay v!" << endl;
			}
			else cout << "Vui long khoi tao danh sach!" << endl;
			break;
		default:
			cout << "Chao tam biet!" << endl;
			break;
		}
		_getch();
	} while (choice >= 1 && choice <= 5);
	return 0;
}