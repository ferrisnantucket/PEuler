#include <iostream>
#include <cinttypes>

const uint32_t NUM_CELLS = 4;
//
uint8_t cells[NUM_CELLS];

int main()
{
	int32_t i;
	uint8_t remainder;
	uint8_t bring_down;
	uint32_t accumulator;
	uint32_t sum=0;
	bool zero=false;
	
	cells[NUM_CELLS-1]=8;
	
	while(!zero)
	{
		remainder=0;
		zero=true;

		for(i=NUM_CELLS-1;i>=0;i--)
		{
			bring_down = cells[i];
			zero= (bring_down ? false : zero);
			accumulator=(remainder << 4) + bring_down;
			cells[i] = accumulator / 10;
			remainder = accumulator % 10;
		}
		sum += remainder;
	}	
	std::cout<<sum<<std::endl;
	return 0;
}