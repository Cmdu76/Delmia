#ifndef NISOMETRIC_HPP
#define NISOMETRIC_HPP

#include "LayerComponent.hpp"

namespace NIsometric
{

class NLayerComponent : public ::NLayerComponent
{
    public:
        NLayerComponent(sf::Vector2i coords = sf::Vector2i(0,0));
        NLayerComponent(std::string const& textureName, sf::Vector2i coords = sf::Vector2i(0,0));
        NLayerComponent(std::string const& textureName, sf::Vector2i layerSize, sf::Vector2i tileSize, sf::Vector2i coords = sf::Vector2i(0,0));

        void create(std::string const& textureName, sf::Vector2i layerSize, sf::Vector2i tileSize);

        sf::FloatRect getBounds() const;
};

sf::Vector2i worldToCoords(sf::Vector2f const& pos);
sf::Vector2i worldToChunk(sf::Vector2f const& pos);
sf::Vector2i worldToRelative(sf::Vector2f const& pos);

sf::Vector2f coordsToWorld(sf::Vector2i const& coords); // center of the tile
sf::Vector2i coordsToChunk(sf::Vector2i const& coords);
sf::Vector2i coordsToRelative(sf::Vector2i const& coords);

std::vector<sf::Vector2i> getNeighboors(sf::Vector2i const& coords, bool diag = false);
std::vector<sf::Vector2i> pathfinding(sf::Vector2i const& begin, sf::Vector2i const& end);

void setTileSize(sf::Vector2i const& tileSize);
void setLayerSize(sf::Vector2i const& layerSize);
sf::Vector2i getTileSize();
sf::Vector2i getLayerSize();

} // namespace NIsometric

#endif // NISOMETRIC_HPP
