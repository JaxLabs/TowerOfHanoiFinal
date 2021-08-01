//
// Created by Jax on 5/19/21.
//

#ifndef TOWEROFHANOIFINAL_STORY_H
#define TOWEROFHANOIFINAL_STORY_H
#include "Background.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Story : public Background{
public:
    Story();
    Story(std::string fileName, std::string dialog, bool);
    Story(std::string fileName, std::string dialog);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    sf::RectangleShape textBox;
    sf::Text dialogText;
    std::string dialog;
    bool drawTextbox;

};


#endif //TOWEROFHANOIFINAL_STORY_H
