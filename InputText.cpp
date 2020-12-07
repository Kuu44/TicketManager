#include "InputText.h"
#include<string>
#include<iostream>
#include<sstream>

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

void InputText::nextQuestion(Entry& currentData)
{
	//take input
	switch (currentQuestion) {
	case 0:
		data.name = input;
		break;
	case 1:
	{
		std::stringstream age(input);
		age >> data.age;
	}
	break;
	case 2:
	{
		std::stringstream seat(input);
		seat >> data.seat_no;
	}
	break;
	}
	input = "";
	inputText.setString(input);

	if (currentQuestion++ < 2){
		std::string questionString = "Please enter the" + criteria[currentQuestion] + ":";
		questionText.setString(questionString);
	}	

	if (currentQuestion == 3) {
		for (int i = 0; i < (currentData.getSize() - 1); i++) {
			if (currentData.entries[i].seat_no == data.seat_no) {
				std::string questionString = "That Seat number is taken, please enter another (Upto 10)";
				questionText.setString(questionString);
				currentQuestion = 2;
				break;
			}
		}
	}
}
void InputText::addData(Entry& newData) {
	newData.inputData(data.name.c_str(), data.age, data.seat_no);

}
void InputText::reset() {
	currentQuestion = 0;
	std::string questionString = "Please enter the" + criteria[currentQuestion] + ":";
	questionText.setString(questionString);
	input = "";
	inputText.setString(input);

	data.name = "";
	data.age = NULL;
	data.seat_no = NULL;
}

void InputText::draw(sf::RenderWindow &window)
{
	window.draw(questionText);
	window.draw(inputText);
}
