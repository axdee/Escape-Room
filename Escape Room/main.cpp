#include<SFML/Graphics.hpp>



int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Main Menu",sf::Style::Close);

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();
		window.display();

	}

}