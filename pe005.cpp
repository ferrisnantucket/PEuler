//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>
#include <cmath>

void getFactors(int num, int (&temp)[8]);

int main()
{
	//std::cout<<5*7*8*9;
	int arr[8]={2,3,5,7,11,13,17,19};
	int largest[]={0,0,0,0,0,0,0,0};
	int temp[8];
	for(int i=2;i<11;i++)
	{
		for(int x=0;x<8;x++)temp[x]=0;
		getFactors(i,temp);
		for(int j=0;j<8;j++)
		{
			if(temp[j]>largest[j])largest[j]=temp[j];
		}
	}
	for(int x=0;x<8;x++)std::cout<<largest[x]<<", ";
	//getFactors(20);
	return 0;
}
void getFactors(int num, int (&temp)[8])
{
	//std::cout << s << std::endl;
	
	for(int s=num-1;s>0;s--)
	{
		if(s==1)
		{
			//std::cout<<std::endl;
			return;
		}
		else if(num%s==0)
		{	
			if(s==2)
			{
				//std::cout<<num<<" :"<<s<<std::endl;
				temp[0]++;
			}
			else if(s==3)
			{
				temp[1]++;
			}
			else if(s==5)
			{
				temp[2]++;
			}
			else if(s==7)
			{
				temp[3]++;
			}
			else if(s==11)
			{
				temp[4]++;
			}
			else if(s==13)
			{
				temp[5]++;
			}
			else if(s==17)
			{
				temp[6]++;
			}
			else if(s==19)
			{
				temp[7]++;
			}

			if(num/s==2)
			{
				//std::cout<<num<<" :"<<s<<std::endl;
				temp[0]++;
			}
			else if(num/s==3)
			{
				temp[1]++;
			}
			else if(num/s==5)
			{
				temp[2]++;
			}
			else if(num/s==7)
			{
				temp[3]++;
			}
			else if(num/s==11)
			{
				temp[4]++;
			}
			else if(num/s==13)
			{
				temp[5]++;
			}
			else if(num/s==17)
			{
				temp[6]++;
			}
			else if(num/s==19)
			{
				temp[7]++;
			}
			getFactors(s, temp);
			getFactors(sqrt(num/s), temp);
		}
	}
}

//generate all prime factors used for each number and record the highest number used for each prime.
//for example, 16 is made up of 2 * 2 * 2 * 2 and has the highest number of 2's used and thus a quantity 4 will be recorded for the factor "2".