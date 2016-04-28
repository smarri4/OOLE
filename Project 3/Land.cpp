//
//  Land.cpp
//  CS474 project 3
//
//  Copyright © 2016 UIC. All rights reserved.
//

#include "Land.hpp"
#include "Rabbit.h"
#include "Wolf.h"
#include "Grass.h"
#include <typeinfo>
#include "Living.h"
#include "Globals.h"

using std::cout;
using std::endl;
    Land::Land(){
        
    }
    Land::~Land(){
        if (Y>0) {
            for (int j=0; j<X; j++) {
                delete[] Yard[j];
            }
        }
        delete[] Yard;
    }

    Land::Land(int horizontalSquares,int VerticalSquares,sf::RenderWindow &w){
        X = horizontalSquares;
        Y = VerticalSquares;
        float xOffset=0;
        float yOffset=0;
        
        float dx = (float (w.getSize().x) / float (horizontalSquares));
        float dy = (float (w.getSize().y) / float (VerticalSquares));
        
        
        // Allocate the array
        Yard = new SquareYard*[X];
        for(int i = 0; i < X; ++i){
            Yard[i]= new SquareYard[Y];
        }
        
        // Allocate the Grid array
        Grid = new Living**[X];
        for(int i = 0; i < X; ++i){
            Grid[i]= new Living*[Y];
        }
        
        // Allocate the Grass array
        plants = new Grass**[X];
        for(int i = 0; i < X; ++i){
            plants[i]= new Grass*[Y];
        }
        
        //Setup the default state.
        for (int j=0; j<Y; j++) {
            xOffset=0;
            for (int i=0; i<X ;i++) {
                Yard[i][j].set(xOffset,yOffset,dx,dy);
                xOffset+=dx;
                plants[i][j] = new Grass();
            }
            yOffset+=dy;
        }
    }

    void Land::update(){
            //Your code here. maybe.
        for (int j=3; j<Y-40; j++) {
            for (int i=3; i<X-40 ;i++) {
              
               Grid[i][j]->Grow(this);
                
                Grid[i][j]->Move(this);
               
                
            }
        }
    }

    void Land::draw(sf::RenderWindow &w){
        for (int j=0; j<Y; j++) {
            for (int i=0; i<X ;i++) {
                Yard[i][j].draw(w);
            }
        }
    }


    //Get Maxes
    int Land::maxX(){
        return X;
    }
    int Land::maxY(){
        return Y;
    }



    //Get and Set inner color.
    void Land::setInnerColor(int x,int y,sf::Color c){
        Yard[x][y].SetInnerSquare(c);
    }
    sf::Color Land::getInnerValue(int x,int y){
        return Yard[x][y].getInnerSquare();
    }
        //Get and set outer color.
    void Land::setOuterColor(int x,int y,sf::Color c){
        Yard[x][y].SetOuterSquare(c);
    }
    sf::Color Land::getOuterValue(int x,int y){
        return Yard[x][y].getOuterSquare();
    }

    void Land::setAllColor(int x,int y,sf::Color c){
        Yard[x][y].SetInnerSquare(c);
        Yard[x][y].SetOuterSquare(c);
    }
void Land::setAnimal(int x,int y, state st){
    //cout <<
    
    if(st==state::RABBIT){
        Grid[x][y] = new Rabbit();
        Yard[x][y].SetInnerSquare(sf::Color::White);
    }
    if(st==state::WOLF){
        Grid[x][y] = new Wolf();
        Yard[x][y].SetInnerSquare(sf::Color(165,42,42));
    }
    if(st==state::GRASS){
        Grid[x][y] = new Grass();
        
        Yard[x][y].SetInnerSquare(sf::Color(16,125,16));
        Yard[x][y].SetOuterSquare(sf::Color(16,125,16));
    }

}

void Land::ridAnimal(int x,int y, Living& l){
    delete Grid[x][y] ;
}














