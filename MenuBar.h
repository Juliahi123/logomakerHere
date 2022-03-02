//
// Created by Rena on 6/5/21.
//

#ifndef FIRSTDRAFT_MENUBAR_H
#define FIRSTDRAFT_MENUBAR_H

# include "Menu.h"
# include "ItemList.h"
# include <iostream>
class MenuBar: public sf::Drawable {
private:
    std::vector<ItemList> menuItemList;
    Menu menu;
    std::vector<Menu> MenuBarVector;
public:
    MenuBar();
    int getListPosition(sf::Vector2f pos);
    int getMenuItemListSize() const;
    ItemList getItemListFromVector(int index) const;
    int getMenuBarVectorLength();
    int findHightLightIndexAtList(int index, sf::Vector2f mpos);
    void hightLight(int index, int appl);
    void hightLightMenu(int index);
    void noHightLightMenu(int index);
    void UnhightLight(int index, int appl);
    void updateFunction(int index, int appl);
    void addMenuItemList(ItemList itemList);
    void setMenuBar();
    int getMenuPress(sf::Vector2f pos);
    void showListAt(int index);
    int getMenuVectorSize();
    Menu getMenuAt(int index);
    void notshowListAt(int index);
    void addMenuToMenuBar(Menu m);
    void setUpDefaultMenuBar();
    void draw(sf::RenderTarget& window,  sf::RenderStates states) const;
    std::vector <Menu> getMenuList() const;
};



#endif //FIRSTDRAFT_MENUBAR_H
