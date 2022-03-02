//
// Created by Rena on 5/27/21.
//

#include "Typer.h"
Typer::Typer(){
    menuBar.setUpDafault();

}

void Typer::addEventHandler(sf::RenderWindow& window, sf::Event event){
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect boxSize = box.getBoxGlobal();

    if(cursor.getCursorPosition().x > 527)
    {
        label.tooMuchletter();
    }
    if (event.type == sf::Event::TextEntered ||sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
        if (event.text.unicode == '\b') {   // handle backspace explicitly
            //history.pushHistory(snapshot);
            if(cursor.getCursorPosition().x>=47 && inputtext.getTextString().size()>0)
            {
                label.getNormal();
                inputtext.deleteStack();
                //snapshot.removeChar();

            }
        }
//        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
//        {
//            inputtext.updateReturn();
//            label.getNormal();
//        }
        else if(event.type == sf::Event::TextEntered)
        {
            if(cursor.getCursorPosition().x < 320)
            {
                //history.pushHistory(snapshot);
                ss = static_cast<char>(event.text.unicode);
                inputtext.setText(ss,sf::Color::White);
                sf::Vector2f temp = inputtext.lastCharacterPos();
                //snapshot.insertChar(static_cast<char>(event.text.unicode), key.KeyBoardColor(window,event), temp);
            }
        }
    }

    logoScreen.addEventHandler(window, event);
    menuBar.addEventHandler(window, event);

}

void Typer::setTextInput()
{
    box.setTextInput(inputtext);
    logoScreen.setLogo(100, sf::Color::Red, inputtext.getTextString(), {0,100});

}

void Typer::update(){
    inputtext.checker();
    cursor.update(sta);
    if(inputtext.getLinkedListSize() > 0){
        setTextInput();
            sf::Vector2f pos = inputtext.lastCharacterPos();
            cursor.updatePosition(pos);
    }
    menuBar.update();
    if(menuBar.determineSaveFile())
    {
        inputtext.setText(logoScreen.getString());
        logoScreen.setFileValue();
        logoScreen.setColorValue();
        menuBar.setFileFalse();
    }
    if(menuBar.determineSaveFileORNOFile())
    {
        setOutFile();
        menuBar.setNotOpenFile();
    }
}
void Typer::setOutFile()
{
    outfile.open("saveFileOne.txt");
    if(outfile.is_open())
    {
        outfile << inputtext.getTextString() << std::endl;
        for(int i = 0 ; i < 9; i++)
        {
            std::string temp = std::to_string(logoScreen.getSliderValueList().at(i));
            outfile << temp <<std::endl;
        }
        logoScreen.setColorValueForOutput();
        outfile << logoScreen.get11()<<std::endl;
        outfile << logoScreen.get21()<<std::endl;
        outfile << logoScreen.get12()<<std::endl;
        outfile << logoScreen.get22();
        outfile.close();
    }
}

void Typer::setFalse()
{
    menuBar.setFalse();
}

bool Typer::getFormatIndex()
{
    int a = menuBar.returnWindow();
    if (a == 0)
        return true;
    else
        return false;
}
bool Typer::getFormatIndexOpen()
{
    int a = menuBar.returnSmallWindow();
    if (a == 0)
        return true;
    else
        return false;
}


void Typer::draw(sf::RenderTarget& window, sf::RenderStates states) const{

    window.draw(label);
    window.draw(box);
    window.draw(inputtext);
    window.draw(logoScreen);
    window.draw(menuBar);

}
