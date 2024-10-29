#pragma once
#include <cstdint>

struct Point {
    size_t x, y;

    bool operator==(const Point& other) const { return x == other.x && y == other.y; }

    bool operator!=(const Point& other) const { return x != other.x || y != other.y; }

    bool operator<(const Point& other) const
    {
        if (x == other.x) { return y < other.y; }
        return x < other.x;
    }

    bool operator>(const Point& other) const
    {
        if (x == other.x) { return y > other.y; }
        return x > other.x;
    }
};
