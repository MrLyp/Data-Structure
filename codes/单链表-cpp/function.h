#ifndef FUNCTION_H
#define FUNCTION_H

#include "struct.h"
#include "head.h"
#include <iostream>

void Creat(LinkList &L,int n);
Status Show(LinkList L);
Status Search(LinkList L);
Status Insert(LinkList &L,int i,ElemType e);
Status Delete(LinkList &L);
void Destory(LinkList& L);
void Print();

void Creat(LinkList &L){
    int n;
    cout<<endl<<"\t\t\t\t\t��ïΰ���������봴�����ٸ���?"<<endl;
    cout<<"\t\t\t\t\t�㣺";
    cin>>n;
    cout<<endl;
    L = (LinkList)malloc(sizeof(LNode));
    LinkList r=L;
    for(int i=0;i<n;i++){
        LinkList p=(LinkList)malloc(sizeof(LNode));
        cout<<"\t\t\t\t\t��ïΰ���������"<<i+1<<"����:";
        cin>>(p->data);
        r->next=p;
        r=p;
    }
    r->next=NULL;
}

Status Show(LinkList L){
    if(L->next==NULL){
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
    int i=0;
    while(L->next){
        cout<<"\t\t\t\t\t��ïΰ����"<<i+1<<"����Ϊ:"<<L->next->data<<endl;
        L=L->next;
        i++;
    }
    cout<<endl<<"\t\t\t\t\t��ïΰ��һ��"<<i<<"������"<<endl;
    cout<<endl<<endl<<"\t\t\t\t\t";
    system("pause");
}

Status Search(LinkList L){
    cout<<endl<<"\t\t\t\t\t��������Ҫ���ҵ�����";
    ElemType e;
    cin>>e;
    cout<<endl;
    LinkList p = L->next;
    int i=1;
    while (p){
        if(p->data==e){
            cout<<"\t\t\t\t\t��ïΰ��"<<e<<"������ڵ�"<<i<<"���λ��"<<endl;
            cout<<endl<<"\t\t\t\t\t";
            system("pause");
            return OK;
        }
        p = p->next;
        i++;

    }
    cout<<"\t\t\t\t\t��ïΰ��δ�ҵ������"<<endl;
    cout<<endl<<"\t\t\t\t\t";
    system("pause");
    return ERROR;
}

Status Insert(LinkList &L,int i,ElemType e){
    LinkList p=L;
    int j=0;
    while(p&&j<i-1){
        p=p->next;
        ++j;
    }
    cout<<endl;
    if(!p||j>i-1){
        cout<<"\t\t\t\t\t���Խ�磬��Ч��"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }
    LinkList s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    cout<<"\t\t\t\t\tϵͳ��ʾ������ɹ���"<<endl;
    cout<<endl<<"\t\t\t\t\t";
    system("pause");
    return ERROR;
    return OK;

}

Status Delete(LinkList &L){
    if(L->next==NULL){
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

    LinkList p=L;
    int j=0;
    while(p->next&&j<i-1){
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1){
        cout<<endl<<"\t\t\t\t\tϵͳ��ʾ�����Խ�磬��Ч��"<<endl;
        cout<<endl<<"\t\t\t\t\t";
        system("pause");
        return ERROR;
    }
    LinkList q=p->next;
    cout<<endl<<"\t\t\t\t\tϵͳ��ʾ����"<<i<<"����Ϊ"<<q->data<<"�������Ƿ�ȷ��ɾ����"<<endl;
    cout<<"\t\t\t\t\t(1����YES��0����NO)"<<endl;
    cout<<endl<<"\t\t\t\t\t�㣺";
    int a;
    cin>>a;
    if(a==1){
        cout<<endl<<"\t\t\t\t\t���Ժ�";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        p->next=q->next;
        free(q);
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

void Destory(LinkList &L){
    L->next=NULL;
    cout<<endl<<"\t\t\t\t\t��ïΰ����ճɹ��������˳���"<<endl;
    cout<<endl<<"\t\t\t\t\t���Ժ�";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<".";
    Sleep(1000);
    cout<<endl<<"\t\t\t\t\tϵͳ��ʾ�����˳���(�س�����)"<<endl;
    cout<<"\t\t\t\t\t";
    Sleep(2000);
}

void Print(){
    system("cls");
    cout<<endl<<"\t\t\t\t\t    ����һ���߶˴����ϵ��εķ�ïΰ�Ĳ˵�ͼ"<<endl;
    cout<<"\t\t\t\t\t_____________________________________________"<<endl;
    cout<<"\t\t\t\t\t|                 1.��ʾ                    |"<<endl;
    cout<<"\t\t\t\t\t|                 2.����                    |"<<endl;
    cout<<"\t\t\t\t\t|                 3.����                    |"<<endl;
    cout<<"\t\t\t\t\t|                 4.ɾ��                    |"<<endl;
    cout<<"\t\t\t\t\t|                 0.���                    |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t���������ָ��:";
}

#endif // FUNCTION_H
