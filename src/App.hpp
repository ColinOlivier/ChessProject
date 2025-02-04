#pragma once

#include "Board.hpp"
#include "BoardRenderer.hpp"

class App {
    Board         m_chessboard;
    BoardRenderer m_boardRenderer;

public:
    App();

    void render() const;
};