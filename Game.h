#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "obstacles.h"
#include "Menu.h"
#include "Player.h"
#include "PickUps.h"

using namespace sf;

class Game
{
	RenderWindow mywindow;
	Sprite background;
	Text scoretext, timetext, livestext, text;
	obstacles objects;
	Texture bg, winFrogT;
	Font ft;
	int score = 0, lives = 3, n = -1, wins = 0, x = 2;

	enum menu
	{
		none,
		play,
		options,
		Exit
	};
	menu menuitems = none;
	float deltatime = 0.0f;
	Clock clock;
	Player frog;
	Keyboard::Key keypressed;
	Menu menu;
	Event evnt;
	Event event;
	float time = 500;
	Texture dd;
	Sprite winFrog[4];
	bool dead = true, flag = true;
	bool gameover = false;
	PickUps pickups;
	int xposition = rand() % 600 + 50;
	int yposition = rand() % 600 + 50;

  public:
	Game();
	void renderwindow();
	void runGame();
	void player();
	void displayScore();
	void dispdead();
	~Game();
};