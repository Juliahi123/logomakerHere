//
// Created by Rena on 5/27/21.
//

#ifndef FIRSTDRAFT_TEXTINPUT_H
#define FIRSTDRAFT_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>
#include <iostream>
//#include "Snapshot.h"
//#include "History.h"
#include <vector>
//#include "saveFile.h"
#include "LinkedList.h"
class TextInput:public sf::Drawable{
private:
    sf::Text text;
    sf::Font font;
    //Snapshot snapshot;
    LinkedList<sf::Text> t;
    //History history;
    float x;
    float yy;


public:
    TextInput();
    void setText(sf::String s, sf::Color color);
    void setText(std::string s);
    void setText(sf::String s);
    std::string getTextString();
    void setTextPosition(sf::Vector2f pos);
    sf::Vector2f getTextPosition(int index);
    void deleteStack();
    void setTextByFile();
    void checker();
    void updateReturn();
    int getLinkedListSize();
    //History popHistoryfromText();
    //void resetStringwithSnapShot(Snapshot& s);
    //std::vector<char> UndoChecker(History& history);
    //std::vector<sf::Color> UndoCheckerColor(History& history);
    //std::vector<sf::Vector2f> UndoCheckerPos(History& history);

    sf::Vector2f lastCharacterPos();
    void addColorText(sf::String s, sf::Color color);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};




#endif //FIRSTDRAFT_TEXTINPUT_H
