//
// Created by Rena on 6/5/21.
//

#ifndef FIRSTDRAFT_RANDOMGENERATOR_H
#define FIRSTDRAFT_RANDOMGENERATOR_H
# include <random>
# include <iostream>
#include "saveFile.h"
class randomGenerator {
private:
    saveFile s;
    int textOpacity;
    int fontSize;
    int skew;
    int showOpacity;
    int backGroundOpacity;
    int textPosx;
    int textPosy;
    int showPosx;
    int showPosy;
    int rgbOneIndex;
    int rgbOnePos;
    int rgbTwoIndex;
    int rgbTwoPos;
    std::vector<int> numberList;
    std::vector<int> numberList1;

public:
    randomGenerator();
    void setRandomValue();
    int getInt();
    void setFileValue();
    std::vector<int> getNumberList();
    std::vector<int> getNumberList1();


};


#endif //FIRSTDRAFT_RANDOMGENERATOR_H
