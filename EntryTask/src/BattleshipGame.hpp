#pragma once
#include <vector>
#include <cstdint>
#include "Point.hpp"

// #include "KDTree.hpp"

class BattleshipGame
{
public:
    BattleshipGame() = default;
    ~BattleshipGame() = default;

    void Init(size_t width, size_t height, size_t numVessels, uint32_t vesselDetectionRange);
    bool Run();

    void PrintMap();

private:
    size_t GetDistanceSquared(const Point& point, const Point& vessel) const;
    bool IsInRange(size_t distance) const;

    std::vector<Point> m_Vessels;

    Point m_BoardSize{};
    size_t m_NumVessels{};
    size_t m_DetectionRange{};
};