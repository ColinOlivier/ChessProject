#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class PawnPiece : public AbstractPiece {
public:
    PawnPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}

    std::vector<BoardTile*> getPossibleMove() const override;
};
