#include <iostream>
using namespace std;

int main()
     {
     int n, i, j, binary=0;

     cout<<"Please: ";
     cin>>n;

     i=1;

      for(j=n;j>0;j=j/2)
       {
        binary = binary +(n%2)*i;
        i=i*10;
        n=n/2;
       }
     
     cout<<binary<<endl;
 }