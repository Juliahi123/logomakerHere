//
// Created by Rena on 5/27/21.
//

#ifndef FIRSTDRAFT_BOX_H
#define FIRSTDRAFT_BOX_H

#include <SFML/Graphics.hpp>
#include "TextInput.h"
class Box : public sf::Drawable{
private:
    sf::RectangleShape rect;
    TextInput textInput;
public:
    Box();
    void updateReturn();
    void setBoxSize();
    void setTextInput(TextInput t);
    sf::Vector2f getBoxSize();
    sf::Vector2f getBoxPosition();
    sf::FloatRect getBoxGlobal();
    void setBoxBold();
    sf::RectangleShape getRect();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //FIRSTDRAFT_BOX_H
