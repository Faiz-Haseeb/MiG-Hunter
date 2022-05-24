#include<SDL.h>

class Bullet{
    SDL_Rect srcRect, moverRect;
    //int count;
    public:
    void draw(SDL_Renderer*, SDL_Texture* );
    void shot();
    void explosion(SDL_Renderer*, SDL_Texture* );
    Bullet();
    Bullet(int x_click,int y_click);
    int get_x();
    int get_y(); 
};
