#pragma once

#include "PositionTile.hpp"
#include "piece/AbstractPiece.hpp"

class Board;

class BoardTile {
    PositionTile   m_position;
    Board*         m_boardPtr;
    AbstractPiece* m_piecePtr;
};