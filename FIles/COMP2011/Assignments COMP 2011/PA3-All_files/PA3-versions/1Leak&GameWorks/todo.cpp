//ONLY SUBMIT THIS FILE TO ZINC
#include "given.h"
#include "todo.h"
#include <iostream>
using namespace std;
//be reminded that you should NOT include any additional library, please read "Additional Notes" on the PA3 webpage 

Node* ll_create(Thing thing,int quantity){


    Node* p = new Node;

    p->thing = thing;
    p->quantity = quantity;
    p->next = nullptr;
    
    return p;

}

void deallocate(Node* a){
    
    delete a;
    a = nullptr;

    return;
}

////search for similar Things
Node* ll_search(Node* head, Thing thing){
    for(Node* temp = head; temp!= nullptr;temp = temp->next){
        if (temp->thing == thing){
            return temp;
        }
    }

    return nullptr;
}


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

    return p;
}

void printHeroStatus(const HeroStatus& heroStatus)
{

    cout<<"Hero status: x="<<heroStatus.x<<" y="<<heroStatus.y<<" #mace="<<heroStatus.maceCount<<" #dagger="<<heroStatus.daggerCount;
    cout<<" #sword="<<heroStatus.swordCount<<endl;

}

void printMonsterCount(Node*** map, int width, int height)
{
    if(getMonsterCount(map,width,height)==1){
        cout<<"There is still one more monster left!"<<endl;
    }
    else
    {
        cout<<"There are "<<getMonsterCount(map,width,height)<<" monsters left in the world!"<<endl;
    }
}

int getLinkedListLength(const Node* head)
{
    int length = 0;
    for(const Node* temp = head; temp != nullptr; temp = temp->next){
        ++length;
    }

    return length;
}

bool addThing(Node*** map, int width, int height, int x, int y, Thing thing, int quantity)
{
    int size;

    if(x<0 || y<0 || x > width-1 || y>height-1){
        return false;
    }

    if(map[y][x] == NULL){

        Node* head;
        head = ll_create(thing,quantity);
        deallocate(ll_create(thing,quantity));
        head->next = nullptr;
        map[y][x] = head;

    }

    else
    {
        if(map[y][x]!=NULL){
            Node* head = map[y][x];
            //creates the new node with it's values
            deallocate(ll_create(thing,quantity));
            //insert at the beginning

            //special case insert after head
            if(head->next == nullptr){

                if(head != ll_search(head,thing)){
                    Node* newnode = ll_create(thing,quantity);
                    head->next = newnode;
                    newnode->quantity = quantity;    
                }

                if(head == ll_search(head,thing)){
                    head->quantity = head->quantity + quantity; 
                }

            }

            else
            {
                Node* head = map[y][x];
                Node* temp = head;
                Node* newnode = ll_create(thing,quantity);
                deallocate(ll_create(thing,quantity));
                

                ///search if got the same
                if(newnode == ll_search(temp,thing)){
                    temp->quantity = temp->quantity + newnode->quantity;

                }

                else{

                    for(temp;temp->next != nullptr; temp = temp->next);
                    newnode->next = temp->next;
                    temp->next = newnode;

                }
                
            }
            

            
        }

    }



    return true;
}

bool removeThing(Node*** map, int width, int height, int x, int y, Thing thing, int quantity)
{
    if(x<0 || y<0 || x > width-1 || y>height-1){
        return false;
    }

    Node* head = map[y][x];
    Node* temp = head;
    Node* temp2 = head;

    for(temp2;temp2!=nullptr;temp2 = temp2->next){

        
        if(ll_search(temp,thing) == temp2){
            if( temp2->quantity > quantity){
                temp2->quantity = temp2->quantity - quantity;

                return true;
            }

            if( temp2->quantity == quantity){
                temp2->quantity = temp2->quantity - quantity;
                if (head == temp2){
                    map[y][x] = nullptr;
                }

                return true;

            }

            
        }

    }


    
    

    return false;
}

void deleteLinkedList(Node*& head)
{
    if(head == nullptr){
        return; 
    }

    else
    {
       deleteLinkedList(head->next);
       delete head;
       head = nullptr;
       return;

    }
    
    
    
    
}

void deleteMap(Node*** map, int width, int height)
{
    for(int j=0;j<height;++j){

        for(int i=0; i<width; ++i){
            deleteLinkedList(map[j][i]);
        }

        delete [] map[j]; 
        map[j] = nullptr;
    }

    delete [] map;
    map = nullptr;

    
}

bool moveHero(char move, Node*** map, int width, int height, HeroStatus &heroStatus)
{
    if(heroStatus.x <0 || heroStatus.y <0 || heroStatus.x > width-1 || heroStatus.y > height-1){
        return false;
    }

    if(heroStatus.alive == true)
    {
        switch(move){
        case 'd':
        if(heroStatus.x + 1 < width -1 || heroStatus.x+1 == width -1){

            heroStatus.x = heroStatus.x + 1;
            ///if cell is empty
            if(map[heroStatus.y][heroStatus.x]==nullptr){
                addThing(map,width,height,heroStatus.x,heroStatus.y,HERO,1);
                removeThing(map,width,height,heroStatus.x-1,heroStatus.y,HERO,1);
            }

            else
            {
                if(map[heroStatus.y][heroStatus.x] != nullptr){
                    removeThing(map,width,height,heroStatus.x-1,heroStatus.y,HERO,1);
                    Node* head = map[heroStatus.y][heroStatus.x];
                    Node* temp = head;

                    if(ll_search(temp,MACE) != nullptr){
                        heroStatus.maceCount = heroStatus.maceCount + ll_search(temp,MACE)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,MACE,ll_search(temp,MACE)->quantity);
                    }

                    if(ll_search(temp,DAGGER) != nullptr){
                        heroStatus.daggerCount = heroStatus.daggerCount + ll_search(temp,DAGGER)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,DAGGER,ll_search(temp,DAGGER)->quantity);
                    }

                    if(ll_search(temp,SWORD) != nullptr){
                        heroStatus.swordCount = heroStatus.swordCount + ll_search(temp,SWORD)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,SWORD,ll_search(temp,SWORD)->quantity);
                    }

                    //if move into a cell with monsters

                    if(ll_search(temp,VAMPIRE) != nullptr){
                        if(heroStatus.daggerCount > ll_search(temp,VAMPIRE)->quantity || heroStatus.daggerCount == ll_search(temp,VAMPIRE)->quantity){
                            heroStatus.daggerCount = heroStatus.daggerCount - ll_search(temp,VAMPIRE)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,VAMPIRE,ll_search(temp,VAMPIRE)->quantity);
                        }

                        if(heroStatus.daggerCount < ll_search(temp,VAMPIRE)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    if(ll_search(temp,SKELETON) != nullptr){
                        if(heroStatus.maceCount > ll_search(temp,SKELETON)->quantity || heroStatus.maceCount == ll_search(temp,SKELETON)->quantity){
                            heroStatus.maceCount = heroStatus.maceCount - ll_search(temp,SKELETON)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,SKELETON,ll_search(temp,SKELETON)->quantity);
                        }

                        if(heroStatus.maceCount < ll_search(temp,SKELETON)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    if(ll_search(temp,DRAGON) != nullptr){
                        if(heroStatus.swordCount > ll_search(temp,DRAGON)->quantity || heroStatus.swordCount == ll_search(temp,DRAGON)->quantity){
                            heroStatus.swordCount = heroStatus.swordCount - ll_search(temp,DRAGON)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,DRAGON,ll_search(temp,DRAGON)->quantity);
                        }

                        if(heroStatus.swordCount < ll_search(temp,DRAGON)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    addThing(map,width,height,heroStatus.x,heroStatus.y,HERO,1);

                    
                }
            }

            return true;

        }
        break;

        case 'a':
        if(heroStatus.x - 1 > 0 || heroStatus.x-1 == 0){
            heroStatus.x = heroStatus.x - 1;
            //if cell is empty
            if(map[heroStatus.y][heroStatus.x]==nullptr){
                addThing(map,width,height,heroStatus.x,heroStatus.y,HERO,1);
                removeThing(map,width,height,heroStatus.x+1,heroStatus.y,HERO,1);
            }

            else
            {
                if(map[heroStatus.y][heroStatus.x] != nullptr){
                    removeThing(map,width,height,heroStatus.x+1,heroStatus.y,HERO,1);
                    Node* head = map[heroStatus.y][heroStatus.x];
                    Node* temp = head;

                    if(ll_search(temp,MACE) != nullptr){
                        heroStatus.maceCount = heroStatus.maceCount + ll_search(temp,MACE)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,MACE,ll_search(temp,MACE)->quantity);
                    }

                    if(ll_search(temp,DAGGER) != nullptr){
                        heroStatus.daggerCount = heroStatus.daggerCount + ll_search(temp,DAGGER)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,DAGGER,ll_search(temp,DAGGER)->quantity);
                    }

                    if(ll_search(temp,SWORD) != nullptr){
                        heroStatus.swordCount = heroStatus.swordCount + ll_search(temp,SWORD)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,SWORD,ll_search(temp,SWORD)->quantity);
                    }

                    //if move into a cell with monsters

                    if(ll_search(temp,VAMPIRE) != nullptr){
                        if(heroStatus.daggerCount > ll_search(temp,VAMPIRE)->quantity || heroStatus.daggerCount == ll_search(temp,VAMPIRE)->quantity){
                            heroStatus.daggerCount = heroStatus.daggerCount - ll_search(temp,VAMPIRE)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,VAMPIRE,ll_search(temp,VAMPIRE)->quantity);
                        }

                        if(heroStatus.daggerCount < ll_search(temp,VAMPIRE)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    if(ll_search(temp,SKELETON) != nullptr){
                        if(heroStatus.maceCount > ll_search(temp,SKELETON)->quantity || heroStatus.maceCount == ll_search(temp,SKELETON)->quantity){
                            heroStatus.maceCount = heroStatus.maceCount - ll_search(temp,SKELETON)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,SKELETON,ll_search(temp,SKELETON)->quantity);
                        }

                        if(heroStatus.maceCount < ll_search(temp,SKELETON)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    if(ll_search(temp,DRAGON) != nullptr){
                        if(heroStatus.swordCount > ll_search(temp,DRAGON)->quantity || heroStatus.swordCount == ll_search(temp,DRAGON)->quantity){
                            heroStatus.swordCount = heroStatus.swordCount - ll_search(temp,DRAGON)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,DRAGON,ll_search(temp,DRAGON)->quantity);
                        }

                        if(heroStatus.swordCount < ll_search(temp,DRAGON)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    addThing(map,width,height,heroStatus.x,heroStatus.y,HERO,1);

                    
                }
            }

            return true;
        }
        break;

        case 'w':
        if(heroStatus.y -1 > 0 || heroStatus.y -1 == 0 ){
            heroStatus.y = heroStatus.y -1;
            //if cell is empty
            if(map[heroStatus.y][heroStatus.x]==nullptr){
                addThing(map,width,height,heroStatus.x,heroStatus.y,HERO,1);
                removeThing(map,width,height,heroStatus.x,heroStatus.y+1,HERO,1);
            }

            else
            {
                if(map[heroStatus.y][heroStatus.x] != nullptr){

                    removeThing(map,width,height,heroStatus.x,heroStatus.y+1,HERO,1);
                    Node* head = map[heroStatus.y][heroStatus.x];
                    Node* temp = head;

                    if(ll_search(temp,MACE) != nullptr){
                        heroStatus.maceCount = heroStatus.maceCount + ll_search(temp,MACE)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,MACE,ll_search(temp,MACE)->quantity);
                    }

                    if(ll_search(temp,DAGGER) != nullptr){
                        heroStatus.daggerCount = heroStatus.daggerCount + ll_search(temp,DAGGER)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,DAGGER,ll_search(temp,DAGGER)->quantity);
                    }

                    if(ll_search(temp,SWORD) != nullptr){
                        heroStatus.swordCount = heroStatus.swordCount + ll_search(temp,SWORD)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,SWORD,ll_search(temp,SWORD)->quantity);
                    }
                    
                    //if move into a cell with monsters

                    if(ll_search(temp,VAMPIRE) != nullptr){
                        if(heroStatus.daggerCount > ll_search(temp,VAMPIRE)->quantity || heroStatus.daggerCount == ll_search(temp,VAMPIRE)->quantity){
                            heroStatus.daggerCount = heroStatus.daggerCount - ll_search(temp,VAMPIRE)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,VAMPIRE,ll_search(temp,VAMPIRE)->quantity);
                        }

                        if(heroStatus.daggerCount < ll_search(temp,VAMPIRE)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    if(ll_search(temp,SKELETON) != nullptr){
                        if(heroStatus.maceCount > ll_search(temp,SKELETON)->quantity || heroStatus.maceCount == ll_search(temp,SKELETON)->quantity){
                            heroStatus.maceCount = heroStatus.maceCount - ll_search(temp,SKELETON)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,SKELETON,ll_search(temp,SKELETON)->quantity);
                        }

                        if(heroStatus.maceCount < ll_search(temp,SKELETON)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    if(ll_search(temp,DRAGON) != nullptr){
                        if(heroStatus.swordCount > ll_search(temp,DRAGON)->quantity || heroStatus.swordCount == ll_search(temp,DRAGON)->quantity){
                            heroStatus.swordCount = heroStatus.swordCount - ll_search(temp,DRAGON)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,DRAGON,ll_search(temp,DRAGON)->quantity);
                        }

                        if(heroStatus.swordCount < ll_search(temp,DRAGON)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    

                    addThing(map,width,height,heroStatus.x,heroStatus.y,HERO,1);



                }
            }
            
            
            return true;
        }
        break;

        case 's':
        if(heroStatus.y + 1 < height -1 || heroStatus.y + 1 == height -1){
            heroStatus.y = heroStatus.y +1 ;
            ///if cell is empty
            if(map[heroStatus.y][heroStatus.x]==nullptr){
                addThing(map,width,height,heroStatus.x,heroStatus.y,HERO,1);
                removeThing(map,width,height,heroStatus.x,heroStatus.y-1,HERO,1);
            }

            else
            {
                //hero arriving will delete that node(weapons)
                //update the no of items

                if(map[heroStatus.y][heroStatus.x]!=nullptr){
                    removeThing(map,width,height,heroStatus.x,heroStatus.y-1,HERO,1);
                    Node* head = map[heroStatus.y][heroStatus.x];
                    Node* temp = head;

                    if(ll_search(temp,MACE) != nullptr){
                        heroStatus.maceCount = heroStatus.maceCount + ll_search(temp,MACE)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,MACE,ll_search(temp,MACE)->quantity);
                    }

                    if(ll_search(temp,DAGGER) != nullptr){
                        heroStatus.daggerCount = heroStatus.daggerCount + ll_search(temp,DAGGER)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,DAGGER,ll_search(temp,DAGGER)->quantity);
                    }

                    if(ll_search(temp,SWORD) != nullptr){
                        heroStatus.swordCount = heroStatus.swordCount + ll_search(temp,SWORD)->quantity;
                        removeThing(map,width,height,heroStatus.x,heroStatus.y,SWORD,ll_search(temp,SWORD)->quantity);
                    }

                    ///if move into a cell with monsters

                    if(ll_search(temp,VAMPIRE) != nullptr){
                        if(heroStatus.daggerCount > ll_search(temp,VAMPIRE)->quantity || heroStatus.daggerCount == ll_search(temp,VAMPIRE)->quantity){
                            heroStatus.daggerCount = heroStatus.daggerCount - ll_search(temp,VAMPIRE)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,VAMPIRE,ll_search(temp,VAMPIRE)->quantity);
                        }
                        if(heroStatus.daggerCount < ll_search(temp,VAMPIRE)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    if(ll_search(temp,SKELETON) != nullptr){
                        if(heroStatus.maceCount > ll_search(temp,SKELETON)->quantity || heroStatus.maceCount == ll_search(temp,SKELETON)->quantity){
                            heroStatus.maceCount = heroStatus.maceCount - ll_search(temp,SKELETON)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,SKELETON,ll_search(temp,SKELETON)->quantity);
                        }
                        if(heroStatus.maceCount < ll_search(temp,SKELETON)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    if(ll_search(temp,DRAGON) != nullptr){
                        if(heroStatus.swordCount > ll_search(temp,DRAGON)->quantity || heroStatus.swordCount == ll_search(temp,DRAGON)->quantity){
                            heroStatus.swordCount = heroStatus.swordCount - ll_search(temp,DRAGON)->quantity;
                            removeThing(map,width,height,heroStatus.x,heroStatus.y,DRAGON,ll_search(temp,DRAGON)->quantity);
                        }
                        if(heroStatus.swordCount < ll_search(temp,DRAGON)->quantity){
                            heroStatus.alive = false;
                            return true;
                        }

                    }

                    addThing(map,width,height,heroStatus.x,heroStatus.y,HERO,1);

                }
            }
            

            return true;
        }

    }
        
    }

    return false;
  
}

int getMonsterCount(Node*** map, int width, int height)
{
    int num_of_monsters = 0;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            Node* head = map[i][j];
            for(Node* temp = head;temp!=nullptr;temp = temp->next){
                if(temp == ll_search(head,VAMPIRE)){
                    num_of_monsters = num_of_monsters + temp->quantity;
                }
                if(temp == ll_search(head,DRAGON)){
                    num_of_monsters = num_of_monsters + temp->quantity;
                }
                if(temp == ll_search(head,SKELETON)){
                    num_of_monsters = num_of_monsters + temp->quantity;
                }

            }

        }
    }

    return num_of_monsters;
}
