/**
 * Project Untitled
 */


#include "Rabbit.h"
#include <iostream>
#include "Land.hpp"
#include "Grass.h"
#include "Wolf.h"

using namespace std;

/**
 * Rabbit implementation
 */

Rabbit::Rabbit(){
    foodLevel = 10;
}


void Rabbit::Move(Land* const & land) {
    //reached edges
    if(this->row>=49||this->column>=49)
        return;
    int currRow=this->row;
    int currCol = this->column;
    Living *up,*down,*right,*left;
    //four positions
    up = land->plants[this->row][this->column-1];
    down = land->plants[this->row][this->column+1];
    right = land->plants[this->row+1][this->column];
    left = land->plants[this->row-1][this->column];
    //choosing optimum position to move (position with highest grass content)
    int arr[] = {up->foodLevel,down->foodLevel,right->foodLevel,left->foodLevel};
    std::vector<int> myvector (arr, arr+4);
    std::sort (myvector.begin(), myvector.begin()+4);
    
    bool spotFound = false;
    int i = 3;
    int maxVal = arr[i];
    
    while (!spotFound) {
        if(i<0) {
            break;
        }

    if( maxVal == right->foodLevel){
        //if maximum grass is on right
        if (typeid(land->Grid[row][column+1]) != typeid(Rabbit) && typeid(land->Grid[row][column+1]) != typeid(Wolf)) {
            //if there is no rabbit or wolf
            spotFound = true;
            if (right->foodLevel>5) {
                //grass content decreased by 5
                right->foodLevel-=5;

            }
            else {
                //grass becomes zero if it was less than 5
                right->foodLevel=0;
            }
            //moving to right
            land->ridAnimal(this->row+1, this->column,*this);
            land->setAnimal(this->row+1, this->column,state::RABBIT);
            // set the current cell to grass from the plants array
            land->ridAnimal(this->row, this->column,*this);
            land->setAnimal(this->row, this->column,state::GRASS);
            this->row = this->row+1;
            //evade
            this->Evade(land);
        }
        else {
            maxVal = arr[i--];
            continue;
        }

    }
    if( maxVal == down->foodLevel){
        //if maximum grass is on down
        if (typeid(land->Grid[row+1][column]) != typeid(Rabbit) && typeid(land->Grid[row+1][column]) != typeid(Wolf)) {
            //if there is no rabbit or wolf
            spotFound = true;
        if (down->foodLevel>5) {
             //grass content decreased by 5
            down->foodLevel-=5;
        }
        else
            //grass becomes zero if it was less than 5
            down->foodLevel=0;
            //moving to down
        land->ridAnimal(this->row, this->column+1,*this);
        land->setAnimal(this->row, this->column+1,state::RABBIT);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
            this->column = this->column+1;
            //evade
            this->Evade(land);
        }
    else{
        maxVal = arr[i--];
        continue;
    }
    }
    
    if( maxVal == left->foodLevel){
        //if maximum grass is on left
        if (typeid(land->Grid[row][column-1]) != typeid(Rabbit) && typeid(land->Grid[row][column-1]) != typeid(Wolf)) {
            //if there is no rabbit or wolf
            spotFound = true;
        if (left->foodLevel>5) {
            left->foodLevel-=5;
        }
        else
            left->foodLevel=0;
            //moving to left
        land->ridAnimal(this->row-1, this->column,*this);
        land->setAnimal(this->row-1, this->column,state::RABBIT);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
            this->row = this->row-1;
            //evade
            this->Evade(land);
        }
    else{
        maxVal = arr[i--];
        continue;
    }
    }
    
    if( maxVal == up->foodLevel){
        if (typeid(land->Grid[row-1][column]) != typeid(Rabbit) && typeid(land->Grid[row-1][column]) != typeid(Wolf)) {
            //if there is no rabbit or wolf
            spotFound = true;
        if (up->foodLevel>5) {
            //grass content decreased by 5
            up->foodLevel-=5;
        }
        else
            //grass becomes zero if it was less than 5
            up->foodLevel=0;
            //moving to up
        land->ridAnimal(this->row, this->column-1,*this);
        land->setAnimal(this->row, this->column-1,state::RABBIT);
        // set the current cell to grass from the plants array
        land->ridAnimal(this->row, this->column,*this);
        land->setAnimal(this->row, this->column,state::GRASS);
            this->column = this->column-1;
            //evade
            this->Evade(land);
    }
    else{
        maxVal = arr[i--];
        continue;
    }
    }
    
  }
    //reproduces
    this->Reproduce(currRow, currCol, land);
}

void Rabbit::Evade(Land* const & land) {
    cout <<  "row: " << this->row << "column: " << this->column << endl;
    //reached edges
    if(this->row>=49||this->column>=49)
        return;
    Living *up,*down,*right,*left;
    //four positions
    up = land->Grid[this->row][this->column-1];
    down = land->Grid[this->row][this->column+1];
    right = land->Grid[this->row+1][this->column];
    left = land->Grid[this->row-1][this->column];
    isEvade = true;
    
    if (typeid(land->Grid[row][column+1]) == typeid(Wolf)) {
        //if wolf is on right
        if (typeid(land->Grid[row][column-1]) == typeid(Grass)) {
            //evades to left
            land->ridAnimal(this->row, this->column-1,*this);
            land->setAnimal(this->row, this->column-1,state::RABBIT);
        }
    }
    
    else if (typeid(land->Grid[row][column-1]) == typeid(Wolf)) {
        //if wolf is on left
        if (typeid(land->Grid[row][column+1]) == typeid(Grass)) {
            //evades to right
            land->ridAnimal(this->row, this->column-1,*this);
            land->setAnimal(this->row, this->column-1,state::RABBIT);
        }
    }
    
    else if (typeid(land->Grid[row+1][column]) == typeid(Wolf)) {
        //if wolf is on down
        if (typeid(land->Grid[row-1][column]) == typeid(Grass)) {
            //evades to up
            land->ridAnimal(this->row, this->column-1,*this);
            land->setAnimal(this->row, this->column-1,state::RABBIT);
        }
    }
    
    else if (typeid(land->Grid[row-1][column]) == typeid(Wolf)) {
        //wolf is on up
        if (typeid(land->Grid[row+1][column]) == typeid(Grass)) {
            //evades to down
            land->ridAnimal(this->row, this->column-1,*this);
            land->setAnimal(this->row, this->column-1,state::RABBIT);
        }
    }
    
    else {
        //cannot evade, stuck in that position
        isEvade = false;
        return;
    }

}

void Rabbit::Reproduce(int row, int col, Land* const & land) {
    
    //since a rabbit has a 50% chance of reproducing
    int nrand = rand()%2;
    switch (nrand) {
        case 0:
            if (this->age>10 && this->foodLevel>40 && !this->isEvade) {
                //age is greater than 10 and food is greater than 40 and has not evaded
                land->setAnimal(this->row, this->column,state::RABBIT);
            }
            break;
        case 1:
            break;
            
        default:
            break;
    }
}

void Rabbit::Die(Land* const & land) {
    //age is greater than 25 or food is zero
    if (this->age>25||this->foodLevel==0) {
        delete this;
        land->setAnimal(this->row, this->column,state::GRASS);
    }

}

// When a rabbit grows, it increases age per stage, and it reduces foodLevel by 3.
void Rabbit::Grow(Land* const & land) {
    //metabolic rate of rabbit is 3
    (this->foodLevel>3)?this->foodLevel-=3:0;
    if (this->foodLevel==0 || this->age > 25) {
        this->Die(land);
        
    }
    //ages by 1
    this->age++;}

state  Rabbit::who()
{
    return RABBIT;
}
