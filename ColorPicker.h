//
// Created by Rena on 5/31/21.
//

#ifndef FIRSTDRAFT_COLORPICKER_H
#define FIRSTDRAFT_COLORPICKER_H
#include <SFML/Graphics.hpp>
#include <iostream>
class ColorPicker : public sf::Drawable{
private:
    int showRect;
    int showBigColor;
    int showRect2;
    int rectColorForIndex;
    int rectColorSecondIndex;
    int rectBackColorForIndex;
    int rectBackColorSecondIndex;

    sf::VertexArray color;
    sf::RectangleShape rectColor;
    sf::RectangleShape rectColor2;
    sf::RectangleShape backRect;
    sf::RectangleShape backRect2;
    std::vector<sf::RectangleShape> rectColorList;
    std::vector<sf::RectangleShape> rectColorList2;
    std::vector<sf::RectangleShape> pixels;


public:
    ColorPicker();
    void setForBackGroundColorPicker();
    void setColorPicker(sf::Color color, sf::Vector2f pos);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setRectColor(sf::Color color, sf::RectangleShape rect);
    sf::Color returnTextColorPicker();
    sf::Color returnBackGroundColorPicker();
    void setColorByValue(int a, int b);
    void getColorString(int index) ;
    void setBackgroundColorByValue(int a, int b);
    void update(sf::Color color, sf::Vector2f pos);
    void setColorValueForOutput();
    void setColorFromFile(sf::Color color, int a);
    int get11();
    int get12();
    int get21();
    int get22();
    sf::VertexArray getColor();
};


#endif //FIRSTDRAFT_COLORPICKER_H
