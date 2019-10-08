#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    string s;
    QElemType e;
    SqQueue q;
    InitQueue(q);
    int flag=1;
    while(flag!=0){
        print();
        cin>>flag;
        switch (flag) {
        case 1:
            cout<<endl<<"\t\t\t\t\t������Ҫѹ�������";
            cin>>e;
            if(EnQueue(q,e)==OK){
                cout<<endl<<"\t\t\t\t\tѹ�������ɣ�";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\tѹ�����ʧ�ܣ�";
                system("pause");
            }
            break;
        case 2:
            if(DeQueue(q,e)==OK){
                cout<<endl<<"\t\t\t\t\t����������ɣ�����Ԫ��Ϊ��"<<e<<endl;
                cout<<"\t\t\t\t\t";
                system("pause");
            }else{
                cout<<endl<<"\t\t\t\t\t�˶���Ϊ�գ������Ƿ�ѹ��������(1����YES��0����NO)��";
                int a;
                cin>>a;
                if(a==0){
                    cout<<"\t\t\t\t\t";
                    system("pause");
                }else if(a==1){
                    cout<<"\t\t\t\t\t������Ҫѹ�������";
                    cin>>e;
                    EnQueue(q,e);
                    cout<<endl<<"\t\t\t\t\tѹ�������ɣ�";
                    system("pause");
                }else{
                    cout<<"\t\t\t\t\t��������";
                    system("pause");
                }
            }
            break;
        case 3:
            cout<<endl<<"\t\t\t\t\t�˶��еĳ���Ϊ��"<<QueueLength(q)<<endl;
            cout<<"\t\t\t\t\t";
            system("pause");
            break;
        case 4:
            cout<<endl<<"\t\t\t\t\t������һ�����У�";
            cin>>s;
            if(judgeNum(s)==TRUE){
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
    }

    return 0;
}
