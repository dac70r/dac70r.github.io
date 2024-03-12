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

int counting(int a){

    
    int  temp;
    int count = 0;
    // Store to temporary variable.
    temp = a;
    
    while(temp != 0) {

        // Increment counter
        count++;

        // Remove last digit of 'temp'
        temp /= 10;
    
    }
    return count;

}

int re(int n){
     int i, j, binary=0;

     

     i=1;

      for(j=n;j>0;j=j/2)
       {
        binary = binary +((n+1)%2)*i;
        i=i*10;
        n=n/2;
        
       }
       return binary;
       
       }
     
     


  int main(){

    int x;
    cin>>x;
    cout<<counting(re(x))<<endl;;
    onescomp(x);

    return 0;
  }