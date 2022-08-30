#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
using namespace std;
#define MAX 20
struct Node {
	int value;
	Node* next;
};
Node* sp;
Node* front, * rear;
Node* First[MAX]; // DS cac DSK
int n;
char vertex[MAX];
void initStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node* p = new Node;
	p->value = x;
	p->next = sp;
	sp = p;
}
int PopS(int& x)
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

void initQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if (front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->next = p;
	rear = p;
}
int PopQ(int& x)
{
	if (front != NULL)
	{
		Node* p = front;
		front = p->next;
		x = p->value;
		if (front == NULL)
		{
			rear = NULL;
		}
		return 1;
	}
	return 0;
}
void initGraph()
{
	n = 0;
}
void InsertLast(Node*& first, Node* p)
{
	if (first == NULL)
		first = p;
	else
	{
		Node* q = first;
		while (q->next != NULL)
			q = q->next;
		q->next = p;
	}
}
void inputGraph()
{
	cout << "Nhap so dinh so thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n;i++)
		cin >> vertex[i];
	for (int i = 0; i < n + 1 ;i++)
	{
		if (i > 0)
			cout << "Nhap DSK cua dinh thu " << i - 1 << " (" << vertex[i - 1] << ") : ";
		int u;
		string str;
		while (getline(cin, str))
		{
			istringstream ss(str);
			while (ss >> u)
			{
				Node* p = new Node;
				p->value = u;
				p->next = NULL;
				InsertLast(First[i-1], p);
				//cout << u << "-";
			}
			//cout << "i=" << i-1 << endl;
			break;
		}
	}
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("dsk1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while (getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while (ss >> u)
			{
				//Dinh u
				Node* p = new Node;
				p->value = u;
				p->next = NULL;
				InsertLast(First[i], p);
			}
			i++;
		}
	}
}
void outputGraph()
{

	for (int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		Node* p = First[i];
		while (p != NULL)
		{
			cout << p->value << "	";
			p = p->next;
		}
		cout << endl;
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n;i++)
		cout << vertex[a[i]] << "	";
}
//Duyet BFS
int c[100], bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n;i++) // n la so dinh cua do thi
		c[i] = 1;
}
void BFS(int v)
{
	int p;
	Node* w;
	PushQ(v);
	c[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs++;
		while (w != NULL)
		{
			if (c[w->value])
			{
				PushQ(w->value);
				c[w->value] = 0;
			}
			w = w->next;
		}
	}
}
//DFS
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int u = s;
	Node* v = NULL;
	while (isEmptyS() == 0)
	{
		if (v == NULL)
			PopS(u);
		v = First[u];
		while (v != NULL)
		{
			if (c[v->value] == 1)
			{
				PushS(u);
				PushS(v->value);
				dfs[ndfs] = v->value;
				ndfs++;
				c[v->value] = 0;
				u = v->value;
				break;
			}
			v = v->next;
		}
	}
}
//Tim theo BFS
void Search_by_BFS(int x, int v)
{
	int p;
	Node* w;
	PushQ(v);
	c[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		w = First[p];
		while (w != NULL)
		{
			if (c[w->value])
			{
				PushQ(w->value);
				c[w->value] = 0;
			}
			w = w->next;
		}
	}
}
int main()
{
	int a[MAX], b[MAX];
	int choice, x, i;
	do
	{

		system("cls");
		cout << "---------- BAI TAP 5 CHUONG 5 DO THI --------" << endl
			<< "1. Khoi tao DANH SACH KE rong" << endl
			<< "2. Nhap DANH SACH KE tu file text" << endl
			<< "3. Nhap DANH SACH KE " << endl
			<< "4. Xuat DANH SACH KE " << endl
			<< "5. Duyet do thi theo chieu rong BFS - DSLK " << endl
			<< "6. Duyet do thi theo chieu sau DFS - DSLK" << endl
			<< "7. Tim dinh co gia tri x theo BFS" << endl
			<< "8. Thoat" << endl
			<< "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			initGraph();
			cout << "Khoi tao DSK rong thanh cong!" << endl;
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap DSK tu file: " << endl;
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			initQueue();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS: " << endl;
			output(bfs, n);
			break;
		case 6:
			initStack();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(dfs, n);
			break;
		case 7:
			initQueue();
			initC();
			nbfs = 0;
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			Search_by_BFS(x, 0);
			break;
		default:
			cout << "Chao tam biet!" << endl;
			break;
		}
		_getch();
	} while (choice >= 1 && choice <= 7);
	return 0;
}