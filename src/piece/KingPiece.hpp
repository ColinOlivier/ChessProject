#pragma once

#include "AbstractPiece.hpp"
class KingPiece : public AbstractPiece {
public:
    KingPiece(PlayerColor playerColor)
        : AbstractPiece(playerColor) {}
};