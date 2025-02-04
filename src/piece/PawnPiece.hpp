#pragma once

#include <string>
#include "AbstractPiece.hpp"
class PawnPiece : public AbstractPiece {
public:
    PawnPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}

    std::string getLabel() override { return "P"; };
};
