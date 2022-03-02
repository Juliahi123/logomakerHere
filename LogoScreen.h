//
// Created by Rena on 5/27/21.
//

#ifndef FIRSTDRAFT_LOGOSCREEN_H
#define FIRSTDRAFT_LOGOSCREEN_H
#include "asset.h"
#include "TextInput.h"
#include <SFML/Graphics.hpp>
#include "SliderMenu.h"
#include "BackGround.h"
#include "ColorPicker.h"
#include "saveFile.h"
#include "FontBox.h"
class LogoScreen : public sf::Drawable{
private:
    ColorPicker colorPicker;
    sf::Text text;
    sf::Text text2;
    saveFile file;
    SliderMenu sliderMenu;
    BackGround background;
    FontBox fontBox;
public:
    LogoScreen();
    LogoScreen(std::string str, sf::Vector2f pos, int size);
    void setLogoSize(int size);
    void setLogoColor(sf::Color color);
    void setFont(int index);
    void update(sf::Color color);
    void setLogoString(std::string s);
    void setLogoPos(sf::Vector2f pos);
    void setLogo(int size, sf::Color color, std::string s, sf::Vector2f pos);
    void setFileValue();
    std::string getString();
    void setColorValue();
    void setColorValueForOutput();
    std::vector<int> getSliderValueList();
    int get11();
    int get12();
    int get21();
    int get22();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //FIRSTDRAFT_LOGOSCREEN_H
