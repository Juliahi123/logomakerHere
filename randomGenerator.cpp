//
// Created by Rena on 6/5/21.
//

#include "randomGenerator.h"
randomGenerator::randomGenerator()
{

}
void randomGenerator::setRandomValue()
{
    srand(time(0));

    if(!numberList.empty())
        numberList.clear();
    textOpacity = abs((rand() % 220) + 42);
    fontSize = abs(51 + (rand() % 100));
    skew = abs(3 + rand()%130);
    showOpacity = abs(41 + rand() % 250);
    while (showOpacity > textOpacity)
    {
        showOpacity = abs(41 + rand() % 250);
    }
    backGroundOpacity = abs(rand() % 250);
    textPosx = abs(rand() % 699);
    textPosy = abs(rand() % 266);
    showPosx = abs(rand() % 699);
    showPosy = abs(102 + rand()% 402);
    rgbOneIndex = rand()%5;
    rgbOnePos = rand()%255;
    rgbTwoIndex = rand()%5;
    rgbTwoPos = rand()%255;

    numberList.push_back(textOpacity);
    numberList.push_back(fontSize);
    numberList.push_back(skew);
    numberList.push_back(showOpacity);
    numberList.push_back(backGroundOpacity);
    numberList.push_back(textPosx);
    numberList.push_back(textPosy);
    numberList.push_back(showPosx);
    numberList.push_back(showPosy);
    numberList.push_back(rgbOneIndex);
    numberList.push_back(rgbOnePos);
    numberList.push_back(rgbTwoIndex);
    numberList.push_back(rgbTwoPos);

}
std::vector<int> randomGenerator::getNumberList()
{
    setRandomValue();
    for(int i =0 ; i < numberList.size(); i++)
    {
        std::cout << "num: " << numberList.at(i) << std::endl;
    }
    return numberList;
}
int randomGenerator::getInt()
{
    return textOpacity;
}



void randomGenerator::setFileValue()
{
    numberList1.clear();
    s.setFile();
    for(int i =0; i < 9; i++)
    {
        numberList1.push_back(s.getFileList().at(i));
    }
}
std::vector<int> randomGenerator::getNumberList1()
{
    for(int i =0 ; i < numberList1.size(); i++)
    {
        std::cout << "num1: " << numberList1.at(i) << std::endl;
    }
    return numberList1;
}

