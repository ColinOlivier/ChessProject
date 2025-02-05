#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class KnightPiece : public AbstractPiece {
public:
    KnightPiece(PlayerColor color, BoardTile* startTile)
    {
        setPlayerColor(color);
        setTile(startTile);
    }

    std::vector<BoardTile*> getPossibleMove(Board* board)
    {
        std::vector<BoardTile*> possibleMoves;

        // Récupérer la case actuelle
        BoardTile* currentTile = getTile();
        if (!currentTile || !board)
        {
            return possibleMoves; // Si la pièce n'est pas sur une case valide ou si le plateau est nul
        }

        PositionTile currentPos = currentTile->getPosition();
        unsigned int x          = currentPos.x;
        unsigned int y          = currentPos.y;

        // Liste des déplacements possibles pour un cavalier
        const std::vector<std::pair<int, int>> knightMoves = {
            {-2, -1}, {-2, 1}, // Mouvement vers le haut-gauche et haut-droite
            {2, -1},
            {2, 1}, // Mouvement vers le bas-gauche et bas-droite
            {-1, -2},
            {1, -2}, // Mouvement gauche-haut et gauche-bas
            {-1, 2},
            {1, 2} // Mouvement droite-haut et droite-bas
        };

        // Parcourir chaque déplacement
        for (const auto& move : knightMoves)
        {
            int newX = x + move.first;
            int newY = y + move.second;

            // Vérifier si la position est dans les limites du plateau
            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8)
            {
                BoardTile* targetTile = board->getTile(newX, newY);

                if (targetTile)
                {
                    AbstractPiece* targetPiece = targetTile->getPiece();

                    // Si la case est vide ou contient une pièce ennemie
                    if (!targetPiece || targetPiece->getPlayerColor() != getPlayerColor())
                    {
                        possibleMoves.push_back(targetTile);
                    }
                }
            }
        }

        return possibleMoves;
    }
};
