//
// Created by Rena on 6/5/21.
//

#ifndef FIRSTDRAFT_SETUPFORMATE_H
#define FIRSTDRAFT_SETUPFORMATE_H

# include "MenuBar.h"
# include "ItemList.h"
#include "FileTree.h"
class SetUpFormate: public sf::Drawable {
private:
    MenuBar menuBar;
    int determine;
    ItemList itemList;
    int windowIndex;
    int hightLightIndex;
    bool fileTrue;
    bool saveFileOrNo;
    int smallWindow;
    int hightLightMenuIndex;
    Menu smallMenu;
public:
    SetUpFormate();
    void setUpDafault();
    void setFalse();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    bool determineSaveFile();
    void setFileFalse();
    bool determineSaveFileORNOFile();
    void setNotOpenFile();
    int returnWindow();
    int returnSmallWindow();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //FIRSTDRAFT_SETUPFORMATE_H
