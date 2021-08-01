//
// Created by Jax on 5/21/21.
//

#include "MainGame.h"

MainGame::MainGame(): Background(2320,1276,"graphics/gamebackround.png") {
    firstBottle.setTexture(*TextureManager::instance().loadTexture("graphics/bottle.png"));
    firstBottle.setPosition(410,920);

    secondBottle.setTexture(*TextureManager::instance().loadTexture("graphics/bottle.png"));
    secondBottle.setPosition(1050,920);

    thirdBottle.setTexture(*TextureManager::instance().loadTexture("graphics/bottle.png"));
    thirdBottle.setPosition(1650,920);
}
void MainGame::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(backImage);
    window.draw(firstBottle);
    window.draw(secondBottle);
    window.draw(thirdBottle);
}