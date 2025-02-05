#include "KingPiece.hpp"
#include <vector>
#include "BoardTile.hpp"

std::vector<BoardTile*> KingPiece::getPossibleMove(Board* board)
{
    std::vector<BoardTile*> possibleMoves;

    // Récupérer la case actuelle
    BoardTile* currentTile = getTile();
    if (!currentTile || !board)
    {
        return possibleMoves; // Si le roi n'est pas sur une case valide ou si le plateau est nul
    }

    PositionTile currentPos = currentTile->getPosition();
    int          x          = currentPos.x;
    int          y          = currentPos.y;

    // Toutes les directions possibles pour un roi
    const std::vector<std::pair<int, int>> directions = {
        {-1, -1}, // Haut gauche
        {-1, 0},  // Haut
        {-1, 1},  // Haut droite
        {0, -1},  // Gauche
        {0, 1},   // Droite
        {1, -1},  // Bas gauche
        {1, 0},   // Bas
        {1, 1}    // Bas droite
    };

    // Parcourir toutes les directions
    for (const auto& dir : directions)
    {
        int newX = x + dir.first;
        int newY = y + dir.second;

        // Vérifier si la position est dans les limites du plateau
        if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8)
        {
            BoardTile& targetTile = board->getTile(newX, newY);

            AbstractPiece* targetPiece = targetTile.getPiece();

            // Si la case est vide ou contient une pièce ennemie
            if (!targetPiece || targetPiece->getPlayerColor() != getPlayerColor())
            {
                possibleMoves.push_back(&targetTile);
            }
        }
    }

    return possibleMoves;
}