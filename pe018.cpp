/**

3
7 4
2 4 6
8 5 9 3


75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
**/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
	std::string s=R"(
		75
		95 64
		17 47 82
		18 35 87 10
		20 04 82 47 65
		19 01 23 75 03 34
		88 02 77 73 07 63 67
		99 65 04 28 06 16 70 92
		41 41 26 56 83 40 80 70 33
		41 48 72 33 47 32 37 16 94 29
		53 71 44 65 25 43 91 52 97 51 14
		70 11 33 28 77 73 17 78 39 68 17 57
		91 71 52 38 17 14 91 43 58 50 27 29 48
		63 66 04 68 89 53 67 30 73 16 69 87 40 31
		04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
	)";
	
	//parse string
	std::stringstream stream(s);
	std::string nextNumStr;
	
	//array init
	int numRows=15;

	int **tri=new int*[numRows];
	int **sum=new int*[numRows];
	int indices[numRows];
	
	//init size of 2d array
	for(int i=0;i<numRows;i++)
	{
		tri[i]=new int[i+1];
		sum[i]=new int[i+1];
	}
	
	//fill 2d array with data
	for(int i=0;i<numRows;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			stream >> nextNumStr;
			tri[i][j]=std::stoi(nextNumStr);
			sum[i][j]=tri[i][j];
		}
	}
	
	//start with second to last row and work towards the top.
	//add the highest number from the row below of the "left" (down, same j index) or "right" (down and right, j+1 index)
	for(int i=numRows-2;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			if(sum[i+1][j]>sum[i+1][j+1]) sum[i][j]+=sum[i+1][j];
			else sum[i][j]+=sum[i+1][j+1];
		}	
	
	}
	
	
	for(int i=0;i<numRows;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			std::cout<<tri[i][j]<<":"<<sum[i][j]<< " ";
		}
		std::cout<<std::endl;
	}
	//pick highest number and save the index of the best number for each row.
	int j=0;
	for(int i=0;i<numRows;i++)
	{
		if(i==0 || sum[i][j]>sum[i][j+1]) indices[i]=j;
		else indices[i]=++j;
		
		std::cout<<"Indices "<<i<<": "<<indices[i]<<std::endl;
	}
	
	//return max sum based off indices
	int max=0;
	int index=0;
	for(int i=0;i<numRows;i++)
	{
		index=indices[i];
		max+=tri[i][index];
		std::cout<<tri[i][index]<<std::endl;
	}
	std::cout<<"Max: "<<max<<std::endl;
	return 0;
}