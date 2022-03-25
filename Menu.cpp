#include "Menu.h"

Menu::Menu()
{
	float wd = 750, ht = 800;

	font.loadFromFile("fonts/formenu.ttf");

	float menuStartX = wd / 2 - 50;
	float menuStartY = ht / 2 - 50;
	float deltaMenuY = 60;
	for (int i = 0; i < items; i++)
	{
		menu[i].setFont(font);
		menu[i].setCharacterSize(46);
		menu[i].setFillColor(Color::White);
		menu[i].setPosition(menuStartX, menuStartY + deltaMenuY * i);
	}
	menu[0].setString("Play");
	menu[1].setString("Exit");

	menu[selecteditem].setFillColor(Color::Green);

	menuBg.loadFromFile("images/Menu.png");
	menuBgTexture.setTexture(menuBg);
	menuBgTexture.setPosition(0.0f, 0.0f);
	title.loadFromFile("images/title.png");
	titleTexture.setTexture(title);
	titleTexture.setPosition(125.0f, 80.0f);
}

int Menu::getSelectedItem()
{
	return selecteditem;
}

void Menu::drawmenu(RenderWindow &window)
{
	window.draw(menuBgTexture);
	window.draw(titleTexture);
	for (int i = 0; i < items; i++)
		window.draw(menu[i]);
}
void Menu::moveup()
{
	if (selecteditem - 1 >= 0)
	{
		menu[selecteditem].setFillColor(Color::White);
		selecteditem--;
		menu[selecteditem].setFillColor(Color::Green);
	}
}
void Menu::movedown()
{
	if (selecteditem + 1 < items)
	{
		menu[selecteditem].setFillColor(Color::White);
		selecteditem++;
		menu[selecteditem].setFillColor(Color::Green);
	}
}
Menu::~Menu()
{
}
