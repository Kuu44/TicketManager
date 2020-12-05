#include "BoxText.h"
#define MAX 50
BoxText::BoxText(float t_hSize, float t_vSize):vSize(t_vSize),hSize(t_hSize)
{
	if (!font.loadFromFile("Fonts/Roboto-Bold.ttf")) throw("No Font");  

    //Defining Text Boxes
    text = new sf::Text* [MAX];
    for (int i = 0; i < MAX; i++) {
        text[i] = new sf::Text[MAX];
    }
}
void BoxText::set(std::string** string,int rows, int cols) {
    maxRows = rows; maxCols = cols;
    sf::Text t_text[MAX][MAX];

    //Filling Text
    //i=rows, j=columns
    for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxCols; j++) {
            t_text[i][j].setFont(font);
            t_text[i][j].setCharacterSize(20);
            t_text[i][j].setFillColor(sf::Color::Black);
            t_text[i][j].setString(string[i][j]);

            //Centralizing Text
            size_t characterSize = t_text[i][j].getCharacterSize();
            size_t maxHeight = 0;
            std::string str = t_text[i][j].getString().toAnsiString();
            bool bold = (t_text[i][j].getStyle() & sf::Text::Bold);

            for (size_t x = 0; x < t_text[i][j].getString().getSize(); ++x)
            {
                sf::Uint32 character = str.at(x);
                const sf::Glyph& currentGlyph = font.getGlyph(character, characterSize, bold);
                size_t height = currentGlyph.bounds.height;
                maxHeight = (maxHeight < height) ? height : maxHeight;
            }
            sf::FloatRect rect = t_text[i][j].getGlobalBounds();
            float textX = (hSize / 2.f) - (rect.width / 2.f);
            float textY = (vSize / 2.f) - (maxHeight / 2.f) - (rect.height - maxHeight) + ((rect.height - characterSize) / 2.f);
            t_text[i][j].setPosition(textX + j*hSize, textY+i*vSize);
        }
    }
    for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxCols; j++) {
            text[i][j] = t_text[i][j];
        }
    }
}
void BoxText::draw(sf::RenderWindow& window) {
    for (int i = 0; i < maxRows; i++) {
        for (int j = 0; j < maxCols; j++) {
            window.draw(text[i][j]);
        }
    }
}
