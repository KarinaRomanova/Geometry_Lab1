#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "Small Circular Gradient Background");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		// Получаем центр окна
		sf::Vector2u windowSize = window.getSize();
		float centerX = static_cast<float>(windowSize.x) / 2;
		float centerY = static_cast<float>(windowSize.y) / 2;

		// Создаем круговой градиент
		sf::CircleShape gradientCircle(200); 

		sf::Color startColor(128, 0, 128); //(RGB: 128, 0, 128)
		sf::Color endColor(255, 255, 255); //(RGB: 200, 15, 65)

		// Заполняем круг градиентом
		sf::Uint8 r = static_cast<sf::Uint8>((endColor.r - startColor.r) / 2);
		sf::Uint8 g = static_cast<sf::Uint8>((endColor.g - startColor.g) / 2);
		sf::Uint8 b = static_cast<sf::Uint8>((endColor.b - startColor.b) / 2);

		gradientCircle.setFillColor(startColor);
		gradientCircle.setOutlineThickness(0);
		gradientCircle.setPosition(centerX - 200, centerY - 200); // Позиция центра круга

		// Закрашиваем окно круговым градиентом
		window.draw(gradientCircle);

		window.display();
	}

	return 0;
}
