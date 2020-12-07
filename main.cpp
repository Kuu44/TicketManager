#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Cell.h"
#include "BoxText.h"
#include "Menu.h"
#include "InputText.h"
#include "Entry.h"

#define MAX_SIZE 50

void drawBox(Cell cell, BoxText boxtext, sf::RenderWindow& window) {
	cell.draw(window);
	boxtext.draw(window);
}
void drawMenu(Menu menu, sf::RenderWindow& window) {
	menu.draw(window);
}
void setBoxes(Cell& cell, BoxText& boxtext,Entry data) {
	cell.set(data.getSize(), 4);
	boxtext.set(data.getResult(), data.getSize(), 4);
}
int main()
{
	//Declarations
	sf::RenderWindow window(sf::VideoMode(1000, 660), "Ticket Manager", sf::Style::Default);
	window.setFramerateLimit(144);
	//0=Menu, 1=Input, 2=Show
	int menuMode = 0;

	float hSize = 200.0f, vSize = 60.f;
	
	Cell cell(hSize, vSize);
	BoxText boxtext(hSize, vSize);
	Menu menu(window.getSize().x, window.getSize().y);
	std::string criteriaS[3] = {" Name", " Age", " Seat No."};
	std::string* criteria=new std::string[3];
	for (int j = 0; j < 3; j++) {
		criteria[j] = criteriaS[j];
	}
	InputText inputText(criteria);
	Entry data;

	//Pre-registered, Unsorted Data	
	data.inputData("Sandesh", 15, 5);
	data.inputData("Gopal", 22, 1);
	data.inputData("Anushka", 20, 2);
	data.inputData("Sushmita", 14, 7);

	//file.read

	//Setting up the table
	cout<<data.getSize();
	setBoxes(cell, boxtext, data);

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
						if (inputText.currentQuestion > 2) { 
							inputText.addData(data);
							setBoxes(cell, boxtext, data);
							menuMode = 0;
							//file.save
						}
						if(menuMode==1) inputText.nextQuestion(data);
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
								case 2:
									data.BubbleSort();
									setBoxes(cell, boxtext, data);
									break;
								case 3:
									data.SelectionSort();
									setBoxes(cell, boxtext, data);
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
