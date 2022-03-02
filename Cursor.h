//
// Created by Rena on 5/27/21.
//

#ifndef FIRSTDRAFT_CURSOR_H
#define FIRSTDRAFT_CURSOR_H
#include <SFML/Graphics.hpp>
#include "State.h"


class Cursor : public sf::Drawable{
private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    State ss;
    int blinkSpeed = 500;
    void toggleBlinkState();

public:
    Cursor();
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f size);
    void updatePosition(sf::Vector2f v);
    sf::Vector2f getCursorPosition();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update(State s);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    sf::FloatRect getGlobalBounds();
};

#endif //FIRSTDRAFT_CURSOR_H
