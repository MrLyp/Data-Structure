#pragma once
#include "head.h"
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;  //���Һ���ָ��
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T);   //����������T
void PreOrderTraverse(BiTree T);          //�������������
void InOrderTraverse(BiTree T);         //�������������
void PostOrderTraverse(BiTree T);         //�������������
void LevelOrderTraverse(BiTree T);         //��������α���
int tree_depth(BiTree T);               //�������T�����
int count_n(BiTree T);                   //��������Ľ������
int CountSingle(BiTree T);            //�����������֧�ڵ����Ŀ