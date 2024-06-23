//The sum of the primes below 10 is 2+3+5+7=17.
//Find the sum of all the primes below two million.

//Copied code from pe007.cpp but made a larger array to hold more primes allocated to the heap.
//sum the primes as I find them and break the loop when counter reaches a number of 2,000,000 or larger.
#include <iostream>

int main()
{
	int numPrimes=1000000;
	int i=0;
	int* foundPrimes = new int[numPrimes]; //stack overflow must allocate to heap
	foundPrimes[i]=2;
	i++;
	int counter=3;
	long long sum=2;
	
	while(i<numPrimes)
	{
		for(int x=0;x<i;x++)
		{
			if(counter%foundPrimes[x]==0)break;
			else if(x==i-1){foundPrimes[i]=counter;sum+=counter;i++;}
		}
		counter++;
		if(counter>2000000)break;
	}
	
	
	std::cout<<sum<<std::endl;
	return 0;
}