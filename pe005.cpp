//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>
#include <cmath>

//void getFactors(int num, int (&temp)[8]);
bool isPrime(int num)
{
	for(int i=sqrt(num);i>0;i--)
	{
		if(i==1)return true;
		else if(num%i==0)return false;
	}
}
//void getFactors(int num, int temp[]);
void getFactors(int num, int temp[])
{
	if(isPrime(num)){temp[num]++;return;}
	for(int s=num-1;s>0;s--)
	{
		if(s==1)return;
		else if(num%s==0)
		{	
			if(isPrime(s))temp[s]++;
			else getFactors(s, temp);
			if(isPrime(num/s))temp[num/s]++;
			else getFactors((num/s), temp);
			return;
		}
	}
}
int main()
{
	int arrSize=21;
	int largest[arrSize];
	int temp[arrSize];
	for(int x=0;x<arrSize;x++)largest[x]=temp[x]=0; //reset arr to 0s
	for(int i=2;i<arrSize+1;i++)
	{
		for(int x=0;x<arrSize;x++)temp[x]=0; //reset arr to 0s
		getFactors(i,temp);
		for(int j=0;j<arrSize;j++)if(temp[j]>largest[j])largest[j]=temp[j]; //set largest values in largest array
	}
	int prod=1;
	
	for(int x=1;x<arrSize;x++)
	{
		prod=static_cast<int>(round(prod*pow(x,largest[x]))); //pow function returns a float which causes floating point error
	}
	
	
	for(int x=0;x<arrSize;x++)std::cout<<largest[x]<<", ";
	std::cout<<std::endl;
	
	
	std::cout<<"Product: "<<prod<<std::endl;
	
	return 0;
}


//generate all prime factors used for each number and record the highest number used for each prime.
//for example, 16 is made up of 2 * 2 * 2 * 2 and has the highest number of 2's used and thus a quantity 4 will be recorded for the factor "2".