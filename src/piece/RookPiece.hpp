#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class RookPiece : public AbstractPiece {
public:
    std::vector<BoardTile*> getPossibleMove() const override;
};