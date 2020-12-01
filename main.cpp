#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Cell.h"

int main()
{
    //Declarations
    sf::RenderWindow window(sf::VideoMode(1000, 500), "Ticket Manager", sf::Style::Default);
    window.setFramerateLimit(144);    
    Cell cell;

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
        window.display();
    }
    return 0;
}
