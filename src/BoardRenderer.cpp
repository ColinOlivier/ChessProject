#include "BoardRenderer.hpp"
#include <imgui.h>
#include <vcruntime_typeinfo.h>
#include <cstddef>
#include <string>
#include "Board.hpp"
#include "piece/PawnPiece.hpp"

void BoardRenderer::renderBoard(const Board& board) const
{
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
    for (size_t y{0}; y < 8; ++y)
    {
        for (size_t x{0}; x < 8; ++x)
        {
            // Color

            renderTile(board.getTile(x, y));

            ImGui::SameLine();
        }
        ImGui::NewLine();
    }
    ImGui::PopStyleVar(2);
}

void BoardRenderer::renderTile(const BoardTile& tile) const
{
    if (tile.x() % 2 == 0 && tile.y() % 2 == 1 || tile.x() % 2 == 1 && tile.y() % 2 == 0)
        ImGui::PushStyleColor(ImGuiCol_Button, boardColor1);
    else
        ImGui::PushStyleColor(ImGuiCol_Button, boardColor2);

    ImVec4 textColor{0.0, 0.0, 0.0, 1.0};
    if (tile.getPiece() != nullptr && tile.getPiece()->getPlayerColor() == PlayerColor::White)
        textColor = ImVec4(1.0, 1.0, 1.0, 1.0);

    ImGui::PushStyleColor(ImGuiCol_Text, textColor);

    if (ImGui::Button(tile.getLabel().c_str(), {100.0, 100.0}))
    {
        // Select the piece
    }
    ImGui::PopStyleColor(2);
}
