#include "Board.hpp"

const BoardTile& Board::getTile(PositionTile position) const
{
    return getTile(position);
}

BoardTile& Board::getTile(PositionTile position)
{
    return getTile(position.x, position.y);
}

const BoardTile& Board::getTile(unsigned int x, unsigned int y) const
{
    return getTile(x, y);
}

BoardTile& Board::getTile(unsigned int x, unsigned int y)
{
    return m_tiles[x + y * 8];
}