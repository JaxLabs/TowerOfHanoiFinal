//
// Created by Jax on 5/17/21.
//

#ifndef TOWEROFHANOIFINAL_TEXTUREMANAGER_H
#define TOWEROFHANOIFINAL_TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
class TextureManager {
public:
    TextureManager();
    sf::Texture startTexture;
    static TextureManager& instance()
    {
        static TextureManager INSTANCE;
        return INSTANCE;
    }
    sf::Texture* loadTexture(std::string filename);
};


#endif //TOWEROFHANOIFINAL_TEXTUREMANAGER_H
