#include "BoardRenderer.hpp"
#include <imgui.h>
#include <vcruntime_typeinfo.h>
#include <cstddef>
#include <string>
#include "Board.hpp"

void BoardRenderer::renderBoard(const Board& board) const
{
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, params.ItemSpacing);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, params.FramePadding);
    for (size_t y{0}; y < 8; ++y)
    {
        for (size_t x{0}; x < 8; ++x)
        {
            // Color
            renderTile(board.getTile(x, y), false);

            ImGui::SameLine();
        }
        ImGui::NewLine();
    }
    ImGui::PopStyleVar(2);
}

void BoardRenderer::renderTile(const BoardTile& tile, bool isSelectable) const
{
    if (isSelectable)
        ImGui::PushStyleColor(ImGuiCol_Button, params.TileSelectableColor);
    else if (tile.x() % 2 == 0 && tile.y() % 2 == 1 || tile.x() % 2 == 1 && tile.y() % 2 == 0)
        ImGui::PushStyleColor(ImGuiCol_Button, params.TileColor1);
    else
        ImGui ::PushStyleColor(ImGuiCol_Button, params.TileColor2);

    if (tile.getPiece() != nullptr && tile.getPiece()->getPlayerColor() == PlayerColor::White)
        ImGui::PushStyleColor(ImGuiCol_Text, params.PieceColor1);
    else
        ImGui::PushStyleColor(ImGuiCol_Text, params.PieceColor2);

    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, params.TileHoveredColor);

    if (ImGui::Button(tile.getLabel().c_str(), {100.0, 100.0}))
    {
        // Select the piece
    }
    ImGui::PopStyleColor(3);
}
