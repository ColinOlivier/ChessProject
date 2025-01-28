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

protected:
    void       setTile(BoardTile* tile) { m_tilePtr = tile; }
    void       setPlayerColor(PlayerColor color) { m_playerColor = color; }
    BoardTile* getTile() const { return m_tilePtr; }

public:
    PlayerColor                     getPlayerColor() const { return m_playerColor; }
    virtual std::vector<BoardTile*> getPossibleMove();
};