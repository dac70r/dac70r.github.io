


#include<iostream>

using namespace std;

//reverse tool
int reverse(int decimal)
{  
int n, reverse=0, rem;    
cout<<"Enter a number: ";    
cin>>n;    
  while(n!=0)    
  {    
     rem=n%10;      
     reverse=reverse*10+rem;    
     n/=10;    
  }    
 
return 0;  
}  

//assuming either 0 or 1 will be the input
int if0then1(int decimal){

    if (decimal==1){

        return 0;
    }
    else 
    return 1;

}

int decimal_to_binary(int decimal)
{
    int remainder = decimal % 2;
    if (decimal < 1)
        return 0;
    decimal_to_binary(decimal / 2);
    cout << remainder;
}

int main(){
    int x;
    cin>>x;
    decimal_to_binary(x);

    return 0;



}

