//
// Created by Rena on 6/5/21.
//

#include "windowOne.h"
windowOne::windowOne()
{
}
void windowOne::draw()
{
    w.setPosition({100,100});
    w.setFramerateLimit(120);

    while(w.isOpen()){
        sf::Event event;
        while(w.pollEvent(event)){
            if(event.type == sf::Event::Closed) {
                t.setFalse();
                w.close();
            }}
        t.addEventHandler(w,event);
        t.update();
        w.clear(sf::Color::Black);
        w.draw(t);
        w.display();
        }
    }

void windowOne::close()
{
    w.close();
}



void windowOne::openSmallWindow() {
    w.create({1000, 800}, "New Project");
}
