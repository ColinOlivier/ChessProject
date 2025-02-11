#include "BoardTile.hpp"
#include "PositionTile.hpp"

BoardTile::BoardTile(Board& board, unsigned int x, unsigned int y)
    : m_boardPtr(&board), m_piecePtr(nullptr)
{
    m_position = PositionTile(x, y);
}

std::string BoardTile::getLabel() const
{
    if (m_piecePtr == nullptr)
        return "##";
    return m_piecePtr->getLabel();
};

void BoardTile::setPiece(AbstractPiece& piece)
{
    m_piecePtr = &piece;
}

void BoardTile::removePiece()
{
    delete m_piecePtr;
    m_piecePtr = nullptr;
}
