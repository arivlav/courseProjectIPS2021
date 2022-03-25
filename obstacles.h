#include <SFML\Graphics.hpp>
#include <time.h>
#include "Player.h"

using namespace sf;

class obstacles
{
	Sprite rivObjects[6][3];
	Sprite win[4];
	Texture rivObject1T, rivObject2T, rivObject3T, winT, transparentT;

	Sprite carsr1[5];
	Sprite carsr2[5];
	Sprite carsr3[5];
	Sprite carsr4[5];
	Sprite carsr5[5];
	float speed = 1;
	Texture c1;
	Texture c2;
	Texture c3;
	Texture c4;
	Texture c5;
	bool state = false;
	bool once = true;
	int level = 5;
	int i = 0;
	bool returnone = false;

  public:
	obstacles();
	~obstacles();
	void move();
	bool intersection(Sprite ob, Sprite obstacle);
	int getState(RenderWindow &, Player &);
	bool checkIntersect(RenderWindow &window, Player &);
	void draw(RenderWindow &w);
	void renderlevels();
	void nextLevel();
	void levelOne();
};