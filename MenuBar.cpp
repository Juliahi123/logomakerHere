//
// Created by Rena on 6/5/21.
//

#include "MenuBar.h"
MenuBar::MenuBar(){}
void MenuBar::setMenuBar()
{
    float x  = 0 ;
    float y = 0 ;
    if(MenuBarVector.size() > 0 )
    {
        for(int i = 0; i < MenuBarVector.size(); i++)
        {
            MenuBarVector.at(i).setPosition({x,y});
            x += 150;
        }
    }
}
void MenuBar::addMenuToMenuBar(Menu m)
{
    MenuBarVector.push_back(m);
}
int MenuBar::getMenuPress(sf::Vector2f pos)
{
    for(int i = 0; i < MenuBarVector.size(); i++)
    {
        sf::FloatRect temp = MenuBarVector.at(i).getGlobal();
        if(temp.contains(pos))
        {
            return i;
        }
    }
    return -1;
}
void MenuBar::showListAt(int index)
{
    menuItemList.at(index).visual();
}
void MenuBar::notshowListAt(int index)
{
    menuItemList.at(index).notVisual();

}
int MenuBar::getMenuBarVectorLength()
{
    return MenuBarVector.size();
}
void MenuBar::hightLight(int index, int appl)
{
    if(index != -1)
    {
        if(appl != -1)
            menuItemList.at(index).hightLight(appl);
    }
}
int MenuBar::findHightLightIndexAtList(int index, sf::Vector2f mpos)
{
    return menuItemList.at(index).getItemListPostionWithMpos(mpos);
}
void MenuBar::UnhightLight(int index, int appl)
{
    if(index != -1)
    {
        if(appl != -1)
            for(int i =0; i< menuItemList.at(index).getItemList().size(); i++)
            {
                if(i != appl)
                    menuItemList.at(index).unHighLight(i);

            }
    }
    if(index == -1)
    {
        for(int i =0 ; i < menuItemList.size(); i++)
        {
            for(int j =0; j< menuItemList.at(i).getItemList().size(); j++)
            {
                menuItemList.at(i).unHighLight(j);

            }
        }

    }
}
void MenuBar::hightLightMenu(int index)
{
    if(index != -1)
        MenuBarVector.at(index).highLightMenu();
}
void MenuBar::noHightLightMenu(int index)
{
    if(index != -1)
    {
        for(int i = 0; i < MenuBarVector.size(); i++)
        {
            if(i != index)
            {
                MenuBarVector.at(i).NoHightLightMenu();
            }
        }
    }
    else
    {
        for(int i = 0; i < MenuBarVector.size(); i++)
        {
            MenuBarVector.at(i).NoHightLightMenu();
        }
    }

}

int MenuBar::getListPosition(sf::Vector2f pos)
{
    return 1;
}
Menu MenuBar::getMenuAt(int index)
{
    return MenuBarVector.at(index);
}
ItemList MenuBar::getItemListFromVector(int index) const
{
    return menuItemList.at(index);
}

void MenuBar::addMenuItemList(ItemList itemList)
{
    menuItemList.push_back(itemList);
}
int MenuBar::getMenuItemListSize() const
{
    return menuItemList.size();
}

void MenuBar::setUpDefaultMenuBar()
{
    float xx = 0;
     std::string temp = "File";
        menu.createMenu(temp, {xx,0});
        xx+=150;
        addMenuToMenuBar(menu);
    temp = "Edit";
    menu.createMenu(temp, {xx,0});
    xx+=150;
    addMenuToMenuBar(menu);
    temp = "Window";
    menu.createMenu(temp, {xx,0});
    addMenuToMenuBar(menu);
    setMenuBar();
}
void MenuBar::updateFunction(int index, int appl)
{
    if(index != -1)
    {
        if(appl != -1) {
            if(index == 0 && appl ==0)
            {
                std::cout << "sdefrffefefe"<< std::endl;
            }
        }
        if(index == 2&& appl ==0)
        {
            noHightLightMenu(2);
        }
    }
}

int MenuBar::getMenuVectorSize()
{
    return MenuBarVector.size();
}

std::vector<Menu> MenuBar::getMenuList() const
{
    return MenuBarVector;
}

void MenuBar::draw(sf::RenderTarget& window,  sf::RenderStates states) const
{
    for(int i = 0; i < MenuBarVector.size(); i++)
    {
        window.draw(MenuBarVector.at(i));
    }
}
