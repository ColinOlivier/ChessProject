#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class QueenPiece : public AbstractPiece {
public:
    QueenPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}

public:
    std::vector<BoardTile*> getPossibleMove() const;
};
