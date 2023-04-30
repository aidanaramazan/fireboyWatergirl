#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fireboy and Watergirl");
    sf::ContextSettings settings;
    	settings.antialiasingLevel = 8;
    sf::Sprite fireboy;
    sf::Sprite watergirl;
    sf::Sprite key;
    sf::Sprite door;
    sf::Sprite obstacle;
	sf::RectangleShape rectangle(sf::Vector2f(200, 2));
	rectangle.setPosition(sf::Vector2f(300, 100));
	rectangle.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fireboy);
        window.draw(watergirl);
        window.draw(key);
        window.draw(door);
        window.draw(obstacle);
        window.display();
    }

    return 0;
}
