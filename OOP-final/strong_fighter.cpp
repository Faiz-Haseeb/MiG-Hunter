#include "strong_fighter.hpp"
using namespace std;
#include <iostream>

strong_fighter::strong_fighter(){
    srcRect={0,0,160,133};
    moverRect = {30,40, 50, 60};

    }
void strong_fighter::fly(){
    // redefined function as mover rect need to be increased by higher amount to make the plane move faster 
    moverRect.y+= 2;
}
strong_fighter::strong_fighter(int x_click,int y_click){
     
    srcRect = {177,929,109,92};

    moverRect = {x_click, y_click, 80, 80};

}
