#include <iostream>  
using namespace std; 



int re(int n){
int reverse=0, rem;  

while(n!=0)    
  {    
     rem=n%10;      
     reverse=reverse*10+rem;    
     n/=10;  
    cout<<reverse;
  } 
  return -1;
}
int main()  
{  
int n;
cout<<"Enter a number: ";    
cin>>n;    
     
 cout<<"Reversed Number: "<<re(n)<<endl;     
return 0;  
} 