#include<SDL.h>

class boost{
    
    //int count;
    SDL_Rect srcRect, moverRect;
    public:
    void draw(SDL_Renderer*, SDL_Texture* assets);
    void fly();
    int get_x();
    int get_y();
    boost(int x_click,int y_click);
};
