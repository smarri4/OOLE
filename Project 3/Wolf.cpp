/**
 * Project Untitled
 */


#include "Wolf.h"
#include "Rabbit.h"
#include <iostream>
#include "Land.hpp"
#include "Grass.h"

using namespace std;

/**
 * Wolf implementation
 */

Wolf::Wolf() {
    foodLevel = 150;
}

state Wolf::who(){
    return WOLF;
}

void Wolf::Move(Land* const & land) {
    
    //reached edges
    if(this->row>=49||this->column>=49)
        return;
    Living *up,*down,*right,*left;
    //four moves
    up = land->Grid[this->row][this->column-1];
    down = land->Grid[this->row][this->column+1];
    right = land->Grid[this->row+1][this->column];
    left = land->Grid[this->row-1][this->column];
    
    //first hunts
    this->Hunt(land);
    
    // after hunt, moves
    if (typeid(up) == typeid(Grass)) {
        //moving up
        land->ridAnimal(this->row-1, this->column,*this);
        land->setAnimal(this->row-1, this->column,state::WOLF);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
    }
    else if (typeid(down) == typeid(Grass)) {
        //moving down
        land->ridAnimal(this->row+1, this->column,*this);
        land->setAnimal(this->row+1, this->column,state::WOLF);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
    }
    else if (typeid(left) == typeid(Grass)) {
        //moving left
        land->ridAnimal(this->row, this->column-1,*this);
        land->setAnimal(this->row, this->column-1,state::WOLF);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
    }
    
    else if (typeid(right) == typeid(Grass)) {
        //moving right
        land->ridAnimal(this->row, this->column+1,*this);
        land->setAnimal(this->row, this->column+1,state::WOLF);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
    }
    
    else {
        //no option to move (if surrounded by wolves), stays at the same place
        return;
    }
}

void Wolf::Hunt(Land* const & land) {
    
    //reached edges
    if(this->row>=49||this->column>=49)
        return;
    Living *up,*down,*right,*left;
    //four positions to hunt
    up = land->Grid[this->row][this->column-1];
    down = land->Grid[this->row][this->column+1];
    right = land->Grid[this->row+1][this->column];
    left = land->Grid[this->row-1][this->column];
    
    
    if (typeid(up) == typeid(Rabbit) && this->foodLevel <= 190) {
        //hunts up
        land->ridAnimal(this->row-1, this->column,*this);
        land->setAnimal(this->row-1, this->column,state::WOLF);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
        this->foodLevel += 10;
    }
    else if (typeid(down) == typeid(Rabbit) && this->foodLevel <= 190) {
        //hunts down
        land->ridAnimal(this->row+1, this->column,*this);
        land->setAnimal(this->row+1, this->column,state::WOLF);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
        this->foodLevel += 10;
    }
    else if (typeid(left) == typeid(Rabbit) && this->foodLevel <= 190) {
        //hunts left
        land->ridAnimal(this->row, this->column-1,*this);
        land->setAnimal(this->row, this->column-1,state::WOLF);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
        this->foodLevel += 10;
        
    }
    
    else if (typeid(right) == typeid(Rabbit) && this->foodLevel <= 190) {
        //hunts rights
        land->ridAnimal(this->row, this->column+1,*this);
        land->setAnimal(this->row, this->column+1,state::WOLF);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
        this->foodLevel += 10;
        
    }
    else {
        //no option to hunt (surrounded by grass or wolves), simply moves to a position
        return;
    }


}



void Wolf::Reproduce(int row, int col, Land* const & land) {
    //since a wolf has a 40% chance of reproducing
    int nrand = (rand()%5)%2;
    switch (nrand) {
        case 0:
            if (this->age>10 && this->foodLevel>120) {
                //age greater than 10 and food greater than 120
                land->setAnimal(this->row, this->column,state::WOLF);
            }
            break;
        case 1:
            break;
        
        default:
            break;
    }

}

void Wolf::Die(Land* const & land) {
    //age greater than 50 or food is zero
    if (this->age>50||this->foodLevel==0) {
        delete this;
        land->setAnimal(this->row, this->column,state::GRASS);
    }

}

void Wolf::Grow(Land* const & land) {
    //metabolic rate of wolf is 2
    (this->foodLevel>2)?this->foodLevel-=2:0;
    if (this->foodLevel==0 || this->age > 50) {
        this->Die(land);

    }
    //cout << "Wolf grow" << endl;
    //ages by 1
    this->age++;
}