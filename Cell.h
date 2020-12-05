#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Cell
{
private:
    sf::RectangleShape rect[10][10];
    sf::RectangleShape border;
    float hSize, vSize;
    int maxCols, maxRows;
public:
    Cell(float, float);
    void set(int,int);
    void draw(sf::RenderWindow&);
};

