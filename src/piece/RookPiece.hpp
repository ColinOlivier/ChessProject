#pragma once

#include "AbstractPiece.hpp"
class RookPiece : public AbstractPiece {
public:
    RookPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}
};