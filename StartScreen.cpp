//
// Created by Jax on 5/17/21.
//

#include "StartScreen.h"
StartScreen::StartScreen(): Background(2320,1276) {
    backImage.setTexture(&TextureManager::instance().startTexture);
    startMessage.setFont(Background::font);
    startMessage.setPosition(625,640);
    startMessage.setCharacterSize(100);
    startMessage.setString("Click To Start Start");
    startMessage.setFillColor(sf::Color(186,85,211));

    classText.setFont(Background::font);
    classText.setPosition(50,20);
    classText.setCharacterSize(100);
    classText.setString("CS003A\n31195\nSpring 2021");
    classText.setFillColor(sf::Color(186,85,211));

}


void StartScreen::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(backImage);
    window.draw(startMessage);
    window.draw(classText);
}