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

