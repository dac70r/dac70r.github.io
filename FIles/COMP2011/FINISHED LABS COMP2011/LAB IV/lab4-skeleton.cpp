#include <iostream>
#include <algorithm>

using namespace std;

// width and height of the maze
const int WIDTH = 11;
const int HEIGHT = 8;

// Given
нн{
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        cout << maze[i];
        if ((i + 1) % WIDTH == 0)
            cout << endl;
    }
}

// Task 1: find the position of a symbol
void find_pos(const char maze[], char symbol, int pos[]) {
    // TODO

}

// Task 2: check whether the move is valid or not based on the current position, including
// 3 situations: 1) hit the wall 2) goes beyond the maze boundary 3) illegal 'move' character, besides the defined 4 control directions.
bool is_valid_move(const char maze[], int pos[], char move) {
    // TODO

}

// Task 3: update the position info
void update_pos(int pos[], char move) {
    // TODO
        
}

// Task 4: check whether the prince & monster will see each other based on the positions of prince & monster
bool check_visible(const char maze[], const int prince_pos[], const int monster_pos[]) {
    // TODO

}

// Task 5: To update the position informations, status of prince, monster, weapon & snow white and 
// update the symbols of the maze
// Fill in the three missing parts for this incomplete Function 
//
// status_list[] stores the status of the objects in the game
// 	First element:  true if the monster 'M' is alive; otherwise false
// 	Second element: false if the weapon 'W' has not been fetched; otherwise true 
// 	Third element:  false if the Snow White 'S' has not been reached; otherwise true 
// 	Last element:   true the prince 'P' is alive; otherwise false
void update_maze(char maze[], int prince_pos[], char prince_move, int monster_pos[], char& monster_move, bool status_list[]) {
        
    // remove 'P' from the old position
    maze[prince_pos[1] * WIDTH + prince_pos[0]] = ' ';

    // update the position info of the prince
    update_pos(prince_pos, prince_move);

    // update the status of the weapean
    if (maze[prince_pos[1] * WIDTH + prince_pos[0]] == 'W')
        // TODO:
        // fill one line inside the above if statement to update the status of the weapon
    
    // update the status of snow white
    if (maze[prince_pos[1] * WIDTH + prince_pos[0]] == 'S')
        // TODO
        // fill one line inside the above if statement to update the status of the snow white


    // move prince to the new position
    maze[prince_pos[1] * WIDTH + prince_pos[0]] = 'P'; // assign 'P' to new position
                
    if (status_list[0]){ // if the monster is alive
        maze[monster_pos[1] * WIDTH + monster_pos[0]] = ' '; // remove 'M' 
        if (is_valid_move(maze, monster_pos, monster_move))
            update_pos(monster_pos, monster_move);
        else {
            monster_move = (monster_move == 'a') ? 'd': 'a';
            update_pos(monster_pos, monster_move);
        }       
        maze[monster_pos[1] * WIDTH + monster_pos[0]] = 'M'; // assign 'M' to new position

        bool vis = check_visible(maze, prince_pos, monster_pos);

        if (vis and (!status_list[1]))
            // TODO:
            // fill one line inside the above if statement to update the status of the prince 'P'
            cout<<"hello";
            
        else if (vis and status_list[1]) {
            status_list[0] = false;   
            maze[monster_pos[1] * WIDTH + monster_pos[0]] = ' '; // remove 'M' 
        }  
    }
}

int main() {
    // initial maze definition
    char maze[HEIGHT*WIDTH] = {'#', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', '#',
               '#', 'P', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
               '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ',
               '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', 
               ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', 
               'W', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', 
               '#', '#', ' ', 'M', ' ', ' ', ' ', ' ', ' ', ' ', '#', 
               '#', '#', ' ', '#', '#', '#', 'S', ' ', '#', 'E', '#' };

    int prince_pos[2], monster_pos[2], exit_pos[2];
    // positions of the prince, monster & exit
    // {x, y}, x defines column number , y defines row number
    // e.g. prince_pos[0] stores the column number, while prince_pos[1] stores the row number
              
    // find the initial position of the prince, monster & exit 
    find_pos(maze, 'P', prince_pos);
    find_pos(maze, 'M', monster_pos);
    find_pos(maze, 'E', exit_pos);

    cout << "***************************************************************" << endl;
    cout << "*** Welcome to the maze! Let's start saving our snow white! ***" << endl;
    cout << "***************************************************************" << endl;
    cout << "The prince (P) is in {" <<  prince_pos[0] << ", " << prince_pos[1] << "}" << endl;
    cout << "The monster (M) is in {" <<  monster_pos[0] << ", " << monster_pos[1] << "}" << endl;
    cout << "The exit (E) is in {" <<  exit_pos[0] << ", " << exit_pos[1] << "}" << endl;

    char prince_move;
    char monster_move = 'd';

    /* 
       Status_list stores the status of the objects in the game
       First element:  true if the monster 'M' is alive; otherwise false
       Second element: false if the weapon 'W' has not been fetched; otherwise true 
       Third element:  false if the Snow White 'S' has not been reached; otherwise true 
       Last element:   true the prince 'P' is alive; otherwise false
    */
    bool status_list[] = {true, false, false, true}; // see comments above
    
    do {
        print_maze(maze);
                cout << endl;
        cout << "Your (the prince) current position is at: (" << prince_pos[0] << ", " << prince_pos[1] << ")" << endl;
        cout << "Please enter your move: (up:w, down:s, left:a, right:d)  ";
        cin >> prince_move;
        if (is_valid_move(maze, prince_pos, prince_move)) {
            update_maze(maze, prince_pos, prince_move, monster_pos, monster_move, status_list);

            if (!status_list[3]){ // prince is alive or not
            	cout << "Game Over! Failed." << endl;
            	return 0;
            }
            if (!status_list[2] && !(prince_pos[0] == exit_pos[0] && prince_pos[1] == exit_pos[1]))
            	maze[exit_pos[1] * WIDTH + exit_pos[0]] = 'E';

        } else {
            cout << "Game Over! Failed." << endl;
            return 0;
        }
    } while (!(prince_pos[0] == exit_pos[0] && prince_pos[1] == exit_pos[1]) || !status_list[2]);

    cout << "Amazing! You have completed the maze!" << endl;
    return 0;
}
