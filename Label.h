//
// Created by Rena on 5/27/21.
//

#ifndef FIRSTDRAFT_LABEL_H
#define FIRSTDRAFT_LABEL_H

#include <iostream>
#include <SFML/Graphics.hpp>
class Label: public sf::Drawable{
public:
    Label();
    void setLabelPosition(sf::Vector2f pos);
    void setLabel(std::string a);
    void setLabelSize(int size);
    void tooMuchletter();
    void getNormal();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
private:
    std::string l;
    sf::Text text;
    sf::Text text1;
    sf::Font font;
    int size;

};


#endif //FIRSTDRAFT_LABEL_H
