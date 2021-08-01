//
// Created by Jax on 5/24/21.
//

#include "Disks.h"

Disks::Disks() {
    won = false;

    LBottle.setId(1);
    MBottle.setId(2);
    RBottle.setId(3);

    //stack colors
    LBottle.push(color::GREEN);
    LBottle.push(color::YELLOW);
    LBottle.push(color::ORANGE);
    LBottle.push(color::RED);

    //rect color
    red.setFillColor(sf::Color::Red);
    orange.setFillColor(sf::Color(255,140,0));
    yellow.setFillColor(sf::Color::Yellow);
    green.setFillColor(sf::Color::Green);

    //size
    green.setSize(sf::Vector2f(130,45));
    yellow.setSize(sf::Vector2f(130,45));
    orange.setSize(sf::Vector2f(130,45));
    red.setSize(sf::Vector2f(130,45));

    //starting position
    green.setPosition(500,1173);
    yellow.setPosition(500,1128);
    orange.setPosition(500,1090);
    red.setPosition(500,1045);
}

bool Disks::moveDisk(int fromBottleIndex, int toBottleIndex) {
    if (fromBottleIndex == toBottleIndex){
        return false;
    }

    Stack *fromStack;
    Stack *toStack;
    fromStack = assignStack(fromBottleIndex);
    toStack = assignStack(toBottleIndex);

    Node* toCheck = fromStack->top();
    if (toCheck == nullptr || toStack->invalid(*toCheck)) {
        return false;
    }

    Node* toAdd = new Node;
    toAdd->color = fromStack->pop();

    toStack->push(toAdd->color);
    moveRect(toAdd->color, *toStack);
    return true;
}

void Disks::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(green);
    window.draw(yellow);
    window.draw(orange);
    window.draw(red);
}

Stack *Disks::assignStack(int stack) {
    switch (stack) {
        case 1:
            return &LBottle;
            break;
        case 2:
            return &MBottle;
            break;
        case 3:
            return &RBottle;
            break;
    }
}

void Disks::moveRect(color diskColor, Stack stack) {
    if (stack.getId() == LBottle.getId()) {
        switch (diskColor) {
            case color::RED:
                red.setPosition(500, getY(stack));
                break;
            case color::ORANGE:
                orange.setPosition(500, getY(stack));
                break;
            case color::YELLOW:
                yellow.setPosition(500, getY(stack));
                break;
            case color::GREEN:
                green.setPosition(500, getY(stack));
                break;
        }
    }
    if (stack.getId() == MBottle.getId()) {
        switch (diskColor) {
            case color::RED:
                red.setPosition(1140, getY(stack));
                break;
            case color::ORANGE:
                orange.setPosition(1140, getY(stack));
                break;
            case color::YELLOW:
                yellow.setPosition(1140, getY(stack));
                break;
            case color::GREEN:
                green.setPosition(1140, getY(stack));
                break;
        }
    }
    if (stack.getId() == RBottle.getId()) {
        switch (diskColor) {
            case color::RED:
                red.setPosition(1740, getY(stack));
                break;
            case color::ORANGE:
                orange.setPosition(1740, getY(stack));
                break;
            case color::YELLOW:
                yellow.setPosition(1740, getY(stack));
                break;
            case color::GREEN:
                green.setPosition(1740, getY(stack));
                break;
        }
    }
}

int Disks::getY(Stack stack) {
    switch (stack.size()) {
        case 1:
            return 1173;
            break;
        case 2:
            return 1128;
            break;
        case 3:
            return 1090;
            break;
        case 4:
            return 1045;
            break;
    }
}

Disks::~Disks() {
    while(LBottle.size()>0)
        LBottle.pop();
    while(MBottle.size()>0)
        MBottle.pop();
    while(RBottle.size()>0)
        RBottle.pop();
}

bool Disks::yourAWinner() {
    if (won){
        return true;
    }
    else if (RBottle.size() == 4){
        return true;
    }
    return false;
}

void Disks::solve() {
    float seconds = clock.getElapsedTime().asSeconds();
    static bool alreadyReset = false;
    if (seconds < 1 && !alreadyReset) {
        alreadyReset = true;
        reset();
    }
    else if (seconds >= 1 && solveStep == 0) {
        solveStep = 1;
        moveDisk(1,2);//1
    }
    else if (seconds >= 2 && solveStep == 1) {
        solveStep = 2;
        moveDisk(1,3);//2
    }

    else if (seconds >= 3 && solveStep == 2) {
        solveStep = 3;
        moveDisk(2, 3);//3
    }

    else if (seconds >= 4 && solveStep == 3) {
        solveStep = 4;
        moveDisk(1,2);//4
    }

    else if (seconds >= 5 && solveStep == 4) {
        solveStep = 5;
        moveDisk(3, 1);//5
    }

    else if (seconds >= 6 && solveStep == 5) {
        solveStep = 6;
        moveDisk(3, 2);//6
    }

    else if (seconds >= 7 && solveStep == 6) {
        solveStep = 7;
        moveDisk(1, 2);//7
    }

    else if (seconds >= 8 && solveStep == 7) {
        solveStep = 8;
        moveDisk(1, 3);//8
    }

    else if (seconds >= 9 && solveStep == 8) {
        solveStep = 9;
        moveDisk(2, 3);//9
    }

    else if (seconds >= 10 && solveStep == 9) {
        solveStep = 10;
        moveDisk(2, 1);//10
    }

    else if (seconds >= 11 && solveStep == 10) {
        solveStep = 11;
        moveDisk(3, 1);//11
    }

    else if (seconds >= 12 && solveStep == 11) {
        solveStep = 12;
        moveDisk(2, 3);//12
    }

    else if (seconds >= 13 && solveStep == 12) {
        solveStep = 13;
        moveDisk(1, 2);//13
    }

    else if (seconds >= 14 && solveStep == 13) {
        solveStep = 14;
        moveDisk(1, 3);//14
    }

    else if (seconds >= 15 && solveStep == 14) {
        solveStep = 15;
        moveDisk(2, 3);//15
    }
    else if (seconds >= 16 && solveStep == 15) {
        solveStep = 16;
    }

}

void Disks::reset() {
    while(LBottle.size()>0)
        LBottle.pop();
    while(MBottle.size()>0)
        MBottle.pop();
    while(RBottle.size()>0)
        RBottle.pop();

    //stack colors
    LBottle.push(color::GREEN);
    LBottle.push(color::YELLOW);
    LBottle.push(color::ORANGE);
    LBottle.push(color::RED);

    //starting position
    green.setPosition(500,1173);
    yellow.setPosition(500,1128);
    orange.setPosition(500,1090);
    red.setPosition(500,1045);


}

void Disks::clockReset() {
    clock.restart();
    solveStep = 0;
}

int Disks::getSolveStep() const {
    return solveStep;
}

void Disks::setSolveStep(int solveStep) {
    Disks::solveStep = solveStep;
}
