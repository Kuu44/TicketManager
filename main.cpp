#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "Ticket Manager");

    /*
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    */

    // run the program as long as the window is open
    while (window.isOpen()) {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();
        }
        /*
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
        */
    }
    return 0;
}
/*
Debug:
opengl32.lib
freetype.lib
winmm.lib
gdi32.lib
flac.lib
vorbisenc.lib
vorbisfile.lib
vorbis.lib
ogg.lib
ws2_32.lib
sfml-window-s-d.lib
sfml-system-s-d.lib
sfml-graphics-s-d.lib
sfml-audio-s-d.lib
sfml-network-s-d.lib

Release:
opengl32.lib
freetype.lib
winmm.lib
gdi32.lib
flac.lib
vorbisenc.lib
vorbisfile.lib
vorbis.lib
ogg.lib
ws2_32.lib
sfml-graphics-s.lib
sfml-window-s.lib
sfml-audio-s.lib
sfml-network-s.lib
sfml-system-s.lib
*/