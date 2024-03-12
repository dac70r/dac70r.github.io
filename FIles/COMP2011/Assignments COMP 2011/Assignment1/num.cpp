#include<iostream>
using namespace std;



void num(int x){
int rem;

    if (x<=1){
        cout << !num;
        return;
    }

    rem = x%2;
    cout<< !rem;
    num(x);

}
int main()

{
    int x;

    cout<<"Please: ";
    cin>>x;
    num(x);






    return 0;
}