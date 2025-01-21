#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL.h>

using namespace std;

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

	SDL_Window* window=nullptr;
	SDL_Renderer* renderer=nullptr;
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(640,480,0,&window,&renderer);
	
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	//SDL_RendererSetScale(renderer,4,4);
	SDL_RenderDrawPoint(renderer,640/2,480/2);
	
	SDL_RenderPresent(renderer);
	SDL_Delay(10000);
	
    int randomNumber;

	int i=0;
	int lossCount=0;
	int initialBetAmount=1;
	int betAmount=initialBetAmount;
	int MbetAmount=1;
	int wallet=250;
	int win=0;
	int round=1;
	int lossLevel=10;
	int lowestWallet=wallet;
	for(i=0;i<99999;i++)
	{
		//enter bet
		wallet=wallet-betAmount;
		if(wallet<lowestWallet)lowestWallet=wallet;
		//check win loss
		randomNumber=rand()%100+1;
		
		//loss
		if(randomNumber<51){win=0;lossCount++;}
		//win
		else {wallet+=(betAmount*2);win=1;lossCount=0;}
		
		if(lossCount==lossLevel){betAmount=((lossLevel*betAmount)/2)+MbetAmount;}
		else if(lossCount>lossLevel){betAmount=betAmount*2;}
		else betAmount=initialBetAmount;
		
		
		if(lossCount>6)
		{
			
			cout<< round << " : " << win << " : " << lossCount << "    Wallet: " << wallet << "  randNum : " << randomNumber << "  betAmount: " << betAmount << endl;
			
		}
		if(wallet<1) 
		{cout<< "********************BUST*********************"<<endl;
		break;}
		round++;
	}	
	cout<<wallet<<"  lowestWallet: "<<lowestWallet<<endl;
    return 0;
}