#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
using namespace std;

//khai bao ma tran bang mang 2 chieu
#define MAX 20
int a[MAX][MAX];
int n; // so dinh
char vertex[MAX]; //ten dinh


void InitGraph()
{
	n = 0;
}

// nhap mtk cua do thi
void inputGraph()
{
	cout << "Nhap so dinh cua do thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "nhap vao dong thu" << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

//nhap graph tu file
void inputGraphFromText()
{
	string line;
	ifstream myfile("mttk1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			myfile >> a[i][j];
		}

	}
}
 // xuat ma tran ke cua do thi
void outputGraph()
{
	cout << setw(6) << left;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}

}


//khai bao tap E
int e1[MAX];
int e2[MAX];
int wE[MAX];
int nE = 0;  //so phan tu cua tap E

//khai bao tap T
int t1[MAX];
int t2[MAX];
int wT[MAX];
int nT = 0;  //so phan tu cua tap T

int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}
void XoaViTriE(int i)
{
	for (int j = i; j < nE; j++)
	{
		e1[j] = e1[j + 1];
		e2[j] = e2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
	{
		if (e1[i] == u && e2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
	}
}
void Prim(int s)
{
	int u = s, min, i, d1, d2;
	while (nT < n - 1)
	{
		for (int v = 0; v < n; v++)
			if (a[u][v] != 0)
				if (TonTai(v, t2, nT) == 0)
				{
					e1[nE] = u;
					e2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
		for (i = 0; i < nE; i++)
			if (TonTai(e2[i], t2, nT) == 0)
			{
				min = wE[i];
				d1 = e1[i];
				d2 = e2[i];
				break;
			}
		for (; i < nE; i++)
			if (TonTai(e2[i], t2, nT) == 0)
				if (min > wE[i])
				{
					min = wE[i];
					d1 = e1[i];
					d2 = e2[i];
				}
		t1[nT] = d1;
		t2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}

}

	//xuat ten dinh 
	void output(bool VertexName)
{
		int tong = 0;
		for (int i = 0; i < n; i++)
		{
			if (VertexName)
				cout << endl << "( " << vertex[t1[i]] << "," << vertex[t2[i]] << ")= " << wT[i];
			else cout << endl << "(" << t1[i] << "," << t2[i] << ")= " << wT[i];
			tong += wT[i];
		}
		cout << "\n Tong = " << tong;
	}

int main()
{
	int choice, x, i;
	do {
		system("cls");
		cout << "===bai 4 chuong 6===\n"
			<< "1. Khoi tao ma tran ke rong\n"
			<< "2. Nhap MTK tu file\n"
			<< "3. Nhap MTK\n"
			<< "4. Xuat MTK\n"
			<< "5. Tim cay khung toi thieu bang PRIM\n"
			<< "Ban chon:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			InitGraph();
			cout << "Ban vua khoi tao ma tran ke rong thanh cong!\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap mtk tu file \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			cout << "Ban vua nhap mtk \n";
				break;
		case 4: 
			outputGraph();
			break;
		case 5:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			Prim(x);
			cout << "Cay khung toi tieu voi PRIM: " << endl;
			output(true);
			break;
		case 6:
			cout << "Goodbieeeeeeee " << endl;
			break;
		default: break;
		}
		_getch();
	} while (choice >= 1 && choice <=5);
	return 0;

}