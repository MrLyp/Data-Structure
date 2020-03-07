#include <iostream>
#include <stdio.h>
#include "function.h"

using namespace std;

int main()
{
    SqStack s;
    InitStack(s);
    int Sel=1;
    SElemType e;
    string str;
    int data;
    int a;
    while(Sel!=0){
        print();
        cin>>Sel;
        switch (Sel) {
        case 1:
            if(GetTop(s,e)==OK){
                cout<<endl<<"\t\t\t\t\tջ��Ԫ��Ϊ��"<<e<<endl;
                cout<<"\t\t\t\t\t";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t��ջΪ�գ������Ƿ�ѹջ(1����YES��0����NO)��";
                int a;
                cin>>a;
                if(a==0){
                    cout<<"\t\t\t\t\t";
                    system("pause");
                }else if(a==1){
                    cout<<"\t\t\t\t\t������Ҫѹջ������";
                    cin>>e;
                    Push(s,e);
                    cout<<endl<<"\t\t\t\t\tѹջ��ɣ�";
                    system("pause");
                }else{
                    cout<<"\t\t\t\t\t��������";
                    system("pause");
                }
            }
            break;
        case 2:
            cout<<endl<<"\t\t\t\t\t������Ҫѹջ������";
            cin>>e;
            if(Push(s,e)==OK){
                cout<<endl<<"\t\t\t\t\tѹջ��ɣ�";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\tѹջʧ�ܣ�";
                system("pause");
            }
            break;
        case 3:
            if(Pop(s,e)==OK){
                cout<<endl<<"\t\t\t\t\t��ջ��ɣ�����Ԫ��Ϊ��"<<e<<endl;
                cout<<"\t\t\t\t\t";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t��ջΪ�գ������Ƿ�ѹջ(1����YES��0����NO)��";
                int a;
                cin>>a;
                if(a==0){
                    cout<<"\t\t\t\t\t";
                    system("pause");
                }else if(a==1){
                    cout<<"\t\t\t\t\t������Ҫѹջ������";
                    cin>>e;
                    Push(s,e);
                    cout<<endl<<"\t\t\t\t\tѹջ��ɣ�";
                    system("pause");
                }else{
                    cout<<"\t\t\t\t\t��������";
                    system("pause");
                }
            }
            break;
        case 4:
            Show(s);
            break;
        case 5:
            if(StackEmpty(s)==TRUE){
                cout<<endl<<"\t\t\t\t\tȷʵ�ǿ�ջ��";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t���ǿ�ջ��";
                system("pause");
            }
            break;
        case 6:
            cout<<endl<<"\t\t\t\t\t��ջ�ĳ���Ϊ��"<<StackLength(s)<<endl;
            cout<<"\t\t\t\t\t";
            system("pause");
            break;
        case 7:
            if(ClearStack(s)==TRUE){
                cout<<endl<<"\t\t\t\t\t����ձ�Ϊ��ջ��";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t���ʧ�ܣ�";
                system("pause");
            }
            break;
        case 8:
            if(DestroyStack(s)==OK)
                cout<<endl<<"\t\t\t\t\t���ٳɹ���";
            else{
                cout<<endl<<"\t\t\t\t\t����ʧ�ܣ�";
                break;
            }
            system("pause");
            while(Sel!=0){
                print_in();
                cin>>Sel;
                switch (Sel) {
                case 1:
                    cout<<endl<<"\t\t\t\t\t������һ��ʮ��������";
                    cin>>data;
                    cout<<"\t\t\t\t\tת��Ϊ�����ƣ�";
                    cin>>a;
                    conversion(data,a);
                break;
                case 2:
                    cout<<endl<<"\t\t\t\t\t������һ������(��)��[��]�������У�";
                    cin>>str;
                    if(matching(str)==OK){
                        cout<<endl<<"\t\t\t\t\t����ƥ�䣡";
                    }
                    else{
                        cout<<endl<<"\t\t\t\t\t���Ų�ƥ�䣡";
                    }
                    system("pause");
                break;
                case 3:
                    cout<<endl<<"\t\t\t\t\t�ù��ܻ�δʵ�֣�";
                    system("pause");
                break;
                case 4:
                    cout<<endl<<"\t\t\t\t\t������һ�����У�";
                    cin>>str;
                    if(judgeNum(str)==TRUE){
                        cout<<endl<<"\t\t\t\t\t�ǻ�������";
                        system("pause");
                    }
                    else{
                        cout<<endl<<"\t\t\t\t\t���ǻ�������";
                        system("pause");
                    }
                break;
                case 0:
                    cout<<endl<<"\t\t\t\t\t�˳��ɹ���";
                    system("pause");
                    exit(0);
                    break;
                default:
                    cout<<endl<<"\t\t\t\t\t���벻�Ϸ���";
                    system("pause");
                break;
                }
            };

        case 9:
            cout<<endl<<"\t\t\t\t\t������һ��ʮ��������";
            cin>>data;
            cout<<"\t\t\t\t\tת��Ϊ�����ƣ�";
            cin>>a;
            conversion(data,a);
            break;
        case 10:

            cout<<endl<<"\t\t\t\t\t������һ������(��)��[��]�������У�";
            cin>>str;
            if(matching(str)==OK){
                cout<<endl<<"\t\t\t\t\t����ƥ�䣡";
            }
            else{
                cout<<endl<<"\t\t\t\t\t���Ų�ƥ�䣡";
            }
            system("pause");
            break;
        case 11:
            cout<<endl<<"\t\t\t\t\t�ù��ܻ�δʵ�֣�";
            system("pause");
        break;
        case 12:
            cout<<endl<<"\t\t\t\t\t������һ�����У�";
            cin>>str;
            if(judgeNum(str)==TRUE){
                cout<<endl<<"\t\t\t\t\t�ǻ�������";
                system("pause");
            }
            else{
                cout<<endl<<"\t\t\t\t\t���ǻ�������";
                system("pause");
            }
        break;
        case 0:
            cout<<endl<<"\t\t\t\t\t�˳��ɹ���";
            system("pause");
            exit(0);
            break;
        default:
            cout<<endl<<"\t\t\t\t\t���벻�Ϸ���";
            system("pause");
            break;
        }
    };

    return 0;
}
