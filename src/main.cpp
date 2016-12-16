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

using namespace std;

int main(int argc, char *argv[]) {
	cout << "executing " << argv[0] << endl;
	cout << "arguments given: " << argc - 1 << endl;

	srand(time(NULL));

	// create a render window of size 800x600 with a title.
	sf::RenderWindow window(sf::VideoMode(2500, 1250), "A* Algorithm");
	// window.setFramerateLimit(1);

	// print out the window size.
	cout << "window size: " << window.getSize().x << ", " << window.getSize().y << endl;

	// set the constants int the file that define the grid to be displayed.
	// for the mac
	const int tile_size = 21;
	const int rows = 41;
	const int cols = 34;

	// const int tile_size = 25;
	// const int rows = 50;
	// const int cols = 100;

	int start_x = rand() % cols;
	int start_y = rand() % rows;

	int end_x = rand() % cols;
	int end_y = rand() % rows;

	// print out that information.
	cout << "tile size: " << tile_size << "px, rows: " << rows << ", cols: " << cols << endl;

	// create the array of the right size using the constants.
	int tiles[cols * rows];

	for(int i = 0; i < cols * rows; ++i)
		tiles[i] = 0;

	// create a tile map that will be used to display the array.
	TileMap map;

	AStar path_finder;

	// event loop that runs the window.
	while(window.isOpen()) {
		// create an event.
		sf::Event event;
		// check if an event has been triggered.
		while(window.pollEvent(event))
			// if the event is the window closing, close the window.
			if(event.type == sf::Event::Closed)
				window.close();

		// check if mouse buttons are prgetSizeessed.
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			// get the position of the mouse.
			sf::Vector2i mouse = sf::Mouse::getPosition(window);
			// set the tile colour to 1.
			tiles[(int)(mouse.x / tile_size) + cols * (int)(mouse.y / tile_size)] = 1;

			cout << (int)(mouse.y / tile_size) << " " << (int)(mouse.x / tile_size) << endl;
		} else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			sf::Vector2i mouse = sf::Mouse::getPosition(window);
			// set the tile colour to 2.
			tiles[(int)(mouse.x / tile_size) + cols * (int)(mouse.y / tile_size)] = 0;
		}

		for(int i = 0; i < cols * rows; ++i)
			if(tiles[i] != 1)
				tiles[i] = 0;

		// for(int i = 0; i < cols * rows; ++i)
		//  tiles[i] = 0;
		//
		// for(int i = 0; i < 1500; ++i)
		//  tiles[rand() % (cols * rows)] = 1;

		// start_x = rand() % cols;
		// start_y = rand() % rows;
		//
		// end_x = rand() % cols;
		// end_y = rand() % rows;

		tiles[start_y * cols + start_x] = 3;
		tiles[end_y * cols + end_x] = 2;

		path_finder.start_algorithm(tiles, cols, rows);

		tiles[start_y * cols + start_x] = 3;
		tiles[end_y * cols + end_x] = 2;

		// update tile map with the correct array.
		map.load("res/GridTileTexture5.png", sf::Vector2f(200, 200), sf::Vector2f(tile_size, tile_size), tiles, cols, rows);

		// clear the screen.
		window.clear(sf::Color(47, 47, 47));
		// draw the map onto the screen.
		window.draw(map);
		// display the window.
		window.display();
	}

	return 0;
}
