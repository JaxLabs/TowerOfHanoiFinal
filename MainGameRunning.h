//
// Created by Jax on 5/24/21.
//

#ifndef TOWEROFHANOIFINAL_MAINGAMERUNNING_H
#define TOWEROFHANOIFINAL_MAINGAMERUNNING_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "StartScreen.h"
#include "Story.h"
#include "State.h"
#include "Fade.h"
#include "MainGame.h"
#include "Disks.h"
#include "SetBottle.h"
#include<unistd.h>

class MainGameRunning {
public:
    void run();
private:
    MainGame maingame;

    SetBottle bottle;
    StartScreen screen;

    Disks disks;
    bool runSolve = false;

    int introPageNum = 0;
    std::vector <Story> introStory;

    std::vector <Story> endingStory;
    int endingPageNum = 0;

};


#endif //TOWEROFHANOIFINAL_MAINGAMERUNNING_H
