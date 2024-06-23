//By listing the first six prime numbers: 2,3,5,7,11, and 13 we can see that the 6th prime is 13.
//Wht is the 10,001st prime number?


#include <iostream>

int main()
{
	int numPrimes=10001;
	int i=0;
	long long foundPrimes[numPrimes];
	foundPrimes[i]=2;
	i++;
	long long counter=3;
	//loop through all primes found to test if current number is prime.
	//if the current number is not divisible by any found prime then the current number is prime.
	while(i<numPrimes)
	{
		for(int x=0;x<i;x++)
		{
			if(counter%foundPrimes[x]==0)break;
			else if(x==i-1){foundPrimes[i]=counter;i++;}
		}
		counter++;
	}
	for(int x=0;x<numPrimes;x++)std::cout<<foundPrimes[x]<<std::endl;
	return 0;
}