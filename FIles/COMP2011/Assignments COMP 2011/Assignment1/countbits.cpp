/*Program to get minimum number of bits to store an integer number.*/

#include <iostream>
using namespace std;

/*function declaration
	* name		: countBit
	* Desc		: to get bits to store an int number
	* Parameter	: int 
	* return	: int 
*/
int countBit(int n)
{
	int count=0,i;
	if(n==0) return 0;
	for(i=0; i< 32; i++)
	{	
		if( (1 << i) & n)
			count=i;
	}
	return ++count;
}

int main()
{
	int num;
	cout<<"Enter an integer number :";
	cin>>num;

	countBit(num);
	return 0;
}

