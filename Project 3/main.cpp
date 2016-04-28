//
//  main.cpp
//  CS474 project 3
//
//  Copyright © 2016 UIC. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Land.hpp"
#include <iostream>
#include "Living.h"
#include "Rabbit.h"
#include "Grass.h"
#include "Wolf.h"
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include "Globals.h"
void new_rand(Land*, int);

using namespace std;


int main(){
    int flag=0;
    sf::RenderWindow window(sf::VideoMode(1000, 700), "CS 474 project 3");
    window.setVerticalSyncEnabled(true);
    
    
    Land land = Land(50,50,window);//50 cell by 50 cell grid.
    
    
    //new_rand(&land,flag);
    
    while (window.isOpen()){
        // Process events
        sf::Event event;
        while (window.pollEvent(event)){
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color::White);// Clear screen
        
        
        flag=(flag==0)?1:0;
        // generating random generations at the start
        new_rand(&land,flag);

        //Updating the grids with new stage of herbivores and carnivores.
        //land.update();
        
        land.draw(window);
        //slowing down the thread to show the stages every second
        std::this_thread::sleep_for (std::chrono::seconds(2));
        
        // Update the window
        window.display();
    }
    
    
    return 0;
}


void new_rand(Land* land, int flag){
    int rand_num,rand_n;
    state* wArr = new state[200];
    state* rArr = new state[200];
    for(int i=0;i<200;i++){
        if(i<40)
            wArr[i] = state::RABBIT;
        else if (i>160)
            wArr[i] = state::GRASS;
        else
            wArr[i] = state::WOLF;
    }
    for(int i=0;i<200;i++){
        if(i<40)
            rArr[i] = state::WOLF;
        else if (i>160)
            wArr[i] = state::GRASS;
        else
            rArr[i] = state::RABBIT;
    }
    
    
    for (int i=0; i<50; ++i)
        for (int j = 0; j < 50 ; ++j)
        {
            rand_n= rand();
            rand_n= rand_n%3;
            rand_num = rand();
            rand_num = rand_num%200;
            switch(rand_n)
            {
                case 0:{
                    if (flag==0) {
                        land->setAnimal(i,j,rArr[rand_num]);
                    } else {
                        land->setAnimal(i,j,wArr[rand_num]);
                    }
                    break;
                }
                case 1:{
                    if (flag==0) {
                        land->setAnimal(i,j,rArr[rand_num]);
                    } else {
                        land->setAnimal(i,j,wArr[rand_num]);
                    }
                    break;
                }
                case 2:{
                    land->setAnimal(i,j,state::GRASS);
                    break;
                }
                    
            }
            
        }
    
}

