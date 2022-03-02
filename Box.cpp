//
// Created by Rena on 5/27/21.
//

#include "Box.h"
Box::Box()
{
    rect.setSize({300,30});
    rect.setFillColor(sf::Color::Black);
    rect.setPosition({30,430});
    rect.setOutlineThickness(1);
    rect.setOutlineColor(sf::Color::White);

}
sf::RectangleShape Box::getRect()
{
    return rect;
}
void Box::updateReturn()
{
//    int s = textInput.getLinkedListSize();
//    sf::Vector2f one = textInput.getTextPosition(s - 1);
//    rect.setSize({500, one.y - 70});
}

sf::FloatRect Box::getBoxGlobal()
{
    return rect.getGlobalBounds();
}

void Box::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(rect);
}
sf::Vector2f Box::getBoxPosition()
{
    return rect.getPosition();
}

sf::Vector2f Box::getBoxSize()
{
    return rect.getSize();
}
void Box::setTextInput(TextInput t)
{
    textInput = t ;
    updateReturn();
}

