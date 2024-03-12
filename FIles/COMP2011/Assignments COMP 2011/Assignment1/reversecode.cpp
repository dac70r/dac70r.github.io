#include <iostream>  
using namespace std;  



int reversef(int x){

int reverse=0, rem;   
 while(x!=0)    
  {    
     rem=x%10;      
     reverse=reverse*10+rem;    
     x/=10;    
  }    
  return reverse;

}

int main()  
{  
int n;
cout<<"Enter a number: ";    
cin>>n;    
  
 cout<<"Reversed Number: "<<reversef(n)<<endl;     
return 0;  
}  