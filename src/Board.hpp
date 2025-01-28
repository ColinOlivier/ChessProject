#pragma once

#include <array>
#include <vector>
#include "BoardTile.hpp"
#include "PositionTile.hpp"
#include "piece/AbstractPiece.hpp"

class Board {
    std::array<BoardTile, 64>  m_tiles;
    std::vector<AbstractPiece> m_pieces;

public:
    BoardTile* getTile(PositionTile position) const;
    BoardTile* getTile(unsigned int x, unsigned int y) const;

    std::vector<AbstractPiece*> getPieces() const;
    std::vector<AbstractPiece*> getPieces(PlayerColor playerColor) const;

    AbstractPiece* getPiece(PositionTile position) const;
    AbstractPiece* getPiece(unsigned int x, unsigned int y) const;

    unsigned int getPieceCount() const;
};