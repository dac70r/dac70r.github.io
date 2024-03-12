#include<iostream>
#include<cstring>

using namespace std;

// Global Variables
const int MAX_CONTACT_NUMBER = 10;

struct Contact{
    char name[MAX_CONTACT_NUMBER];
    char phone_number[MAX_CONTACT_NUMBER];
};

struct Telephone_Directory {
    Contact* contacts_by_name[MAX_CONTACT_NUMBER]; // in sorted order of contact_name
    Contact* contacts_by_phone_number[MAX_CONTACT_NUMBER]; // in sorted order of phone_number
    int num_of_contacts; // number of contacts
};

Contact* new_contact(const char name[],const char phone_number[]){

    Contact a;
    Contact* ptr1 = &a;
    strcpy(a.name,name);
    strcpy(a.phone_number,phone_number);
    
    return ptr1;

}



int main(){

    string a = "Hello" ;
    string b =  "World" ;
    
    new_contact(a,b);
    










    return 0;
}