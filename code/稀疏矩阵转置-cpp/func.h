#ifndef FUNC_H
#define FUNC_H

#include "struct.h"

Status CreateSMatrix(TSMatrix &M);   //����
Status DestroySMatrix(TSMatrix &M);   //����
void PrintSMatrix(TSMatrix M);   //���

Status TransposeSMatrix(TSMatrix M,TSMatrix &T);   //ת��
Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T);  //��ת


Status CreateSMatrix(TSMatrix &M){
    int i,j;
    int count=0; //����Ԫ
    cout<<"������Ҫ��������ϡ�����"<<endl;
    cout<<"�У�";
    cin>>i;
    cout<<"�У�";
    cin>>j;
    cout<<endl;
    cout<<"���������Ԫ�ĸ�����";
    cin>>count;
    M.mu = i;
    M.nu = j;
    M.tu = count;
    cout<<"�밴��(�С��С�ֵ)�ĸ�ʽ��������"<<M.tu<<"������Ԫ����Ϣ��\n";
    int m,n,t;
    for(int i=1;i<=M.tu;i++)
    {
        cin>>m>>n>>t;
        M.data[i].i=m;
        M.data[i].j=n;
        M.data[i].e=t;
    }
    cout<<"���Ѵ������һ��ϡ�����"<<endl;
    return OK;
}

Status DestroySMatrix(TSMatrix &M){
    if (M.tu != 0){
    for (int ii = 1; ii <= M.tu; ++ii){
        M.data[ii].i = 0;
        M.data[ii].j = 0;
        M.data[ii].e = 0;
        }
        M.mu = 0;
        M.tu = 0;
        M.nu = 0;
        return OK;
    }
    else
        return ERROR;
}

void PrintSMatrix(TSMatrix M){
    cout<<endl;
    int k =1;
    for(int i=1;i<=M.mu;i++)
    {
        for(int j=1;j<=M.nu;j++)
        {
            if(M.data[k].i==i && M.data[k].j==j && k<=M.tu)
            {
                cout<<M.data[k++].e<<" ";
            }else
                cout<<0<<" ";
        }
        cout<<endl;
    }
}


Status TransposeSMatrix(TSMatrix M,TSMatrix &T){
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    int q=1;
    if(T.tu){
        for(int col=1;col<=M.nu;++col)
            for(int p=1;p<=M.tu;++p){
                if(M.data[p].j==col){
                    T.data[q].i=M.data[p].j;
                    T.data[q].j=M.data[p].i;
                    T.data[q].e=M.data[p].e;
                    ++q;
                }
            }
        return OK;
    }
}

Status FastTransposeSMatrix(TSMatrix M,TSMatrix &T){
    int col, t, p, q;
    int num[20], cpot[20];
    T.mu = M.nu;  T.nu = M.mu;  T.tu = M.tu;
    if (T.tu) {
        for (col = 1; col <= M.nu; ++col)	//���������г�ʼ��
            num[col] = 0;
        for (t = 1; t <= M.tu; ++t) // �� M ��ÿһ����������Ԫ�ĸ���
            ++num[M.data[t].j];
        cpot[1] = 1;
        // �� M ��ÿһ�еĵ�һ������Ԫ�� b.data �е����
        for (col = 2; col <= M.nu; ++col)
            cpot[col] = cpot[col - 1] + num[col - 1];
        for (p = 1; p <= M.tu; ++p)
        {
            col = M.data[p].j;
            q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            ++cpot[col];
        } // for
    } // if
    return OK;
}



#endif // FUNC_H
