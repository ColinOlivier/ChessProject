#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class BishopPiece : public AbstractPiece {
public:
    std::vector<BoardTile*> getPossibleMove() const override;
};
