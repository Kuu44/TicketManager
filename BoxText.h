#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#pragma once
class BoxText
{
private:
	sf::Font font;
	sf::Text** text;
	float hSize, vSize;
	int maxRows, maxCols;
public:
	BoxText(float, float);
	void set(std::string**,int,int);
	void draw(sf::RenderWindow&);
};

