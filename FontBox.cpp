//
// Created by Rena on 6/4/21.
//

#include "FontBox.h"
FontBox::FontBox()
{
    show = 0;
    sf::RectangleShape fontBox;
    fontBox.setSize({250, 40});
    fontBox.setPosition({460, 425});
    fontBox.setFillColor(sf::Color::White);
    fontBox.setOutlineColor(sf::Color::Black);
    fontBox.setOutlineThickness(1);

    fontBoxMenu.push_back(fontBox);
    sf::RectangleShape fontBox1;
    fontBox1.setSize({250, 40});
    fontBox1.setPosition({460, 465});
    fontBox1.setFillColor(sf::Color::White);
    fontBox1.setOutlineColor(sf::Color::Black);
    fontBox1.setOutlineThickness(1);
    fontBoxMenu.push_back(fontBox1);

    sf::RectangleShape fontBox2;
    fontBox2.setSize({250, 40});
    fontBox2.setPosition({460, 505});
    fontBox2.setFillColor(sf::Color::White);
    fontBox2.setOutlineColor(sf::Color::Black);
    fontBox2.setOutlineThickness(1);
    fontBoxMenu.push_back(fontBox2);

    if(!loadFont) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cout << "Failed to load font\n";
        }
        loadFont = true;
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(30);
    text.setString("arial.ttf");
    text.setFillColor(sf::Color::Black);
    text.setPosition({fontBox.getPosition().x +3, fontBox.getPosition().y});
    textMenu.push_back(text);

    sf::Text text1;
    text1.setFont(font);
    text1.setCharacterSize(30);
    text1.setString("valuoldcaps.ttf");
    text1.setFillColor(sf::Color::Black);
    text1.setPosition({fontBox1.getPosition().x +3, fontBox1.getPosition().y});
    textMenu.push_back(text1);

    sf::Text text2;
    text2.setFont(font);
    text2.setCharacterSize(30);
    text2.setString("stocky.ttf");
    text2.setFillColor(sf::Color::Black);
    text2.setPosition({fontBox2.getPosition().x +3, fontBox2.getPosition().y});
    textMenu.push_back(text2);
    fontName = text.getString();
}
void FontBox::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect fontBoxSize = fontBoxMenu.at(0).getGlobalBounds();
    sf::FloatRect fontBoxSize1 = fontBoxMenu.at(1).getGlobalBounds();
    sf::FloatRect fontBoxSize2 = fontBoxMenu.at(2).getGlobalBounds();

    if (event.type == sf::Event::MouseButtonPressed && fontBoxSize.contains(mpos))
    {
        show = 1;
    }
    if (show == 1)
    {
        if (event.type == sf::Event::MouseButtonPressed && fontBoxSize1.contains(mpos))
        {
            std::string temp = textMenu.at(0).getString();
            textMenu.at(0).setString(textMenu.at(1).getString());
            textMenu.at(1).setString(temp);
            show = 0;
        }
        else if (event.type == sf::Event::MouseButtonPressed && fontBoxSize2.contains(mpos))
        {
            show = 0;
            std::string temp = textMenu.at(0).getString();
            textMenu.at(0).setString(textMenu.at(2).getString());
            textMenu.at(2).setString(temp);
        }
        else if (event.type == sf::Event::MouseButtonPressed && !fontBoxSize.contains(mpos))
        {
            show = 0;
        }
    }
    fontName = textMenu.at(0).getString();
}
std::string FontBox::getMenuFileName()
{
    return fontName;
}

void FontBox::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if(show == 1)
    {
        for(int i = 0; i < fontBoxMenu.size(); i++)
        {
            window.draw(fontBoxMenu.at(i));
            window.draw(textMenu.at(i));
        }
    }
    else
    {
        window.draw(fontBoxMenu.at(0));
        window.draw(textMenu.at(0));
    }
}
