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

int re(int n){
     int i, j, binary=0;

     

     i=1;

      for(j=n;j>0;j=j/2)
       {
        binary = binary +(n%2)*i;
        i=i*10;
        n=n/2;
        
       }
       cout<<binary<<endl;
       
       }
     
     


  int main(){

    int x;
    cin>>x;
    re(x);
    onescomp(x);


  }