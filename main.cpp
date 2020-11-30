#include <SFML/Graphics.hpp>
#include "header.hpp"
#define _PATH_IMG_ "../../../img/"
using namespace std;
using namespace sf;
const std::string path_image(_PATH_IMG_);

int main() {
	/*const Vector2u WINDOW_SIZE(1920, 1080);

	RenderWindow app(VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y, 32), "My Game");
	app.setFramerateLimit(60);
	//Texture testbg;
	//testbg.loadFromFile(path_image + "shark.jpeg");
	//Sprite stestbg(testbg);

	while (app.isOpen()) 
	{
		Event event;
		while (app.pollEvent(event)) 
		{
			if ((event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape) || event.type == Event::Closed)
			{
				app.close();
			}
		}

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {}

		// Display
		
		app.clear();
		//app.draw(stestbg);
		app.display();
		
	}*/
	string file = "parcours.txt";
	string file2 = "coureurs.txt";
	Trajectory test = getParcours(file, numberOfLines(file));
	test.print();
	Participants ttest = getCoureurs(file2, numberOfLines(file));
	ttest.getCoureur(0).print();
	return EXIT_SUCCESS;
}