#include "BattleshipGame.hpp"
#include <random>
#include <stdio.h>
#include <algorithm>
#include "LinkedList.hpp"

void BattleshipGame::Init(size_t width, size_t height, size_t numVessels, uint32_t vesselDetectionRange)
{
    m_BoardSize = {width, height};
    m_DetectionRange = vesselDetectionRange;
    m_NumVessels = numVessels;
    m_Vessels.reserve(numVessels);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distributionX(0, width - 1);
    std::uniform_int_distribution<> distributionY(0, height - 1);

    for (size_t i = 0; i < numVessels; i++)
    {
        size_t vesselX = distributionX(gen);
        size_t vesselY = distributionY(gen);

        m_Vessels.push_back({vesselX, vesselY});
    }
    printf("\n%zu %zu %zu %zu\n", m_BoardSize.x, m_BoardSize.y, m_NumVessels, m_DetectionRange);
}

void BattleshipGame::PrintMap()
{
    for (size_t y = 0; y < m_BoardSize.y; y++)
    {
        for (size_t x = 0; x < m_BoardSize.x; x++)
        {
            auto it = std::find(m_Vessels.begin(), m_Vessels.end(), Point{x, y});
            if (it != m_Vessels.end()) { printf("X"); }
            else { printf("."); }
        }
        printf("\n");
    }
}

bool BattleshipGame::Run()
{
    PrintMap();

    if (m_Vessels.size() == 0)
    {
        printf("Win!\n");
        return true;
    }

    Point point;
    scanf("%zu %zu", &point.x, &point.y);

    auto hitIt = std::find(m_Vessels.begin(), m_Vessels.end(), point);
    bool hit = hitIt != m_Vessels.end();

    if (hit)
    {
        printf("Hit!\n");
        m_Vessels.erase(hitIt);
        return 0;
    }

    size_t numVesselsInRadius = 0;
    LinkedList<double> vesselDistances;

    for (auto vessel: m_Vessels)
    {
        size_t distanceSquared = GetDistanceSquared(point, vessel);
        if (IsInRange(distanceSquared))
        {
            vesselDistances.Insert(std::sqrt(distanceSquared));
            numVesselsInRadius++;
        }
    }

    printf("Miss! %zu ", numVesselsInRadius);
    vesselDistances.Print();

    return false;
}

size_t BattleshipGame::GetDistanceSquared(const Point& point, const Point& vessel) const
{
    return ((point.x - vessel.x) * (point.x - vessel.x) + (point.y - vessel.y) * (point.y - vessel.y));
}

bool BattleshipGame::IsInRange(size_t distance) const { return distance <= m_DetectionRange * m_DetectionRange; }