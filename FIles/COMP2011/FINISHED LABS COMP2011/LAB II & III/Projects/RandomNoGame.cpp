#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    srand(time(nullptr));
    int guess;
     
    int target = rand()%100 + 1;


    cout<<"Welcome to the Guessing Game!"<<endl;
    
    /** cout<< target<<endl; ***/ 

    do{
        cout<<"Please enter a number to participate: "<<endl;
        cin>>guess;

        if (guess < target)
            cout<<"Too Small!"<<endl;

        else if(guess > target)
        cout<<"Too big!"<<endl;

        else
        cout<<"You got it!"<<endl;

    }while (guess != target);



    return 0;
}