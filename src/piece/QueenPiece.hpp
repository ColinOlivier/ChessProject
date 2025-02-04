#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class QueenPiece : public AbstractPiece {
public:
    QueenPiece(PlayerColor color, BoardTile* startTile);

    std::vector<BoardTile*> getPossibleMove(Board* board);
};
