/*
 *
 * description:
 *
 * author: Yann Herklotz <ymherklotz@gmail.com>
 * date created: DD-MM-YYYY
 *
 */

#include "../include/TileMap.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "executing " << argv[0] << endl;
	cout << "arguments given: " << argc - 1 << endl;

	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 600), "A* Algorithm");

	cout	<< "window size: " << window.getSize().x << ", " << window.getSize().y
			<< endl;

	const int tile_size = 21;
	const int rows = 41;
	const int cols = 34;

	cout << "tile size: " << tile_size << "px, rows: " << rows << ", cols: " <<
		cols << endl;

	int tiles[cols * rows];

	for(int i = 0; i < cols * rows; ++i)
		tiles[i] = 0;

	TileMap map;

	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event))
			if(event.type == sf::Event::Closed)
				window.close();

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i mouse = sf::Mouse::getPosition(window);

			tiles[(int)(mouse.x / tile_size) +
				  cols * (int)(mouse.y / tile_size)] = 1;
		} else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			sf::Vector2i mouse = sf::Mouse::getPosition(window);

			tiles[(int)(mouse.x / tile_size) +
				  cols * (int)(mouse.y / tile_size)] = 2;
		}

		//tiles[rand() % (rows*cols)] = rand() % 4;

		map.load("res/GridTileTexture3.png", sf::Vector2f(200, 200),
				 sf::Vector2f(tile_size, tile_size), tiles, cols, rows);

		window.clear(sf::Color(47, 47, 47));
		window.draw(map);
		window.display();
	}

	return 0;
}
