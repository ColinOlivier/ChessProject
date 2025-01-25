#pragma once

#include <cstdint>
class BoardTile;

enum class PlayerColor : uint8_t {
    White,
    Black
};

class AbstractPiece {
    PlayerColor m_playerColor;
    BoardTile*  m_tilePtr;
};