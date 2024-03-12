#include<iostream>
#include <cstring>
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
Hint: you can use "std::random_shuffle()" function to generate 1d array with size 25, and resize it to 5x5 2d array
*/

// function name: init_player
// Your code here




 
/*
Task 2:
Display five players' information:
If the number has been picked, add '*' after it. 
The output for each player looks like this:
___________________________________________________
Name: Peter
Bingo card ('*' means the number has been picked)
20      4       15      16      11
3       23      25      9*      5
21      8       6       12      2
10      1       22      14      19
13      24      7       17      18
*/
// function name: display_info
// Your code here




/*
Task 3:
Change the status for picked number:
You should find the position of the number you picked in bingo card and update the status.
*/

// function name: change_status
// Your code here


/*
Task 4:
Check bingo:
You should check the status for all rows, columns and two diagonals. 
Return true if there is an entire occupied line, otherwise, return false.
*/

// function name: check_bingo
// Your code here


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


