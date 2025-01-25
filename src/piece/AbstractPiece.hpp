#pragma once

#include <cstdint>
#include <vector>
#include "../PositionTile.hpp"

class BoardTile;

enum class PlayerColor : uint8_t {
    White,
    Black
};

class AbstractPiece {
    PlayerColor m_playerColor;
    BoardTile*  m_tilePtr;

public:
    PlayerColor  getPlayerColor() const;
    PositionTile getPosition() const;

    virtual std::vector<BoardTile*> getPossibleMove();
};