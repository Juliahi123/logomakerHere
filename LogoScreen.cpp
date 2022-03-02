//
// Created by Rena on 5/27/21.
//

#include "LogoScreen.h"
LogoScreen::LogoScreen()
{
    if(!loadFont) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cout << "Failed to load font\n";
        }
        loadFont = true;
    }


    text.setFont(font);
    text2.setFont(font);
    file.setFile();

}
void LogoScreen::setFont(int index)
{
    if (!font.loadFromFile("valuoldcaps.ttf")) {
        std::cout << "Failed to load font\n";
    }
    text.setFont(font);
    text2.setFont(font);
}
void LogoScreen::setFileValue()
{
    sliderMenu.setValue();
}


LogoScreen::LogoScreen(std::string str, sf::Vector2f pos, int size)
{
    text.setFont(font);
    text.setString(str);
    //text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
  //  text.setPosition(pos);
    text.setCharacterSize(size);
//    sf::Color white = sf::Color::White;
//    white.a = 90;
    text2.setStyle(sf::Text::Italic);
    //text2.setFillColor(white);
    text2.setPosition(pos.x, pos.y+190);

    text2.setCharacterSize(size);
    text2.setString(str);
}
void LogoScreen::setLogoString(std::string s)
{
    text.setString(s);
    text2.setString(s);
}
void LogoScreen::setLogoPos(sf::Vector2f pos)
{
    text.setPosition(pos);
    text2.setPosition(pos.x, pos.y+190);
}
void LogoScreen::setLogo(int size, sf::Color color, std::string s, sf::Vector2f pos)
{
    //text.setFillColor(color);
    text.setString(s);
    //text.setPosition(pos);
;

    text2.setString(s);
}
void LogoScreen::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    fontBox.addEventHandler(window, event);
    sliderMenu.addEventHandler(window, event);
    //sliderMenu.setOutFile();
    colorPicker.addEventHandler(window,event);
    update(colorPicker.returnTextColorPicker());
    if(sliderMenu.getRandColor())
    {
        colorPicker.setColorByValue(sliderMenu.getSliderColorList().at(0), sliderMenu.getSliderColorList().at(1));
        colorPicker.setBackgroundColorByValue(sliderMenu.getSliderColorList().at(2), sliderMenu.getSliderColorList().at(3));
        sliderMenu.setRandColorFalse();
    }
}
int LogoScreen::get11()
{
    return colorPicker.get11();
}
int LogoScreen::get12()
{
    return colorPicker.get12();
}
int LogoScreen::get21()
{
    return colorPicker.get21();
}
int LogoScreen::get22()
{
    return colorPicker.get22();
}
std::vector<int> LogoScreen::getSliderValueList()
{
    if(sliderMenu.getSliderList().size() > 3)
    return sliderMenu.setOutFile();
}

std::string LogoScreen::getString()
{
    return file.getText();
}

void LogoScreen::setColorValue()
{
    for(int i =0 ; i < file.getFileList().size(); i++)
    {
        std::cout << "finalnumber list " << std::to_string(file.getFileList().at(i)) + ", "<<  std::endl;
    }
    colorPicker.setColorByValue(file.getFileList().at(9), file.getFileList().at(10));
    colorPicker.setBackgroundColorByValue(file.getFileList().at(11), file.getFileList().at(12));
}

void LogoScreen::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(sliderMenu);
    window.draw(background);
    window.draw(text);
    window.draw(text2);
    window.draw(fontBox);
    window.draw(colorPicker);
}
void LogoScreen::update(sf::Color color)
{
    sliderMenu.updateSliderMenu();

    int temp = sliderMenu.getSliderValueFromList(1);
    text.setCharacterSize(temp);
    text2.setCharacterSize(temp);
    temp = sliderMenu.getSliderValueFromList(0);
    sf::Color white = color;
    white.a = temp;
    text.setFillColor(white);
    temp= sliderMenu.getSliderValueFromList(3);
    white.a = temp;
    text2.setFillColor(white);

    temp = sliderMenu.getSliderValueFromList(5);
    text.setPosition(temp, text.getPosition().y);
    temp = sliderMenu.getSliderValueFromList(6);
    text.setPosition(text.getPosition().x, temp);

    text2.setStyle(sf::Text::Italic);
    text2.setScale(1,-1);

    temp = sliderMenu.getSliderValueFromList(7);
    text2.setPosition(temp, text2.getPosition().y);
    temp = sliderMenu.getSliderValueFromList(8);
    text2.setPosition(text2.getPosition().x, temp);

    temp =sliderMenu.getSliderValueFromList(4);
    background.setOpacity(temp, colorPicker.returnBackGroundColorPicker());

    temp = sliderMenu.getSliderValueFromList(2);
    text2.setScale(1,-0.01*temp);

    if (!font.loadFromFile(fontBox.getMenuFileName())) {
            std::cout << "Failed to load font\n";
        }
    text.setFont(font);
    text2.setFont(font);

}
void LogoScreen::setColorValueForOutput()
{
    colorPicker.setColorValueForOutput();
}
