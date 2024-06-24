//Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
	//std::ofstream file;
	//file.open("./myfile.txt");
	//file<<"REtest"<<std::endl;
	std::ifstream file;
	if(argc>1)file.open(argv[1]);
	if(file.is_open())
	{
		std::string s;
		long long sum=0;
		int i=0;
		while(std::getline(file,s))
		{
			//first 10 digit math on each string.
			
			//get last 10 digits of each string
			std::string s1=s.substr(38,49);
			
			//convert each substring to a long int and sum them as converted
			sum+=std::stoll(s1,nullptr,10);
			
			//std::cout<<s1<<std::endl;
		}
		//convert sum to 10 digit string.
		std::string sumString=std::to_string(sum);
		
		
		
		std::cout<<sumString.substr(sumString.length()-10,sumString.length())<<std::endl;
	}
	return 0;
}