#pragma once

#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class BishopPiece : public AbstractPiece {
public:
    BishopPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}
    std::vector<BoardTile*> getPossibleMove() const;
};
