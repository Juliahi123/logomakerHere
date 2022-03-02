//
// Created by Rena on 5/25/21.
//

#ifndef FIRSTDRAFT_ITEM_H
#define FIRSTDRAFT_ITEM_H


#include <SFML/Graphics.hpp>
# include "asset.h"
# include <iostream>
class Item : public sf::Drawable{
private:
    sf::RectangleShape rectBox;
    bool drawTextOrNot;
    sf::Text text;
public:
    Item();
    void createItem(std::string str);
    void hightLight();
    void visual();
    sf::FloatRect getGlobal();
    void unHighLight();
    void notVisual();
    void createItem(std::string str, sf::Vector2f pos, sf::Vector2f size);
    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);
    std::string getItemString();
    sf::Vector2f getItemPosition();

    void draw(sf::RenderTarget& window,  sf::RenderStates states) const;
};

#endif //FIRSTDRAFT_ITEM_H
