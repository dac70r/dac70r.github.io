#include "lab8.h"

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

void init_player(Player& a,const char name[],int bingo_card[][SIZE],bool card_status[][SIZE],bool bingo){

    strcpy(a.name,name);
    

    return;
}





 
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

