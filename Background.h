//
// Created by Jax on 5/17/21.
//

#ifndef TOWEROFHANOIFINAL_BACKGROUND_H
#define TOWEROFHANOIFINAL_BACKGROUND_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include "TextureManager.h"
class Background : public sf::RectangleShape {
public:
    Background();
    Background(float x, float y);
    Background(float x, float y, std::string fileName);

    static sf::Font font;
protected:
    sf::RectangleShape backImage;
private:
    static sf::Font& setUpFont();
};


#endif //TOWEROFHANOIFINAL_BACKGROUND_H
