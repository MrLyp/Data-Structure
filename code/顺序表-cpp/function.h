#ifndef FUNCTION_H
#define FUNCTION_H

#include "struct.h"
#include "head.h"

Status InitList(SqList& L);
void Creat(SqList &L);
Status Show(SqList L);
Status Search(SqList L);
Status Insert(SqList &L,int i,ElemType e);
Status Delete(SqList &L);
Status Ascend(SqList& L,int i);
void Destory(SqList& L);
void Print();

Status InitList(SqList& L){
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

void Creat(SqList &L){
    int n;
    cout<<endl<<"\t\t\t\t\t��ïΰ���������봴�����ٸ���?"<<endl;
    cout<<"\t\t\t\t\t�㣺";
    cin>>n;
    if(L.length>=L.listsize){
        ElemType* newbase = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize+=LISTINCREMENT;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"\t\t\t\t\t��ïΰ���������"<<i+1<<"����:";
        cin>>L.elem[i];
        L.length++;
    }
    system("cls");
    cout<<endl<<"\t\t\t\t\t��ïΰ�����ѳɹ�������׼���ÿ�ʼ����  ";
    Sleep(3000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t3"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t2"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t1"<<endl;
    Sleep(1000);
}

Status Show(SqList L){
    if(L.length==0){
        cout<<endl<<"\t\t\t\t\tϵͳ��ʾ���ձ�"<<endl<<endl;
        cout<<"\t\t\t\t\t��ïΰ�������Ƿ��������¹���һ����"<<endl;
        cout<<"\t\t\t\t\t(1����YES��0����NO)"<<endl;
        cout<<"\t\t\t\t\t�㣺";
        int a;
        cin>>a;
        if(a==1){
            Creat(L);
            return OK;
        }
        else if(a==0){
            return ERROR;
        }
        else{
            cout<<endl<<"\t\t\t\t\tϵͳ��ʾ������";
        }
        system("pause");
        return 0;
    }
    cout<<endl;
    for(int i=0;i<L.length;i++){
        cout<<"\t\t\t\t\t��ïΰ����"<<i+1<<"����Ϊ:"<<L.elem[i]<<endl;
    }
    cout<<endl<<"\t\t\t\t\t��ïΰ��һ��"<<L.length<<"������"<<endl;
    cout<<endl<<endl<<"\t\t\t\t\t";
    system("pause");
}

Status Search(SqList L){
    cout<<endl<<"\t\t\t\t\t��������Ҫ���ҵ�����";
    ElemType e;
    cin>>e;
    for(int i=0; i<L.length; i++)
        if(L.elem[i] == e){
            cout<<"\t\t\t\t\t��ïΰ����"<<i+1<<"����Ϊ"<<L.elem[i]<<endl;
            cout<<endl<<"\t\t\t\t\t";
            system("pause");
            return OK;
        }
    cout<<"\t\t\t\t\t��ïΰ��δ�ҵ������"<<endl;
    cout<<endl<<"\t\t\t\t\t";
    system("pause");
    return ERROR;
}

Status Insert(SqList &L,int i,ElemType e){
    ElemType *p,*q;
    if(i<1||i>L.length+1){
        cout<<"\t\t\t\t\t���Խ�磬��Ч��"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }
    if(L.length>=L.listsize){
        ElemType* newbase = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize+=LISTINCREMENT;
    }
    q=&(L.elem[i-1]);
    for(p=&(L.elem[L.length-1]);p>=q;--p){
        *(p+1)=*p;
    }
    *q=e;
    ++L.length;
    return OK;
}

Status Delete(SqList &L){
    if(L.length<=0){
        cout<<endl<<"\t\t\t\t\tϵͳ��ʾ���ձ�"<<endl<<endl;
        cout<<"\t\t\t\t\t��ïΰ�������Ƿ��������¹���һ����"<<endl;
        cout<<"\t\t\t\t\t(1����YES��0����NO)"<<endl;
        cout<<"\t\t\t\t\t�㣺";
        int a;
        cin>>a;
        if(a==1){
            Creat(L);
            return OK;
        }
        else if(a==0){
            return ERROR;
        }
        else{
            cout<<endl<<"\t\t\t\t\tϵͳ��ʾ������";
        }
        system("pause");
        return 0;
    }
    cout<<endl<<"\t\t\t\t\t��ïΰ����������ɾ���ڼ�����"<<endl;
    int i;
    cout<<"\t\t\t\t\t�㣺";
    cin>>i;
    if(L.length<i||i<1){
        cout<<endl<<"\t\t\t\t\tϵͳ��ʾ�����Խ�磬��Ч��"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }
    cout<<endl<<"\t\t\t\t\tϵͳ��ʾ����"<<i<<"����Ϊ"<<L.elem[i-1]<<"�������Ƿ�ȷ��ɾ����"<<endl;
    cout<<"\t\t\t\t\t(1����YES��0����NO)"<<endl;
    cout<<endl<<"\t\t\t\t\t�㣺";
    int a;
    cin>>a;
    if(a==1){
        ElemType *p,*q;
        p=&(L.elem[i-1]);
        ElemType e=*p;
        q=L.elem+L.length-1;
        for(++p;p<=q;++p){
            *(p-1)=*p;
        }
        L.length--;
        cout<<endl<<"\t\t\t\t\t���Ժ�";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<endl<<"\t\t\t\t\tϵͳ��ʾ��ɾ���ɹ���"<<endl;
        Sleep(2000);
        cout<<"\t\t\t\t\t";
        return OK;
    }
    else if(a==0){
        cout<<endl<<"\t\t\t\t\tϵͳ��ʾ������Ϊ�㷵�أ�"<<endl;
        cout<<"\t\t\t\t\t���Ժ�";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        return ERROR;
    }
    else{
        cout<<endl<<"\t\t\t\t\tϵͳ��ʾ�����Խ�磬��Ч��"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }

}

Status Ascend(SqList &L,int i){
    if(i==1){
        for (int j=0;j<L.length-1;j++)
            for (int k=0;k<L.length-1-j; k++)
                if (L.elem[k] > L.elem[k+1]){
                    int temp = L.elem[k];
                    L.elem[k] = L.elem[k+1];
                    L.elem[k+1] = temp;
                }
            cout<<endl<<"\t\t\t\t\tϵͳ��ʾ����������ɹ���"<<endl;
            cout<<endl<<"\t\t\t\t\t";
            system("pause");
            return OK;
    }
    else if(i==2){
        for (int j=0;j<L.length-1;j++)
            for (int k=0;k<L.length-1-j; k++)
                if (L.elem[k] < L.elem[k+1]){
                    int temp = L.elem[k];
                    L.elem[k] = L.elem[k+1];
                    L.elem[k+1] = temp;
                }
            cout<<endl<<"\t\t\t\t\tϵͳ��ʾ����������ɹ���"<<endl;
            cout<<endl<<"\t\t\t\t\t";
            system("pause");
            return OK;
    }
    else{
        cout<<endl<<"\t\t\t\t\tϵͳ��ʾ������";
    }
}

void Destory(SqList &L){
    L.length=0;
    cout<<endl<<"\t\t\t\t\t��ïΰ����ճɹ��������˳���";
    Sleep(3000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t3"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t2"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t1"<<endl;
    Sleep(1000);
    system("cls");
    cout<<endl<<"\t\t\t\t\t��ïΰ���ݰ�~(�س���������)"<<endl;
}

void Print(){
    system("cls");
    cout<<endl<<"\t\t\t\t\t    ����һ���߶˴����ϵ��εķ�ïΰ�Ĳ˵�ͼ"<<endl;
    cout<<"\t\t\t\t\t_____________________________________________"<<endl;
    cout<<"\t\t\t\t\t|                 1.��ʾ                    |"<<endl;
    cout<<"\t\t\t\t\t|                 2.����                    |"<<endl;
    cout<<"\t\t\t\t\t|                 3.����                    |"<<endl;
    cout<<"\t\t\t\t\t|                 4.ɾ��                    |"<<endl;
    cout<<"\t\t\t\t\t|                 5.����                    |"<<endl;
    cout<<"\t\t\t\t\t|                 0.���                    |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t���������ָ��:";
}

#endif // FUNCTION_H
