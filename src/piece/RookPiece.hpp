#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class RookPiece : public AbstractPiece {
public:
    RookPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}
    std::vector<BoardTile*> getPossibleMove() const;
};