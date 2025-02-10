#pragma once

#include <string>
#include "PositionTile.hpp"
#include "piece/AbstractPiece.hpp"

class Board;

class BoardTile {
    PositionTile   m_position;
    Board*         m_boardPtr;
    AbstractPiece* m_piecePtr;

public:
    AbstractPiece* getPiece() const { return m_piecePtr; }
    Board*         getBoard() const { return m_boardPtr; }
    BoardTile() = default;
    BoardTile(Board& board, unsigned int x, unsigned int y);

    PositionTile getPosition() const { return m_position; };
    unsigned int x() const { return m_position.x; };
    unsigned int y() const { return m_position.y; };

    std::string getLabel() const;

    void setPiece(AbstractPiece& piece);
    bool isEmpty() const { return m_piecePtr == nullptr; }
};