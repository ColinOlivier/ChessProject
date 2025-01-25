#pragma once

#include <array>
#include <vector>
#include "BoardTile.hpp"
#include "piece/AbstractPiece.hpp"

class Board {
    std::array<BoardTile, 64>  m_tiles;
    std::vector<AbstractPiece> m_pieces;
};