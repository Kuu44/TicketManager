#include "Cell.h"

Cell::Cell(float t_hSize, float t_vSize):hSize(t_hSize), vSize(t_vSize) {}
void Cell::set(int rows, int cols){
    maxCols = cols;
    maxRows = rows;

    //Defining Border
    border = sf::RectangleShape(sf::Vector2f(maxCols * (hSize + 1), maxRows * (vSize + 1)));
    border.setFillColor(sf::Color::Black);

    //Defining Cells
    //i=columns, j=rows
    for (int j = 0; j < 1; j++) {
        for (int i = 0; i < maxCols; i++) {
            rect[i][j] = sf::RectangleShape(sf::Vector2f(hSize, vSize));
            rect[i][j].setPosition(sf::Vector2f(i * (hSize + 1), j * (vSize + 1)));
            if (i % 2) rect[i][j].setFillColor(sf::Color(120, 255, 214, 255));
            else rect[i][j].setFillColor(sf::Color(161, 104, 58, 255));
        }
    }
    for (int j = 1; j < maxRows; j++) {
        for (int i = 0; i < maxCols; i++) {
            rect[i][j] = sf::RectangleShape(sf::Vector2f(hSize, vSize));
            rect[i][j].setPosition(sf::Vector2f(i * hSize + i, j * vSize + j));
            if (i % 2)
            {
                if (j % 2) rect[i][j].setFillColor(sf::Color(225, 250, 249, 255));
                else rect[i][j].setFillColor(sf::Color(210, 250, 249, 255));
            }
            else
            {
                if (j % 2) rect[i][j].setFillColor(sf::Color(232, 153, 141, 255));
                else rect[i][j].setFillColor(sf::Color(217, 153, 141, 255));
            }
        }
    }
}
void Cell::draw(sf::RenderWindow &window)
{
    window.draw(border);
    for (int i = 0; i < maxCols; i++) {
        for (int j = 0; j < maxRows; j++) {
            window.draw(rect[i][j]);
        }
    }
}
