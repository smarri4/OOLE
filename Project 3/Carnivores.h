/**
 * Project Untitled
 */


#ifndef _CARNIVORES_H
#define _CARNIVORES_H

#include "Living.h"
#include "Land.hpp"


class Carnivores: public Living {
public: 
    int foodLevel;
    int maxFoodLevel;
    int metabolismRate;
    
    virtual void Move(Land* const &) = 0;
    
    virtual void Hunt(Land* const &) = 0;
    
    virtual void Reproduce(int, int, Land* const &) = 0;
    
    virtual void Die(Land* const &)= 0;
    
    virtual void Grow(Land* const &) = 0;
    virtual state  who() = 0;
};

#endif //_CARNIVORES_H