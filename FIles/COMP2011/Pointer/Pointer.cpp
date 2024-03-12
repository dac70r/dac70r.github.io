#include<iostream>
using namespace std;

struct ll_node{
    char data;
    ll_node* next;

};

ll_node* create_node(char a){

    ll_node* newnode = new ll_node;
    newnode->data = a;
    newnode->next = nullptr;
    return newnode;

}

int main(){

    char text[] = "cats and dogs";
    ll_node* head = nullptr;
    head = create_node(text[0]);

    cout<<"Data contained inside head: "<<endl;
    cout<<head->data<<endl;

    ll_node* temp = head;
    
    cout<<"Now for the fun part: "<<endl;
    for(int i=1;text[i]!='\0';i++,temp = temp->next){
        temp->next = create_node(text[i]);
        cout<<temp->data;
        
    }
    
    
    cout<<endl;
    cout<<"Printing the string: "<<endl;
    for(temp = head; temp!= nullptr; temp = temp->next){
        cout<<temp->data;
    }

    ///when deleting, delete in the opposite direction

    for(ll_node* temp = head, *nextnode = nullptr; temp!=nullptr;){
        nextnode = temp->next;
        delete temp;
        temp  = nextnode;
   
    }




    return 0;
}