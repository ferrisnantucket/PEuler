//3x+1 longest chain under 1MM

#include <iostream>

void collatz(long long num, int& count)
{
	count++;
	if(num==1)return;
	else if(num%2==0)collatz((num/2),count);
	else collatz(((3*num)+1),count);
}

int main()
{
	int index=0;
	int largest=0;
	int count=0;
	for(int i=1;i<1000000;i++)
	{
		count=0;
		collatz(i,count);
		//std::cout<<count<<std::endl;
		if(count>largest)
		{
			index=i;
			largest=count;
		}
	}
	
	std::cout<<index<<", chainCount: "<<largest<<std::endl;
	return 0;
}