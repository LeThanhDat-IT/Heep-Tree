#include "Header.h"
void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(vector<int>& hT, int i)
{
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;

    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}
void insert(vector<int>& hT, int newNum)
{
    int size = hT.size();
    if (size == 0)
    {
        hT.push_back(newNum);
    }
    else
    {
        hT.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(hT, i);
        }
    }
}
void deleteNode(vector<int>& hT, int num)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }
    swap(&hT[i], &hT[size - 1]);

    hT.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, i);
    }
}

void createHTree(vector<int> &t) {
    int x;
    do {
        cout << "\nNhap x= "; cin >> x;
        if (x == 0)	break;
        try {
            insert(t, x);
        }
        catch (const char* s1) {
            cout << "\nLoi " << s1;
        }

    } while (true);
}

int searchX(vector<int> t, int x) {
    int size = t.size();
    int i = 0;
    while (i < size && x != t[i] )
        i++;
    if (i >= size)
        return -1;
    return i;
}
void removeTree(vector<int>t) {
    for (int i = 0; i < t.size(); i++)
    {
        t[i] = 0;
    }
}
void menu(vector<int> t) {
    int chon, x, k;
    char ch;
    do {
        cout << "\n0.Thoat";
        cout << "\n1.Tao cay Heap Tree";
        cout << "\n2.Them mot nut vao cay Heap Tree";
        cout << "\n3.Xoa mot nut trong cay Heap Tree";
        cout << "\n4.Duyet Heap";
        cout << "\n5.Tim kiem mot nut trong cay Heap Tree";
        cout << "\n6.Xoa toan bo cay Heap Tree";
        cout << "\n7.Ghi File Heap Tree";
        cout << "\n8.Doc File Heap Tree";
        cout << "\n==> Vui long chon chuc nang ";
        cin >> chon;
        if (chon == 0)   break;
        switch (chon)
        {
        case 1:
            createHTree(t);
            cout << "\n-->Da tao cay thanh cong, vui long xem lai ";
            break;
        case 2:
            cout << "\nVui long nhap gia tri can them ";
            cin >> x;
            insert(t, x);
            cout << "\n-->Da them thanh cong, vui long xem lai ";
            break;
        case 3:
        {
            cout << "\nVui long nhap nut can xoa";
            cin >> x;
            int q = searchX(t, x);
            if (q != -1) {
                deleteNode(t, x);
                cout << "\n-->Da xoa thanh cong, vui long xem lai ";
            }
            else
                cout << "\nKhong co gia tri cua " << x;

            break;
        }
        case 4:
            cout << "\nDuyet cay Heap\n";
            printHeap(t);
            break;
        
        case 5:
            cout << "\nVui long nhap gia tri can tim ";
            cin >> x;
           
            if (searchX(t,x)!=-1)
                cout << "\nCo "<<x<<" trong Heap";
            else
                cout << "\nKhong co " << x << " trong Heap";
            break;
        
        case 6:
            cout << "\nBan co chac xoa toan bo cay STree (Y/N)";
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                removeTree(t);
                cout << "\nDa xoa toan bo cac nut trong cay";
            }
            break;
        case 7:
            cout << "\nGhi File ";
            //cout << heightTree(root);
            break;
        case 8:
            cout << "\nDoc File ";
            //cout << heightTree(root);
            break;
        default:
            break;
        }
    } while (true);
}
void printHeap(vector<int>& hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

