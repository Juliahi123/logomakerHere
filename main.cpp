#include "windowOne.h"
#include "saveFile.h"
#include "Typer.h"
int main() {
        windowOne one;
        saveFile sssave;
        sssave.setFile();
        sf::RenderWindow window;
        window.create({1000, 800}, "fileTree");
        window.setFramerateLimit(120);
        Typer t;

//    item.push("Directory 3");

        while(window.isOpen()){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed){
                    window.close();
                }

                t.addEventHandler(window,event);
            }
            if(t.getFormatIndex())
            {
                one.openSmallWindow();
                one.draw();
                t.setFalse();
            }
            t.update();
            window.clear(sf::Color::Black);
            window.draw(t);
            window.display();

        }

    return 0;
}
