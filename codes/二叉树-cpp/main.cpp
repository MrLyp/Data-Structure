#include "func.h"

int main()
{
    BiTree T;
    cout << "������һ����������0Ϊ������־����";
    CreateBiTree(T);
    cout << "���������";
    PreOrderTraverse(T);
    cout << endl << "���������";
    InOrderTraverse(T);
    cout << endl << "���������";
    PostOrderTraverse(T);
    cout << endl << "��������ȣ�" << tree_depth(T) << endl;
    cout << "�������������" << count_n(T) << endl;
    cout << "����������֧�������" << CountSingle(T) << endl;
    system("pause");
    return 0;
}