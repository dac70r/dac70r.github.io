#include<iostream>
using namespace std;
int main()
{
    int marks;
    char grade;
    cout<<"please enter your marks, we will tell you your grade"<<endl;
    cout<<"Your marks: ";cin>>marks;

    grade = (marks>=85)?'A':((marks>=60)?'B':((marks>=15)?'C':((marks>=5)?'D':'F')));

    cout<<grade<<endl;
    
    return 0;


}