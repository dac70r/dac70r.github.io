#include <iostream>     /* File: inc-mod.cpp */
using namespace std;	

int main() 
{
    int x = 100, y = 100; // Variable definitions and initialization
    int a = 10, b = 10, c = 10, d = 10;
    
    cout << ++x << "\t"; cout << "x = " << x << endl; // Pre-increment 100, x = 10
    cout << y++ << "\t"; cout << "y = " << y << endl; // Post-increment 100, y = 10

    a = ++b; cout << "a = " << a << "\t" << "b = " << b << endl; //a = 11, b = 10 
    c = d++; cout << "c = " << c << "\t" << "d = " << d << endl;// c = 10, d = 10
    
    cout << 17%5 << endl; // Trickiness of the mod function // 3
    cout << (-17)%5 << endl; //-3
    cout << 17%(-5) << endl; // 3
    cout << (-17)%(-5) << endl; //-3
    
    return 0;
}
