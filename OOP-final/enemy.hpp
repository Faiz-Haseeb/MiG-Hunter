#include<SDL.h>

class Enemy{
    
    
    protected:
    //protected so that the chils class can use these attributes
     int health=9;
     SDL_Rect srcRect, moverRect;
    public:
    void draw(SDL_Renderer*, SDL_Texture* assets);
    virtual void fly(); //virtual void fly and decrement health as they are overridden in child classes
    Enemy();
    virtual void decrement_health();
    Enemy(int x_click,int y_click);
    int get_x();
    int get_y();
    int get_health(); 
    int check_destroy();
};
