#include "AbstractPiece.hpp"
#include "BoardTile.hpp"
#include "PositionTile.hpp"

AbstractPiece::AbstractPiece(PlayerColor playerColor)
    : m_playerColor(playerColor)
{}

PositionTile AbstractPiece::getPosition()
{
    return m_tilePtr->getPosition();
}

void AbstractPiece::setTile(BoardTile& tile)
{
    m_tilePtr = &tile;
    tile.setPiece(*this);
}