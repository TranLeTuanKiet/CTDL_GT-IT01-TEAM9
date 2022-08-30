#include <iostream>
#include <conio.h>
#include <fstream>
#define MAX 20
using namespace std;
int a[MAX][MAX];
int n;
char vertex[MAX];
struct Node {
	int value;
	Node* next;
};
Node* sp;
Node* front, * rear;
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
void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ":	";
		for (int j = 0; j < n;j++)
			cin >> a[i][j];
	}
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("mtk1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n;i++)
		{
			for (int j = 0; j < n;j++)
				myfile >> a[i][j];
		}
	}
}
void outputGraph()
{
	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "	";
		cout << endl;
	}

}
void output(int a[], int n)
{
	for (int i = 0; i < n;i++)
		cout << vertex[a[i]] << "	";
}
//Duyet BFS (QUEUE)
int c[100], bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n;i++) // n la so dinh cua do thi
		c[i] = 1;
}
void BFS(int v)
{
	int w, p;
	PushQ(v);
	c[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for ( w = 0; w < n; w++)
			if (c[w] && a[p][w] == 1)
			{
				PushQ(w);
				c[w] = 0;
			}
	}
}
// Duyet DFS (STACK)
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int v = -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			PopS(u);
		for (v = 0; v < n; v++)
			if (a[u][v] != 0 && c[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				u = v;
				break;
			}
	}
}
void Search_by_BFS(int x, int v) // v la dinh bat dau
{
	int w, p;
	PushQ(v);
	c[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout << "Tim thay x= " << x << endl;
			return;
		}
		for ( w =0 ;w< n;w++)
			if (c[w] && a[p][w] == 1)
			{
				PushQ(w);
				c[w] = 0;
			}
	}
}
int main()
{
	int a[MAX], b[MAX];
	int choice, sp, sp_b, x, i;
	do
	{
		system("cls");
		cout << "---------- BAI TAP 4 CHUONG 5 DO THI --------" << endl
			<< "1. Khoi tao MA TRAN KE rong" << endl
			<< "2. Nhap MA TRAN KE tu file text" << endl
			<< "3. Nhap MA TRAN KE " << endl
			<< "4. Xuat MA TRAN KE " << endl
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
			cout << "Khoi tao MTK rong thanh cong!" << endl;
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MTK tu file: " << endl;
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