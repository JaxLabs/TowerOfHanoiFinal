//
// Created by Jax on 5/22/21.
//

#include "Fade.h"
sf::Font Fade::font = Fade::setUpFont();

void Fade::appear() {
    sf::Color c = text.getFillColor();
    c.a = 255;
    text.setFillColor(c);
}

void Fade::update() {
    sf::Color c = text.getFillColor();
    if (c.a <= 5) {
        c.r = 150;
        c.g = 108;
        c.b = 65;
        c.a = 0;
    } else {
        c.r = 255;
        c.g = 255;
        c.b = 255;
        c.a -= 5;
    }
    text.setFillColor(c);
}

sf::Font&  Fade::setUpFont(){
    font.loadFromFile("fonts/OpenSans-Bold.ttf");
    return font;
}

void Fade::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(text);
}

Fade::Fade(std::string textString, int x, int y) {
    text.setString(textString);
    text.setPosition(x,y);
    text.setFont(font);
    text.setFillColor(sf::Color(150,108,65,0));
    text.setCharacterSize(100);
}
