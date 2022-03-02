//
// Created by Rena on 5/30/21.
//

#ifndef FIRSTDRAFT_SLIDERMENU_H
#define FIRSTDRAFT_SLIDERMENU_H
#include "Slider.h"
#include "Box.h"
#include "randomGenerator.h"
class SliderMenu:public sf::Drawable {
private:
    randomGenerator randomg;
    Box box;
    std::vector<Slider> sliderList;
    std::vector <int> sliderColorList;
    std::vector<int> sliderValueList;
    bool randColor;
public:
    SliderMenu();
    SliderMenu(Slider slider);
    void setRandColorFalse();
    bool getRandColor();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addSliderToList(Slider slider);
    void setUpNumberList();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void addSliderElementToList(std::string labelName, sf::Vector2f lineSize, sf::Vector2f labelPosition);
    int getSliderValueFromList(int index);
    void setValue();
    std::vector<int> setOutFile();
    std::vector<int> getSliderColorList();
    std::vector<Slider> getSliderList();
    void updateSliderMenu();
};


#endif //FIRSTDRAFT_SLIDERMENU_H
