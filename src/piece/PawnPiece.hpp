#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class PawnPiece : public AbstractPiece {
public:
    PawnPiece(PlayerColor color, BoardTile* startTile);

    std::vector<BoardTile*> getPossibleMove(Board* board);
};
