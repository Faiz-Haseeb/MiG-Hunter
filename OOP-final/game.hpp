#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>
#include "score.hpp"
class Game{
    //Screen dimension constants
    
    const int SCREEN_WIDTH = 1045;
    const int SCREEN_HEIGHT = 600;
    Mix_Music* gMusic=NULL;
    Mix_Music * giMusic=NULL;
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;
    
    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    SDL_Texture* giTexture = NULL;
    SDL_Texture* gikTexture = NULL;
    SDL_Texture* gikiTexture = NULL;
    SDL_Texture* gikikTexture = NULL;
    SDL_Texture* background = NULL;
    SDL_Texture* assets_4=NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    SDL_Texture* assets_1=NULL;
    SDL_Texture* assets_2=NULL;
    SDL_Texture* assets_3=NULL;
    SDL_Texture* pause_asset=NULL;
    SDL_Texture* healt_asset=NULL;
    SDL_Texture* renewed=NULL;
    SDL_Rect camera_rect={0,0,1000,600};
    
    int final_sig=0;
    
    Score* s1;
    Score * s2;
    Score * s3;
    int store_var;
    int digit_1;
    int digit_2;
    int digit_3;
    int state=0;
    int signal=0;
       int counter=0;
    bool paused=false;

    SDL_Rect pause_moverRect = {430,250,160,145};

public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
};

