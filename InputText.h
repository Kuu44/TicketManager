#include "SFML/Graphics.hpp"

#pragma once
class InputText
{
private:
	sf::Font font;
	std::string* criteria;
public:
	int currentQuestion;
	sf::String question, input;
	sf::Text questionText, inputText;
	
	InputText(std::string*);
	void nextQuestion();
	void reset();
	void draw(sf::RenderWindow&);
};

