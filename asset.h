//
// Created by Rena on 5/25/21.
//

#ifndef FIRSTDRAFT_ASSET_H
#define FIRSTDRAFT_ASSET_H


#include <SFML/Graphics.hpp>
enum Image
{
    FILE1,
    DIRECTORY
};
static std::map<Image, bool> loadImage;
static bool loadFont = false;
static sf::Font font;
static sf::Texture fileTexture;
static sf::Texture DirectoaryTexture;
class asset {
public:
    static sf::Font fontForS;
    static bool fontLoader;
};

#endif //FIRSTDRAFT_ASSET_H
