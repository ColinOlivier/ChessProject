#pragma once

#include <array>
#include <memory>
#include <stdexcept>
#include <vector>
#include "BoardTile.hpp"
#include "PositionTile.hpp"
#include "piece/AbstractPiece.hpp"

class Board {
    std::array<BoardTile, 64>                   m_tiles;
    std::vector<std::unique_ptr<AbstractPiece>> m_piecesPtr;

public:
    // Constructor
    Board();

    // Getters
    const BoardTile& getTile(PositionTile position) const;
    BoardTile&       getTile(PositionTile position);
    const BoardTile& getTile(unsigned int x, unsigned int y) const;
    BoardTile&       getTile(unsigned int x, unsigned int y);

    std::vector<AbstractPiece*> getPieces() const;
    std::vector<AbstractPiece*> getPieces(PlayerColor playerColor) const;

    AbstractPiece& getPiece(PositionTile position) const;
    AbstractPiece& getPiece(unsigned int x, unsigned int y) const;

    unsigned int getPieceCount() const;

    // Create a piece of type PieceType at the given position
    template<typename PieceType>
    void createPiece(PositionTile position, PlayerColor playerColor)
    {
        if (!position.isValid())
            throw std::runtime_error("Cannot create piece on an invalid position");

        if (!getTile(position).isEmpty())
            throw std::runtime_error("Cannot create piece on a non-empty tile");

        auto piece = std::make_unique<PieceType>(playerColor);
        piece->setTile(getTile(position));
        m_piecesPtr.push_back(std::move(piece));
    }

    // Remove the piece at the given position
    void removePiece(PositionTile position);
};