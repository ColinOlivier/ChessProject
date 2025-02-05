#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class KingPiece : public AbstractPiece {
public:
    std::vector<BoardTile*> getPossibleMove(Board* board);
};
