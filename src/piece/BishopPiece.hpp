#pragma once

#include "AbstractPiece.hpp"
class BishopPiece : public AbstractPiece {
public:
    BishopPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}
};