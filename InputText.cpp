#include "InputText.h"

InputText::InputText(std::string* t_criteria):criteria(t_criteria)
{
	reset();
	if (!font.loadFromFile("Fonts/Roboto-Bold.ttf")) throw("No Font");
	inputText.setFont(font);
	inputText.setCharacterSize(20);
	inputText.setFillColor(sf::Color::Black);
	inputText.setPosition(10.f, 60.f);

	std::string questionString = "Please enter the" + criteria[currentQuestion] + ":";
	questionText.setString(questionString);
	questionText.setFont(font);
	questionText.setCharacterSize(30);
	questionText.setFillColor(sf::Color::Red);	
}

void InputText::nextQuestion()
{
	//take input
	std::string questionString = "Please enter the" + criteria[++currentQuestion] + ":";
	questionText.setString(questionString);
	input = "";
	inputText.setString(input);
}
void InputText::reset() {
	currentQuestion = 0;
}

void InputText::draw(sf::RenderWindow &window)
{
	window.draw(questionText);
	window.draw(inputText);
}
