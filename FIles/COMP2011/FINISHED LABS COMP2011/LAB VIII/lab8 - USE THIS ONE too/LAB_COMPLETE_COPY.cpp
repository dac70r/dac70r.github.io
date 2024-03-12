#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
using namespace std;

//Global constant definition
const int PLAYER_NUM = 5;
const int SIZE = 5;
const int MAX_NAME_LENGTH = 10;
const int MAX_NUMBER = SIZE * SIZE;

// User-defined data type
struct Player
{ 
    char name[MAX_NAME_LENGTH];  
    int bingo_card[SIZE][SIZE];             
    bool card_status[SIZE][SIZE];     // 0 for empty, 1 for occupied
    bool bingo;               
};

/*
Task 1
Initialize the players:
Assign the name
Randomly generate a bingo card
Initialize card_status to all zeros and bingo to false
*/

void init_player(Player& players,char name[]){

    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    
    for(int i=25-1; i>0; i--){
        int j = rand()%(i+1);

        swap(a[i],a[j]);
    }

    strcpy(players.name,name);
    
    players.bingo_card[SIZE][SIZE];
    players.card_status[SIZE][SIZE];
    players.bingo = false;
    int f=0;

    for(int i=0;i<5;i++){
        for(int k=0;k<5;k++){
            
            players.bingo_card[i][k] = a[f];
            players.card_status[i][k] = false;
            f++;
        }
    }

    return;

}

void display_info(Player plys[], int PLAYER_NUM)
{
    int n;
    for(int k=0;k<PLAYER_NUM;k++){

        
        
        cout.width(6);cout<<"Name: "<<plys[k].name;
        cout.width(6);cout<<endl;
        cout.width(6);cout<<"Bingo card ('*' means the number has been picked)"<<endl;
        
        for(int j=0;j<5;j++){
            for(int m=0;m<5;m++){
                n++;
                cout<<plys[k].bingo_card[j][m];
                if(plys[k].card_status[j][m]==true){
                    cout<<"*";
                }
                //formatting
                if(n%5==0){
                    cout<<endl;
                }
                else
                {
                    cout<<"\t";
                }

            }
        }

    }
    return;
}

/*
Task 3:
Change the status for picked number:
You should find the position of the number you picked in bingo card and update the status.
*/

// function name: change_status
// Your code here

void change_status(Player &players,int number_selected){
    int a;
    for(int k=0;k<PLAYER_NUM;k++){
        for(int j=0;j<5;j++){
            for(int m=0;m<5;m++){

                if(number_selected == players.bingo_card[j][m]){
                    players.card_status[j][m] = true;

                }
    
            }
        }

    }
       
    return;
}

/*
Task 4:
Check bingo:
You should check the status for all rows, columns and two diagonals. 
Return true if there is an entire occupied line, otherwise, return false.
*/

// function name: check_bingo
// Your code here
bool check_bingo(Player &players){
    //horizontal
    if(players.card_status[0][0]==true && players.card_status[0][1]==true && players.card_status[0][2]==true && players.card_status[0][3]==true && players.card_status[0][4]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[1][0]==true && players.card_status[1][1]==true && players.card_status[1][2]==true && players.card_status[1][3]==true && players.card_status[1][4]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[2][0]==true && players.card_status[2][1]==true && players.card_status[2][2]==true && players.card_status[2][3]==true && players.card_status[2][4]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[3][0]==true && players.card_status[3][1]==true && players.card_status[3][2]==true && players.card_status[3][3]==true && players.card_status[3][4]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[4][0]==true && players.card_status[4][1]==true && players.card_status[4][2]==true && players.card_status[4][3]==true && players.card_status[4][4]==true){
            players.bingo = true;
            return true;
    }
    //vertical
    if(players.card_status[0][0]==true && players.card_status[1][0]==true && players.card_status[2][0]==true && players.card_status[3][0]==true && players.card_status[4][0]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[0][1]==true && players.card_status[1][1]==true && players.card_status[2][1]==true && players.card_status[3][1]==true && players.card_status[4][1]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[0][2]==true && players.card_status[1][2]==true && players.card_status[2][2]==true && players.card_status[3][2]==true && players.card_status[4][2]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[0][3]==true && players.card_status[1][3]==true && players.card_status[2][3]==true && players.card_status[3][3]==true && players.card_status[4][3]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[0][4]==true && players.card_status[1][4]==true && players.card_status[2][4]==true && players.card_status[3][4]==true && players.card_status[4][4]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[0][0]==true && players.card_status[1][1]==true && players.card_status[2][2]==true && players.card_status[3][3]==true && players.card_status[4][4]==true){
            players.bingo = true;
            return true;
    }

    if(players.card_status[0][4]==true && players.card_status[1][3]==true && players.card_status[2][2]==true && players.card_status[3][1]==true && players.card_status[4][0]==true){
            players.bingo = true;
            return true;
    }
  
    else
    {
        return false;
    }
    
    
}

int main()
{
    srand((unsigned) time(NULL));
    bool END = false;
    struct Player plys[PLAYER_NUM];
  	
    // input information for each player
	for(int i = 0; i < PLAYER_NUM; i++){
        char name[MAX_NAME_LENGTH];
		cout << "Player " << i + 1 << endl;
		cout << "Enter name (shorter than 10 characters)" << endl;
		cin >> name;
		cout << "Generating bingo card for player " << i + 1 << "..." << endl;
        init_player(plys[i], name);
	}
    cout << "Initialization done." << endl;
    display_info(plys, PLAYER_NUM);

    // Start game
    cout << endl;
    cout << "=================Welcome to Bingo Game=================" << endl;

    int round = 0;
    while(!END){

        cout << "-----------Round " << ++ round << "-----------" << endl;
        cout << "Please select a number between 1 to 25: ";
        int selected_number;
        cin >> selected_number;

        for(int i = 0; i < 5; i ++){
            change_status(plys[i], selected_number);
            bool ret = check_bingo(plys[i]);
            if (ret){
                END = true;
            }
        }

        display_info(plys, PLAYER_NUM);
    }

    // print the winner(s)
    for(int i = 0; i < 5; i ++){
        if (plys[i].bingo)
            cout << plys[i].name << " is the winner!" << endl;
    }
    cout << "=================Game over==================" << endl;

    return 0;

}
