#pragma once

#include <array>
#include <memory>
#include <stdexcept>
#include <vector>
#include "BoardTile.hpp"
#include "PositionTile.hpp"
#include "piece/AbstractPiece.hpp"

class Board {
    std::array<BoardTile, 64>                   m_tiles;
    std::vector<std::unique_ptr<AbstractPiece>> m_piecesPtr;

public:
    void initialize();

    const BoardTile& getTile(PositionTile position) const;
    BoardTile&       getTile(PositionTile position);
    const BoardTile& getTile(unsigned int x, unsigned int y) const;
    BoardTile&       getTile(unsigned int x, unsigned int y);

    std::vector<AbstractPiece*> getPieces() const;
    std::vector<AbstractPiece*> getPieces(PlayerColor playerColor) const;

    AbstractPiece& getPiece(PositionTile position) const;
    AbstractPiece& getPiece(unsigned int x, unsigned int y) const;

    unsigned int getPieceCount() const;
};