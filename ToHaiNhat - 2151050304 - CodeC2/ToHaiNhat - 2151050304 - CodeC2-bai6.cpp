#include<iostream>
using namespace std;


struct node
{
    int data;
    struct node* pNext;
};
typedef struct node NODE;


struct stack
{
    NODE* pTop; 
};
typedef struct stack STACK;


void KhoiTaoStack(STACK& s)
{
    s.pTop = NULL;
}


NODE* KhoiTaoNode(int x)
{

    NODE* p = new NODE();
    if (p == NULL)
    {
        cout << "\nKhông đủ bộ nhớ để cấp phát !";
        return NULL;
    }

    p->data = x;
    p->pNext = NULL;
    return p;
}


bool IsEmpty(STACK s)
{
    // nếu stack rỗng
    if (s.pTop == NULL)
    {
        return false;
    }
    return true;
}

bool Push(STACK& s, NODE* p)
{

    if (p == NULL)
    {
        return false;
    }


    if (IsEmpty(s) == false)
    {

        s.pTop = p;
    }
    else
    {

        p->pNext = s.pTop;

        s.pTop = p;
    }

    return true;
}


bool Pop(STACK& s, int& x)
{

    if (IsEmpty(s) == false)
    {

        return false;
    }

    NODE* p = s.pTop;

    s.pTop = s.pTop->pNext;

    x = p->data;

    return true;
}


bool Top(STACK s, int& x)

{


    if (IsEmpty(s) == false)
    {
        return false;
    }
    x = s.pTop->data;
    return true;
}


void Chuyen_Co_So(STACK& s, int cosocandoi, int hethapphan)
{
    while (hethapphan != 0)
    {
        int x = hethapphan % cosocandoi;

        NODE* p = KhoiTaoNode(x);

        Push(s, p);

        hethapphan /= cosocandoi;
    }
}


void XuatStack(STACK& s)
{
    while (IsEmpty(s) == true)
    {
        int x;
        Pop(s, x);
        cout << x;
    }
}

int main()
{
    STACK s;
    KhoiTaoStack(s);

    int hethapphan, cosocandoi = 2;
    cout << "Nhap so thap phan can chuyen: ";
    cin >> hethapphan;
    Chuyen_Co_So(s, cosocandoi, hethapphan);
    cout << "Ket qua nhi phan: ";
    XuatStack(s);
    cout << endl;
    system("pause");
    return 0;
}