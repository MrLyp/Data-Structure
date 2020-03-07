#ifndef FUNCTION_H
#define FUNCTION_H

#include "stack.h"
#include <Windows.h>

Status InitStack(SqStack &s);//����һ����ջs
Status DestroyStack(SqStack &s);//����ջs
Status ClearStack(SqStack &s);//��s��Ϊ��
Status StackEmpty(SqStack s);//�ж�s�Ƿ�Ϊ��
int StackLength(SqStack s);//s�ĳ���
Status GetTop(SqStack s,SElemType &e);//��ջ���գ�e����sջ��Ԫ��
Status Push(SqStack &s,SElemType e);//����Ԫ��eΪ�µ�ջ��Ԫ��
Status Pop(SqStack &s,SElemType &e);//��ջ���գ�ɾ��s��ջ��Ԫ�أ���e����
void Show(SqStack s);//���ջs�����ֵ
void print();//��ʾ�˵�
void conversion(int n,int d);//����ת��
Status matching(string exp);//����ƥ��
Status judgeNum(string exp);//�����ж�

Status InitStack(SqStack &s){
    //����һ����ջs
    s.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!s.base) exit(OVERFLOW);
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack &s){
    s.top=NULL;
    s.stacksize=0;
    free(s.base);
    return OK;
}

Status ClearStack(SqStack &s){
    SElemType e;
    while( !StackEmpty(s) )
        Pop(s,e);
    return OK;
}

Status StackEmpty(SqStack s){
    if(s.top==s.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack s){
    return s.top-s.base;
}

Status GetTop(SqStack s,SElemType &e){
    if(s.top==s.base) return ERROR;
    e=*(s.top-1);
    return OK;
}

Status Push(SqStack &s,SElemType e){
    if(s.top-s.base>=s.stacksize){
        s.base=(SElemType *)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!s.base)
            exit(OVERFLOW);
        s.top=s.base+s.stacksize;
        s.stacksize+=STACKINCREMENT;
    }
    *s.top++ = e;
    return OK;
}

Status Pop(SqStack &s,SElemType &e){
    if(s.top==s.base)
        return ERROR;
    e=*--s.top;
    return OK;
}

void Show(SqStack s){
    SqStack tmp;
    InitStack(tmp);
    SElemType e;
    int i=0;
    cout<<endl;
    while(!StackEmpty(s)){
        Pop(s,e);
        i++;
        cout<<"\t\t\t\t\t��"<<i<<"����Ϊ��"<<e<<endl;
    }
    cout<<endl<<"\t\t\t\t\tһ��"<<i<<"����";
    system("pause");
}

void print()
{
    system("cls");
    cout<<endl<<"\t\t\t\t\t����һ���߶˴����ϵ��εķ�ïΰ�Ĳ˵�ͼ"<<endl;
    cout<<"\t\t\t\t\t_______________________________________"<<endl;
    cout<<"\t\t\t\t\t|              1.��ʾջ��             |"<<endl;
    cout<<"\t\t\t\t\t|              2.ѹջ                 |"<<endl;
    cout<<"\t\t\t\t\t|              3.��ջ                 |"<<endl;
    cout<<"\t\t\t\t\t|              4.������ʾ             |"<<endl;
    cout<<"\t\t\t\t\t|              5.�жϿ�ջ             |"<<endl;
    cout<<"\t\t\t\t\t|              6.ջ��                 |"<<endl;
    cout<<"\t\t\t\t\t|              7.���                 |"<<endl;
    cout<<"\t\t\t\t\t|              8.����                 |"<<endl;
    cout<<"\t\t\t\t\t|-------------------------------------|"<<endl;
    cout<<"\t\t\t\t\t|              9.����ת��             |"<<endl;
    cout<<"\t\t\t\t\t|              10.����ƥ��            |"<<endl;
    cout<<"\t\t\t\t\t|              11.���ʽ��ֵ          |"<<endl;
    cout<<"\t\t\t\t\t|              12.�����ж�            |"<<endl;
    cout<<"\t\t\t\t\t|              0.�˳�                 |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t���������ָ��:";
}

void print_in()
{
    system("cls");
    cout<<endl<<"\t\t\t\t\t����һ���߶˴����ϵ��εķ�ïΰ�Ĳ˵�ͼ"<<endl;
    cout<<"\t\t\t\t\t|-------------------------------------|"<<endl;
    cout<<"\t\t\t\t\t|              1.����ת��             |"<<endl;
    cout<<"\t\t\t\t\t|              2.����ƥ��             |"<<endl;
    cout<<"\t\t\t\t\t|              3.���ʽ��ֵ           |"<<endl;
    cout<<"\t\t\t\t\t|              4.�����ж�             |"<<endl;
    cout<<"\t\t\t\t\t|              0.�˳�                 |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t���������ָ��:";
}

Status matching(string exp){
    SqStack s;
    InitStack(s);
    SElemType e;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='('||exp[i]=='['){
            Push(s,exp[i]);
        }
        else if(exp[i]==')'){
            GetTop(s,e);
            if(e=='('){
                Pop(s,e);
            }
            else
                return ERROR;
        }
        else if(exp[i]==']'){
            GetTop(s,e);
            if(e=='['){
                Pop(s,e);
            }
            else
                return ERROR;
        }
        else{
            return ERROR;
        }
    }
    if(StackEmpty(s)==TRUE)
        return OK;
    else
        return ERROR;
}

void conversion(int n,int d){
    SqStack s;
    InitStack(s);
    SElemType e;
    int temp=n;
    while(n>0){
        Push(s,n%d);
        n=n/d;
    }
    cout<<endl<<"\t\t\t\t\tת�����ֵΪ��";
    while(!StackEmpty(s)){
        Pop(s,e);
        cout<<e;
    }
    cout<<endl;
    cout<<"\t\t\t\t\t";
    system("pause");
}

Status judgeNum(string exp){
    SqStack s;
    InitStack(s);
    SElemType e;
    for(int i=0;i<exp.length();i++){
        Push(s,exp[i]);
    }
    for(int i=0;i<exp.length();i++){
        GetTop(s,e);
        if(exp[i]!=e)
            return FALSE;
        else
            Pop(s,e);
    }
    return TRUE;
}

#endif // FUNCTION_H
