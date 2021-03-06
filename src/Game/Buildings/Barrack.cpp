#include "Barrack.hpp"

Barrack::Barrack() : Building()
{
    mType = Buildings::Barrack;
}

Barrack::Barrack(Player* player, sf::Vector2i const& coords) : Building(player, coords)
{
    mType = Buildings::Barrack;
    generate();
}

std::vector<sf::Vector2i> Barrack::getTilesBlueprint(sf::Vector2i const& coords)
{
    std::vector<sf::Vector2i> tiles;
    if (coords.y % 2 == 0)
    {
        tiles.push_back(coords);
        tiles.push_back(coords + sf::Vector2i(0,-1));
        tiles.push_back(coords + sf::Vector2i(-1,1));
        tiles.push_back(coords + sf::Vector2i(1,0));
    }
    else
    {
        tiles.push_back(coords);
        tiles.push_back(coords + sf::Vector2i(1,-1));
        tiles.push_back(coords + sf::Vector2i(0,1));
        tiles.push_back(coords + sf::Vector2i(1,0));
    }
    return tiles;
}

std::vector<std::pair<sf::Vector2i,sf::IntRect>> Barrack::getTiles(sf::Vector2i const& coords)
{
    std::vector<sf::Vector2i> tilesBP = Barrack::getTilesBlueprint(coords);
    std::vector<std::pair<sf::Vector2i,sf::IntRect>> tiles;
    for (std::size_t i = 0; i < tilesBP.size(); i++)
    {
        tiles.emplace_back();
        tiles.back().first = tilesBP[i];
    }
    for (std::size_t i = 0; i < tiles.size(); i++)
    {
        tiles[i].second = sf::IntRect(1280,0,256,256);
    }
    return tiles;
}
