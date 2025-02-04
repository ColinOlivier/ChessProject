#pragma once

#include "AbstractPiece.hpp"
class QueenPiece : public AbstractPiece {
public:
    QueenPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}
};