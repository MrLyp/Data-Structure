#ifndef STRUCT_H
#define STRUCT_H

#include "head.h"

typedef struct{
    int i,j;     //�÷���Ԫ�����±�����±�
    ElemType e;
}Triple;

typedef struct{
    Triple data[MAXSIZE + 1];  //����Ԫ��Ԫ���data[0]δ��
    int mu,nu,tu;  //����������������ͷ���Ԫ����
}TSMatrix;


#endif // STRUCT_H
