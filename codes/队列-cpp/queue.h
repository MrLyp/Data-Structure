#ifndef QUEUE_H
#define QUEUE_H

#include "head.h"

typedef struct{
    QElemType *base; //��ʼ���Ķ�̬����洢�ռ�
    int front;       //ͷָ�룬�����в��գ�ָ�����ͷԪ��
    int rear;        //βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQueue;

#endif // QUEUE_H
