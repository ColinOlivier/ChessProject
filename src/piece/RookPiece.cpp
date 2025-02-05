#include "RookPiece.hpp"

std::vector<BoardTile*> RookPiece::getPossibleMove(Board* board)
{
    std::vector<BoardTile*> possibleMoves;

    // Récupérer la case actuelle
    BoardTile* currentTile = getTile();
    if (!currentTile || !board)
    {
        return possibleMoves; // Si la tour n'est pas sur une case valide ou si le plateau est nul
    }

    PositionTile currentPos = currentTile->getPosition();
    unsigned int x          = currentPos.x;
    unsigned int y          = currentPos.y;

    // direction gauche
    for (unsigned int i = x - 1; i < 8; --i)
    {
        BoardTile& leftTile = board->getTile(i, y);
        if (leftTile.getPiece() == nullptr)
        {
            possibleMoves.push_back(&leftTile); // Case vide
        }
        else if (leftTile.getPiece()->getPlayerColor() != getPlayerColor())
        {
            possibleMoves.push_back(&leftTile); // Case occupée par une pièce adverse
            break;                              // La pièce adverse est capturée, on s'arrête ici
        }
        else
        {
            break; // La case est occupée par une pièce alliée, on arrête
        }
    }

    // direction droite
    for (unsigned int i = x - 1; i < 8; ++i)
    {
        BoardTile& rightTile = board->getTile(i, y);
        if (rightTile.getPiece() == nullptr)
        {
            possibleMoves.push_back(&rightTile); // Case vide
        }
        else if (rightTile.getPiece()->getPlayerColor() != getPlayerColor())
        {
            possibleMoves.push_back(&rightTile); // Case occupée par une pièce adverse
            break;                               // La pièce adverse est capturée, on s'arrête ici
        }
        else
        {
            break; // La case est occupée par une pièce alliée, on arrête
        }
    }

    // direction haut
    for (unsigned int j = y - 1; j < 8; --j)
    {
        BoardTile& topTile = board->getTile(x, j);
        if (topTile.getPiece() == nullptr)
        {
            possibleMoves.push_back(&topTile); // Case vide
        }
        else if (topTile.getPiece()->getPlayerColor() != getPlayerColor())
        {
            possibleMoves.push_back(&topTile); // Case occupée par une pièce adverse
            break;                             // La pièce adverse est capturée, on s'arrête ici
        }
        else
        {
            break; // La case est occupée par une pièce alliée, on arrête
        }
    }

    // direction bas
    for (unsigned int j = y - 1; j < 8; ++j)
    {
        BoardTile& bottomTile = board->getTile(x, j);
        if (bottomTile.getPiece() == nullptr)
        {
            possibleMoves.push_back(&bottomTile); // Case vide
        }
        else if (bottomTile.getPiece()->getPlayerColor() != getPlayerColor())
        {
            possibleMoves.push_back(&bottomTile); // Case occupée par une pièce adverse
            break;                                // La pièce adverse est capturée, on s'arrête ici
        }
        else
        {
            break; // La case est occupée par une pièce alliée, on arrête
        }
    }

    return possibleMoves;
};