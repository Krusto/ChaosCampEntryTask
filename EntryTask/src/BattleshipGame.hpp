#pragma once
#include <vector>
#include <cstdint>
#include "Point.hpp"
#include "LinkedList.hpp"

/**
 * A simple implementation of the Battleship game
 *
 * The game is played on a grid of size width x height, where width and height are
 * given as parameters to the Init method. The game is initialized with a number
 * of vessels, which are randomly placed on the board. The player can then try
 * to hit the vessels by guessing their coordinates. The game ends when all
 * vessels have been destroyed.
 */
class BattleshipGame
{
public:
    BattleshipGame() = default;
    ~BattleshipGame() = default;

public:
    /**
     * Initializes the game with the given parameters
     *
     * @param width Width of the board
     * @param height Height of the board
     * @param numVessels Number of vessels on the board
     * @param vesselDetectionRange Detection range of the vessels
     */
    void Init(size_t width, size_t height, size_t numVessels, uint32_t vesselDetectionRange);
    /**
     * Runs the main game loop, processing user input and updating the game state
     */
    void Run();
    /**
     * Checks if the game should exit, i.e. if all vessels have been destroyed
     *
     * @return true if the game should exit, false otherwise
     */
    bool ShouldExit();

private:
    void GenerateVessels();
    bool TryHitVessel(const Point& point);
    void GetDistances(const Point& point, LinkedList<double>* distances, size_t* numVesselsInRadius);
    size_t GetDistanceSquared(const Point& point, const Point& vessel) const;
    bool IsVesselInRange(size_t distance) const;

private:
    std::vector<Point> m_Vessels;
    Point m_BoardSize{};
    size_t m_NumVessels{};
    size_t m_DetectionRange{};
};