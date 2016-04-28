/**
 * Project Untitled
 */


#ifndef _GRASS_H
#define _GRASS_H

#include "Plants.h"
#include "Land.hpp"


class Grass: public Plants {
public: 
    int foodLevel = 200000;
    const int maxFoodLevel = 100;
    const int metabolismRate = -1;
    
    Grass();
    Grass(int , int, Grass**);
    Grass(int r, int c) { row = r; column = c; }

    virtual void Move(Land* const &);
    
    virtual void Reproduce(int , int,Land* const & land);
    
    virtual void Die(Land* const &);
    
    virtual void Grow(Land* const &);
    
    virtual state  who();
};

#endif //_GRASS_H