#include <SFML/Graphics.hpp>

int main()
{

	bool isPaused = false;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fireboy and Watergirl");

    sf::Texture fireboyTexture;
    sf::Texture watergirlTexture;
    fireboyTexture.loadFromFile("fireboy.png");
    watergirlTexture.loadFromFile("watergirl.png");
    sf::Sprite fireboy(fireboyTexture);
    sf::Sprite watergirl(watergirlTexture);

    fireboy.setPosition(100, 100);
    watergirl.setPosition(500, 100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            fireboy.move(-5, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            fireboy.move(5, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            fireboy.move(0, -5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            fireboy.move(0, 5);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            watergirl.move(-5, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            watergirl.move(5, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            watergirl.move(0, -5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            watergirl.move(0, 5);




        if (!isPaused)
              {
                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                      fireboy.move(-5, 0);
                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                      fireboy.move(5, 0);
                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                      fireboy.move(0, -5);
                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                      fireboy.move(0, 5);

                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                      watergirl.move(-5, 0);
                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                      watergirl.move(5, 0);
                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                      watergirl.move(0, -5);
                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                      watergirl.move(0, 5);
              }


        window.clear();

        window.draw(fireboy);
        window.draw(watergirl);


        window.display();
    }

    return 0;
}
