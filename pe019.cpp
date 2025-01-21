#include<iostream>

int main()
{
	int year=1900;
	int month=1;
	int day=1;
	int nameDay=1;//sunday=0 monday=1 etc.
	int sundayCount=0;
	bool leap=false;
	bool startCount=false;
	while(year<2001)
	{
		if(day==1 && nameDay==0 && startCount) sundayCount++;
		
		if(year%4==0) leap=true;
		else leap=false;
		
		day++;
		nameDay++;
		if(nameDay>6)nameDay=0;
		if(
		((month==4 || month==6 || month==9 || month==11) && day>30) || 
		(month==2 && leap && day>29) ||
		(month==2 && !leap && day>28) ||
		((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) && day>31)
		)
		{
			day=1;
			month++;
		}
		if(month>12)
		{
			month=1;
			year++;
		}
		if(year>1900)startCount=true;
		
	}
	std::cout<<sundayCount<<std::endl;
	return 0;
}