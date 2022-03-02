//
// Created by Rena on 5/27/21.
//

#include "Label.h"
Label::Label()
{
    l = "" ;
    setLabel(l);
    setLabelSize(15);
    setLabelPosition({30,400});

}
void Label::getNormal()
{
    text1.setString("Background Color");
}

void Label::setLabel(std::string a)
{
    l = a;
    text.setFillColor(sf::Color::Blue);
    if(!font.loadFromFile("Arial.ttf"))
        exit(1);
    text.setFont(font);
    text.setCharacterSize(size);
    text.setString(l);
    text1.setFont(font);
    text1.setCharacterSize(20);
    text1.setPosition({770,440});
    text1.setFillColor(sf::Color::Yellow);
    text1.setString("Background Color");
}

void Label::setLabelSize(int size)
{
    this->size = size;
    text.setCharacterSize(size);
}

void Label::setLabelPosition(sf::Vector2f pos)
{
    text.setPosition(pos);
}
void Label::tooMuchletter()
{
    text1.setString("You enter too much ! \n"
                    "Delete something to keep testing!");
}

void Label::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(text);
    window.draw(text1);
}
