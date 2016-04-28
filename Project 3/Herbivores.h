/**
 * Project Untitled
 */


#ifndef _HERBIVORES_H
#define _HERBIVORES_H

#include "Living.h"
#include "Land.hpp"


class Herbivores: public Living {
public: 
    int foodLevel;
    int maxFoodLevel;
    int metabolismRate;
    bool isEvade=false;
    
    virtual void Move(Land* const &) = 0;
    
    virtual void Evade(Land* const &) = 0;
    
    virtual void Reproduce(int, int, Land* const &) = 0;
    
    virtual void Die(Land* const &) = 0;
    
    virtual void Grow(Land* const &) = 0;
    
};

#endif //_HERBIVORES_H