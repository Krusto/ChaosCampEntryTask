#include "BattleshipGame.hpp"
#include "Log.hpp"

#include <random>
#include <algorithm>

void BattleshipGame::Init(size_t width, size_t height, size_t numVessels, uint32_t vesselDetectionRange)
{
    m_BoardSize = {width, height};
    m_DetectionRange = vesselDetectionRange;
    m_NumVessels = numVessels;
    m_Vessels.resize(numVessels);

    GenerateVessels();

    Log("\n%zu %zu %zu %zu\n", m_BoardSize.x, m_BoardSize.y, m_NumVessels, m_DetectionRange);
}

void BattleshipGame::Run()
{
    Point point;
    scanf("%zu %zu", &point.x, &point.y);

    if (TryHitVessel(point))
    {
        if (ShouldExit()) { Log("Win!\n"); }
        return;
    }
    else
    {
        LinkedList<double> vesselDistances;
        size_t vesselsInRadius = 0;
        GetDistances(point, &vesselDistances, &vesselsInRadius);

        Log("Miss %zu ", vesselsInRadius);
        vesselDistances.ForEach([](const auto value) { Log("%.6f ", value); });
        Log("\n");

        vesselDistances.Destroy();
    }
}

bool BattleshipGame::ShouldExit() { return m_Vessels.size() == 0; }

void BattleshipGame::GenerateVessels()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> distributionX(0, m_BoardSize.x - 1);
    std::uniform_int_distribution<size_t> distributionY(0, m_BoardSize.y - 1);

    std::generate(m_Vessels.begin(), m_Vessels.end(), [&]() { return Point{distributionX(gen), distributionY(gen)}; });
}

bool BattleshipGame::TryHitVessel(const Point& point)
{
    auto hitIt = std::find(m_Vessels.begin(), m_Vessels.end(), point);

    if (hitIt != m_Vessels.end())
    {
        Log("Hit!\n");
        m_Vessels.erase(hitIt);
        return true;
    }

    return false;
}

void BattleshipGame::GetDistances(const Point& point, LinkedList<double>* distances, size_t* numVesselsInRadius)
{
    if (point.x >= m_BoardSize.x || point.y >= m_BoardSize.y) { return; }

    std::for_each(m_Vessels.begin(), m_Vessels.end(), [&](const auto vessel) {
        size_t distanceSquared = GetDistanceSquared(point, vessel);
        if (IsVesselInRange(distanceSquared))
        {
            distances->Insert(std::sqrt(distanceSquared));
            (*numVesselsInRadius)++;
        }
    });
}

size_t BattleshipGame::GetDistanceSquared(const Point& point, const Point& vessel) const
{
    return ((point.x - vessel.x) * (point.x - vessel.x) + (point.y - vessel.y) * (point.y - vessel.y));
}

bool BattleshipGame::IsVesselInRange(size_t distance) const { return distance <= m_DetectionRange * m_DetectionRange; }