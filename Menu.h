//
// Created by Rena on 6/5/21.
//

#ifndef FIRSTDRAFT_MENU_H
#define FIRSTDRAFT_MENU_H

#include "ItemList.h"
#include "Item.h"
class Menu : public sf::Drawable{
private:
    Item item;
    ItemList itemList;
    sf::RectangleShape rect;
    sf::Text text;
    sf::Font font;
    sf::Vector2f position;
    sf::Vector2f size;
public:
    Menu();
    //void setUpDefaultItemList(int i);
    void setPosition(sf::Vector2f pos);
    void resetMenu();
    void clear();
    ItemList getItemListAt(int index);
    void showList();
    void notShowList();
    void highLightMenu();
    void NoHightLightMenu();
    sf::FloatRect getGlobal();
    void createMenu(std::string str, sf::Vector2f pos);
    void draw(sf::RenderTarget& window,  sf::RenderStates states) const;
};


#endif //FIRSTDRAFT_MENU_H
