#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class KnightPiece : public AbstractPiece {
public:
    KnightPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}
    std::string             getLabel() override { return "C"; };
    std::vector<BoardTile*> getPossibleMove() const;
};
