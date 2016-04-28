/**
 * Project Untitled
 */


#ifndef _RABBIT_H
#define _RABBIT_H

#include "Herbivores.h"
#include "SquareYard.hpp"
#include "Land.hpp"

class Rabbit: public Herbivores {
public: 
    int foodLevel = 10;
    const int maxFoodLevel = 45;
    const int metabolismRate = 3;
    
    Rabbit();
    Rabbit(int r, int c){ row = r; column = c; }
    
    
    virtual void Move(Land* const &);
    
    virtual void Evade(Land* const &);
    
    virtual void Reproduce(int, int, Land* const &);
    
    virtual void Die(Land* const &);
    
    virtual void Grow(Land* const &);
    
    virtual state  who();

protected:
    int  age;
};

#endif //_RABBIT_H