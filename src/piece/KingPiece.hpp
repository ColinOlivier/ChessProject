#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class KingPiece : public AbstractPiece {
public:
    KingPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}
    std::vector<BoardTile*> getPossibleMove() const;
};
