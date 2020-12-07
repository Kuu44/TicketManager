#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Cell.h"
#include "BoxText.h"
#include "Menu.h"
#include "InputText.h"
#include "Entry.h"

void drawBox(Cell cell, BoxText boxtext, sf::RenderWindow& window) {
	cell.draw(window);
	boxtext.draw(window);
}
void drawMenu(Menu menu, sf::RenderWindow& window) {
	menu.draw(window);
}
int main()
{
	//Declarations
	sf::RenderWindow window(sf::VideoMode(1000, 500), "Ticket Manager", sf::Style::Default);
	window.setFramerateLimit(144);
	//0=Menu, 1=Input, 2=Show
	int menuMode = 0;

	float hSize = 200.0f, vSize = 60.f;
	int maxCols = 5, maxRows = 6;
	Cell cell(hSize, vSize);
	BoxText boxtext(hSize, vSize);
	Menu menu(window.getSize().x, window.getSize().y);
	std::string criteriaS[3] = {"Name", "Age", "Seat No."};
	std::string* criteria=new std::string[3];
	for (int j = 0; j < 3; j++) {
		criteria[j] = criteriaS[j];
	}
	InputText inputText(criteria);

	//Setting up the table
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
			s[i][j] = str[i][j];
		}
	}

	cell.set(maxRows, maxCols);
	boxtext.set(s, 4, 5);

	// run the program as long as the window is open
	while (window.isOpen()) {

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				if (menuMode == 1) {
					if (
						(event.text.unicode>=48 && event.text.unicode<=57) || 
						(event.text.unicode >= 97 && event.text.unicode <= 122) || 
						(event.text.unicode >= 65 && event.text.unicode <= 90)) {
						inputText.input += event.text.unicode;
						inputText.inputText.setString(inputText.input);
					}
				}
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Escape:
						window.close();
						break;
					//Clearing input Field
					case sf::Keyboard::Return:
						if (inputText.currentQuestion > (3 - 2)) menuMode = 0;
						if(menuMode==1) inputText.nextQuestion();
						break;
					case sf::Keyboard::Up:
						menu.moveUp();
						break;
					case sf::Keyboard::Down:
						menu.moveDown();
						break;
					case sf::Keyboard::Space:
						if (menuMode==0) {
							switch (menu.GetPressedItem()) {
								case 0:
									menuMode = 1;
									inputText.reset();
									break;
								case 1:
									menuMode = 2;
									break;
							}
						}
						else {
							menuMode = 0;
						}
						std::cout << "\nCurrent MenuMode:" << menuMode;
						break;
				}
				break;
			}
		}

		//Refresh Screen
		window.clear(sf::Color::White);

		switch (menuMode) {
		case 0:
			drawMenu(menu, window);
			break;
		case 1:
			inputText.draw(window);
			break;
		case 2:
			drawBox(cell, boxtext, window);
			break;
		}
		window.display();
	}
	return 0;
}
