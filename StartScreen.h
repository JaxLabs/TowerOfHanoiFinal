//
// Created by Jax on 5/17/21.
//

#ifndef TOWEROFHANOIFINAL_STARTSCREEN_H
#define TOWEROFHANOIFINAL_STARTSCREEN_H
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "TextureManager.h"

class StartScreen : public Background{
public:
    StartScreen();
    static sf::Font font;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

private:
    sf::Text classText;
    std::string startMessageText;
    sf::Text startMessage;


};


#endif //TOWEROFHANOIFINAL_STARTSCREEN_H
