//
// Created by Rena on 6/8/21.
//

#include "FileItem.h"

FileItem::FileItem()
        : FileItem(FILE1, "File 1", {200,30}, {0,0}){
    icon.setScale(0.03,0.03);
}


FileItem::FileItem(Image icon, std::string text, sf::Vector2f size, sf::Vector2f position){
    // loading textures
    if(!loadImage[icon]){
        if(icon == FILE1)
            fileTexture.loadFromFile("file.png");
        else if(icon == DIRECTORY)
            DirectoaryTexture.loadFromFile("folder.png");
        loadImage[icon] = true;
    }
    if(!loadFont){
        if(!font.loadFromFile("arial.ttf")){
            std::cout << "Failed to load font\n";
        }
        loadFont = true;
    }
    this->icon.setScale(0.03, 0.03);

    // set outer box
    box.setSize(size);
    box.setFillColor(sf::Color::Transparent);

    // set icon
    if(icon == FILE1)
        this->icon.setTexture(fileTexture);
    else if(icon == DIRECTORY)
        this->icon.setTexture(DirectoaryTexture);

    // set text
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(20);

    // set position
    setPosition(position);


}


void FileItem::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(box);
    window.draw(text);
    window.draw(icon);
}


void FileItem::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(MouseEvents<sf::RectangleShape>::mouseClicked(window, event)){

        if(MouseEvents<sf::RectangleShape>::hovered(box, window)){
            if(box.getFillColor() == sf::Color::Blue)
                box.setFillColor(sf::Color::Transparent);
            else if(box.getFillColor() == sf::Color::Transparent)
                box.setFillColor(sf::Color::Blue);
        }
        else{
            box.setFillColor(sf::Color::Transparent);
        }
    sf::FloatRect temp = box.getGlobalBounds();
        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    }
}


sf::FloatRect FileItem::getGlobalBounds() const{
    return box.getGlobalBounds();
}

sf::Vector2f FileItem::getSize() const{
    return box.getSize();
}


sf::Vector2f FileItem::getPosition() const{
    return box.getPosition();
}


void FileItem::setPosition(sf::Vector2f pos){

    int length = this->icon.getGlobalBounds().width + padding;
    length += this->text.getGlobalBounds().width;

    this->box.setPosition(pos);

    if(text.getString().find("File") != std::string::npos){
        this->icon.setPosition(box.getPosition().x + box.getGlobalBounds().width/3 - length/2 + 5,
                               box.getPosition().y + box.getGlobalBounds().height/2 - this->icon.getGlobalBounds().height/2);

        this->text.setPosition(box.getPosition().x + box.getGlobalBounds().width/3 - length/2 + this->icon.getGlobalBounds().width + padding + 5,
                               box.getPosition().y + box.getGlobalBounds().height/2 - this->text.getGlobalBounds().height/1.5);

    }else{
        this->icon.setPosition(box.getPosition().x + box.getGlobalBounds().width/2 - length/2,
                               box.getPosition().y + box.getGlobalBounds().height/2 - this->icon.getGlobalBounds().height/2);

        this->text.setPosition(box.getPosition().x + box.getGlobalBounds().width/2 - length/2 + this->icon.getGlobalBounds().width + padding,
                               box.getPosition().y + box.getGlobalBounds().height/2 - this->text.getGlobalBounds().height/1.5);
    }
}


void FileItem::setIcon(Image icon){
//    if(!loadImage[icon]){
//        if(icon == FILE1)
//            fileTexture.loadFromFile("file.png");
//        else if(icon == DIRECTORY)
//            DirectoaryTexture.loadFromFile("folder.png");
//        loadImage[icon] = true;
//    }
//    else{
//        if(icon == FILE1)
//            this->icon.setTexture(fileTexture);
//        else if(icon == DIRECTORY)
//            this->icon.setTexture(DirectoaryTexture);
//    }
}

sf::Color FileItem::getFillColor() const{
    return box.getFillColor();
}
