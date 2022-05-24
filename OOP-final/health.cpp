#include "health.hpp"
using namespace std;
#include <iostream>

void health::draw(SDL_Renderer* gRenderer, SDL_Texture* assets,int sig){
    // These if conditions decide how many of the hearts should be drawn based on the health attribute of the player
    // sig is actually the health of the player(see function call in air.cpp)
    if (sig>=1){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    }
    if (sig>=2){
        SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect_1);
    }
    if (sig>=3){
        SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect_2);
    }
    if (sig>=4){
        SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect_3);
    }
    if (sig>=5){
        SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect_4);
    }
    if (sig>=6){
        SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect_5);
    }
    if (sig>=7){
        SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect_6);
    }
}




health::health(){
    srcRect = {20,6,232,231};
    //these mover rects points to the location of the seven hearts that are made on the bottom left of the screen
   moverRect={40,560,40,40};
   moverRect_1={60,560,40,40};
    moverRect_2={80,560,40,40};
    moverRect_3={100,560,40,40};
    moverRect_4={120,560,40,40};    
    moverRect_5={140,560,40,40};
    moverRect_6={160,560,40,40};

}