#include <SFML/Graphics.hpp>
#include "dziritadi.h"
using namespace std;
using namespace sf;

int main()
{
	
	

	Clock saati;
	bool xui = true;
	dziritadi chuchi;
	RenderWindow window(VideoMode(1080,720), "  Conway's game of life  ");
	window.setVerticalSyncEnabled(true);
	float gasulidro = 0.0f;
	
	while (window.isOpen())
	{
		gasulidro += saati.getElapsedTime().asSeconds();
		saati.restart();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Space)
					chuchi.adding(Mouse::getPosition(window));
			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
					xui = !xui;
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::R)
					chuchi.randomfill();
			
		}
		
		if (!xui) {
			chuchi.updating(gasulidro);
		}
		window.clear(Color::Black);
		chuchi.drawingski(window);
		chuchi.information(window);
		window.display();
	}

	return 0;
}