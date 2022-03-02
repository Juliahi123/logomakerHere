//
// Created by Rena on 6/8/21.
//

#include "FileTree.h"

FileTree::FileTree(){}


void FileTree::push(std::string parent, std::string item){
    push(root, parent, item);
}


void FileTree::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    if(root){
        window.draw(*root);
    }
}


void FileTree::addEventHandler(sf::RenderWindow& window, sf::Event event){
    root->addEventHandler(window, event);
}


void FileTree::update(){
    int y = root->getGlobalBounds().top + root->getGlobalBounds().height;
    for(std::map<std::string, FileNode*>::iterator it = root->begin();
        it != root->end(); ++it)
    {
        it->second->setPosition(it->second->getPosition().x + 50, y);
        if(it->second->isClicked()){
            y += it->second->getChildren().size() * it->second->getGlobalBounds().height;
        }
        y += it->second->getGlobalBounds().height;
    }
}


sf::FloatRect FileTree::getGlobalBounds(){
    return root->getGlobalBounds();
}


void FileTree::push(FileNode*& root, std::string parent, std::string item){
    // default: item == "NULL"
    if(!root){
        if(parent.find("Folder") != std::string::npos)
            root = new FileNode(DIRECTORY, parent, {200,30}, initPosition);
        else if(parent.find("txt") != std::string::npos)
            root = new FileNode(FILE1, parent, {200,30}, initPosition);
        return;
    }

    if(item == "NULL"){
        root->addChild(DIRECTORY, parent);
        return;
    }

    if(root->getChildren().empty() && parent == root->getLabel()){
        if(item.find("Folder") != std::string::npos)
            root->addChild(DIRECTORY, item);
        else if(item.find("txt") != std::string::npos)
            root->addChild(FILE1, item);
    }
    else{
        for(std::map<std::string, FileNode*>::iterator it = root->begin();
            it != root->end(); ++it)
        {
            if(it->first == parent){
                if(item.find("Folder") != std::string::npos)
                    it->second->addChild(DIRECTORY, item);
                else if(item.find("txt") != std::string::npos)
                    it->second->addChild(FILE1, item);
                return;
            }
            else if(!it->second->isLeaf()){
                push(it->second, parent, item);
            }
        }
    }



}


void FileTree::traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event){

}
