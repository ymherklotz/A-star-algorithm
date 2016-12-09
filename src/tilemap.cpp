#include "tilemap.hpp"

TileMap::TileMap() {
}

bool TileMap::load(const std::string& txt_file, const sf::Vector2f& txt_size, const sf::Vector2f& tile_size, const int *tiles, unsigned int width, unsigned int height) {
	// load texture from the file
	if(!m_texture.loadFromFile(txt_file))
		return false;

	// set the sizes and type of the vertex array.
	m_vertices.setPrimitiveType(sf::Quads);
	// multiply it by 4 because a square has 4 vertices.
	m_vertices.resize(width * height * 4);

	// go through the array and make vertices.
	for(unsigned int i = 0; i < width; ++i)
		for(unsigned int j = 0; j < height; ++j) {
			// get the colour of the tile
			int tile_number = tiles[i + j * width];

			// get pointer to vertex of current quad.
			sf::Vertex *quad = &m_vertices[(i + j * width) * 4];

			// define the quads.
			quad[0].position = sf::Vector2f(i * tile_size.x, j * tile_size.y);
			quad[1].position = sf::Vector2f((i + 1) * tile_size.x, j * tile_size.y);
			quad[2].position = sf::Vector2f((i + 1) * tile_size.x, (j + 1) * tile_size.y);
			quad[3].position = sf::Vector2f(i * tile_size.x, (j + 1) * tile_size.y);

			// define texture coordinates.
			quad[0].texCoords = sf::Vector2f(tile_number * txt_size.x, 0);
			quad[1].texCoords = sf::Vector2f((tile_number + 1) * txt_size.x, 0);
			quad[2].texCoords = sf::Vector2f((tile_number + 1) * txt_size.x, txt_size.y);
			quad[3].texCoords = sf::Vector2f(tile_number * txt_size.x, txt_size.y);
		}
	return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	// get the transform and set it to the states.
	states.transform = getTransform();
	// assign it the texture as well.
	states.texture = &m_texture;

	// draw the vertices with the transforms and textures.
	target.draw(m_vertices, states);
}
