#pragma once

#include <imgui.h>
#include <string>
#include "Board.hpp"
#include "BoardRendererParams.hpp"
#include "BoardTile.hpp"

class BoardRenderer {
private:
    BoardRendererParams params;
    ImVec4              boardColor1{0.9, 0.9, 0.7, 1.0};
    ImVec4              boardColor2{1.0, 0.5, 0.5, 1.0};

public:
    void renderBoard(const Board& board) const;
    void renderTile(const BoardTile& tile, bool isSelectable) const;

    std::string getPieceLabel(const AbstractPiece& piece) const;
};