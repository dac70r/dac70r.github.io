/*
 * COMP2011 (Fall 2020) Assignment 1: Binary Numbers
 *
 * Student name: WONG Dennis Guan Ming	
 * Student ID: 20654091
 * Student email: dgmwong@connect.ust.hk
 *
 * Note:
 * 1. You CANNOT define and use any arrays.
 * 2. You CANNOT define and use any global variables.
 * 3. You CANNOT use the static keyword.
 * 4. You CANNOT include any extra libraries other than iostream.
 * 5. You CANNOT use any bitwise operators: ~, ^, |, & (since they are not taught in this course).
 * 6. You CANNOT change the function headers of the functions given in the tasks.
 * 7. You CANNOT use any string operations.
 * 8. You can add helper functions.
 */

#include <iostream>

using namespace std;

int onescomp(int num)
{
    int rem;
 
    if (num <= 1)
    {
        cout << !num;
        return 0;
    }
    rem = num % 2;
    onescomp(num / 2);
    cout << !rem;
}

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

int re(int n){
     int i, j, binary=0;

     

     i=1;

      for(j=n;j>0;j=j/2)
       {
        binary = binary +(n%2)*i;
        i=i*10;
        n=n/2;
        
       }
       return binary;
       
       }
     
     

// Task 1
int get_min_bits_length(int x)
{
	if (x>0){
		return counting(re(x)+1);
		
	}
	else if(x==0){
		return 2;
	}
	else 
	return counting(re(-x)+1);;
}

// Task 2
int get_bit_positive(int x, int n)
{
	// TODO
}

// Task 3
int get_bit_negative(int x, int n)
{
	// TODO
}

// Task 4
void print_2s_complement_representation(int x)
{	
	// TODO
}

// Task 5
void print_addition_carry_out(int a, int b)
{
	// TODO
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED

int main()
{
	while (true) {
		int option = 0;

		do {
			cout << "1. Task 1" << endl;
			cout << "2. Task 2" << endl;
			cout << "3. Task 3" << endl;
			cout << "4. Task 4" << endl;
			cout << "5. Task 5" << endl;
			cout << "0. Exit" << endl;
			cout << "Enter an option (0-5): ";
			cin >> option;
		} while (option < 0 || option > 5);
		
		if (option == 0)
			break;
		else if (option == 1) {
			int number;
			cout << "Enter a number: ";
			cin >> number;
			cout << number << " needs " << get_min_bits_length(number) << " bits." << endl;
		}
		else if (option == 2) {
			int number;
			int bit;

			cout << "Enter a number: ";
			cin >> number;

			cout << "Which bit? ";
			cin >> bit;
			
			cout << "The number " << bit << " bit of " << number << " is " << get_bit_positive(number, bit) << endl;
		}
		else if (option == 3) {
			int number;
			int bit;

			cout << "Enter a number: ";
			cin >> number;

			cout << "Which bit? ";
			cin >> bit;
			
			cout << "The number " << bit << " bit of " << number << " is " << get_bit_negative(number, bit) << endl;
		}
		else if (option == 4) {
			int number;
			cout << "Enter a number: ";
			cin >> number;
			cout << "The 2's complement representation of " << number << " is:" << endl;
			print_2s_complement_representation(number);
		}
		else if (option == 5) {
			int a, b;
			cout << "Enter number A: ";
			cin >> a;
			cout << "Enter number B: ";
			cin >> b;
			cout << "The sum of " << a << " and " << b << " is " << a + b << ". The carry bits are:" << endl;
			print_addition_carry_out(a, b);
		}

		cout << endl;
	}

	return 0;
}