#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class BishopPiece : public AbstractPiece {
public:
    // Constructeur
    BishopPiece(PlayerColor color, BoardTile* startTile);
    // Méthode pour obtenir les mouvements possibles
    std::vector<BoardTile*> getPossibleMove(Board* board);
};
