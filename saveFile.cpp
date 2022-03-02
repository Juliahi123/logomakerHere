//
// Created by Rena on 6/6/21.
//

#include "saveFile.h"
saveFile::saveFile()
{

}
void saveFile::setFile()
{
    std::string temp;
    infile.open("saveFileOne.txt");
    if(infile.is_open()){
        while(!infile.eof()){
            getline(infile,temp);
            std::cout<< temp << std::endl;
            numberList.push_back(temp);
        }
        infile.close();
    }
    textInput = numberList.at(0);
    for(int i = 0; i < numberList.size(); i++)
    {
        std::cout << i << ".  " << numberList.at(i) << std::endl;
    }
    if(!numberList.empty())
    {
        for(int i = 1; i < numberList.size(); i++) {
                    int temp = std::stoi(numberList.at(i));
                    finalNumberList.push_back(temp);
                }
            while(finalNumberList.size() < 13)
            {
                finalNumberList.push_back(0);
            }
    }

    numberList.clear();
}
std::string saveFile::getText()
{
    return textInput;
}

std::vector<int> saveFile::getFileList()
{
    for(int i = 0; i < finalNumberList.size(); i++)
    {
        std::cout << "final:  i:    " << i <<"       " << finalNumberList.at(i) << std::endl;
    }
   return finalNumberList;
}
//void saveFile::setOutFile()
//{
//    outfile.open("saveFileOne.txt");
//    if(outfile.is_open())
//    {
//        for(int i = 0 ; i < slider.getSliderList().size(); i++)
//        {
//            outfile << slider.getSliderList().at(i).getSliderValue <<std::endl;
//        }
//        outfile.close();
//    }
//}
