#include "Menu.h"
Menu::Menu(float t_width, float t_height):height(t_height), width(t_width) {
	if (!font.loadFromFile("Fonts/Roboto-Bold.ttf")) throw("No Font");
	std::string options[NO_OF_MENU_ITEMS] = { "Input Data", "Show Data" };

	selectedItemIndex = 0;

	for (int i = 0; i < NO_OF_MENU_ITEMS; i++) {
		buttons[i].setFont(font);
		buttons[i].setString(options[i]);
		buttons[i].setCharacterSize(30);

		sf::FloatRect rect = buttons[i].getGlobalBounds();
		buttonBorders[i] = sf::RectangleShape(sf::Vector2f(rect.width*2, 70.f));
		if(i==selectedItemIndex)
		{
			buttonBorders[i].setFillColor(sf::Color(120, 255, 214, 255));			
			buttons[i].setFillColor(sf::Color::Black);
		}
		else 
		{
			buttonBorders[i].setFillColor(sf::Color(161, 104, 58, 255));
			buttons[i].setFillColor(sf::Color::White);
		}
		buttons[i].setPosition(sf::Vector2f((width / 2) - (rect.width / 2), height / (NO_OF_MENU_ITEMS + 1) * (i + 1)));
		buttonBorders[i].setPosition(sf::Vector2f((width / 2) - (rect.width), (height / (NO_OF_MENU_ITEMS + 1) * (i + 1)) -10.f));
	}

}
Menu::~Menu() {}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < NO_OF_MENU_ITEMS; i++) {
		window.draw(buttonBorders[i]);
		window.draw(buttons[i]);
	}
}

void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		buttonBorders[selectedItemIndex].setFillColor(sf::Color(161, 104, 58, 255));
		buttons[selectedItemIndex].setFillColor(sf::Color::White);

		selectedItemIndex--;

		buttonBorders[selectedItemIndex].setFillColor(sf::Color(120, 255, 214, 255));
		buttons[selectedItemIndex].setFillColor(sf::Color::Black);
	}
}

void Menu::moveDown()
{
	if (selectedItemIndex + 1 < NO_OF_MENU_ITEMS) {
		buttonBorders[selectedItemIndex].setFillColor(sf::Color(161, 104, 58, 255));
		buttons[selectedItemIndex].setFillColor(sf::Color::White);

		selectedItemIndex++;

		buttonBorders[selectedItemIndex].setFillColor(sf::Color(120, 255, 214, 255));
		buttons[selectedItemIndex].setFillColor(sf::Color::Black);
	}
}
