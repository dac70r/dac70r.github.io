#include<iostream>
#include<cstring>
using namespace std;

const int MAX = 10;

struct Contact{

    char name[MAX];
    char phone[MAX];

};

struct Telephone{

    Contact* contact_by_name[MAX]; //creating arrays pointing to Contact, sorted by names.
    Contact* contact_by_phone[MAX];

};

void init_contact(Contact &a,const char name[], const char phone[]){

    strcpy(a.name,name);
    strcpy(a.phone,phone);
}

void print_contact(const Contact a){

    cout<<a.name<<" : "<<a.phone<<endl;

}




int main(){

    Contact a;
    init_contact(a,"Dennis","2065491");
    print_contact(a);

    Telephone b;


    return 0;
}