#include<iostream>
using namespace std;

int main(){
    
    const int Abby = 400;
    //initialize the elements in your array 
    //if not some numbers other than 0 will appear
    int claz[Abby] = {};
    cout<<sizeof(int)<<endl;
    cout<<sizeof(claz)<<endl;
    for(int j=0;j<Abby;++j)
        cout<<claz[j]<< "  ";  

    cout<<endl;

    int clazz[] = {1,2,3,4,5,6,4,5,5,6,4,5,1,1,5};
    cout<<sizeof(int)<<endl;
    cout<<sizeof(clazz)<<endl;

    cout<<"The number of elements in array is: "<<sizeof(clazz)/sizeof(int);


    return 0;
}