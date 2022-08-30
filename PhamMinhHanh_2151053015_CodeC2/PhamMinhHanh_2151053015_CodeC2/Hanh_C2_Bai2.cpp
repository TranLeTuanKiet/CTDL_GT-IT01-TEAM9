#include<iostream>
using namespace std;


struct Node
{
	int data;
	Node* next;
};
Node* first;

struct SingleList
{
	Node* pHead;
};
void Initialize(SingleList*& list)
{
	list = new SingleList;
	list->pHead = NULL;
}
//1

void init() //ham khoi dong
{
	first = NULL;
}

void Nhap(int& x)
{
	cout << "Nhap so nguyen: ";
	cin >> x;
}

void createNode(int x)
{
	Node* p = new Node;
	p->data = x;
	p->next = NULL;
}

//2
void process_list()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

//3
Node* search(int x)
{
	Node* p = first;
	while ((p != NULL) && (p->data != x))
		p = p->next;
	return p;
}

//4
void insert_first(int x)
{
	Node* p;
	p = new Node;
	p->data = x;
	p->next = first;
	first = p;
}

//5
int delete_first()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->next;
		delete p;
		return 1;
	}
	return 0;
}

//6
void insert_last(int x)
{
	Node* p;
	p = new Node;
	p->data = x;
	p->next = NULL;
	if (first == NULL) //khong co phan tu cuoi cung
		first = p;
	else
	{
		Node* q = first;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}

//7
int delete_last()
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = NULL;
		if (p != NULL)
			while (p->next != NULL)
			{
				q = p;
				p = p->next;
			}
		if (p != first) //p tu dau thi khong ton tai q
			q->next = NULL;
		else first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//8
void Seach_Delete(int x)
{
	if (first != NULL)
	{
		Node* p = first;
		Node* q = NULL;
		while (p != NULL && p->data != x)
		{
			q = p;
			p = p->next;
		}
		if (p != NULL)
		{
			if (q == NULL)
				delete_first();
			else
			{
				q->next = p->next;
				p->next = NULL;
				delete p;
			}
		}
	}
}

//9
void SortList(SingleList*& list)
{
	for (Node* pTmp = list->pHead; pTmp != NULL; pTmp = pTmp->next)
	{
		for (Node* pTmp2 = pTmp->next; pTmp2 != NULL; pTmp2 = pTmp2->next)
		{
			if (pTmp->data > pTmp2->data)
			{
				int tmp = pTmp->data;
				pTmp->data = pTmp2->data;
				pTmp2->data = tmp;
			}
		}
	}
}
int main()
{
	SingleList* list;
	Initialize(list);
	int choice = 0;
	int x;
	do {
		system("cls");
		cout << "-----------------------------------------MENU-----------------------------------------" << endl;
		cout << "1. Khoi tao danh sach rong " << endl;
		cout << "2. Xuat cac phan tu trong danh sach " << endl;
		cout << "3. Tim 1 phan tu trong danh sach " << endl;
		cout << "4. Them 1 phan tu vao dau danh sach " << endl;
		cout << "5. Xoa 1 phan tu dau danh sach " << endl;
		cout << "6. Them 1 phan tu vao cuoi danh sach " << endl;
		cout << "7. Xoa 1 phan tu cuoi danh sach " << endl;
		cout << "8. Tim 1 phan tu trong danh sach. Neu tim thay, hay xoa phan tu nay " << endl;
		cout << "9. Sap xep danh sach " << endl;
		cout << "10. Ket thuc chuong trinh " << endl;
		do {
			cout << "Chon: ";
			cin >> choice;
			if (choice < 1 || choice > 10) cout << "Loi gia tri, vui long nhap lai" << endl;
		} while (choice < 1 || choice > 10);
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong" << endl;
			break;
		case 2:
			cout << "Xuat cac phan tu trong danh sach" << endl;
			process_list();
			break;
		case 3:
			Nhap(x);
			if (search(x) != NULL)
				cout << x << " co xuat hien trong danh sach" << search(x) << endl;
			else
				cout << x << " khong xuat hien trong danh sach" << endl;
			break;
		case 4:
			Nhap(x);
			insert_first(x);
			cout << "Them 1 phan tu vao dau danh sach thanh cong" << endl;
			break;
		case 5:
			if (delete_first() != 0)
				cout << "Xoa gia tri dau thanh cong" << endl;
			else
				cout << "Xoa gia tri dau khong thanh cong" << endl;
			break;
		case 6:
			Nhap(x);
			insert_last(x);
			cout << "Them 1 phan tu vao cuoi danh sach thanh cong" << endl;
			break;
		case 7:
			if (delete_last() != 0)
				cout << "Xoa gia tri cuoi thanh cong" << endl;
			else
				cout << "Xoa gia tri cuoi khong thanh cong" << endl;
			break;
		case 8:
			Nhap(x);
			Seach_Delete(x);
			cout << "Tim va xoa phan tu trong danh sach thanh cong" << endl;
			break;
		case 9:
			SortList(list);
			cout << "Sap xep danh sach tang dan thanh cong" << endl;
			break;
		case 10:
			break;
		}
		system("pause");
	} while (choice >= 1 && choice <= 9);
	return 0;
}
