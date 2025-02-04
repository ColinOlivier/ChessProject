#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class RookPiece : public AbstractPiece {
    RookPiece(PlayerColor color, BoardTile* startTile);
    std::vector<BoardTile*> getPossibleMove(Board* board);
};