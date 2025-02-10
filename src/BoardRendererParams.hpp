#include <imgui.h>

struct BoardRendererParams {
    // Style
    ImVec2 ItemSpacing  = ImVec2(0, 0); // Horizontal and vertical spacing between items
    ImVec2 FramePadding = ImVec2(0, 0); // Padding within a framed rectangle (used by most widgets)

    ImVec4 TileColor1          = ImVec4(0.8, 0.8, 0.8, 1.0); // Color of the tiles
    ImVec4 TileColor2          = ImVec4(0.3, 0.3, 0.3, 1.0); // Color of the tiles
    ImVec4 TileSelectedColor   = ImVec4(0.5, 0.5, 0.5, 1.0); // Color of the selected tile
    ImVec4 TileSelectableColor = ImVec4(0.5, 0.5, 0.5, 1.0); // Color of the selectable tile

    ImVec4 TileHoveredColor           = ImVec4(0.5, 0.5, 0.5, 1.0); // Color of the hovered tile
    ImVec4 TileSelectableHoveredColor = ImVec4(0.5, 0.5, 0.5, 1.0); // Color of the hovered selectable tile

    ImVec4 PieceColor1 = ImVec4(0.0, 0.0, 0.0, 1.0); // Color of the pieces
    ImVec4 PieceColor2 = ImVec4(1.0, 1.0, 1.0, 1.0); // Color of the pieces
};