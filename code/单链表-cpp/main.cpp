#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    LinkList L;
    int n=5;
    Creat(L);
    cout << "Hello World!" << endl;
    int Sel=1;
    while(Sel!=0){
        Print();
        cin>>Sel;
        switch (Sel) {
        case 1:
            Show(L);
            break;
        case 2:
            Search(L);
            break;
        case 3:
            cout<<endl<<"\t\t\t\t\t��ïΰ����������λ�����ģ�"<<endl;
            cout<<endl<<"\t\t\t\t\t�㣺";
            int i1;
            cin>>i1;
            cout<<endl<<"\t\t\t\t\t��ïΰ����������ĸ�����"<<endl;
            cout<<endl<<"\t\t\t\t\t�㣺";
            ElemType e;
            cin>>e;
            Insert(L,i1,e);
            break;
        case 4:
            Delete(L);
            break;
        case 0:
            Destory(L);
            break;
        default:
            break;
        }
    };
    return 0;
}
