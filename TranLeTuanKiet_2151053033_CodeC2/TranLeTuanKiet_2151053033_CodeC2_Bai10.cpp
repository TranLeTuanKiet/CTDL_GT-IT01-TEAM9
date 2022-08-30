#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int value;
	Node* next;
};
void init(Node *&sp)
{
	sp = NULL;
}
Node* createNode(int x)
{
	Node* p = new Node;
	p->next = NULL;
	p->value = x;
	return p;
}
int isEmpty(Node* sp)
{
	if (sp == NULL)
		return 1;
	return 0;
}
int Push(Node *&sp, int x)
{
	Node* p = createNode(x);
	p->next = sp;
	sp = p;
	return 1;
}
int Pop(Node *&sp, int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->value;
		sp = p->next;
		delete p;
		return 1;
	}
	return 0;
}
void output(Node* sp)
{
	Node* p = sp;
	while (p != NULL)
	{
		cout << p->value << " <-- ";
		p = p->next;
	}
}
int main()
{
	Node* sp = NULL;
	int choice, i, x;
	bool in = false;
	do
	{
		system("cls");
		cout << "-------- Bai 10 chuong 2 - STACK&DSLK  -------- " << endl
			<< "1. Khoi tao danh sach" << endl
			<< "2. Kiem tra danh sach rong" << endl
			<< "3. Them mot phan tu vao " << endl
			<< "4. Xoa mot phan tu trong " << endl
			<< "5. Xuat danh sach " << endl
			<< "6. Thoat" << endl
			<< "Vui long chon so thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(sp);
			in = true;
			cout << "Khoi tao danh sach thanh cong!" << endl;
			break;
		case 2:
			if (in)
			{
				i = isEmpty(sp);
				if (i == 1)
					cout << "Danh sach rong" << endl;
				else
					cout << "Danh sach da co phan tu" << endl;
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		case 3:
			if (in)
			{
				cout << "Nhap vao gia tri muon them: ";
				cin >> x;
				i = Push(sp, x);
				if (i == 1)
				{
					cout << "Them x vao danh sach thanh cong" << endl;
					output(sp);
				}
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		case 4:
			if (in)
			{
				i = Pop(sp, x);
				if (i == 1)
					cout << "Xoa 1 phan tu thanh cong, trong do x = " << x << endl;
				else
					cout << "Danh sach rong!" << endl;
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		case 5:
			if (in)
			{
				output(sp);
			}
			else cout << "Vui long khoi tao danh sach truoc!" << endl;
			break;
		default:
			cout << "CHAO TAM BIET!" << endl;
			break;
		}
		_getch();
	} while (choice >= 1 && choice <= 5);
	return 0;
}