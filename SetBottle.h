//
// Created by Jax on 5/27/21.
//

#ifndef TOWEROFHANOIFINAL_SETBOTTLE_H
#define TOWEROFHANOIFINAL_SETBOTTLE_H
#include "Disks.h"

class SetBottle {
private:
    int fromBottle;
    int tooBottle;
public:
    void makeMove(Disks &disks);

    int getFromBottle() const;

    void setFromBottle(int fromBottle);

    int getTooBottle() const;

    void setTooBottle(int tooBottle);

    void solve(Disks &disks);
};


#endif //TOWEROFHANOIFINAL_SETBOTTLE_H
