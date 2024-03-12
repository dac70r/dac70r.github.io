#include<iostream>
using namespace std;


int main(){

    const int NUMOSTU = 5;
    int size[NUMOSTU];
    float sum = 0.0;
    float mean = 0.0;

    int j = 0;

    for(j;j<NUMOSTU;j++){
        cin>>size[j];
        sum = sum + size[j];
    }

    
    mean = sum/NUMOSTU;

    cout<<mean<<endl;


    return 0;
}