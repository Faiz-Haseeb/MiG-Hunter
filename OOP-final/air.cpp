#include<iostream>
#include "air.hpp"
#include <ctime>

void air::drawObjects(int sig){
       
   for(Enemy*& t: enemy) //traversal of enemy list for drawing and checking conditions
        { int flag=0;
            for(Bullet* & ba: list_bullets)
            {
                if ((ba->get_x())>(t->get_x()) && (ba->get_x())<(t->get_x()+65) && (ba->get_y()<t->get_y()+70) && (ba->get_y()>t->get_y())){
                   //if condition checks whether bullet is colliding with the enemy 
                    
                    list_bullets.remove(ba);
                   
                    //if it collides bullet is removed and enemy health is decremented
                    t->decrement_health();
                    if(t->check_destroy()==1)
                    { //checks if enemy health is zero and destroys if consition is met
                    enemy.remove(t);
                    
                  
                    ba->explosion(gRenderer,assets_3);
                    // this creates the explosion animation when an enemy plane dies 
                    score=score+1;
                    }
                }
            }
            
            if ((t->get_x())>(p->get_x()) && (t->get_x())<(p->get_x()+60) && (t->get_y()+60>p->get_y()) && (t->get_y()<p->get_y()+60))        
            {   //This is to check collision between enemy and player plane
                /* if collision occurs then the health of enemy is subtracted
                 from  health of player using opertator overloading  and the enemy is destroyed*/
                (*p)-(*t); 
                
                enemy.remove(t);
                
                
            }

            t->draw(gRenderer,assets);
            if (t->get_y()>530 || p->destroyed())
            {   // this checks if game is over (a plane has reached bottom or player health is less than 0)
                game_flag=1;
            }
        }   
  
    for(Bullet*& b: list_bullets)
    {   //draws and updates the bullets
        b->draw(gRenderer,assets_2);
        if (b->get_y()<6){//deletes the bullets when they reach the top of the screen
            list_bullets.remove(b);
            
            
            
        }
    }
    for(boost*& bo: list_boosts)
    {   
        bo->draw(gRenderer,assets_4);
        if (bo->get_y()>600){
            //this deletes the health boost when it has dropped to the very bottom of the screen 

            
            list_boosts.remove(bo);
            
            

        }
        if ((bo->get_x())>(p->get_x()) && (bo->get_x())<(p->get_x()+60) && (bo->get_y()<p->get_y()+60) && (bo->get_y()>p->get_y()))        
            {
                // increases health of player back to full when there is the player planes collides with the boost
                p->refill_health();
                list_boosts.remove(bo);
            }

    }
    p->draw(gRenderer, assets_1,sig);
    h->draw(gRenderer,assets_4,p->get_health());
}
void air::createObject(){
    int randomNumberx, randomNumbery;
    //these two random numbers give some dynamic element to initial location of the planes so they are spread
    //throughout the screen
    for(int i = 0; i < 15; i++){
        int prob = (rand() % 100) + 1 ;
        //produces 15 enemies, the prob is used to decide which kind of enemy will be created 
        randomNumberx = (rand() % 800) + 1;
        randomNumbery = (rand() % 200) - 200 ;

        if (prob < 20){
            //population of the list of enemies with all kind of enemies that will be displayed on the screen 
            strong_fighter * s = new strong_fighter(randomNumberx,randomNumbery);
            enemy.push_back(s);
        }
        else if (prob < 60){
            Enemy* bb = new Enemy (randomNumberx, randomNumbery);
        
        enemy.push_back(bb);
        }
        
        else{
            complicated_fighter * bt = new complicated_fighter(randomNumberx,randomNumbery);
            enemy.push_back(bt);
        }  

    
    }
    int random;
    random=rand() % 2;
    if (random==1){
        //this is used for the creation of health boost, the ransom is used to control frequency of dropping the health boosts
        list_boosts.push_back(new boost(randomNumberx,randomNumbery));

    }
    
    }
void air::fire()
{
    Bullet * bul=new Bullet(p->get_x()+45,p->get_y()-22);
    list_bullets.push_back(bul);
    // creates bullets (on F press)
}
    
air::get_score(){return score;}
// getscore is getter for score
air::game_end(){
    if (game_flag==1)
    {
        return 0;
    }
    else {return 1;}
    //this is to send to game.cpp the status of the game 
}
air::~air(){
    // destructors to delete all the elements of each list which were created using the new command 
    for(Enemy*& t: enemy){
        delete t;
    }
    delete &enemy;
    for(Bullet*& b: list_bullets){
        delete b;
    }
    delete &list_bullets;
    for (Bullet* & d: buffer){
        delete d;
    }
    delete &buffer;
}
//air constructor calling to load up resources required by the many classes that compose it
air::air(SDL_Renderer *renderer, SDL_Texture *asst,SDL_Texture * asst_1, SDL_Texture * asst_2,SDL_Texture * asst_3,SDL_Texture * asst_4):gRenderer(renderer), assets(asst),assets_1(asst_1),assets_2(asst_2),assets_3(asst_3),assets_4(asst_4){}
