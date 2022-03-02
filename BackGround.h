//
// Created by Rena on 5/30/21.
//

#ifndef FIRSTDRAFT_BACKGROUND_H
#define FIRSTDRAFT_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "ColorPicker.h"
class BackGround: public sf::Drawable {
private:
    ColorPicker colorpicker;
    sf::RectangleShape background;
public:
    BackGround();
    void setBackGround(sf::Vector2f size);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setOpacity(int value, sf::Color c);
    sf::Vector2f getSize();
};


#endif //FIRSTDRAFT_BACKGROUND_H
