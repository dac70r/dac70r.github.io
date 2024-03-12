/*
 * COMP2011 (Fall 2020) Assignment 1: Binary Numbers
 *
 * Student name: WONG, Dennis Guan Ming
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

// Task 1
int get_min_bits_length(int x)
{
	int j = x;
	int count = 2;
	int k = 2;

	if (x>=0){
		for(j;j>=(k-1);){

		count++;
		k = k*2;
	

		}
	}
	else
	{
		x = -(x);
		int m = 2;
		int l = x;

		for(l;l>m;){

		count++;
		m = m*2;
	

		}
	}
	
	
	return count;
	

}

// Task 2
int get_bit_positive(int x, int n)
{	
	int count = 0;
	if((x==-1)||(n==-1)){


		return -1;
	}

	else
		while(count<=n){
			if(count != n){count++; x/=2;}

			else
				return (x%2);


		}
	

}

// Task 3
int get_bit_negative(int x, int n)
{
	int count = 0;
	if(x>=0){return -1;}
	else if(n<0){return -1;}

	else{
		while(count<=n){
			if (count !=n){count++;}

			else
			{
				return 1-get_bit_positive((-x-1),count);
			}
			
		}
	}

} 

// Task 4
void print_2s_complement_representation(int x)
{	
	int count = 0;
	int j=x;
	
	while(count<get_min_bits_length(j)){
		count++;
		int a;
		if(j<0){
			cout<<1-get_bit_positive((-j-1),get_min_bits_length(j)-count);
		}
		else
		{
			 cout<<get_bit_positive(j, count);
			
		}
		

		}
		return;
	}


// Task 5
void print_addition_carry_out(int a, int b)
{
	print_2s_complement_representation(a+b);


	return;
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