//
// Created by Rena on 5/30/21.
//

#include "Slider.h"
Slider::Slider()
{
    if(!loadFont) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cout << "Failed to load font\n";
        }
        loadFont = true;
    }
    value = 0;
    labelBeforeLine.setFont(font);
    valueText.setFont(font);
}
Slider::Slider(std::string labelName, sf::Vector2f lineSize, sf::Vector2f labelPosition)
{
    if(!loadFont) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cout << "Failed to load font\n";
        }
        loadFont = true;
    }
    value = 0;
    labelBeforeLine.setFont(font);
    labelBeforeLine.setString(labelName);
    labelBeforeLine.setCharacterSize(20);
    labelBeforeLine.setPosition(labelPosition);
    labelBeforeLine.setFillColor(sf::Color::White);
    valueText.setFont(font);
    valueText.setString(std::to_string(value));
    valueText.setCharacterSize(20);
    valueText.setFillColor(sf::Color::White);
    line.setSize(lineSize);
    line.setFillColor(sf::Color::White);
    line.setPosition(labelPosition.x+labelBeforeLine.getGlobalBounds().width +5, labelPosition.y+12);
    circle.setRadius(9);
    circle.setFillColor(sf::Color::White);
    circle.setPosition({line.getPosition().x + 1,line.getPosition().y -7});
    valueText.setPosition({line.getPosition().x+line.getGlobalBounds().width + 15, labelPosition.y});
    circlePos = circle.getPosition();
}
void Slider::setUpSlider(std::string labelName, sf::Vector2f lineSize, sf::Vector2f labelPosition)
{
    Slider(labelName, lineSize, labelPosition);
}

void Slider::setPosition(sf::Vector2f labelPosition)
{

}
int Slider::getSliderValue()
{
    return value;
}

void Slider::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect cirleSize = circle.getGlobalBounds();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cirleSize.contains(mpos)) {
        if (mpos.x >= line.getPosition().x && mpos.x <= line.getPosition().x + line.getGlobalBounds().width) {
            circle.setPosition({mpos.x - circle.getRadius(), circle.getPosition().y});
            circle.setFillColor(sf::Color::Yellow);
            int tempvalue = circle.getPosition().x + circle.getRadius() - line.getPosition().x;

            value = tempvalue;
            valueText.setString(std::to_string(value));

        }
    }
    else
    {
        circle.setFillColor(sf::Color::White);
    }
}
void Slider::setCirclePosition(float value1)
{
    std::cout <<"value is " << value1 <<std::endl;
    circle.setPosition({circlePos.x - circle.getRadius()+ value1, circle.getPosition().y});
    int tempvalue = value1;

    value = tempvalue;
    valueText.setString(std::to_string(value));
}

void Slider::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(line);
    window.draw(labelBeforeLine);
    window.draw(circle);
    window.draw(valueText);
}
