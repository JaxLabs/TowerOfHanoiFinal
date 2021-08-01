//
// Created by Jax on 5/21/21.
//

#ifndef TOWEROFHANOIFINAL_MAINGAME_H
#define TOWEROFHANOIFINAL_MAINGAME_H
#include "Background.h"
#include "TextureManager.h"

class MainGame: public Background {
public:
    MainGame();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

private:
    sf::Sprite firstBottle;
    sf::Sprite secondBottle;
    sf::Sprite thirdBottle;
};


#endif //TOWEROFHANOIFINAL_MAINGAME_H
