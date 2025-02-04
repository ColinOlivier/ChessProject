#include "Board.hpp"
#include <memory>
#include <stdexcept>
#include "BoardTile.hpp"
#include "PositionTile.hpp"
#include "piece/AbstractPiece.hpp"
#include "piece/KnightPiece.hpp"
#include "piece/PawnPiece.hpp"

void Board::initialize()
{
    for (size_t y{0}; y < 8; ++y)
    {
        for (size_t x{0}; x < 8; ++x)
        {
            m_tiles[x + y * 8] = BoardTile(*this, x, y);
        }
    }

    createPiece<PawnPiece>(PositionTile(1, 0), PlayerColor::White);
    createPiece<KnightPiece>(PositionTile(1, 2), PlayerColor::Black);
}

BoardTile& Board::getTile(PositionTile position)
{
    return getTile(position.x, position.y);
}

const BoardTile& Board::getTile(PositionTile position) const
{
    return getTile(position);
}

BoardTile& Board::getTile(unsigned int x, unsigned int y)
{
    return m_tiles[x + y * 8];
}

const BoardTile& Board::getTile(unsigned int x, unsigned int y) const
{
    return getTile(x, y);
}