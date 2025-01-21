//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3,5,6 and 9.
//The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
using namespace std;
int main()
{
	int i=0;
	//I want to learn to make a stack. I bet it uses pointers.
	// add each found number to a stack that I can print
	int sum=0;
	for(i=0;i<999;i++)
	{
		if((i+1)%3==0)//15 is added here
		{
			sum+=(i+1);
		}
		else if((i+1)%5==0)//thus 15 is skipped here and avoids duplicate summation.
		{
			sum+=(i+1);
		}
	}
	cout << sum << endl;	
	cout << "fuck programming" << endl;
}