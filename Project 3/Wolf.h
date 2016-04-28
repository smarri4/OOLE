/**
 * Project Untitled
 */


#ifndef _WOLF_H
#define _WOLF_H

#include "Carnivores.h"
#include "SquareYard.hpp"
#include "Land.hpp"


class Wolf: public Carnivores {
public:
    Wolf();
    Wolf(int r, int c){ row = r; column = c; }

    int foodLevel = 150;
    const int maxFoodLevel = 200;
    const int metabolismRate = 2;
    
    virtual void Move(Land* const &);
    
    virtual void Hunt(Land* const &);
    
    virtual void Reproduce(int, int, Land* const &);
    
    virtual void Die(Land* const &);
    
    virtual void Grow(Land* const &);
    
    state who();
    
protected:
    int  age;
};

#endif //_WOLF_H