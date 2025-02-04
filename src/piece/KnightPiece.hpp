#pragma once

#include "AbstractPiece.hpp"
class KnightPiece : public AbstractPiece {
public:
    KnightPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}
    std::string getLabel() override { return "C"; };
};