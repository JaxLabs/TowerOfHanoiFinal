//
// Created by Jax on 5/19/21.
//

#include "Story.h"

Story::Story() : Story("graphics/#1.png", "HELLO", true){

}

Story::Story(std::string fileName, std::string dialog):
             Story(fileName,dialog, true){

}


Story::Story(std::string fileName, std::string dialog, bool drawTextbox)
            : dialog(dialog), Background(2320,1276), drawTextbox(drawTextbox) {
    backImage.setTexture(TextureManager::instance().loadTexture(fileName));

    textBox.setSize(sf::Vector2f (950.0f, 500.0f));
    textBox.setPosition(1250,760);
    textBox.setFillColor(sf::Color(169,169,169,220));//set alpha

    dialogText.setFont(Background::font);
    dialogText.setPosition(1250,760);
    dialogText.setCharacterSize(60);
    dialogText.setString(dialog);
    dialogText.setFillColor(sf::Color::Black);




}

void Story::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(backImage);
    if (drawTextbox){
        window.draw(textBox);
        window.draw(dialogText);
    }

}