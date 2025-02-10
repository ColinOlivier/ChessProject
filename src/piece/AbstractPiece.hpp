#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "PositionTile.hpp"

class BoardTile;

enum class PlayerColor : uint8_t {
    White,
    Black
};

class AbstractPiece {
protected:
    PlayerColor m_playerColor{PlayerColor::White};
    BoardTile*  m_tilePtr{};

public:
    AbstractPiece() = delete;
    void       setTile(BoardTile* tile) { m_tilePtr = tile; }
    void       setPlayerColor(PlayerColor color) { m_playerColor = color; }
    BoardTile* getTile() const { return m_tilePtr; }
    AbstractPiece(PlayerColor playerColor);
    virtual std::string getLabel() { return "A"; };
    PlayerColor         getPlayerColor() const { return m_playerColor; };
    PositionTile        getPosition();

    void setTile(BoardTile& tile);

    std::vector<BoardTile*> getPossibleMove();
};
