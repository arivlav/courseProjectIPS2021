#include "obstacles.h"

using namespace sf;

obstacles::obstacles()
{
	winT.loadFromFile("images/Win.png");
	rivObject1T.loadFromFile("images/buoy.png");
	rivObject2T.loadFromFile("images/wood.png");
	rivObject3T.loadFromFile("images/buoy.png");
	transparentT.loadFromFile("images/t.png");
	c1.loadFromFile("images/car1.png");
	c2.loadFromFile("images/car2.png");
	c3.loadFromFile("images/car3.png");
	c4.loadFromFile("images/car4.png");
	c5.loadFromFile("images/car5.png");

	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			carsr1[i].setPosition(300 * i, 370 + 6 * 57.1f);
			carsr1[i].setTexture(c1);
			carsr1[i].setScale(1, 1);
			carsr1[i].setOrigin(0.0f, 15.0f);

			carsr2[i].setTexture(c2);
			carsr2[i].setPosition(300 * i, 375 + 5 * 57.1f);
			carsr2[i].setScale(1, 1);
			carsr2[i].setOrigin(0.0f, 15.0f);

			carsr3[i].setPosition(300 * i, 378 + 4 * 57.1f);
			carsr3[i].setTexture(c3);
			carsr3[i].setScale(1, 1);
			carsr3[i].setOrigin(0.0f, 15.0f);

			carsr4[i].setTexture(c4);
			carsr4[i].setPosition(300 * i, 378 + 3 * 57.1f);
			carsr4[i].setScale(1, 1);
			carsr4[i].setOrigin(0.0f, 15.0f);

			carsr5[i].setPosition(300 * i, 381 + 2 * 57.1f);
			carsr5[i].setTexture(c5);
			carsr5[i].setScale(1, 1);
			carsr5[i].setOrigin(0.0f, 15.0f);
		}
		if (i < 4)
		{
			win[i].setTexture(winT);
			win[i].setScale(1, 1);
			win[i].setPosition(90 + i * 169, 43);
		}
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 || i == 3)
			{
				rivObjects[i][j].setTexture(rivObject1T);
				rivObjects[i][j].setScale(1, 1);
			}

			else if (i == 1 || i == 4)
			{
				rivObjects[i][j].setTexture(rivObject2T);
				rivObjects[i][j].setScale(1, 1);
			}
			else if (i == 2 || i == 5)
			{
				rivObjects[i][j].setTexture(rivObject3T);
				rivObjects[i][j].setScale(1, 1);
			}

			rivObjects[i][j].setOrigin(0, 60.67f);
		}
	}
	rivObjects[0][0].setPosition(0, 104.109f + 57.1f);
	rivObjects[0][1].setPosition(250, 104.109f + 57.1f);
	rivObjects[0][2].setPosition(500, 104.109f + 57.1f);

	rivObjects[3][0].setPosition(700, 266.211f + 57.1f);
	rivObjects[3][1].setPosition(400, 266.211f + 57.1f);
	rivObjects[3][2].setPosition(100, 266.211f + 57.1f);

	rivObjects[1][0].setPosition(800, 158.143f + 57.1f);
	rivObjects[1][1].setPosition(500, 158.143f + 57.1f);
	rivObjects[1][2].setPosition(200, 158.143f + 57.1f);

	rivObjects[4][0].setPosition(100, 320.245f + 57.1f);
	rivObjects[4][1].setPosition(350, 320.245f + 57.1f);
	rivObjects[4][2].setPosition(600, 320.245f + 57.1f);

	rivObjects[2][0].setPosition(200, 212.177f + 57.1f);
	rivObjects[2][1].setPosition(450, 212.177f + 57.1f);
	rivObjects[2][2].setPosition(700, 212.177f + 57.1f);

	rivObjects[5][0].setPosition(600, 374.279f + 57.1f);
	rivObjects[5][1].setPosition(300, 374.279f + 57.1f);
	rivObjects[5][2].setPosition(0, 374.279f + 57.1f);
}

void obstacles::move()
{

	for (int i = 0; i < 3; i++)
	{
		if (speed == 1)
		{
			carsr2[i].setTexture(transparentT);
			carsr2[i].setScale(0.01f, 0.01f);
			carsr4[i].setTexture(transparentT);
			carsr4[i].setScale(0.01f, 0.01f);
		}
		else if (speed == 2)
		{
			carsr2[i].setTexture(c2);
			carsr2[i].setScale(1, 1);
			carsr4[i].setTexture(transparentT);
			carsr4[i].setScale(0.01f, 0.01f);
		}
		else if (speed > 2)
		{
			carsr2[i].setTexture(c2);
			carsr2[i].setScale(1, 1);
			carsr4[i].setTexture(c4);
			carsr4[i].setScale(1, 1);
		}

		carsr1[i].move(-3 * speed, 0);
		if (carsr1[i].getPosition().x < -90)
			carsr1[i].setPosition(800, 370 + 6 * 57.1f);

		carsr2[i].move(2 * speed, 0);
		if (carsr2[i].getPosition().x > 780)
			carsr2[i].setPosition(-120, 375 + 5 * 57.1f);

		carsr3[i].move(-3 * speed, 0);
		if (carsr3[i].getPosition().x < -40)
			carsr3[i].setPosition(800, 378 + 4 * 57.1f);

		carsr4[i].move(3 * speed, 0);
		if (carsr4[i].getPosition().x > 780)
			carsr4[i].setPosition(-130, 378 + 3 * 57.1f);

		carsr5[i].move(-3.5 * speed, 0);
		if (carsr5[i].getPosition().x < -90)
			carsr5[i].setPosition(810, 381 + 2 * 57.1f);

		if (i < 3)
		{
			if (rivObjects[0][i].getPosition().x < 750)
				rivObjects[0][i].move(2 * speed, 0);
			else
				rivObjects[0][i].setPosition(-200, 104.109f + 57.1f);

			if (rivObjects[2][i].getPosition().x < 750)
				rivObjects[2][i].move(2 * speed, 0);
			else
				rivObjects[2][i].setPosition(-200, 212.177f + 57.1f);

			if (rivObjects[4][i].getPosition().x < 750)
				rivObjects[4][i].move(2 * speed, 0);
			else
				rivObjects[4][i].setPosition(-200, 320.245f + 57.1f);

			if (rivObjects[1][i].getPosition().x > -130)
				rivObjects[1][i].move(-2 * speed, 0);
			else
				rivObjects[1][i].setPosition(1000, 158.143f + 57.1f);

			if (rivObjects[3][i].getPosition().x > -130)
				rivObjects[3][i].move(-2 * speed, 0);
			else
				rivObjects[3][i].setPosition(1000, 266.211f + 57.1f);

			if (rivObjects[5][i].getPosition().x > -130)
				rivObjects[5][i].move(-2 * speed, 0);
			else
				rivObjects[5][i].setPosition(1000, 374.279f + 57.1f);
		}
	}
}

bool obstacles::intersection(Sprite ob, Sprite obstacle)
{
	if (obstacle.getGlobalBounds().contains(ob.getPosition().x + 25, ob.getPosition().y + 25))
		return true;
	else
		return false;
}

bool obstacles::checkIntersect(RenderWindow &window, Player &frog)
{
	state = false;
	for (int i = 0; i < 6; i++)
	{
		if (i < 4)
			if (intersection(frog.returnbody(), win[i]))
				state = true;

		if (i < 4)
		{
			if (intersection(frog.returnbody(), carsr1[i]))
				state = true;
			if (intersection(frog.returnbody(), carsr2[i]))
				state = true;
			if (intersection(frog.returnbody(), carsr3[i]))
				state = true;
			if (intersection(frog.returnbody(), carsr4[i]))
				state = true;
			if (intersection(frog.returnbody(), carsr5[i]))
				state = true;
		}
		for (int j = 0; j < 3; j++)
		{
			if ((i == 0 || i == 2 || i == 4) && intersection(frog.returnbody(), rivObjects[i][j]))
			{
				state = true;
				frog.Move(0.5f * 2 * speed, 0);
			}
			else if (intersection(frog.returnbody(), rivObjects[i][j]))
			{
				state = true;
				frog.Move(-0.5f * 2 * speed, 0);
			}
		}
	}
	return state;
}

void obstacles::draw(RenderWindow &w)
{
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			w.draw(carsr1[i]);
			w.draw(carsr2[i]);
			w.draw(carsr3[i]);
			w.draw(carsr5[i]);
			w.draw(carsr4[i]);
		}
		if (i < 4)
			w.draw(win[i]);
		for (int j = 0; j < 3; j++)
			w.draw(rivObjects[i][j]);
	}
}

int obstacles::getState(RenderWindow &myWindow, Player &frog)
{
	int xp = frog.returnbody().getPosition().x, yp = frog.returnbody().getPosition().y;
	int x = 2;
	if (checkIntersect(myWindow, frog))
		x = 1;

	if (yp < 419 && yp > 94)
		if (checkIntersect(myWindow, frog))
			x = 2;
		else
			x = 0;
	if (yp < 94 && checkIntersect(myWindow, frog))
		x = 3;
	return x;
}

void obstacles::nextLevel()
{
	speed++;
}
void obstacles::levelOne()
{
	speed = 1;
}

obstacles::~obstacles()
{
}
