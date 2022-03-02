//
// Created by Rena on 5/25/21.
//

#include "Item.h"
Item::Item(){}
void Item::createItem(std::string str)
{
    drawTextOrNot = true;
    std::cout <<"create";
    rectBox.setPosition({0,0});
    if(asset::fontLoader == false)
    {
        asset::fontForS.loadFromFile("arial.ttf");
        asset::fontLoader = true;
    }

    text.setFont(asset::fontForS);
    text.setCharacterSize(20);
    text.setString(str);
    rectBox.setFillColor(sf::Color::Black);
}
sf::FloatRect Item::getGlobal()
{
    return rectBox.getGlobalBounds();
}
void Item::notVisual()
{
    drawTextOrNot = false;
    rectBox.setFillColor(sf::Color::Black);
    rectBox.setScale(0,0);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(0);
}
void Item::visual()
{
    rectBox.setScale(1,1);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
    drawTextOrNot = true;

}
void Item::hightLight()
{
    rectBox.setFillColor(sf::Color::Blue);
}
void Item::unHighLight()
{

    rectBox.setFillColor(sf::Color::Black);
}

void Item::setPosition(sf::Vector2f pos)
{
    rectBox.setPosition(pos);
    sf::FloatRect rectBounds = rectBox.getGlobalBounds();
    sf::FloatRect textBounds = text.getGlobalBounds();
    text.setPosition(rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
                     rectBounds.top + (rectBounds.height / 2) - textBounds.height);
}
void Item::setSize(sf::Vector2f size)
{
    rectBox.setSize(size);
}
void Item::createItem(std::string str, sf::Vector2f pos, sf::Vector2f size)
{
    createItem(str);
    rectBox.setSize(size);
    setPosition(pos);
}

std::string Item::getItemString()
{
    return text.getString();
}
sf::Vector2f Item::getItemPosition()
{
    return rectBox.getPosition();
}
void Item::draw(sf::RenderTarget& window,  sf::RenderStates states) const
{

    window.draw(rectBox);
    window.draw(text);

}