/**
 * Project Untitled
 */

#include "Globals.h"
#include "SquareYard.hpp"
#include "Land.hpp"
#ifndef _LIVING_H
#define _LIVING_H

class Living {
    
public: 
    int foodLevel;
    int maxFoodLevel;
    int metabolismRate;
    int age;
    int  row,column;
   // extern int row, column;
    
    virtual void Move(Land* const &) = 0;
    virtual void Reproduce(int, int, Land* const &) = 0;
    virtual void Die(Land* const &) = 0;
    virtual void Grow(Land* const &) = 0;
    virtual state  who() = 0;
};

#endif //_LIVING_H