#include<iostream>
using namespace std;

const int SIZE = 5;
int main(){


    int * arr = new int[SIZE]; // arr is a pointer that points to an array 

    arr[0] = 100;
    arr[2] = 300;

    for(int k=0;k<5;k++){
        cout<<arr[k]<<endl;
    }


    //creating a 2D dynamic array

    







    return 0;
}