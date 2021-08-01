//
// Created by Jax on 5/24/21.
//

#include "MainGameRunning.h"
void MainGameRunning::run() {
    sf::VideoMode videoMode(2320,1276, 32);
    sf::RenderWindow window (videoMode, "TowerOfHanoi");
    window.setFramerateLimit(60);

    Fade one("1",530,800);
    Fade two("2", 1170,800);
    Fade three("3", 1775, 800);
    Fade s("Solve",1050,800);
    Fade r("Reset",1050,800);

    Background mainBackground;
    
    //starting story
    introStory.push_back(Story ("graphics/#1.png", "In the kingdom of Bazaar\nthere lived a \nbeautiful princess"));
    introStory.push_back(Story ("graphics/#2.png", "Jealous of her beauty a witch\ngave her a cursed apple\nwhich made her sleep forever"));
    introStory.push_back(Story ("graphics/#3.png", "A prince from another\nkingdom came to\nbrake the curse"));
    introStory.push_back(Story ("graphics/#4.png", "Ignoring warnings to not kiss\nthe princess because she\nate a cursed apple the\nprince did so anyway and\nquickly fell asleep too"));
    introStory.push_back(Story ("graphics/#5.png", "And this is where I\nthe kingdoms\nalchemist come in"));
    introStory.push_back(Story ("graphics/rules.png", "", false));

    //end story
    endingStory.push_back(Story ("graphics/won.png","", false));
    endingStory.push_back(Story ("graphics/ending #1.png","", false));
    endingStory.push_back(Story ("graphics/ending #2.png","", false));
    endingStory.push_back(Story ("graphics/ending #3.png","", false));

    State state = State::START;

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(state){
                case State::START:
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        state = State::INTRO;
                    }
                    break;
                case State::INTRO:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                    || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (introPageNum < introStory.size()-1)
                            introPageNum++;
                        else {
                            bottle.setFromBottle(0);
                            bottle.setTooBottle(0);
                            state = State::GAME;
                        }
                    }
                    break;
                case State::GAME:
                    if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Num1) {
                        one.appear();
                        if (bottle.getFromBottle()>0){
                            bottle.setTooBottle(1);
                            bottle.makeMove(disks);
                        }
                        else{
                            bottle.setFromBottle(1);
                        }
                    }
                    else if (event.key.code == sf::Keyboard::Num2) {
                        two.appear();
                        if (bottle.getFromBottle()>0){
                            bottle.setTooBottle(2);
                            bottle.makeMove(disks);
                        }
                        else{
                            bottle.setFromBottle(2);
                        }
                    }
                    else if (event.key.code == sf::Keyboard::Num3) {
                        three.appear();
                        if (bottle.getFromBottle()>0){
                            bottle.setTooBottle(3);
                            bottle.makeMove(disks);
                        }
                        else{
                            bottle.setFromBottle(3);
                        }
                    }
                    else if (event.key.code == sf::Keyboard::R) {
                        r.appear();
                        disks.reset();
                    }
                    else if(event.key.code == sf::Keyboard::S){
                        s.appear();
                        disks.clockReset();
                        runSolve = true;
                    }
                    if (disks.yourAWinner()){
                        state = State::ENDING;
                    }
                }
                break;
                case State::ENDING:
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                        || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        if (endingPageNum < endingStory.size() - 1)
                            endingPageNum++;
                    }
            }


            if(event.type == sf::Event::Closed)//checks if x is pressed
                window.close();

        }
        //animates screen
        window.clear();
        switch(state){
            case State::START:
                window.draw(screen);
                break;
            case State::INTRO:
                window.draw(introStory[introPageNum]);
                break;
            case State::GAME:
                if (runSolve){
                    disks.solve();
                    if (disks.yourAWinner() && disks.getSolveStep() == 15){
                        state = State::ENDING;
                    }
                }
                window.draw(maingame);
                window.draw(one);
                window.draw(two);
                window.draw(three);
                window.draw(r);
                window.draw(s);
                one.update();
                two.update();
                three.update();
                r.update();
                s.update();
                window.draw(disks);

                break;
            case State::ENDING:
                window.draw(endingStory[endingPageNum]);
                break;
            default:
                exit(0);

        }

        window.display();
    }
}

