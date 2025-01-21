#include <iostream>
#include <string>

int main(void)
{
	std::string s[31];
	s[0]="";
	s[1]="one";
	s[2]="two";
	s[3]="three";
	s[4]="four";
	s[5]="five";
	s[6]="six";
	s[7]="seven";
	s[8]="eight";
	s[9]="nine";
	s[9]="nine";
	s[10]="ten";
	s[11]="eleven";
	s[12]="twelve";
	s[13]="thirteen";
	s[14]="fourteen";
	s[15]="fifteen";
	s[16]="sixteen";
	s[17]="seventeen";
	s[18]="eighteen";
	s[19]="nineteen";
	s[20]="twenty";
	s[21]="thirty";
	s[22]="forty";
	s[23]="fifty";
	s[24]="sixty";
	s[25]="seventy";
	s[26]="eighty";
	s[27]="ninety";
	s[28]="hundred";
	s[29]="thousand";
	s[30]="and";
	
	//std::cout<<s1<<std::endl;
	
	//1,000
	//thousand,hundred, and ,tens, ones
	
	std::string s1="";
	int x,y;
	int sum=0;
	for(int i=1;i<=1000;i++)
	{
		s1="";
		y=i%10;
		if((i)>=1000)
		{
			s1.append(s[(i/1000)%10]+s[29]);
		}
		if((i)>=100)
		{
			x=(i/100)%10;
			if(x>0)s1.append(s[x]+s[28]);
			if(((i/10)%10) || y)s1.append(s[30]);
		}
		x=(i/10)%10;
		
		if((i)>=10)
		{
			int i=(10*x)+y;
			if(x==1)s1.append(s[i]);
			else if(x!=0) s1.append(s[(20+x-2)]);
		}
		if(y!=0 && x!=1)s1.append(s[y]);
		std::cout<<s1.length()<<": "<<s1<<std::endl;
		sum+=s1.length();
	}
	std::cout<<sum<<std::endl;
	
	return 0;
}