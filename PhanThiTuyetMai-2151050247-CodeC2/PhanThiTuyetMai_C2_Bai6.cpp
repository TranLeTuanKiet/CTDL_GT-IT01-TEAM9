#include<iostream>
using namespace std;

//Đổi 1 số thập phân sang cơ số 2

/* khai báo Node */
struct node
{
    int data;
    struct node* pNext;
};
typedef struct node NODE;

//khai báo cấu trúc của Stack
struct stack
{
    NODE* pTop; // con trỏ quản lí đầu stack
};
typedef struct stack STACK;

//hàm khởi tạo Stack
void KhoiTaoStack(STACK& s)
{
    s.pTop = NULL;
}

//hàm khởi tạo 1 cái node
NODE* KhoiTaoNode(int x)
{
    //tạo mới một NODE
    NODE* p = new NODE();
    if (p == NULL)
    {
        cout << "\nKhông đủ bộ nhớ để cấp phát !";
        return NULL;
    }
    // đưa dữ liệu của biến x vào trong cái data của node p
    p->data = x;
    p->pNext = NULL;
    return p;
}

//hàm kiểm tra Stack rỗng
bool IsEmpty(STACK s)
{
    // nếu stack rỗng
    if (s.pTop == NULL)
    {
        return false;
    }
    return true;
}

//Thêm phần tử vào đầu Stack (top)
bool Push(STACK& s, NODE* p)
{
    // node p đang rỗng
    if (p == NULL)
    {
        return false;
    }

    // nếu danh sách rỗng
    if (IsEmpty(s) == false)
    {
        // node p cũng chính là node pTop <=>chính là node đầu stack
        s.pTop = p;
    }
    else
    {
        // B1: cho con trỏ của node p trỏ đến node pTop
        p->pNext = s.pTop;
        // B2: cập nhật lại node đầu chính là node p
        s.pTop = p;
    }
    // thêm thành công
    return true;
}

//Lấy phần tử đầu danh sách và hủy nó đi
bool Pop(STACK& s, int& x) // x chính là giá trị cần lấy ra
{
    // nếu danh sách rỗng
    if (IsEmpty(s) == false)
    {
        // lấy thất bại <=> danh sách đang rỗng
        return false;
    }
    // gán node đầu danh sách vào node p <=> node p chính là node mà tí nữa ta sẽ xóa nó
    NODE* p = s.pTop;
    // cập nhật lại node đầu 
    s.pTop = s.pTop->pNext;
    // lấy giá trị của node đầu ra gán vào biến x
    x = p->data;
    // lấy phần tử thành công
    return true;
}

//Xem thông tin của node đầu danh sách
bool Top(STACK s, int& x)
// x chính là giá trị cần xem
{
    // nếu danh sách rỗng

    if (IsEmpty(s) == false)
    {
        return false;
    }
    x = s.pTop->data;
    return true;
}

//Hàm đổi thập phân sang các cơ số 2
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

//xuất danh sách stack
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