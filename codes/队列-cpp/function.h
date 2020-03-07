#ifndef FUNCTION_H
#define FUNCTION_H

#include "queue.h"
#include <Windows.h>

Status InitQueue(SqQueue &q);//����һ���ն���q
int QueueLength(SqQueue q);//����q��Ԫ�ظ���
Status EnQueue(SqQueue &q,QElemType e);//����Ԫ��eΪq���¶�βԪ��
Status DeQueue(SqQueue &q,QElemType &e);//�����в��գ���ɾ��q�Ķ�ͷԪ�أ���e������ֵ��������OK
Status judgeNum(string exp);//�ж��Ƿ����
void print();

Status InitQueue(SqQueue &q){
    q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(!q.base){
        exit(OVERFLOW);
    }
    q.front=0;
    q.rear=0;
    return OK;
}

int QueueLength(SqQueue q){
    return (q.rear-q.front+MAXQSIZE)%MAXQSIZE;
}

Status EnQueue(SqQueue &q,QElemType e){
    if((q.rear+1)%MAXQSIZE==q.front){
        return ERROR;
    }
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &q,QElemType &e){
    if(q.front==q.rear){
        return ERROR;
    }
    e=q.base[q.front];
    q.front=(q.front+1)%MAXQSIZE;
    return OK;
}

Status judgeNum(string exp){
    SqQueue q;
    InitQueue(q);
    QElemType e;
    for(int i=0;i<exp.length();i++){
        EnQueue(q,exp[i]);
    }
    q.rear--;
    while(q.front<q.rear){
        if(q.base[q.rear--]!=q.base[q.front++]){
            return FALSE;
        }
    }
    return TRUE;
}

void print()
{
    system("cls");
    cout<<endl<<"\t\t\t\t\t����һ���߶˴����ϵ��εķ�ïΰ�Ĳ˵�ͼ"<<endl;
    cout<<"\t\t\t\t\t|-------------------------------------|"<<endl;
    cout<<"\t\t\t\t\t|              1.ѹ�����             |"<<endl;
    cout<<"\t\t\t\t\t|              2.��������             |"<<endl;
    cout<<"\t\t\t\t\t|              3.��ʾ�ӳ�             |"<<endl;
    cout<<"\t\t\t\t\t|              4.�����ж�             |"<<endl;
    cout<<"\t\t\t\t\t|              0.�˳�                 |"<<endl;
    cout<<"\t\t\t\t\t---------------------------------------"<<endl;
    cout<<endl<<"\t\t\t\t\t���������ָ��:";
}

#endif // FUNCTION_H
