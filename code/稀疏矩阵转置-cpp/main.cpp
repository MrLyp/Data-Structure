#include <iostream>
#include "func.h"

using namespace std;

int main()
{
    TSMatrix M;
    CreateSMatrix(M);
    PrintSMatrix(M);

    TSMatrix T;

    int i;
    cout<<"��ѡ��1.��ͨת�ã�2.����ת��"<<endl;
    cin>>i;
    if(i==1){
        TransposeSMatrix(M,T);
        PrintSMatrix(T);
    }
    else if(i==2){
        FastTransposeSMatrix(M,T);
        PrintSMatrix(T);
    }
    else
        cout<<"��������!"<<endl;
    DestroySMatrix(M);
    DestroySMatrix(T);

    return 0;
}
