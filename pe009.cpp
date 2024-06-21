//A Pythagorean triplet is a set of three natural numbers, a<b<c, for which,
//a^2+b^2=c^2.
//For example, 3^2+4^2=9+16=25=5^2.

//There exists exactly one pythagorean triplet for which a+b+c=1000.
//Find the product abc.


#include <iostream>

int main()
{
	//brute force
	//triple for loop and c is always bigger than a and b individually.
	long long as=0,bs=0,cs=0;
	for(int a=0;a<1000;a++)
	{
		for(int b=0;b<1000;b++)
		{
			for(int c=0;c<1000;c++)
			{
				as=a*a;
				bs=b*b;
				cs=c*c;
				if(c<a || c<b)continue;
				else if(a+b+c==1000 && (as+bs)==cs)std::cout<<"A: "<<a<<", A^2: "<<(a*a)<<"B: "<<b<<", B^2: "<<(b*b)<<"C: "<<c<<", C^2: "<<(c*c)<<", ABC: "<<a*b*c<<std::endl;
			}
		}
	}
	return 0;
}