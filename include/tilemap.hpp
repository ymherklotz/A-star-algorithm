// Tile map class that creates vertices to form a grid full of
// squares and adds texture to it.

#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

#include <string>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
	TileMap();

	// loads the text file and then creates the vertex array and the assigns
	// the texture to the vertex array. It also therefore defines the size
	// of the grid.
	bool load(const std::string& txt_file, const sf::Vector2f& txt_size, const sf::Vector2f& tile_size, const int *tiles, unsigned int width, unsigned int height);
private:
	// private function draw that overwrites the draw function in the
	// Drawable function. This draws all the vertices to the window.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	// vertex array that contains all the vertices.
	sf::VertexArray m_vertices;
	// texture that will be loaded onto the vertices. This will be associated
	// to the vertices.
	sf::Texture m_texture;
};

#endif
