#include<SDL.h>
#include "enemy.hpp"
class Player{
    SDL_Rect srcRect, moverRect;
    //int count;
    int health =7;
    public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets,int sig);
    Player();
    void operator -( Enemy );
    int destroyed();
    int get_x();
    int get_health();
    int get_y();
    void refill_health();
    Player(int x_click,int y_click); // may add other overloaded constructors here... 
};
