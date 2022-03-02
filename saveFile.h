//
// Created by Rena on 6/6/21.
//

#ifndef FIRSTDRAFT_SAVEFILE_H
#define FIRSTDRAFT_SAVEFILE_H

#include <iostream>
#include <fstream>
#include <vector>
class saveFile {
private:
    std::ifstream infile;
    std::vector<std::string> numberList;
    std::vector<int> finalNumberList;

    std::string textInput;
public:
    saveFile();
    void setFile();
    std::string getText();
    std::vector<int> getFileList();


};


#endif //FIRSTDRAFT_SAVEFILE_H
