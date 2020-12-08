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
int InputText::getInputNum(int& menuMode) {
	int result;
	std::stringstream searchTerm(input);
	searchTerm >> result;

	if (result > 10 || result < 1) {
		std::string questionString = "Invalid input! please enter a number upto 10";
		questionText.setString(questionString);
		input = "";
		inputText.setString(input);
		menuMode = 5; 
	}
	return result;
}
void InputText::setSearchMode() {
	std::string questionString = "Enter the Bus number to search for (Upto 10)";
	questionText.setString(questionString);
}
void InputText::displaySearchResult(Person person) {
	for (int i=0; i < 3; i++) {
		results[i].setFont(font);
		results[i].setCharacterSize(20);
		results[i].setPosition(10.f, 60.f*(i+1));
	}
	results[0].setFillColor(sf::Color::Red);
	results[1].setFillColor(sf::Color::Blue);
	results[2].setFillColor(sf::Color::Black);
	if(person.seat_no==-1)
		results[0].setString("That Seat is Empty!");
	else {
		results[0].setString("Name:" + person.name);
		results[1].setString("Seat No:" + std::to_string(person.seat_no));
		results[2].setString("Age:" + std::to_string(person.age));
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
	results[0].setString("");
	results[1].setString("");
	results[2].setString("");
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
void InputText::drawRes(sf::RenderWindow &window)
{
	for(int i=0;i<3;i++)
		window.draw(results[i]);
}
