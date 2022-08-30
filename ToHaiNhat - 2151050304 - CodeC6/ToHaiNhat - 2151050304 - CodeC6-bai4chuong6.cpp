#include<iostream>
#include<stdio.h>
using namespace std;
# define MAX 20
int a[MAX][MAX];
int n;
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;
void prim(int s)
{
	int u = s, min, i, d1, d2;
	while (nT < n - 1)
	{
		for (int v = 0; v < n; v++)
			if (a[u][v] != 0)
				if (TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;   E2[nE] = v;
					wE[nE] = a[u][v];  nE++;
				}
		for (i = 0; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i]; d1 = E1[i];
				d2 = E2[i]; break;
			}
		for (; i < nE; i++)
			if (TonTai(E2[i], T2, nT) == 0)
				if (min > wE[i])
				{
					min = wE[i]; d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1; T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0; a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}
}
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
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}
void output()
{
	int tong = 0;
	for (int i = 0; i < nT; i++)
	{
		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\n  Tong = " << tong;
}
void XoaCanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
		if (E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
}
int main() {

}
