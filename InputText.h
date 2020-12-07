#include "SFML/Graphics.hpp"
#include "Entry.h"

#pragma once
class InputText
{
private:
	sf::Font font;
	std::string* criteria;
	Person data;
public:
	int currentQuestion;
	std::string question, input;
	sf::Text questionText, inputText;
	
	InputText(std::string*);
	void nextQuestion(Entry&);
	void reset();
	void draw(sf::RenderWindow&);
	void addData(Entry&);
};

