/**
 * Project Untitled
 */

#ifndef _PLANTS_H
#define _PLANTS_H

#include <stdio.h>
#include "Living.h"
#include "Land.hpp"

class Plants: public Living {
public: 
    int foodLevel;
    int maxFoodLevel;
    int metabolismRate;
    
    virtual void Move(Land* const &) = 0;
    
    virtual void Reproduce(int, int, Land* const &) = 0;
    
    virtual void Die(Land* const &) = 0;
    
    virtual void Grow(Land* const &) = 0;
    
};

#endif //_PLANTS_H