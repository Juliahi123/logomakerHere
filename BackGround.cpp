//
// Created by Rena on 5/30/21.
//

#include "BackGround.h"
BackGround::BackGround()
{
    background.setSize({1000, 360});
    background.setPosition({0, 60});
    background.setFillColor(sf::Color::Transparent);

}
sf::Vector2f BackGround::getSize()
{
    return background.getSize();
}

void BackGround::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
}

void BackGround::setBackGround(sf::Vector2f size)
{
    background.setSize(size);
}
void BackGround::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(colorpicker);
}
void BackGround::setOpacity(int value, sf::Color color)
{
    sf::Color white = color;
    white.a = value;
    background.setFillColor(white);
}