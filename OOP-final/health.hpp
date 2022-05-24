#include<SDL.h>

class health{
    SDL_Rect srcRect, moverRect,moverRect_1,moverRect_2,moverRect_3,moverRect_4,moverRect_5,moverRect_6;
    //int count;
    
    public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets,int sig);
    health();
    
  // may add other overloaded constructors here... 
};
