//
// Created by Rena on 6/5/21.
//

#include "SetUpFormate.h"
SetUpFormate::SetUpFormate()
{
    determine = -1;
    hightLightIndex = -1;
    hightLightMenuIndex = -1;
    windowIndex = -1;
    fileTrue = false;
    saveFileOrNo = false;
    smallWindow = -1;
}
void SetUpFormate::setFileFalse()
{
    fileTrue =false;
}

void SetUpFormate::setUpDafault()
{
    Item temp ;
    float x = 0;
    float y = 30;
    std::string tempString;
    menuBar.setUpDefaultMenuBar();
    if(menuBar.getMenuVectorSize() > 0)
    {
        tempString = "New Project";
        temp.createItem(tempString, {x, y}, {150, 30});
        itemList.addItemToList(temp);
        y+=30;
        tempString = "Open Project";
        temp.createItem(tempString, {x, y}, {150, 30});
        itemList.addItemToList(temp);
        y+=30;
        tempString = "Save Project";
        temp.createItem(tempString, {x, y}, {150, 30});
        itemList.addItemToList(temp);
        y+=30;
        tempString = "Close Project";
        temp.createItem(tempString, {x, y}, {150, 30});
        itemList.addItemToList(temp);
        y+=30;
        tempString = "Quit";
        temp.createItem(tempString, {x, y}, {150, 30});
        itemList.addItemToList(temp);
        menuBar.addMenuItemList(itemList);
        itemList.clear();

        y = 30;
        x+=150;

        tempString = "Redo";
        temp.createItem(tempString, {x, y}, {150, 30});
        itemList.addItemToList(temp);
        y+=30;
        tempString = "Undo";
        temp.createItem(tempString, {x, y}, {150, 30});
        itemList.addItemToList(temp);
        menuBar.addMenuItemList(itemList);
        itemList.clear();
        y = 30;
        x+=150;
        tempString = "Export";
        temp.createItem(tempString, {x, y}, {150, 30});
        itemList.addItemToList(temp);
        menuBar.addMenuItemList(itemList);
        itemList.clear();
    }

}
void SetUpFormate::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(menuBar);
    for(int i = 0; i < menuBar.getMenuItemListSize(); i++)
    {
        window.draw(menuBar.getItemListFromVector(i));
    }
}
bool SetUpFormate::determineSaveFile()
{
    return fileTrue;
}

void SetUpFormate::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    int menuClickIndex = menuBar.getMenuPress(mpos);
    if(menuClickIndex != -1)
        hightLightMenuIndex = menuClickIndex;
    else
        hightLightMenuIndex = determine;
    if(determine != -1 )
    {
        hightLightIndex = menuBar.findHightLightIndexAtList(determine, mpos);
        for(int i = 0; i< menuBar.getMenuItemListSize(); i++)
        {
            if(i != determine)
                menuBar.getItemListFromVector(i).notVisual();
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            menuBar.updateFunction(determine, hightLightIndex);
            if(determine ==0 && hightLightIndex == 0)
            {
                windowIndex = 0;
            }
            if(determine ==0 && hightLightIndex == 1)
            {
                smallWindow = 0;
                //fileTrue = true;
            }
            if(determine ==0 && hightLightIndex == 2)
            {
                saveFileOrNo = true;
            }
            if(determine ==0 && hightLightIndex == 3)
            {
                window.close();
            }
            if(determine == 2 && hightLightIndex == 0)
            {
                sf::Texture texture;
                sf::Image imageTemp;
                sf::Image image;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                imageTemp = texture.copyToImage();
                image.create(1000, 360, sf::Color::Transparent);
                image.copy(imageTemp, 0,0, sf::IntRect(50,60,1000,360), false);
                if(image.saveToFile("empty.png"))
                    std::cout << "successsss!!!!!" ;
            }
            if(determine == 0 && hightLightIndex ==4)
                window.close();
        }
    }
    if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left) {
            determine = menuClickIndex;
        }
    }
}
void SetUpFormate::setFalse()
{
    windowIndex = -1;
}
bool SetUpFormate::determineSaveFileORNOFile()
{
    return saveFileOrNo;
}
void SetUpFormate::setNotOpenFile()
{
    saveFileOrNo = false;
}

int SetUpFormate::returnWindow()
{
    return windowIndex;
}
int SetUpFormate::returnSmallWindow()
{
    return smallWindow;
}

void SetUpFormate::update() {
    if(smallWindow == 0) {
        smallMenu.createMenu("justSave.txt", {0,0});
        sf::RenderWindow openProject;
        openProject.create({400, 200}, "Open Project");
        openProject.setPosition({500, 200});
        openProject.setFramerateLimit(120);
        while (openProject.isOpen()) {
            sf::Event event;
            while (openProject.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    openProject.close();
                }
                sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(openProject);
                if(smallMenu.getGlobal().contains(mpos))
                {
                    smallMenu.highLightMenu();
                    if(event.type == sf::Event::MouseButtonPressed)
                    {
                        fileTrue = true;
                        smallWindow = -1;
                        openProject.close();
                    }
                }
            }
            openProject.clear(sf::Color::Black);
            openProject.draw(smallMenu);
            openProject.display();

        }
    }
    menuBar.hightLightMenu(hightLightMenuIndex);
    menuBar.noHightLightMenu(hightLightMenuIndex);
    if (determine != -1) {
        menuBar.showListAt(determine);
        for (int i = 0; i < menuBar.getMenuVectorSize(); i++) {
            if (i != determine)
                menuBar.notshowListAt(i);
        }
        menuBar.hightLight(determine, hightLightIndex);
        menuBar.UnhightLight(determine, hightLightIndex);
    }
    else {
        for (int i = 0; i < menuBar.getMenuVectorSize(); i++)
            menuBar.notshowListAt(i);
        menuBar.UnhightLight(determine, hightLightIndex);

    }
}