//
// Created by Rena on 5/25/21.
//
#ifndef FIRSTDRAFT_MOUSEEVENT_CPP
#define FIRSTDRAFT_MOUSEEVENT_CPP

#include "MouseEvent.h"

template <class T>
int MouseEvents<T>::clicks;


template <class T>
bool MouseEvents<T>::mouseClicked(T& object, sf::RenderWindow& window){
    if( hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) ){
        return true;
    }else{
        return false;
    }
}

template <class T>
bool MouseEvents<T>::mouseClicked( sf::RenderWindow& window, sf::Event event){
    if( (event.type == event.MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Button::Left) ){
        return true;
    }else{
        return false;
    }
}

template <class T>
bool MouseEvents<T>::mouseDoubleClicked(){
    if(clicks == 2){
        return true;
    }
}

template <class T>
bool MouseEvents<T>::mouseTripleClicked(){
    return (clicks == 3);
}

template <class T>
bool MouseEvents<T>::draggedOver(T& object, sf::RenderWindow& window, sf::Event event){
    if(mouseClicked(object, window)){
        while( event.type != event.MouseButtonReleased ){
            if(event.type == event.MouseMoved){
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool MouseEvents<T>::hovered(T& object, sf::RenderWindow& window){
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    if( object.getGlobalBounds().contains(pos.x, pos.y) ){
        return true;
    }else{
        return false;
    }
}


template <class T>
void MouseEvents<T>::countClicks(sf::Event event){
    while(clock.getElapsedTime().asSeconds() <= 1){
        if( (event.type == event.MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Button::Left) ){
            clock.restart();
            ++clicks;
        }
    }

}
#endif