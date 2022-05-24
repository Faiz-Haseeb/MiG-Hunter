#include<SDL.h>
#include "player.hpp"
class complicated_fighter:public Enemy {
    //Complicated fighter inherits from enemy  in a public scope 
    //The decrement health happens differently and hence is redefined here 
    //because it was virtual void in the main enemy

    // health decrement is slower here to make enemey die on more bullets
    
    
    
    public:
    
    void decrement_health();
    complicated_fighter();
    complicated_fighter(int x_click,int y_click);
     
};