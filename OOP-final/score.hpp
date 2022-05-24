#include<SDL.h>

class Score{
    SDL_Rect srcRect, moverRect;
    //int count;
    public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* );
    
    Score(int x_click,int y_click,int digit); // may add other overloaded constructors here... 
};