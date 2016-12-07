#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

#include <string>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    TileMap();
    ~TileMap();

    bool load(const std::string& txt_file, const sf::Vector2f& txt_size,
              const sf::Vector2f& tile_size, const int* tiles,
              unsigned int width, unsigned int height);
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_texture;
};

#endif
