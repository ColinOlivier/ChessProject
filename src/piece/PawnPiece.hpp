#pragma once

#include "../Board.hpp"
#include "../BoardTile.hpp"
#include "AbstractPiece.hpp"

class PawnPiece : public AbstractPiece {
public:
    PawnPiece(PlayerColor color, BoardTile* startTile)
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
            return possibleMoves; // Si le pion n'est pas sur une case valide ou si le plateau est nul
        }

        PositionTile currentPos = currentTile->getPosition();
        unsigned int x          = currentPos.x;
        unsigned int y          = currentPos.y;

        int direction = (getPlayerColor() == PlayerColor::White) ? 1 : -1;

        // Avancer d'une case
        BoardTile* oneStepAhead = board->getTile(x, y + direction);
        if (oneStepAhead && oneStepAhead->getPiece() == nullptr) // vérifie si la case devant est vide
        {
            possibleMoves.push_back(oneStepAhead); // ajoute la case concernée dans le tableau des cases valides

            // Avancer de deux cases si c'est le premier mouvement
            if ((getPlayerColor() == PlayerColor::White && y == 1) || (getPlayerColor() == PlayerColor::Black && y == 6))
            {
                BoardTile* twoStepsAhead = board->getTile(x, y + 2 * direction);
                if (twoStepsAhead && twoStepsAhead->getPiece() == nullptr)
                {
                    possibleMoves.push_back(twoStepsAhead);
                }
            }
        }

        // Captures diagonales
        BoardTile* leftDiagonal  = board->getTile(x - 1, y + direction);
        BoardTile* rightDiagonal = board->getTile(x + 1, y + direction);

        if (leftDiagonal && leftDiagonal->getPiece() && leftDiagonal->getPiece()->getPlayerColor() != getPlayerColor()) // vérifie que le pion à catpurer n'est pas de la meme couleur, que la case est valide et qu'elle contient une pièce
        {
            possibleMoves.push_back(leftDiagonal);
        }

        if (rightDiagonal && rightDiagonal->getPiece() && rightDiagonal->getPiece()->getPlayerColor() != getPlayerColor())
        {
            possibleMoves.push_back(rightDiagonal);
        }

        return possibleMoves;
    }
};
