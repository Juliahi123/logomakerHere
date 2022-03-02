//
// Created by Rena on 6/4/21.
//

#ifndef FIRSTDRAFT_FONTBOX_H
#define FIRSTDRAFT_FONTBOX_H
# include <SFML/Graphics.hpp>
# include "asset.h"
#include <iostream>
class FontBox: public sf::Drawable {
private:
    std::vector<sf::RectangleShape> fontBoxMenu;
    std::vector<sf::Text> textMenu;
    std::string fontName;
    int show;
public:
    FontBox();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    std::string getMenuFileName();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //FIRSTDRAFT_FONTBOX_H
