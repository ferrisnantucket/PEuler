/** The prime factors of 13195 are 5,7,13 and 29.
	What is the largest prime factor of the number 600851475143?**/

#include <iostream>
#include <cmath>

bool isPrime(long long num)
{
	long long s=sqrt(num);
	//std::cout << s << std::endl;
	for(;s>0;s--)
	{
		if(s==1)return true;
		else if(num%s==0) return false;
	}	
}
int getDivisors(long long num)
{
	
	long long s=sqrt(num);
	//std::cout << s << std::endl;
	for(;s>0;s--)
	{
		if(s==1)return 0;
		else if(num%s==0)
		{
			if(isPrime(s))
			{
				std::cout <<num<<": "<< s << std::endl;
			}
		}
	}
	
}

//void 

int main()
{
	long long n=13195;
	long long n2=600851475143;
	
	getDivisors(n2);
	return 0;
}

/**

#include <iostream>
#include <cstdlib>

int main()
{
    int* myArray = (int*) malloc(sizeof(int) * 10); // allocates memory for 10 integers
    // you can later resize the array using realloc
    // for example:
    myArray = (int*) realloc(myArray, sizeof(int) * 20); // resizes the array to hold 20 integers
    return 0;
}

**/


/**   int* myArray = (int*) malloc(sizeof(int) * 1);
	myArray[0]=69;
	myArray = (int*) realloc(myArray, sizeof(int) * 2);
	std::cout<<myArray[0];
	myArray[1]=70;
	std::cout<<myArray[1];**/