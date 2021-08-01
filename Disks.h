//
// Created by Jax on 5/24/21.
//

#ifndef TOWEROFHANOIFINAL_DISKS_H
#define TOWEROFHANOIFINAL_DISKS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Stack.h"
#include "Node.h"
#include "Color.h"

class Disks: public Background {
public:
    Disks();
    ~Disks();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    bool moveDisk(int fromBottleIndex, int toBottleIndex);
    bool yourAWinner();
    void solve();
    int getSolveStep() const;
    void setSolveStep(int solveStep);
    void reset();
    void clockReset();

private:
    int getY(Stack stack);
    void moveRect(color diskColor, Stack);
    Stack* assignStack(int);
    bool won;

    sf::Clock clock;
    int solveStep = 0;

    sf::RectangleShape red;
    sf::RectangleShape orange;
    sf::RectangleShape yellow;
    sf::RectangleShape green;

    Stack LBottle;
    Stack MBottle;
    Stack RBottle;
};


#endif //TOWEROFHANOIFINAL_DISKS_H
