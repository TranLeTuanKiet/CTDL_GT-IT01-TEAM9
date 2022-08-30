#include<iostream>
using namespace std;

//4.1 khai báo cấu trúc danh sách
struct Node {
	int info;
	Node* link;
};
Node* first;

//4.2 Khởi tạo danh sách rỗng
void init()
{
	first = NULL;
}
struct SingleList
{
	Node* pHead;
};
void Initialize(SingleList*& list)
{
	list = new SingleList;
	list->pHead = NULL;
}

//4.3 Thêm một phần tử vào danh sách
void Insert_first(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

//4.4 Viết thủ tục xuất các phần tử trong danh sách
void Process_List()
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

//Sắp xếp danh sách
void SortList(SingleList*& list)
{
	for (Node* pTmp = list->pHead; pTmp != NULL; pTmp = pTmp->link)
	{
		for (Node* pTmp2 = pTmp->link; pTmp2 != NULL; pTmp2 = pTmp2->link)
		{
			if (pTmp->info > pTmp2->info)
			{
				int tmp = pTmp->info;
				pTmp->info = pTmp2->info;
				pTmp2->info = tmp;
			}
		}
	}
}

//4.5 Viết thủ tục tìm một phần tử trong danh sách
Node* Search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

//4.6 Viết thủ tục tìm một phần tử trong danh sách và xóa nếu tìm thấy phần tử đó
int SearchAndDelete(int x)
{
	if (first != NULL)
	{
		Node* p, * q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			//Phần tử giữa danh sách
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
		}
		else
			if (p == first)
			{
				//Phần tử đầu danh sách
				first = p->link;
				delete p;
			}
			else
				if (p->link == NULL && p->info == x)
				{
					//Phần tử cuối danh sách
					q->link = NULL;
					delete p;
				}
		return 1;
	}
	return 0;
}

int main()
{
	SingleList* list;
	Initialize(list);
	int choice = 0;
	int x, i;
	Node* p;
	system("cls");
	cout << "---------------------------- Bai Tap 4, Chuong 2 - DSLK DON ----------------------------" << endl;
	cout << "1. Khoi tao danh sach lien ket don rong" << endl;
	cout << "2. Them phan tu vao dau danh sach" << endl;
	cout << "3. Xuat danh sach lien ket don" << endl;
	cout << "4. Tim phan tu trong danh sach" << endl;
	cout << "5. Tim phan tu va xoa phan tu do neu co trong danh sach " << endl;
	cout << "6. Thoat chuong trinh " << endl;

	do {
		cout << "Vui long chon Menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao thanh cong danh sach lien ket don" << endl;
			break;
		case 2:
			cout << "Vui long nhap x: ";
			cin >> x;
			Insert_first(x);
			cout << "Sau khi them dau danh sach voi gia tri x = " << x << " la: ";
			Process_List();
			break;
		case 3:
			cout << "Danh sach lien ket hien tai la: " << endl;
			Process_List();
			break;
		case 4:
			SortList(list);
			cout << "Cap nhat danh sach: ";
			Process_List();
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			p = Search(x);
			if (p == NULL)
				cout << "Khong tim thay x = " << x << " trong danh sach lien ket don" << endl;
			else
				cout << "Tim thay x = " << x << " trong danh sach lien ket don" << endl;
			break;
		case 5:
			SortList(list);
			cout << "Cap nhat danh sach: ";
			Process_List();
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			i = SearchAndDelete(x);
			if (i == 0)
				cout << "Khong tim thay x = " << x << " trong danh sach lien ket don" << endl;
			else
			{
				cout << "Tim thay x = " << x << " trong danh sach lien ket don" << endl;
				cout << "Danh sach sau khi xoa la: " << endl;
				Process_List();
			}
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