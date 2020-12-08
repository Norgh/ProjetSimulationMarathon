#include <SFML/Graphics.hpp>
#include "header.hpp"
#define _PATH_IMG_ "../../../img/"
using namespace std;
using namespace sf;
const string path_image(_PATH_IMG_);

int main() {
	srand((unsigned int)time(NULL));
	Trajectory randomtest(50);
	randomCoureurs(4);
	Participants test;

	sf::RenderWindow window(sf::VideoMode(800, 800), "My Game");
	window.setFramerateLimit(60);
	sf::RectangleShape rectangle(sf::Vector2f(10, 5));
	rectangle.setPosition(sf::Vector2f(250, 100));
	rectangle.setFillColor(sf::Color::Green);
	sf::RectangleShape rectangle1(sf::Vector2f(10, 5));
	rectangle1.setPosition(sf::Vector2f(250, 200));
	rectangle1.setFillColor(sf::Color::Blue);
	sf::RectangleShape rectangle2(sf::Vector2f(10, 5));
	rectangle2.setPosition(sf::Vector2f(250, 300));
	rectangle2.setFillColor(sf::Color::Yellow);
	sf::RectangleShape rectangle3(sf::Vector2f(10, 5));
	rectangle3.setPosition(sf::Vector2f(250, 400));
	rectangle3.setFillColor(sf::Color::Red);
	sf::Font police_arial;
	if (!police_arial.loadFromFile("polices/arial.ttf"))
	{
		std::cout << "erreur dans le chargement des polices" << std::endl;
	}
	sf::Text Nom;
	Nom.setFont(police_arial);
	Nom.setPosition(20, 85);
	Nom.setString(test.getCoureur(0).getName());
	Nom.setCharacterSize(20);
	Nom.setFillColor(sf::Color::White);

	sf::Text Nom1;
	Nom1.setFont(police_arial);
	Nom1.setPosition(20, 185);
	Nom1.setString(test.getCoureur(1).getName());
	Nom1.setCharacterSize(20);
	Nom1.setFillColor(sf::Color::White);

	sf::Text Nom2;
	Nom2.setFont(police_arial);
	Nom2.setPosition(20, 285);
	Nom2.setString(test.getCoureur(2).getName());
	Nom2.setCharacterSize(20);
	Nom2.setFillColor(sf::Color::White);

	sf::Text Nom3;
	Nom3.setFont(police_arial);
	Nom3.setPosition(20, 385);
	Nom3.setString(test.getCoureur(3).getName());
	Nom3.setCharacterSize(20);
	Nom3.setFillColor(sf::Color::White);
	bool end = 0;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || event.type == Event::Closed)
			{
				window.close();
			}
		}
		end = test.startMarathon();
		window.clear();

		window.draw(Nom);
		window.draw(Nom1);
		window.draw(Nom2);
		window.draw(Nom3);
		bool isFinished = 0;
		if (test.getCoureur(0).getIsOver() && test.getCoureur(1).getIsOver() && test.getCoureur(2).getIsOver() && test.getCoureur(3).getIsOver())
		{
			isFinished = 1;
		}
		if (isFinished==1)
		{
			window.draw(rectangle);
			window.draw(rectangle1);
			window.draw(rectangle2);
			window.draw(rectangle3);
		}
		else
		{
			rectangle.setSize(Vector2f(test.getCoureur(0).getDistance()*10, test.getTotalDistance()));
			rectangle1.setSize(Vector2f(test.getCoureur(1).getDistance()*10, test.getTotalDistance()));
			rectangle2.setSize(Vector2f(test.getCoureur(2).getDistance()*10, test.getTotalDistance()));
			rectangle3.setSize(Vector2f(test.getCoureur(3).getDistance()*10, test.getTotalDistance()));
			window.draw(rectangle);
			window.draw(rectangle1);
			window.draw(rectangle2);
			window.draw(rectangle3);
			window.display();
		}

		if (end == 1)
		{
			cout << "Marathon is over\n";
			system("PAUSE");
			window.close();
		}
	}
	return EXIT_SUCCESS;
}