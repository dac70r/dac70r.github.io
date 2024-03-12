#include <iostream>

using namespace std;

//counting digits in a binary digit
int counting(int a){

    
    int  temp;
    int count = 0;
    // Store to temporary variable.
    temp = a;
    
    while(temp != 0) {

        // Increment counter
        count++;

        // Remove last digit of 'temp'
        temp /= 10;
    
    }
    return count;

}
int main() {


    // Take input from user
    int num;
    cout << "Enter any number : ";
    cin >> num;


    cout << endl << "Total digits in " << num << " : "<<counting(num);

    return 0;
}