#include <iostream>

using namespace std;

void onescomp(int num)
{
    int rem;
 
    if (num <= 1)
    {
        cout << !num;
        return;
    }
    rem = num % 2;
    onescomp(num / 2);
    cout << !rem;
}

int main(){
    int x;
    

    cout<<"Please: "<<endl;
    cin>>x;
    onescomp(x);





    return 0;
}