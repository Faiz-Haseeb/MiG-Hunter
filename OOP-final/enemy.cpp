#include "enemy.hpp"
using namespace std;
#include <iostream>

void Enemy::fly(){
    //for moving the enemy
    moverRect.y+= 1;
}
void Enemy::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    fly();   
}
Enemy::get_health(){
    //getter is for overloaded operator 
    return health;
}
Enemy::Enemy(){
    srcRect={0,0,160,133};
    moverRect = {30,40, 50, 60};
    
    }
Enemy::get_x(){
    return moverRect.x;
}
Enemy::get_y(){
    return moverRect.y;
}
void Enemy:: decrement_health(){
   //decreases health on bullet hit
    health=health-2;

}
Enemy::check_destroy(){
    // returns for air.cpp to remove when enough bullets have been shot
    if (health<=0){
        return 1;
        }
    else{return 0;}

}
Enemy::Enemy(int x_click,int y_click){
     
    
    srcRect = {290,482,107,80};
    
    
    moverRect = {x_click, y_click, 80, 80};

}