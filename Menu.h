#pragma once
#include "SFML/Graphics.hpp"

#define NO_OF_MENU_ITEMS 4  

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow&);
	void moveUp();
	void moveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text buttons[NO_OF_MENU_ITEMS];
	sf::RectangleShape buttonBorders[NO_OF_MENU_ITEMS];
	float width, height;
};

