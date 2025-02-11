#include "Board.hpp"

Board::Board()
{
    for (unsigned int y = 0; y < 8; y++)
    {
        for (unsigned int x = 0; x < 8; x++)
        {
            getTile(x, y) = BoardTile(*this, x, y);
        }
    }
}

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
    return m_tiles[x + y * 8];
}

BoardTile& Board::getTile(unsigned int x, unsigned int y)
{
    return m_tiles[x + y * 8];
}

void Board::removePiece(PositionTile position)
{
    getTile(position).removePiece();
}