#include "complicated_fighter.hpp"
using namespace std;
#include <iostream>

complicated_fighter::complicated_fighter(){
    srcRect={0,0,160,133};
    moverRect = {30,40, 50, 60};
    }
complicated_fighter::complicated_fighter(int x_click,int y_click){
     
    //srcRect is diffeerent to change the appearance of the jet
    srcRect = {177,571,109,84};
    
    moverRect = {x_click, y_click, 80, 80};

}
void complicated_fighter::decrement_health(){
    //redefined decrement health as this should require more bullets then the enemy parent class 
    health=health-1;
}