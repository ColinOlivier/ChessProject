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
    // Constructor
    BoardTile() = default;
    BoardTile(Board& board, unsigned int x, unsigned int y);

    // Getters
    unsigned int x() const { return m_position.x; };
    unsigned int y() const { return m_position.y; };

    AbstractPiece* getPiece() const { return m_piecePtr; }
    Board*         getBoard() const { return m_boardPtr; }
    PositionTile   getPosition() const { return m_position; };
    bool           isEmpty() const { return m_piecePtr == nullptr; }

    std::string getLabel() const;

    // Setters
    void setPiece(AbstractPiece& piece);
    void removePiece();
};