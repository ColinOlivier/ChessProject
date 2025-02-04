#include "QueenPiece.hpp"

QueenPiece::QueenPiece(PlayerColor color, BoardTile* startTile)
{
    setPlayerColor(color);
    setTile(startTile);
}

std::vector<BoardTile*> QueenPiece::getPossibleMove(Board* board)
{
    std::vector<BoardTile*> possibleMoves;

    // Récupérer la case actuelle
    BoardTile* currentTile = getTile();
    if (!currentTile || !board)
    {
        return possibleMoves; // Si la reine n'est pas sur une case valide ou si le plateau est nul
    }

    PositionTile currentPos = currentTile->getPosition();
    int          x          = currentPos.x;
    int          y          = currentPos.y;

    // Liste des directions : diagonales + orthogonales
    const std::vector<std::pair<int, int>> directions = {
        {-1, -1}, // Haut-gauche
        {-1, 1},  // Haut-droite
        {1, -1},  // Bas-gauche
        {1, 1},   // Bas-droite
        {-1, 0},  // Gauche
        {1, 0},   // Droite
        {0, -1},  // Haut
        {0, 1}    // Bas
    };

    // Parcourir chaque direction
    for (const auto& dir : directions)
    {
        int dx = dir.first;
        int dy = dir.second;

        int newX = x + dx;
        int newY = y + dy;

        // Parcourir dans une direction jusqu'à atteindre une limite ou une pièce
        while (newX >= 0 && newX < 8 && newY >= 0 && newY < 8)
        {
            BoardTile* targetTile = board->getTile(newX, newY);
            if (!targetTile)
            {
                break; // Case invalide
            }

            AbstractPiece* targetPiece = targetTile->getPiece();
            if (!targetPiece)
            {
                possibleMoves.push_back(targetTile); // Case vide
            }
            else
            {
                // Si la case contient une pièce adverse
                if (targetPiece->getPlayerColor() != getPlayerColor())
                {
                    possibleMoves.push_back(targetTile);
                }
                break; // On ne peut pas sauter par-dessus une pièce
            }

            // Avancer dans la direction
            newX += dx;
            newY += dy;
        }
    }

    return possibleMoves;
}
