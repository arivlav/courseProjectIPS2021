#include "PickUps.h"

PickUps::PickUps()
{
	s = rand() % 3;
}

void PickUps::setPickupposition(RenderWindow &window)
{

	switch (s)
	{
	case 0:
		Pickup.setScale(0.07, 0.07);
		break;
	case 1:
		Pickup.setScale(0.07, 0.07);
		break;
	case 2:
		Pickup.setScale(0.07, 0.07);
		break;
	}
	Pickup.setPosition(xposition, yposition);
}

void PickUps::draw(RenderWindow &window)
{
	window.draw(Pickup);
}

Sprite PickUps::getBoundingRectangle()
{
	return Pickup;
}

bool PickUps::PickupIntersect(Player &player, RenderWindow &window)
{
	if (player.returnbody().getGlobalBounds().intersects(getBoundingRectangle().getGlobalBounds()))
		return true;
	else
		return false;
}
PickUps::~PickUps()
{
}
