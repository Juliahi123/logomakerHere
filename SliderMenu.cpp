//
// Created by Rena on 5/30/21.
//

#include "SliderMenu.h"
SliderMenu::SliderMenu()
{
    // 0
    addSliderElementToList("Text Opacity:", {250, 3}, {30,480});
    // 1
    addSliderElementToList("Font Size:", {150, 3}, {450,480});
    // 2
    addSliderElementToList("skew:", {130, 3},{750,480});

    // 3
    addSliderElementToList("Shadow Opacity:", {250, 3},{30,530});
    // 4
    addSliderElementToList("Background Opacity:", {250, 3},{500,530});

    // 5
    addSliderElementToList("Text X-Axis:", {700, 3},{30,580});
    // 6
    addSliderElementToList("Text Y-Axis:", {700, 3},{30,630});
    // 7
    addSliderElementToList("Shadow X-Axis:",{700, 3}, {30,680});
    // 8
    addSliderElementToList("Shadow Y-Axis:", {700, 3},{30,730});
    randColor  = false;

}
void SliderMenu::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect boxSize = box.getBoxGlobal();
    if (boxSize.contains(mpos) && event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            std::cout << "dddddhreifeiufheiuhfehfeu";
            setUpNumberList();
            randColor = true;
        }
    }
    for(int i = 0; i < sliderList.size(); i++)
    {
        sliderList.at(i).addEventHandler(window, event);
    }
}
bool SliderMenu::getRandColor()
{
    if(randColor)
        return true;
    else
        return false;
}

void SliderMenu::setRandColorFalse()
{
    randColor = false;
}

SliderMenu::SliderMenu(Slider slider)
{
    sliderList.push_back(slider);
}
void SliderMenu::addSliderElementToList(std::string labelName, sf::Vector2f lineSize, sf::Vector2f labelPosition)
{
    Slider temp(labelName, lineSize, labelPosition);
    sliderList.push_back(temp);
}

void SliderMenu::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(int i = 0; i < sliderList.size(); i++)
    {
        window.draw(sliderList.at(i));
    }
}
void SliderMenu::updateSliderMenu()
{

}
void SliderMenu::setUpNumberList()
{
    for(int i = 0; i < sliderList.size(); i++)
    {
        sliderList.at(i).setCirclePosition(randomg.getNumberList().at(i));
    }
    sliderColorList.clear();
    sliderColorList.push_back(randomg.getNumberList().at(sliderList.size()));
    sliderColorList.push_back(randomg.getNumberList().at(sliderList.size()+1));
    sliderColorList.push_back(randomg.getNumberList().at(sliderList.size()+2));
    sliderColorList.push_back(randomg.getNumberList().at(sliderList.size()+3));

}
void SliderMenu::setValue()
{
    randomg.setFileValue();
    for(int i = 0; i < sliderList.size(); i++)
    {
        sliderList.at(i).setCirclePosition(randomg.getNumberList1().at(i));
    }

}
std::vector<int> SliderMenu::setOutFile()
{
    for(int i = 0 ; i < sliderList.size(); i++)
        {
            sliderValueList.push_back(sliderList.at(i).getSliderValue());
        }
    return sliderValueList;
}
std::vector<int> SliderMenu::getSliderColorList()
{
    return sliderColorList;
}

int SliderMenu::getSliderValueFromList(int index)
{
    return sliderList.at(index).getSliderValue();
}
std::vector<Slider> SliderMenu::getSliderList()
{
    return sliderList;
}
