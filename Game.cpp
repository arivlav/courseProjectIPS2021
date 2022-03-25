#include <math.h>
#include "Game.h"

Game::Game()
{

	mywindow.create(VideoMode(750, 800), "Frog crosses the road", Style::Default);
	mywindow.setFramerateLimit(30);

	ft.loadFromFile("fonts/maintext.ttf");

	bg.loadFromFile("images/background.JPG");

	dd.loadFromFile("images/frog/dead.png");
	scoretext.setFont(ft);
	timetext.setFont(ft);
	livestext.setFont(ft);

	background.setTexture(bg);
	background.setScale(1, 1);
	background.setPosition(0, 0);

	scoretext.setPosition(Vector2f(10, 0));
	scoretext.setCharacterSize(25);

	timetext.setPosition(Vector2f(260, 0));
	timetext.setCharacterSize(25);

	livestext.setPosition(Vector2f(620, 0));
	livestext.setCharacterSize(25);

	text.setFont(ft);
	text.setPosition(Vector2f(400.0f, 400.0f));
	text.setCharacterSize(40);

	winFrogT.loadFromFile("images/frog/NB.png");
}
void Game::renderwindow()
{
	while (mywindow.isOpen())
	{
		if (menuitems == none)
		{

			menu.drawmenu(mywindow);
			while (mywindow.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case Event::Closed:
					mywindow.close();
					break;
				case Event::KeyPressed:
					switch (evnt.key.code)
					{
					case Keyboard::Down:
						menu.movedown();
						break;
					case Keyboard::Up:
						menu.moveup();
						break;
					}
				}
			}
		}
		else if (menuitems == play)
		{
			mywindow.clear();
			runGame();
		}
		else if (menuitems == options)
		{
			mywindow.clear();
			while (mywindow.pollEvent(evnt))
			{
				switch (evnt.type)
				{
				case Event::Closed:
					mywindow.close();
					break;
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape) && menuitems == options)
		{
			menuitems = none;
		}
		if (Keyboard::isKeyPressed(Keyboard::Return) && menuitems == none)
		{
			switch (menu.getSelectedItem())
			{
			case 0:
				menuitems = play;
				mywindow.clear();
				runGame();
				break;
			case 1:
				mywindow.close();
				break;
			}
		}

		mywindow.display();
	}
}

void ::Game::runGame()
{

	if (menuitems != none)
	{
		time = time - clock.getElapsedTime().asSeconds();
	}
	if (time < 0)
		time = 0;
	x = objects.getState(mywindow, frog);
	deltatime = clock.restart().asSeconds();
	mywindow.clear();
	mywindow.draw(background);
	objects.draw(mywindow);
	frog.Draw(mywindow);

	pickups.setpos(xposition, yposition);
	pickups.setPickupposition(mywindow);

	pickups.draw(mywindow);

	if (pickups.PickupIntersect(frog, mywindow))
	{
		switch (pickups.returns())
		{
		case 0:
			frog.setscore(20);
			pickups.disapper();
			break;
		case 1:
			frog.increselives(1);
			pickups.disapper();
			break;
		case 2:
			time += 15;
			pickups.disapper();
			break;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		mywindow.draw(winFrog[i]);
		if (objects.intersection(frog.returnbody(), winFrog[i]))
			x = 0;
	}
	displayScore();
	if (frog.getLives() == 0)
	{
		x = 4;
		time = 0;
	}
	if (x == 1 || x == 0 || (frog.getYPosition() < 96 && x != 3) || (time == 0 && frog.getLives() != 0))
	{
		text.setString("Not Nice xD \n press Space to return");
		text.setPosition(Vector2f(100, 300));
		dispdead();
		text.setCharacterSize(60);
		if (dead)
			frog.DecreaseLives();
		dead = false;
	}
	else if (x == 2)
	{
		while (mywindow.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				mywindow.close();
				break;
			case Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::Down:
					text.setString("   ");
					keypressed = Keyboard::Down;
					frog.move(keypressed);
					break;
				case Keyboard::Up:
					text.setString("   ");
					keypressed = Keyboard::Up;
					frog.move(keypressed);
					break;
				case Keyboard::Right:
					text.setString("   ");
					keypressed = Keyboard::Right;
					frog.move(keypressed);
					break;
				case Keyboard::Left:
					text.setString("   ");
					keypressed = Keyboard::Left;
					frog.move(keypressed);
					break;
				}
			}
		}
		objects.move();
	}
	else if (x == 3)
	{
		if (frog.getXPosition() > 550)
		{
			n = 3;
			winFrog[n].setTexture(winFrogT);
			winFrog[n].setColor(Color::Blue);
			winFrog[n].setScale(1, 1);
			winFrog[n].setPosition(100 + n * 169, 43);
		}
		else if (frog.getXPosition() > 400)
		{
			n = 2;
			winFrog[n].setTexture(winFrogT);
			winFrog[n].setColor(Color::Blue);

			winFrog[n].setScale(1, 1);
			winFrog[n].setPosition(100 + n * 169, 43);
		}
		else if (frog.getXPosition() > 200)
		{
			n = 1;
			winFrog[n].setTexture(winFrogT);
			winFrog[n].setColor(Color::Blue);

			winFrog[n].setScale(1, 1);
			winFrog[n].setPosition(100 + n * 169, 43);
		}
		else
		{
			n = 0;
			winFrog[n].setTexture(winFrogT);
			winFrog[n].setColor(Color::Blue);

			winFrog[n].setScale(1, 1);
			winFrog[n].setPosition(100 + n * 169, 43);
		}
		wins++;
		frog.initializefrog(mywindow);
		text.setString("Nice :))");

		text.setPosition(Vector2f(200, 300));
		text.setCharacterSize(100);
		if (wins == 4)
		{
			text.setString("WoW \n move to next level");
			text.setPosition(Vector2f(200, 300));
			text.setCharacterSize(50);
		}
	}
	else
	{
		text.setCharacterSize(50);
		text.setString("Game Over \n Press enter to restart game");
		text.setPosition(Vector2f(100, 300));
	}
	if ((Keyboard::isKeyPressed(Keyboard::Key::Space) && x != 2) || (Keyboard::isKeyPressed(Keyboard::Key::Space) && time == 0))
	{
		time = 100;
		clock.restart();
		x = 2;
		frog.initializefrog(mywindow);
		dead = true;
	}
	if (frog.getLives() == 0 && Keyboard::isKeyPressed(Keyboard::Return))
	{
		clock.restart();
		time = 100;
		frog.initializefrog(mywindow);
		gameover = true;
		objects.levelOne();
		frog.setlives(3);
		frog.setScore(0);
	}
	else if (wins == 4)
	{
		for (int i = 0; i < 4; i++)
			winFrog[i].setPosition(100 + i * 169, -100);
		objects.nextLevel();
		x = 2;
		wins = 0;
	}
	mywindow.draw(text);

	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
	{
		menuitems = none;
	}
	if (gameover)
	{
		gameover = false;
		menuitems = none;
		renderwindow();
	}
}
void Game::displayScore()
{
	scoretext.setString("Score: " + std::to_string(frog.getscore()));
	int intTime = floor(time);
	timetext.setString("Time: " + std::to_string(intTime));
	livestext.setString("Lives: " + std::to_string(frog.getLives()));
	mywindow.draw(scoretext);
	mywindow.draw(timetext);
	mywindow.draw(livestext);
}

void Game::dispdead()
{
	float i = .4;
	int acc = 500;
	frog.setTexure(dd);
	while (acc != 0)
	{
		frog.setscale(i, i);
		i = i * 2;
		acc -= 5;
	}
	frog.resetscalse();
}

Game::~Game() {}
