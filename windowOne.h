//
// Created by Rena on 6/5/21.
//

#ifndef FIRSTDRAFT_WINDOWONE_H
#define FIRSTDRAFT_WINDOWONE_H

# include <SFML/Graphics.hpp>
#include "Typer.h"
#include "FileTree.h"
class windowOne {
private:
    int size;
    Typer t;
    sf::RenderWindow w;
public:
    windowOne();
    void draw();
    void openSmallWindow();
    void close();
    void setOpenFile();
}
;

#endif //FIRSTDRAFT_WINDOWONE_H
