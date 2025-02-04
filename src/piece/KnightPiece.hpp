#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class KnightPiece : public AbstractPiece {
public:
    KnightPiece(PlayerColor color, BoardTile* startTile);

    std::vector<BoardTile*> getPossibleMove(Board* board);
};
