#pragma once

struct PositionTile {
    unsigned int x;
    unsigned int y;

    PositionTile(); // default constructor
    PositionTile(unsigned int _x, unsigned int _y);

    bool operator==(const PositionTile& pos) const;

    bool isValid() const
    {
        return x >= 0 && y >= 0 && x < 8 && y < 8;
    }
};