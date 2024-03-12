// COMP2011 Fall 2020
// lab9.cpp -- source file

#include <iostream>
#include <cstring>
#include "lab9.h"
using namespace std;

// This function prints one contact's information.
void print_contact(const Contact* contact){
        cout << contact->contact_name <<  ":" << contact->phone_number << endl;
}

// This function will create (new) a Contact object with the given contact_name & phone_number,
// and return its address (pointer).
Contact* new_contact(const char contact_name[], const char phone_number[]){
        
        //Contact a;
        Contact* ptr1 = new Contact;
        strcpy(ptr1 -> contact_name,contact_name);
        strcpy(ptr1 -> phone_number,phone_number);

        return ptr1;

}

// This function will create (new) a Telephone_Directory object,
// initialize num_of_contact to 0, initialize all array elements to nullptr,
// and return the Telephone_Directory pointer (address).
Telephone_Directory* new_telephone_directory(){

        //Telephone_Directory a;
        Telephone_Directory* ptr2 = new Telephone_Directory;
        ptr2->num_of_contacts = 0;

        for(int k=0;k<MAX_CONTACT_NUMBER;k++){
                ptr2 -> contacts_by_name[k] =nullptr;
                ptr2 -> contacts_by_phone_number[k] =nullptr;
        }
        return ptr2;

}

// This function will use new_contact() to create object within given contact_name & phone_num,
// and add the pointer (address) to the 2 arrays of pointers in the Telephone_Directory object pointed by d.
// contacts_by_name is to maintain the contacts in sorted order of names,
// contacts_by_phone_number is to maintain the contacts in sorted order of phone numbers.
void add_contact_to_telephone_directory(Telephone_Directory *d, const char contact_name[], const char phone_num[]){

        Contact* a = new_contact(contact_name,phone_num);
        
        if(d->num_of_contacts ==0){
                d->contacts_by_name[0] = a;
                d->contacts_by_phone_number[0]=a;
                d->num_of_contacts = 1;
        }

        else
        {       //Eric,Shirley,Paul
                // first one sth like Eric, 2nd Shirley,  
                // second Shirley, 3rd Paul i = 1, 
                
                int i;
                for(i = (d->num_of_contacts)-1;(strcmp(d->contacts_by_name[i]->contact_name,contact_name)>0);i--){
                        d->contacts_by_name[i+1] = d->contacts_by_name[i]; //paul's place (3nd) replaced by Shirley (2st)
                        if(i==0){
                                i= -1;
                                break;
                        }
                }
                d->contacts_by_name[i+1]=a; //first eric&shirley -> nothing runs, next paul and shirley-> paul's initial position(2) now is shirley's position,  loops again, (1) = paul , done.

                int j;
                for(j=(d->num_of_contacts)-1;(strcmp(d->contacts_by_phone_number[j]->phone_number,phone_num)>0);j--){
                        d->contacts_by_phone_number[j+1] = d->contacts_by_phone_number[j];
                        if(j==0){
                                j = -1;
                                break;
                        }
                }
                d->contacts_by_phone_number[j+1]=a;

                d->num_of_contacts = (d->num_of_contacts)+1;
        }
        
}

// This function will print all contacts' infomation sorted by their names if by_names is true.
// Otherwise print the contacts by their phone numbers
void show_contacts(const Telephone_Directory* d, bool by_names){

        if(by_names){
                for(int k=0;k<d->num_of_contacts;k++){
                        cout<< d->contacts_by_name[k]->contact_name<<": "<<d->contacts_by_name[k]->phone_number<<endl;
                }
        }

        else
        {
                for(int k=0;k<d->num_of_contacts;k++){
                        cout<<d->contacts_by_phone_number[k]->contact_name<<": "<<d->contacts_by_phone_number[k]->phone_number<<endl;
                }
                
        }
        return;

}

// This function will print queried contacts' infomation (indices stored in matched_contacts[]) either sorted by their names (when by_name=true) or sorted by their phone numbers (when by_name=false)
void show_contacts(const Telephone_Directory* d, const int matched_contacts[], int matched_contacts_count,  bool by_name){
        
        cout<<matched_contacts_count<<" Number of contacts returned! "<<endl;

        if(by_name){
                for(int k=0;k<matched_contacts_count;k++){
                        cout<<d->contacts_by_name[(matched_contacts[k])]->contact_name<<": "<<d->contacts_by_name[(matched_contacts[k])]->phone_number<<endl;
                }
        }

        else
        {
                for(int k=0;k<matched_contacts_count;k++){
                        cout<<d->contacts_by_phone_number[(matched_contacts[k])]->contact_name<<": "<<d->contacts_by_phone_number[(matched_contacts[k])]->phone_number<<endl;
                }
        }
        

        

}


// This function will search for contacts matching with the substring contact_name_partial, 
// return num of matched contacts and store the indices of the matched contacts 
// in the contacts_by_name array of Telephone_Directory in the array matched_contacts.
int lookup_by_contact_name(const Telephone_Directory* d, const char contact_name_partial[], int matched_contacts[]){

        int i=0;
        for(int k =0;k<d->num_of_contacts;k++){
                if(strstr(d->contacts_by_name[k]->contact_name,contact_name_partial)!=NULL){

                        
                        matched_contacts[i]=k;
                        ++i;
                
                }
        }

        return i;

}

// This function will search for contacts matching with the substring phone_number_partial, 
// return num of matched contacts and store the indicses of the matched contacts 
// in the contacts_by_phone_number array of Telephone_Directory in the array matched_contacts.
int lookup_by_phone_number(const Telephone_Directory* d, const char phone_number_partial[], int matched_contacts[]){
        
        int i=0;
        for(int k =0;k<d->num_of_contacts;k++){
                if(strstr(d->contacts_by_phone_number[k]->phone_number,phone_number_partial)!=NULL){

                        
                        matched_contacts[i]=k;
                        ++i;
                        
                
                }
        }

        return i;
}

// This function will update a contact's phone number given the contact_name.
// and update the contacts_by_phone_num array in sorted order.
void update_phone_number(Telephone_Directory* d, const char contact_name[], const char phone_number[]){

        Contact* a = new_contact(contact_name,phone_number);

        for(int k=0;k<d->num_of_contacts;k++){
                if(strcmp(d->contacts_by_name[k]->contact_name,contact_name)==0){
                        d->contacts_by_name[k] = a;                      
                }
        }

        for(int k=0;k<d->num_of_contacts;k++){
                if(strcmp(d->contacts_by_phone_number[k]->contact_name,contact_name)==0){
                        d->contacts_by_phone_number[k] = a;                      
                }
        }

        for(int i=0;i<d->num_of_contacts;i++){
                for(int j = i+1;j<d->num_of_contacts;j++)
                {
                        if(strcmp(d->contacts_by_phone_number[i]->phone_number,d->contacts_by_phone_number[j]->phone_number)>0)
                        {
                                Contact* temp = d->contacts_by_phone_number[i];
                                d->contacts_by_phone_number[i] = d->contacts_by_phone_number[j];
                                d->contacts_by_phone_number[j] = temp;


                        }
                }
        }



        return;
}
/*if(strcmp(d->contacts_by_phone_number[k]->phone_number,d->contacts_by_phone_number[k+1]->phone_number)>0){
                        cout<<"Hello World"<<endl;

                }

*/

// This function will delete all the Contact objects and the Telephone_Directory object.
void delete_telephone_directory(Telephone_Directory* d) {

        
        delete d;
        d = nullptr;

}

