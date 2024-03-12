#include<iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
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

void random(int arr[],int n){

    srand((unsigned)time(NULL));

    for(int i=n-1; i>0; i--){
        int j = rand()%(i+1);
        swap(arr[i],arr[j]);
    }
    return;
}

void init_player(Player& players,char name[]){

    strcpy(players.name,name);
    players.bingo_card[SIZE][SIZE];
    
    return;

}

void display_info(Player plys[], int PLAYER_NUM)
{
    for(int k=0;k<PLAYER_NUM;k++){
        cout.width(6);cout<<plys[k].name<<endl;
    }

    
    return;
}


int main()
{
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

    cout << "=================Game over==================" << endl;
    return 0;
}