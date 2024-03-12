#include<iostream>

using namespace std;

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

    if (decimal > 0){

        int a=0;

        int remainder = decimal %2;
        decimal = decimal/2;
        cout<<(remainder);
        decimal_to_binary(decimal);
        

    }
        
        else
        {
            return 0;
        }
        




    



    
}



    
    

    




int main(){
    int x;
    cin>>x;
    decimal_to_binary(x);

    return 0;



}