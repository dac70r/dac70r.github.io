#include<iostream>
using namespace std;

int main(){

    const int hello[4] = {};
    hello[0] = 100;

    for(int i = 0;i<4; i++){
        cout<<hello[i]<<endl;
    }
    






    return 0;
}