//
// Created by Rena on 5/27/21.
//

#ifndef FIRSTDRAFT_TYPER_H
#define FIRSTDRAFT_TYPER_H
#include "TextInput.h"
#include "Label.h"
#include "Box.h"
#include "State.h"
#include "Cursor.h"
#include "TextInput.h"
#include "SetUpFormate.h"
#include "LogoScreen.h"
#include "MouseEvent.h"
class Typer : public sf::Drawable{
private:
    Label label;
    Box box;
    std::ofstream outfile;
    SetUpFormate menuBar;
    LogoScreen logoScreen;
    //KeyBoardEvent key;
    Cursor cursor;
    //History history;
    //Snapshot snapshot;
    TextInput inputtext;
    MouseEvents<sf::RectangleShape> mos;
    State sta;
    sf::String ss;


public:
    Typer();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setTextInput();
    bool getFormatIndex();
    bool getFormatIndexOpen();
    void setFalse();
    void setOutFile();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;


};



#endif //FIRSTDRAFT_TYPER_H
