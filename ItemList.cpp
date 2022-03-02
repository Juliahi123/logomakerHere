//
// Created by Rena on 6/5/21.
//

#include "ItemList.h"
ItemList::ItemList(){
    show = false;
}
void ItemList::addItemToList(Item I)
{
    ItemLinkedList.push_back(I);
}
void ItemList::clear()
{
    ItemLinkedList.clear();
}

void ItemList::hightLight(int index)
{
    ItemLinkedList.at(index).hightLight();
}
void ItemList::unHighLight(int index)
{
    ItemLinkedList.at(index).unHighLight();
}

void ItemList::notVisual()
{
    for(int i = 0; i <ItemLinkedList.size(); i++)
    {
        ItemLinkedList.at(i).notVisual();
    }
}
std::vector<Item> ItemList::getItemList()
{
    return ItemLinkedList;
}

void ItemList::visual()
{
    for(int i = 0; i <ItemLinkedList.size(); i++)
    {
        ItemLinkedList.at(i).visual();
    }
}
int ItemList::getItemListPostionWithMpos(sf::Vector2f v)
{

    for(int i = 0; i < ItemLinkedList.size(); i++)
    {
        sf::FloatRect temp = ItemLinkedList.at(i).getGlobal();
        if(temp.contains(v))
        {
            return i;
        }
    }
    return -1;
}
void ItemList::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    if(ItemLinkedList.size() > 0)
    {
        for(int i = 0; i < ItemLinkedList.size(); i++)
        {
            window.draw(ItemLinkedList.at(i));
        }
    }

}