/**
 * Project Untitled
 */


#include "Grass.h"
#include "Rabbit.h"
#include <iostream>

using namespace std;

/**
 * Grass implementation
 */

Grass::Grass(){
    foodLevel = 20;
}

Grass::Grass(int x, int y, Grass** plants){
    foodLevel = plants[x][y].foodLevel;
}

void Grass::Move(Land* const & land) {
    //Grass does not move

}


void Grass::Reproduce(int row, int col,Land* const & land) {
    //Grass does not reproduce

}

void Grass::Die(Land* const &){
    //Grass does not die

}

void Grass::Grow(Land* const &) {
    //metabolic rate of grass is -1
    this->foodLevel++;
    //ages by 1
    this->age++;

}
state  Grass::who()
{
    return GRASS;
}