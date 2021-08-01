//
// Created by Jax on 5/17/21.
//

#include "TextureManager.h"
TextureManager::TextureManager() {
    startTexture.loadFromFile("graphics/start screen.png");

}

sf::Texture* TextureManager::loadTexture(std::string filename) {
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(filename);
    return texture;
}


