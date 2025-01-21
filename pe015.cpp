//20 x 20 moving only right and down, how many possible routes?

#include <iostream>

int main()
{
	int gridSize=2;
	//array that holds the path count at each index.
	//0,0 is starting state and 20,20 is goal state.
	long long pathCount[1+gridSize][1+gridSize];
	
	//get pathCount of current node.
	//current node is equal to the bottom node plus the right node's path count
	
	
	
	for(int i=gridSize;i>-1;i--)
	{
		for(int j=gridSize;j>-1;j--)
		{
			if(i==gridSize && j==gridSize)pathCount[gridSize][gridSize]=1;//goal node set to zero
			else
			{
				//add both right and bottom node's path count if possible
				if(i<gridSize && j<gridSize)pathCount[i][j]=pathCount[i+1][j]+pathCount[i][j+1];
				else if(i<gridSize && j==gridSize)pathCount[i][j]=pathCount[i+1][j];
				else if(i==gridSize && j<gridSize)pathCount[i][j]=pathCount[i][j+1];
			}
		}
	}
	std::cout<<pathCount[0][0]<<std::endl;
	return 0;
}