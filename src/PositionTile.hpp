#pragma once

struct PositionTile {
    unsigned int x;
    unsigned int y;
    bool         isValide() const
    {
        return x >= 0 && y >= 0 && x < 8 && y < 8;
    }
};