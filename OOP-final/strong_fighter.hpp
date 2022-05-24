#include<SDL.h>
#include "complicated_fighter.hpp"
class strong_fighter:public Enemy {
    
   // same story as complicated fighter but redefined fly instead of redefining decrement health
    public:
    void fly();
    
    strong_fighter();
    strong_fighter(int x_click,int y_click);   
};