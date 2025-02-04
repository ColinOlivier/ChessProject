#pragma once

#include <imgui.h>
#include <string>
#include "Board.hpp"
#include "BoardTile.hpp"

class BoardRenderer {
public:
    void renderBoard(const Board& board) const;
    void renderTile(const BoardTile& tile) const;

    std::string getPieceLabel(const AbstractPiece& piece) const;
};