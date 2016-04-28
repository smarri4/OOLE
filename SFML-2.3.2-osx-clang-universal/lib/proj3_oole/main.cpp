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


int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 700), "CS 474 project 3");
    window.setVerticalSyncEnabled(true);
    
    
    Land land = Land(50,50,window);//50 cell by 50 cell grid.
    

    while (window.isOpen()){
        // Process events
        sf::Event event;
        while (window.pollEvent(event)){
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear();// Clear screen



        land.update();
        //Your update code here...
        
                    //setInnerColors(x,y,color);
        land.setInnerColor(15, 4, sf::Color::Red);
        land.setOuterColor(20, 10, sf::Color::Blue);
        land.setAllColor(20, 20, sf::Color::Black);
        land.setAllColor(40, 40, sf::Color(244,244,244,255));
        
        land.draw(window);

        
        
        // Update the window
        window.display();
    }
    
    
    return 0;
}


    //Built in colors
    //sf::Color::Black
    //sf::Color::White
    //sf::Color::Red
    //sf::Color::Green
    //sf::Color::Blue
    //sf::Color::Yellow
    //sf::Color::Magenta
    //sf::Color::Cyan
    //sf::Color::Transparent

    //Create your own.
    //Like this.
    //Color (Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha=255)

