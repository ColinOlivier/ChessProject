#include "App.hpp"
#include "Board.hpp"
#include "BoardRenderer.hpp"

App::App()
{
    m_chessboard = Board();
    m_chessboard.initialize();

    m_boardRenderer = BoardRenderer();
}

void App::render() const
{
    m_boardRenderer.renderBoard(m_chessboard);
}
