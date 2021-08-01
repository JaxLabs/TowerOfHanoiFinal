//
// Created by Jax on 5/17/21.
//

#include "Background.h"
Background::Background() : Background(0,0){

}

Background::Background(float x, float y){
    backImage.setSize({x, y});
}

Background::Background(float x, float y, std::string fileName){
    backImage.setTexture(TextureManager::instance().loadTexture(fileName));
    backImage.setSize({x, y});
}

sf::Font Background::font = Background::setUpFont();

sf::Font& Background::setUpFont(){
    font.loadFromFile("fonts/OpenSans-Bold.ttf");
    return font;
}