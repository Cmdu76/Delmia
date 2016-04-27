#include "Hall.hpp"

Hall::Hall()
{
    generateBuilding(0,0,sf::IntRect(0,0,256,256));
}

Hall::Hall(int x, int y)
{
    generateBuilding(x,y,sf::IntRect(0,0,256,256));
}

std::vector<sf::Vector2i> Hall::getTilesBlueprint(int x, int y)
{
    std::vector<sf::Vector2i> tiles;
    if (y % 2 == 0)
    {
        tiles.push_back(sf::Vector2i(x,y));
        tiles.push_back(sf::Vector2i(x,y-1));
        tiles.push_back(sf::Vector2i(x+1,y-2));
    }
    else
    {
        tiles.push_back(sf::Vector2i(x,y));
        tiles.push_back(sf::Vector2i(x+1,y-1));
        tiles.push_back(sf::Vector2i(x+1,y-2));
    }
    return tiles;
}

std::vector<sf::Vector2i> Hall::getTiles(int x, int y)
{
    return Hall::getTilesBlueprint(x,y);
}