#include <iostream>
using namespace std;

int main()
{
     int decimal, i=1;
     //store the same value as decimal
     int j;
     int binary;
     int count=1;
     cout<<"Please enter an integer: ";
     cin>>decimal;

     if (decimal>0){
        for(j=decimal;j>0;j=j/2)
       {
         ///binary is an integer not printed
        binary=binary+(decimal%2)*i;
        i=i*10;
        decimal/=2;
        count++;

       }
     }
     else
     {
        count = 2;
        binary = 0;
     }


      
     
    cout<<binary<<endl;
    cout<<count<<endl;
 }