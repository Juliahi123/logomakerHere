//
// Created by Rena on 5/31/21.
//

#include "ColorPicker.h"
ColorPicker::ColorPicker()
{
    showRect = 0;
    showRect2 = 0;
    showBigColor = 0;
    pixels.resize(255*255);
    rectColor.setSize({40, 40});
    rectColor.setPosition({380,425});
    rectColor.setFillColor(sf::Color::Red);
    rectColor2.setSize({40, 40});
    rectColor2.setPosition({720,425});
    rectColor2.setFillColor(sf::Color::Red);
    backRect.setSize({140, 110});
    backRect.setPosition({374,470});
    backRect.setFillColor(sf::Color::White);

    rectColorForIndex = 0;
    rectColorSecondIndex = 0;
    rectBackColorForIndex = 0;
    rectBackColorSecondIndex= 0;

    float x = 380;
    float y = 480;
    for (int i = 0; i < 6; i++) {
        sf::RectangleShape temp;
        if(i == 3)
        {
            x = 380;
            y+=42;
        }
        temp.setSize({40, 40});
        temp.setPosition({x, y});
        x += 44;
        temp.setFillColor(sf::Color::Red);
        temp.setOutlineColor(sf::Color::Black);
        temp.setOutlineThickness(1);
        rectColorList.push_back(temp);
    }
    rectColorList.at(0).setFillColor(sf::Color::Blue);
    rectColorList.at(1).setFillColor(sf::Color::Yellow);
    rectColorList.at(2).setFillColor(sf::Color::Green);
    rectColorList.at(3).setFillColor(sf::Color::White);
    rectColorList.at(4).setFillColor(sf::Color::Magenta);
    rectColorList.at(5).setFillColor(sf::Color::Red);


    backRect2.setSize({140, 110});
    backRect2.setPosition({714,470});
    backRect2.setFillColor(sf::Color::White);

    float xx = 720;
    float yy = 480;
    for (int i = 0; i < 6; i++) {
        sf::RectangleShape temp;
        if(i == 3)
        {
            xx = 720;
            yy+=42;
        }
        temp.setSize({40, 40});
        temp.setPosition({xx, yy});
        xx += 44;
        temp.setFillColor(sf::Color::Blue);
        temp.setOutlineColor(sf::Color::Black);
        temp.setOutlineThickness(1);
        rectColorList2.push_back(temp);
    }
    rectColorList2.at(0).setFillColor(sf::Color::Blue);
    rectColorList2.at(1).setFillColor(sf::Color::Yellow);
    rectColorList2.at(2).setFillColor(sf::Color::Green);
    rectColorList2.at(3).setFillColor(sf::Color::White);
    rectColorList2.at(4).setFillColor(sf::Color::Magenta);
    rectColorList2.at(5).setFillColor(sf::Color::Red);

}
void ColorPicker::update(sf::Color color, sf::Vector2f pos)
{
    setColorPicker(color, pos);
}
sf::Color ColorPicker::returnTextColorPicker()
{
    return rectColor.getFillColor();
}
sf::Color ColorPicker::returnBackGroundColorPicker()
{
    return rectColor2.getFillColor();
}
void ColorPicker::setBackgroundColorByValue(int a, int b)
{
    getColorString(a);
    std::cout << "Pixel size is: " << pixels.size() << std::endl;
    rectColor2.setFillColor(pixels.at(b).getFillColor());
}

void ColorPicker::setColorByValue(int a, int b)
{
    getColorString(a);
    rectColor.setFillColor(pixels.at(b).getFillColor());
}
void ColorPicker::getColorString(int index)
{
    switch (index) {
        case 0:
        {
            setColorPicker(sf::Color::Red, { 0, 1000});
            break;
        }
        case 1:
        {
            setColorPicker(sf::Color::Green, { 0, 1000});
            break;
        }
        case 2:
        {
            setColorPicker(sf::Color::Yellow, { 0, 1000});
            break;
        }
        case 3:
        {
            setColorPicker(sf::Color::White, { 0, 1000});
            break;
        }
        case 4:
        {
            setColorPicker(sf::Color::Magenta, { 0, 1000});
            break;
        }
        case 5:
        {
            setColorPicker(sf::Color::Blue, { 0, 1000});
            break;
        }
    }
}

void ColorPicker::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect backRectSize = rectColor.getGlobalBounds();
    sf::FloatRect backRectSize2 = rectColor2.getGlobalBounds();

    sf::FloatRect backRectSizeList00 = rectColorList2.at(0).getGlobalBounds();
    sf::FloatRect backRectSizeList11 = rectColorList2.at(1).getGlobalBounds();
    sf::FloatRect backRectSizeList22 = rectColorList2.at(2).getGlobalBounds();
    sf::FloatRect backRectSizeList33 = rectColorList2.at(3).getGlobalBounds();
    sf::FloatRect backRectSizeList44 = rectColorList2.at(4).getGlobalBounds();
    sf::FloatRect backRectSizeList55 = rectColorList2.at(5).getGlobalBounds();

    sf::FloatRect backRectSizeList0 = rectColorList.at(0).getGlobalBounds();
    sf::FloatRect backRectSizeList1 = rectColorList.at(1).getGlobalBounds();
    sf::FloatRect backRectSizeList2 = rectColorList.at(2).getGlobalBounds();
    sf::FloatRect backRectSizeList3 = rectColorList.at(3).getGlobalBounds();
    sf::FloatRect backRectSizeList4 = rectColorList.at(4).getGlobalBounds();
    sf::FloatRect backRectSizeList5 = rectColorList.at(5).getGlobalBounds();

    if (showBigColor != 0) {
        if (event.type == sf::Event::MouseButtonPressed)
        {
            for (int i = 0; i < pixels.size(); i++) {
                if (pixels.at(i).getPosition() == mpos) {
                    if(pixels.at(i).getPosition().x >= 718)
                    {
                        rectColor2.setFillColor(pixels.at(i).getFillColor());

                    }
                    else
                    {
                        rectColor.setFillColor(pixels.at(i).getFillColor());
                    }
                }
            }
        }

    }

    if (event.type == sf::Event::MouseButtonPressed) {
            if(backRectSize2.contains(mpos))
            {
                showRect2 = 1;
                std::cout << "2";
            }
            else if(backRectSize.contains(mpos))
            {
                showRect = 1;
                std::cout << "1";
            }
            else if(showRect != 0)
            {
                if(backRectSizeList0.contains(mpos))
                {
                    update(sf::Color::Blue, {380, 465});
                    showBigColor = 1;
                    showRect = 0;
                    std::cout << "1";
                }
                else if(backRectSizeList1.contains(mpos))
                {
                    showRect = 0;
                    update(sf::Color::Yellow, {380, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }
                else if(backRectSizeList2.contains(mpos))
                {
                    showRect = 0;
                    update(sf::Color::Green, {380, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }
                else if(backRectSizeList3.contains(mpos))
                {
                    showRect = 0;
                    update(sf::Color::White, {380, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }
                else if(backRectSizeList4.contains(mpos))
                {
                    showRect = 0;
                    update(sf::Color::Magenta, {380, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }
                else if(backRectSizeList5.contains(mpos))
                {
                    showRect = 0;
                    update(sf::Color::Red, {380, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }

            }
            else if(showRect2 != 0)
            {
                if(backRectSizeList00.contains(mpos))
                {
                    update(sf::Color::Blue, {720, 465});
                    showBigColor = 1;
                    showRect2 = 0;
                    std::cout << "1";
                }
                else if(backRectSizeList11.contains(mpos))
                {
                    showRect2 = 0;
                    update(sf::Color::Yellow, {720, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }
                else if(backRectSizeList22.contains(mpos))
                {
                    showRect2 = 0;
                    update(sf::Color::Green, {720, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }
                else if(backRectSizeList33.contains(mpos))
                {
                    showRect2 = 0;
                    update(sf::Color::White, {720, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }
                else if(backRectSizeList44.contains(mpos))
                {
                    showRect2 = 0;
                    update(sf::Color::Magenta, {720, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }
                else if(backRectSizeList55.contains(mpos))
                {
                    showRect2 = 0;
                    update(sf::Color::Red, {720, 465});
                    showBigColor = 1;
                    std::cout << "1";
                }
            }
            else
            {
                showRect = 0;
                showRect2 = 0;
                showBigColor = 0;
            }
    }
}

void ColorPicker::setColorValueForOutput()
{
    for(int i =0; i < pixels.size(); i++)
    {
        if(rectColor.getFillColor() == pixels.at(i).getFillColor())
        {
            std::cout <<"pixels value " << i << "     ";
            rectColorSecondIndex = i;
            break;
        }

    }
    for(int i =0; i < pixels.size(); i++)
    {
        if (rectColor2.getFillColor() == pixels.at(i).getFillColor())
        {
            std::cout <<"pixels value " << i << "     ";
            rectBackColorSecondIndex = i;
            break;
        }
    }
}

void ColorPicker::setRectColor(sf::Color color, sf::RectangleShape rect)
{
    rect.setFillColor(color);
    std::cout <<"setRectColor: " << rect.getFillColor().toInteger()<<std::endl;
}

void ColorPicker::setForBackGroundColorPicker()
{
}
int ColorPicker::get11()
{
    return rectColorForIndex;
}
int ColorPicker::get12()
{
    return rectBackColorForIndex;

}
int ColorPicker::get21()
{
    return rectColorSecondIndex;

}
int ColorPicker::get22()
{
    return rectBackColorSecondIndex;
}
sf::VertexArray ColorPicker::getColor()
{
    return color;
}

void ColorPicker::setColorPicker(sf::Color color1, sf::Vector2f pos)
{
    int j, red, gb;
    for (int i = 0; i < pixels.size(); i++) {
        pixels[i] = sf::RectangleShape(sf::Vector2f(1, 1));
        if (i != 0) {
            j = i / 255;
            red = 255 - j;
            gb = i - (255 * j) - j;

            if (gb > red)
            {
                gb -= j;
            }
            else if (gb < 0)
            {
                gb = 0;
            }
            if(color1 == sf::Color::Blue)
            {
                pixels[i].setFillColor(sf::Color(gb, gb, red));
                rectColorForIndex = 5;
                rectBackColorForIndex = 5;
            }
            else if (color1 == sf::Color::Red)
            {
                pixels[i].setFillColor(sf::Color(red, gb, gb));
                rectColorForIndex = 0;
                rectBackColorForIndex = 0;
            }
            else if (color1 == sf::Color::Green)
            {
                pixels[i].setFillColor(sf::Color(gb, red, gb));
                rectColorForIndex = 1;
                rectBackColorForIndex = 1;
            }
            else if (color1 == sf::Color::Yellow)
            {
                pixels[i].setFillColor(sf::Color(red, red, gb));
                rectColorForIndex = 2;
                rectBackColorForIndex = 2;
            }
            else if (color1 == sf::Color::Black)
            {
                pixels[i].setFillColor(sf::Color(gb, gb, gb));
                rectColorForIndex = 3;
                rectBackColorForIndex = 3;
            }
            else if (color1 == sf::Color::Magenta)
            {
                pixels[i].setFillColor(sf::Color(red, gb, red));
                rectColorForIndex = 4;
                rectBackColorForIndex = 4;
            }
            pixels[i].setPosition(pos.x+ 1.0*i - (255 * j), j+pos.y);
        }
        else {
            pixels[i].setFillColor(color1);
            pixels[i].setPosition(0, 0);
        }
    }
}

void ColorPicker::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(rectColor);
    window.draw(rectColor2);
    if(showRect != 0)
    {
        window.draw(backRect);
        for(int i = 0; i < rectColorList.size();i++)
        {
            window.draw(rectColorList.at(i));
        }
    }
    if(showRect2 != 0)
    {
        window.draw(backRect2);
        for(int i = 0; i < rectColorList2.size();i++)
        {
            window.draw(rectColorList2.at(i));
        }
    }
    if(showBigColor != 0)
    {
        for(int i = 0; i <pixels.size(); i++)
            window.draw(pixels.at(i));
    }
}
void ColorPicker::setColorFromFile(sf::Color color, int a)
{

}


