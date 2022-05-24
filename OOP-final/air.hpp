#include<SDL.h>
#include<list>
#include "myVector.cpp"
#include "strong_fighter.hpp"
#include "bullet.hpp"
// #include "player.hpp"
#include "falling_heart.hpp"
#include "health.hpp"
class air

{   int game_flag=0;

    SDL_Texture *assets_1;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    SDL_Texture *assets_2;
    SDL_Texture *assets_3;
    SDL_Texture *assets_4;
    list <Enemy*> enemy;
    list <Bullet*> list_bullets;
    list <Bullet*> buffer;
    list <boost*> list_boosts;
    Player* p = new Player(500, 450);
    health* h=new health();
    int score=0;
    public:
    air(SDL_Renderer *, SDL_Texture *,SDL_Texture *,SDL_Texture *,SDL_Texture *,SDL_Texture*);
    void drawObjects(int sig); 
    void createObject();
    void fire();
    int get_score();
    int game_end();
    ~air();
};

