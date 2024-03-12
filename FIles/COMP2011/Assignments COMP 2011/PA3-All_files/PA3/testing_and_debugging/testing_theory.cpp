#include<iostream>
using namespace std;

enum Thing
{
    MACE,
    DAGGER,
    SWORD,
    SKELETON,
    VAMPIRE,
    DRAGON,
    HERO
};

struct Node
{
    Thing thing; //the thing type that this node represents
    int quantity = 1; //the number of the thing
    Node *next = nullptr;  //the next pointer, remember the last node's "next" must point to nullptr
};

Node*** generateMap(int width, int height)
{
    //creates a 2D array
    Node*** p = new Node**[height];
    for(int k=0;k<height;k++){
        p[k] = new Node*[width];
    }

    for(int i=0;i<height;i++){
        for(int k =0;k<width;k++){
            p[i][k] = nullptr;
        }
    }

    return p; //it is a dummy return statement, you can remove it if you want
}





int main(){




    return 0;
}