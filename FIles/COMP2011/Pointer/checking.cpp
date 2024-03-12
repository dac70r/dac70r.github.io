#include<iostream>
using namespace std;

int main(){

    int *ip = new int;
    *ip = 5;

    cout<<"Before delete: "<< *ip <<" Address: "<< &ip<< endl;

    delete ip;
    /*ip = nullptr;
    */
    cout<< "After delete: "<<*ip <<" Address: "<< &ip << endl;

    double *ip2 = new double;
    *ip2 = 500;

    cout<< *ip2 <<endl; //dereference value of ip2 which is 500
    cout<< ip2 <<endl; // the value of ip2 which is the location of the dynamic memory 
    cout<< &ip2<< endl; // location of the pointer ip2
    cout<< *ip <<endl; // makes no sense




    return 0;
}