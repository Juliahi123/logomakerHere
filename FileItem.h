//
// Created by Rena on 6/8/21.
//

#ifndef FIRSTDRAFT_FILEITEM_H
#define FIRSTDRAFT_FILEITEM_H


#include "asset.h"
#include "MouseEvent.h"
#include <iostream>

class FileItem: public sf::Transformable, public sf::Drawable{

private:
    sf::Sprite icon;
    sf::Text text;
    sf::RectangleShape box;
    float padding = 10;

public:
    //Constructors
    FileItem();
    FileItem(Image icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    //uses an enum to change the icon to a folder or file
    void setIcon(Image icon);
    //if color is blue, that means clicked. if transparent then not clicked
    sf::Color getFillColor() const;
};



#endif //FIRSTDRAFT_FILEITEM_H
