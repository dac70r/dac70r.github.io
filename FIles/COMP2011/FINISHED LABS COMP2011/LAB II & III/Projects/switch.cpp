#include<iostream>
using namespace std;

int main()
{



    cout<<"Please enter a session(1,2,3,4): ";
    int section;
    cin>>section;

    switch(section)
    {
        case 1:
        cout<<"Cheng Man Fung"<<endl;break;

        case 2:
        cout<<"Leung Pak Wo"<<endl;break;

        case 3:
        cout<<"Chen Tian Wen"<<endl;break;

        case 4:
        cout<<"Wong Kam Shing"<<endl;break;


        default:
        cerr<<"Invalid input"<<section<<endl;break;

    }

    return 0;

}