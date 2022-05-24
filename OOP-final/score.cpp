#include "Score.hpp"
using namespace std;
#include <iostream>

void Score::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    
    
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    
}


Score::Score(int x_click,int y_click,int digit){
    // these if conditions on srcRect are to decide location on assets file based on the number
    //the assets file is a sprite sheet filled with numbers from 0-9
    if (digit==0)
    {srcRect={0,1,62,76};}
    if (digit==1)
        {srcRect={113,4,45,76};}
    if (digit==2)
    {srcRect={233,2,53,78};}
    if (digit==3){
        srcRect={346,0,55,80};
    }
    if (digit==4){
        srcRect={461,2,57,79};
    }
    if (digit==5){
        srcRect={2,128,55,78};
    }
    if ( digit==6){
        srcRect={108,128,59,78};

    }
    if (digit==7){
        srcRect={230,129,53,77};
    }
    if (digit==8){
        srcRect={343,128,58,78};
    }
    if (digit==9){
        srcRect={461,130,56,76};

    }
moverRect={x_click,y_click,50,50};

}