//
// Created by Rena on 6/5/21.
//

#include "Menu.h"
Menu::Menu(){}
void Menu::createMenu(std::string str, sf::Vector2f pos)
{
    size = {150, 30};
    position = pos;
    rect.setSize(size);
    rect.setFillColor(sf::Color::White);
    rect.setPosition(pos);
    //rect.setOutlineColor(sf::Color::White);
    if(!font.loadFromFile("arial.ttf"))
        exit(111);
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Blue);
    sf::FloatRect rectBounds = rect.getGlobalBounds();
    sf::FloatRect textBounds = text.getGlobalBounds();
    text.setPosition(rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
                     rectBounds.top + (rectBounds.height / 2) - textBounds.height);
}

//void Menu::setUpDefaultItemList(int index)
//{
//    float tempY = position.y;
//    for(int i = 0 ; i < 3; i++)
//    {
//        tempY +=30;
//        std::string temp = "Menu" + std::to_string(index)+" Item" + std::to_string(i+1);
//        item.createItem(temp, {position.x, tempY}, size);
//        itemList.addItemToList(item);
//    }
//}
void Menu::clear()
{
    itemList.clear();
}

void Menu::showList()
{
    itemList.visual();
}
ItemList Menu::getItemListAt(int index)
{
    itemList.getItemList();
}

void Menu::notShowList()
{
    itemList.notVisual();
}
sf::FloatRect Menu::getGlobal()
{
    return rect.getGlobalBounds();
}
void Menu::highLightMenu()
{
    text.setFillColor(sf::Color::White);
    rect.setFillColor(sf::Color::Blue);
}
void Menu::NoHightLightMenu()
{
    text.setFillColor(sf::Color::Blue);
    rect.setFillColor(sf::Color::Yellow);
}
void Menu::resetMenu()
{


}

void Menu::setPosition(sf::Vector2f pos)
{
    position = pos;
    rect.setPosition(position);
    sf::FloatRect rectBounds = rect.getGlobalBounds();
    sf::FloatRect textBounds = text.getGlobalBounds();
    text.setPosition(rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
                     rectBounds.top + (rectBounds.height / 2) - textBounds.height);

}

void Menu::draw(sf::RenderTarget& window,  sf::RenderStates states) const
{
    window.draw(rect);
    window.draw(text);
    window.draw(itemList);
}
