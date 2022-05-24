#include "Player.hpp"
using namespace std;
#include <iostream>

void Player::draw(SDL_Renderer* gRenderer, SDL_Texture* assets,int sig){
    
    //hese are to move the player left and right sig is passed based on sdl input
    if (sig==1){
        moverRect.x=moverRect.x-25;
    }
    if (sig==2){
        moverRect.x=moverRect.x+25;
    }
    
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    
}
//this overloaded operator is used for subtracting enemy health from player health when the two planes collide
void Player::operator -(Enemy e){health=health-e.get_health();}
Player::destroyed(){
    
    if (health<=0){
        return 1;
    }
    else{
        return 0;
    }
}
Player::Player(){
    srcRect={0,0,160,133};
    moverRect = {30,40, 50, 60};
    //count=1;
    }
Player::get_x(){
    return moverRect.x;
}
Player::get_y(){
    return moverRect.y;
}
Player::get_health(){
    return health;
}
void Player::refill_health(){
    
    //This resets health back to full (used when health boost is collected)
    health=7;
}
Player::Player(int x_click,int y_click){
    
    srcRect = {111, 663, 79, 118};
    moverRect = {x_click, y_click, 100, 100};

}