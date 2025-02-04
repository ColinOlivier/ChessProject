#include "PositionTile.hpp"

PositionTile::PositionTile()
    : x(0), y(0) {}

PositionTile::PositionTile(unsigned int _x, unsigned int _y)
    : x(_x), y(_y) {}

bool PositionTile::operator==(const PositionTile& pos) const
{
    return x == pos.x && y == pos.y;
}

bool PositionTile::isValid() const
{
    return x >= 0 && x <= 7 && y >= 0 && y <= 7;
}
