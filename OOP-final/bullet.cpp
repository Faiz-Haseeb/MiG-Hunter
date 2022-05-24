#include "bullet.hpp"
using namespace std;
#include <iostream>

void Bullet::shot(){
    //this moves the bullet upwards by making use of the moverRect.y attribute    
    moverRect.y=moverRect.y -5;
}
void Bullet::explosion(SDL_Renderer* gRenderer, SDL_Texture* assets){
    
    //this function is used to change the rect and takes it different assets for explosion
    srcRect={17,9,56,52};
    

    SDL_Rect moverect = {moverRect.x-30, moverRect.y - 50, 60, 80};
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverect);

}

void Bullet::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    
    //Actual drawing through sdl render copy is done here
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    shot();   
}
Bullet::Bullet(){
    srcRect={0,0,160,133};
    moverRect = {30,40, 50, 60}; 
    

    }
//getters are for checking the collision of the bullets 
Bullet::get_x(){
    return moverRect.x;
}
Bullet::get_y(){
    return moverRect.y;
}
Bullet::Bullet(int x_click,int y_click){
     
    
    srcRect = {195,0,111,500};
    
   
    moverRect = {x_click, y_click, 10, 30};
    

}