#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Cell.h"
#include "BoxText.h"

int main()
{
    //Declarations
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Ticket Manager", sf::Style::Default);
    window.setFramerateLimit(144);   
    float hSize = 200.0f, vSize = 60.f;
    int maxCols = 5, maxRows = 6;
    Cell cell(hSize,vSize);
    cell.set(maxRows, maxCols);
    BoxText boxtext(hSize, vSize);

    std::string str[4][5] = {
        {"Just","Look at this","Beauuuuuutiful","Perfectly Centered","Text"},
        {"Oh","dear,","my","dear","gorgeous"},
        {"Alluring","Lovely","Magnificient","Marvelous","Resplendent"},
        {"This Does","Bring A","Smile","To My","Face"}
    };
    std::string** s;
    s = new std::string * [4];
    for (int i = 0; i < 4; i++) {
        s[i] = new std::string[5];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            s[i][j]=str[i][j];
        }
    }

    boxtext.set(s, 4, 5);

    // run the program as long as the window is open
    while (window.isOpen()) {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) window.close();
        }
      
        //Update
        //rect.move(-0.1f, 0.f);

        //Refresh Screen
        window.clear(sf::Color::White);
        cell.draw(window);
        boxtext.draw(window);
        window.display();
    }
    return 0;
}
