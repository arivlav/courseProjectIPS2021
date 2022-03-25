#include <SFML/Graphics.hpp>

using namespace sf;

class Menu
{
private:
	int items = 2;
	Text menu[2];
	int selecteditem = 0;
	Font font;
	Texture menuBg, title;
	Sprite menuBgTexture, titleTexture;

public:
	Menu();
	void drawmenu(RenderWindow &window);
	int getSelectedItem();
	void moveup();
	void movedown();
	void moveoup();
	~Menu();
};
