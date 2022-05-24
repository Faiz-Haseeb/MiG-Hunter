#include "falling_heart.hpp"
using namespace std;
#include <iostream>

void boost::fly(){
   //makes the health boost drop
    moverRect.y+= 1;
}
boost::get_x(){
    return moverRect.x;
}
boost::get_y(){
    return moverRect.y;
}
void boost::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    fly();   
}



boost::boost(int x_click,int y_click){
     
    srcRect = {20,6,232,231};
    
    
    moverRect = {x_click, y_click, 40, 40};

}



