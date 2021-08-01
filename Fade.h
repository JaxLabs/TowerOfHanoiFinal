//
// Created by Jax on 5/22/21.
//

#ifndef TOWEROFHANOIFINAL_FADE_H
#define TOWEROFHANOIFINAL_FADE_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Fade: public sf::Drawable {
public:
    Fade(std::string, int, int);
    void update();
    void appear();
    static sf::Font font;
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    static sf::Font& setUpFont();
    sf::Text text;
};


#endif //TOWEROFHANOIFINAL_FADE_H
