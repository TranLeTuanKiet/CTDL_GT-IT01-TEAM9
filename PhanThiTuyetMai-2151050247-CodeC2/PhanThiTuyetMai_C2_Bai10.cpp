#include<stdio.h>
#include<iostream>
using namespace std;
// khai báo cau truc STACK
struct Node{
	int info;
	Node *link;
};
Node *sp;
// Khoi tao STACk rong
void init()
{
	sp=NULL;
}
// kiem tra STACK rong
int isEmty()
{
	if(sp==NULL)
		return 1;
	return 0;
}
// thêm phần tử vào STACK
int Push(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=sp;
	sp=p;
	return 1;
}
// lấy ra 1 phần tử stack
int Pop( int x)
{
	if(sp!=NULL)
	{
		Node *p=sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;
	}
	return 0;
}
// Xuất stack
void Process_stack()
{
	Node *p=sp;
	do{
		cout<<p->info<<" <- ";
		p=p->link;
	}
	while(p!=NULL);
	cout<<endl;
}
void Chuyen_Co_So(STACK& s, int cosocandoi, int hethapphan)
{
    while (hethapphan != 0)
    {
        int x = hethapphan % cosocandoi;
        // thêm x vào node p
        NODE* p = KhoiTaoNode(x);
        // thêm node p vào stack
        Push(s, p);
        //tiếp tục chia đến hết
        hethapphan /= cosocandoi;
    }
}
int main()
{
	int choice=0;
	int sp,x;
	system("cls");
	cout<<"------------------BAI 10 CHUONG 2 STACK (DSLK)----------------"<<endl;
	cout<<"1. Khoi tao stack rong "<<endl;
	cout<<"2. Them mot phan tu vao stack "<<endl;
	cout<<"3. Lay mot phan tu ra khoi stack "<<endl;
	cout<<"4. Kiem tra stack rong"<<endl;
	cout<<"5. Xuat STACK"<<endl;
	cout<<"6. Giai bai toan thap HA NOI"<<endl;
	cout<<"7. Doi tu thap phan sang nhi phan"<<endl;
	cout<<"8. Thoat"<<endl;
	do
	{
		cout<<"Vui long chon lenh thuc hien: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			init();
			cout<<"Khoi tao stack rong thanh cong "<<endl;
			break;
		case 2:
			cout<<"Nhap gia tri can them vao STACK x= ";
			cin>>x;
			Push(x);
			cout<<"STACK sau khi them la: ";
			Process_stack();
			break;
		case 3:
			Pop(x);
			cout<<"Phan tu duoc lay ra khoi Stack la: "<<x<<endl;
			cout<<"Stack sau khi lay ra la: ";
			Process_stack();
			break;
		case 4:
			if(isEmty()==1)
				cout<<"STACK rong"<<endl;
			else cout<<"STACK khong rong "<<endl;
			break;
		case 5:
			Process_stack();
			break;
		case 8:
			cout<<"Chuong trinh ket thuc!!"<<endl;
			break;
		}
	}
	while(choice!=6);
	system("pause");
	return 0;
}