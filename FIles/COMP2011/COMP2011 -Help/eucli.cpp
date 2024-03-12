#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    double x;
    double y;
};

void print_distance(const Point*, const Point* );

void print_distance(const Point* p1, const Point* p2)
 {
 cout << "Distance between ";
 cout << " and "; 
 cout << " is "<< endl;
 cout<< p1->x<<  " "<< p1->y<<" "<<p2->x<<" "<<p2->y <<endl;
 }


int main(){

    Point a,b;
    cin>>a.x;
    cin>>a.y;

    cin>>b.x;
    cin>>b.y;


    print_distance(&a,&b);


    return 0;
}