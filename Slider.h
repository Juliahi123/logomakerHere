//
// Created by Rena on 5/30/21.
//

#ifndef FIRSTDRAFT_SLIDER_H
#define FIRSTDRAFT_SLIDER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "asset.h"
class Slider: public sf::Drawable {
private:
    sf::RectangleShape line;
    sf::Text labelBeforeLine;
    sf::CircleShape circle;
    int value;
    sf::Text valueText;
    sf::Vector2f circlePos;
public:
    Slider();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    Slider(std::string labelName, sf::Vector2f lineSize, sf::Vector2f labelPosition);
    void setUpSlider(std::string labelName, sf::Vector2f lineSize, sf::Vector2f labelPosition);
    void setPosition(sf::Vector2f labelPosition);
    int getSliderValue();
    void setCirclePosition(float value);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //FIRSTDRAFT_SLIDER_H
