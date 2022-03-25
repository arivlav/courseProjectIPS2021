#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum Direction
{
	up,
	down,
	right,
	left
};

class Player
{
  private:
	Sprite frog;
	float speed;
	Direction direction;
	Texture frogtexture;
	int lives, score;

  public:
	Player();
	~Player();
	void initializefrog(RenderWindow &window);
	void Draw(RenderWindow &window);
	void setPosition(float x, float y);
	void Move(float x, float y);
	void move(Keyboard::Key &keypressed);
	void DecreaseLives();
	void setWinTexture(const int &x);
	void updateScore(const int &x);
	Vector2f getOrigin();
	int getLives();
	void increselives(int d) { lives += d; }
	int getscore();
	void setscore(int d) { score += d; }
	int remaininglives();
	float getXPosition();
	float getYPosition();
	Sprite returnbody();
	FloatRect getboundingrectangle();
	void setlives(int x);
	void setScore(int x);

	void setTexure(Texture &texture) { frog.setTexture(texture); };
	void setscale(float x, float y) { frog.setScale(x, y); }
	void resetscalse() { frog.setScale(1, 1); }
};
