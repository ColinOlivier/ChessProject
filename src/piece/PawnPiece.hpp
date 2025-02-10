#pragma once

#include <string>
#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class PawnPiece : public AbstractPiece {
public:
    PawnPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}

    std::string             getLabel() override { return "P"; };
    std::vector<BoardTile*> getPossibleMove() const;
};
