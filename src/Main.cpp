#include <SFML/Graphics.hpp>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default, settings);
	sf::Font font;
	sf::Text text;

	if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
	{
		// error...
		return 1;
	}

	text.setFont(font);
	text.setString(L"ă");
	text.setCharacterSize(20);
	text.setPosition(10.f, 300.f);
	text.setFillColor(sf::Color::Green);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);

		sf::CircleShape shape(50.f);
		shape.setFillColor(sf::Color(150, 50, 250));

		// set a 10-pixel wide orange outline
		shape.setOutlineThickness(1.f);
		shape.setOutlineColor(sf::Color(250, 150, 100));
		shape.setPosition(50.f, 50.f);
		window.draw(shape);
		window.draw(text);

		// end the current frame
		window.display();
	}

	return 0;
}