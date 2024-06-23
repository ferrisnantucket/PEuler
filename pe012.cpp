#include <iostream>
#include <cmath>
int triangle_number(int num)
{
	int sum=0;
	for(int i=0;i<num;i++)sum+=i+1;
	return sum;
}
int numFactors(int num)
{
	int count=0;
	for(int i=sqrt(num);i>0;i--)
	{
		if(num%i==0)
		{
			count++;
			if(i*i!=num && i!=1)count++;
		}
		
	}
	return count;
}
int main()
{
	int tri=0,count=0,i=0;
	while(count<500)
	{
		tri=triangle_number(i);
		count=numFactors(tri);
		i++;
	}
	std::cout<<tri<<std::endl;
	//std::cout<< <<std::endl;
	
}