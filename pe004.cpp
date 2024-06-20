//A palindromic number reads the same both ways. 
//The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.

//Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <string>

int main()
{
	int largest=0;
	int li=0, lj=0;
	for(int i=100;i<1000;i++)
	{
		for(int j=100;j<1000;j++)
		{
			int p=i*j;
			if(p/100000%10!=0)
			{
				if(p%10==p/100000%10 && p/10%10==p/10000%10 && p/100%10==p/1000%10 && p>largest)
				{
					largest=p;
					li=i;
					lj=j;
				}
			}
			else
			{
				if(p%10==p/10000%10 && p/10%10==p/1000%10 && p>largest)
				{
					largest=p;
					li=i;
					lj=j;
				}
			}
		}
	}
	std::cout<<li<<" ,"<<lj<<": "<<largest;
	
	return 0;
}

//how do I get each individual digit from the product of numbers?
//use the mod operator

//how many digits are in the product?
//product will have a min of 5 digits (100x100) and a max of 6 digits (999x999=998001)
//if product mod 100000==0 then product is 5 digits.

//if 5 digits long then compare 1's and 10000's digit and 10's and 1000's digit
//if 6 digits then compare 1's and 100000's digit, 10's and 10000's digit, and 100's and 1000's digit

//how to find the largest palindrome?
//brute force?