#include "SFML/Graphics.hpp"
#include "Entry.h"
#include<string>
#include<cstring>
#include<iostream>
#include<sstream>

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
	sf::Text questionText, inputText, results[3];
	
	InputText(std::string*);
	void nextQuestion(Entry&);
	void reset();
	void draw(sf::RenderWindow&);
	void drawRes(sf::RenderWindow&);
	void addData(Entry&);
	int getInputNum(int&);
	void setSearchMode();
	void displaySearchResult(Person);
};

