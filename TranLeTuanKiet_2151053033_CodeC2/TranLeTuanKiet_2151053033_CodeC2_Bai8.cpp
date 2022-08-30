//Chương 2 - Bài 8: Sử dụng stack đã xây dựng, đổi cơ số hệ thập phân sang hệ bất kì.

#include<iostream>
using namespace std;

//Khai bao Node
struct node
{
    int data;
    struct node* pNext;
};
typedef struct node NODE;

//Khai bao STACK
struct stack
{
    NODE* pTop;
};
typedef struct stack STACK;

//Khoi tao STACK
void KhoiTaoStack(STACK& s)
{
    s.pTop = NULL;
}

//Ham khoi tao Node
NODE* KhoiTaoNode(int x)
{
    NODE* p = new NODE();
    if (p == NULL)
    {
        cout << "\nKhong du bo nho de cap phat !!";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

//Kiem tra STACK rong
bool IsEmpty(STACK s)
{
    if (s.pTop == NULL)
    {
        return false;
    }
    return true;
}

//Them phan tu vao dau STACK (top)
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

//Xoa phan tu dau danh sach
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

//Xem thong tin Node dau danh sach
bool Top(STACK s, int& x)

{
    if (IsEmpty(s) == false)
    {
        return false;
    }
    x = s.pTop->data;
    return true;
}

//Ham doi co so 10 sang cac co so 2, 8, 16
void ChuyenDoiCoSo(STACK& s, int SoCanDoi, int HeThapPhan)
{
    while (HeThapPhan != 0)
    {
        int x = HeThapPhan % SoCanDoi;
        NODE* p = KhoiTaoNode(x);
        Push(s, p);
        HeThapPhan /= SoCanDoi;
    }
}

//Xuat STACK
void XuatStack(STACK& s)
{
    while (IsEmpty(s) == true)
    {
        int x;
        Pop(s, x);
        if (x < 10)
        {
            cout << x;
        }
        else
        {
            if (x == 10)
            {
                cout << "A";
            }
            else if (x == 11)
            {
                cout << "B";
            }
            else if (x == 12)
            {
                cout << "C";
            }
            else if (x == 13)
            {
                cout << "D";
            }
            else if (x == 14)
            {
                cout << "E";
            }
            else if (x == 15)
            {
                cout << "F";
            }
        }
    }
}

int main()
{
    STACK s;
    KhoiTaoStack(s);

    int HeThapPhan, SoCanDoi;
    cout << "\nNhập giá trị thập phân cần chuyển: ";
    cin >> HeThapPhan;
    do {
        cout << "\nNhập cơ số cần chuyển (2, 8, 16):  ";
        cin >> SoCanDoi;
    } while (SoCanDoi != 2 && SoCanDoi != 8 && SoCanDoi != 16);

    ChuyenDoiCoSo(s, SoCanDoi, HeThapPhan);
    cout << "\nKết quả:\n";
    XuatStack(s);
    cout << endl;
}
