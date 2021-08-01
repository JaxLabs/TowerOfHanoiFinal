//
// Created by Jax on 5/27/21.
//

#include "SetBottle.h"

int SetBottle::getFromBottle() const {
    return fromBottle;
}

void SetBottle::setFromBottle(int fromBottle) {
    SetBottle::fromBottle = fromBottle;
}

int SetBottle::getTooBottle() const {
    return tooBottle;
}

void SetBottle::setTooBottle(int tooBottle) {
    SetBottle::tooBottle = tooBottle;
}

void SetBottle::makeMove(Disks &disks) {
    disks.moveDisk(getFromBottle(),getTooBottle());
    setFromBottle(0);
    setTooBottle(0);
}

void SetBottle::solve(Disks &disks) {
    disks.reset();

    setFromBottle(1);
    setTooBottle(2);
    disks.moveDisk(getFromBottle(),getTooBottle());//1

    setFromBottle(1);
    setTooBottle(3);
    disks.moveDisk(getFromBottle(),getTooBottle());//2

    setFromBottle(2);
    setTooBottle(3);
    disks.moveDisk(getFromBottle(),getTooBottle());//3

    setFromBottle(3);
    setTooBottle(2);
    disks.moveDisk(getFromBottle(),getTooBottle());//4

    setFromBottle(3);
    setTooBottle(1);
    disks.moveDisk(getFromBottle(),getTooBottle());//5

    setFromBottle(3);
    setTooBottle(2);
    disks.moveDisk(getFromBottle(),getTooBottle());//6

    setFromBottle(1);
    setTooBottle(2);
    disks.moveDisk(getFromBottle(),getTooBottle());//7

    setFromBottle(1);
    setTooBottle(3);
    disks.moveDisk(getFromBottle(),getTooBottle());//8

    setFromBottle(2);
    setTooBottle(3);
    disks.moveDisk(getFromBottle(),getTooBottle());//9

    setFromBottle(2);
    setTooBottle(1);
    disks.moveDisk(getFromBottle(),getTooBottle());//10

    setFromBottle(3);
    setTooBottle(1);
    disks.moveDisk(getFromBottle(),getTooBottle());//11

    setFromBottle(2);
    setTooBottle(3);
    disks.moveDisk(getFromBottle(),getTooBottle());//12

    setFromBottle(1);
    setTooBottle(2);
    disks.moveDisk(getFromBottle(),getTooBottle());//13

    setFromBottle(1);
    setTooBottle(3);
    disks.moveDisk(getFromBottle(),getTooBottle());//14

    setFromBottle(2);
    setTooBottle(3);
    disks.moveDisk(getFromBottle(),getTooBottle());//15

}
