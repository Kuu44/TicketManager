#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Cell
{
private:
    sf::RectangleShape rect[10][10];
    sf::RectangleShape border;
    float hSize = 200.0f, vSize = 60.f;
    int maxCols = 5, maxRows = 6;
public:
    Cell();
    void draw(sf::RenderWindow&);
};

