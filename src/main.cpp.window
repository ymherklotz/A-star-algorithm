/*
 *
 * description:		Displays the A* Algorithm on a grid.
 *
 * author:          Yann Herklotz <ymherklotz@gmail.com>
 * date created:    DD-MM-YYYY
 *
 */

#include "tilemap.hpp"
#include "astar.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "executing " << argv[0] << endl;
	cout << "arguments given: " << argc - 1 << endl;

	// create a render window of size 800x600 with a title.
	sf::RenderWindow window(sf::VideoMode(800, 600), "A* Algorithm");

	// print out the window size.
	cout << "window size: " << window.getSize().x << ", " << window.getSize().y << endl;

	// set the constants int the file that define the grid to be displayed.
	const int tile_size = 21;
	const int rows = 41;
	const int cols = 34;

	// print out that information.
	cout << "tile size: " << tile_size << "px, rows: " << rows << ", cols: " <<
		cols << endl;

	// create the array of the right size using the constants.
	int tiles[cols * rows];

	// assign zeros to the tiles.
	for(int i = 0; i < cols * rows; ++i)
		tiles[i] = 0;

	// create a tile map that will be used to display the array.
	TileMap map;

	// event loop that runs the window.
	while(window.isOpen()) {
		// create an event.
		sf::Event event;
		// check if an event has been triggered.
		while(window.pollEvent(event))
			// if the event is the window closing, close the window.
			if(event.type == sf::Event::Closed)
				window.close();

		// check if mouse buttons are pressed.
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			// get the position of the mouse.
			sf::Vector2i mouse = sf::Mouse::getPosition(window);
			// set the tile colour to 1.
			tiles[(int)(mouse.x / tile_size) + cols * (int)(mouse.y / tile_size)] = 1;
		} else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			sf::Vector2i mouse = sf::Mouse::getPosition(window);
			// set the tile colour to 2.
			tiles[(int)(mouse.x / tile_size) + cols * (int)(mouse.y / tile_size)] = 2;
		}

		// update tile map with the correct array.
		map.load("res/GridTileTexture3.png", sf::Vector2f(200, 200), sf::Vector2f(tile_size, tile_size), tiles, cols, rows);

		// clear the screen.
		window.clear(sf::Color(47, 47, 47));
		// draw the map onto the screen.
		window.draw(map);
		// display the window.
		window.display();
	}

	return 0;
}
