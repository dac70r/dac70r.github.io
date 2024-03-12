#include <iostream>
using namespace std;

int twoscomp(int x){

  x = (x>=0)?x:-x-1;

  return x;

}



int re(int n){
     int i, j, binary=0;
     i=1;

    if (n >0){
      
       cout<<binary;

    }
    else if (n<0){
      n = -(n-1);
      return re(n);
    }
        


    else
    {
      return 0;
    }
    

    
        
       
       }
     

  
     


  int main(){

    int x;
    cin>>x;
    
    
    twoscomp(x);
    re(twoscomp(x));

    return 0;
  }