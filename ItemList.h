//
// Created by Rena on 6/5/21.
//

#ifndef FIRSTDRAFT_ITEMLIST_H
#define FIRSTDRAFT_ITEMLIST_H

#include <iostream>
#include "Item.h"
class ItemList:public sf::Drawable {
private:
    bool show;
    std::vector<Item> ItemLinkedList;
public:
    ItemList();
    int getItemListPostionWithMpos(sf::Vector2f mpos);
    void addItemToList(Item I);
    void notVisual();
    void visual();
    std::vector<Item> getItemList();
    void clear();
    void unHighLight(int index);
    void hightLight(int index);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //FIRSTDRAFT_ITEMLIST_H
