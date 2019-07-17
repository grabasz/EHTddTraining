#include "pch.h"

//RULES
//1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
//2. Any live cell with more than three live neighbours dies, as if by overcrowding.
//3. Any live cell with two or three live neighbours lives on to the next generation.
//4. Any dead cell with exactly three live neighbours becomes a live cell.

class Cell
{
private:
	bool isAlive;
public:
	void setCurrentState(bool b)
	{
		isAlive = b;
	}

	bool IsAliveInNextGeneration(int neighbours)
	{
		return (isAlive && neighbours == 2) || neighbours == 3;
	}
};

TEST(GameOfLifeTests, ShouldBeDeadFor0Neighbours)
{
	Cell c;
	bool isAlive = c.IsAliveInNextGeneration(0);
	EXPECT_FALSE(isAlive);
}

TEST(GameOfLifeTests, ShouldBeDeadFor1Neighbours)
{
	Cell c;
	bool isAlive = c.IsAliveInNextGeneration(1);
	EXPECT_FALSE(isAlive);
}

TEST(GameOfLifeTests, ShouldBeDeadFor2NeighboursIfPreviouslyWasDead)
{
	Cell c;
	c.setCurrentState(false);
	bool isAlive = c.IsAliveInNextGeneration(2);
	EXPECT_FALSE(isAlive);
}

TEST(GameOfLifeTests, ShouldBeAliveFor2NeighboursIfPreviouslyWasAlive)
{
	Cell c;
	c.setCurrentState(true);
	bool isAlive = c.IsAliveInNextGeneration(2);
	EXPECT_TRUE(isAlive);
}

TEST(GameOfLifeTests, ShouldBeAliveFor3NeighboursIfPreviouslyWasDead)
{
	Cell c;
	c.setCurrentState(false);
	bool isAlive = c.IsAliveInNextGeneration(3);
	EXPECT_TRUE(isAlive);
}

TEST(GameOfLifeTests, ShouldBeAliveFor3NeighboursIfPreviouslyWasAlive)
{
	Cell c;
	c.setCurrentState(true);
	bool isAlive = c.IsAliveInNextGeneration(3);
	EXPECT_TRUE(isAlive);
}

TEST(GameOfLifeTests, ShouldBeDeadFor4NeighboursIfPreviouslyWasDead)
{
	Cell c;
	c.setCurrentState(false);
	bool isAlive = c.IsAliveInNextGeneration(4);
	EXPECT_FALSE(isAlive);
}

TEST(GameOfLifeTests, ShouldBeDeadFor4NeighboursIfPreviouslyWasAlive)
{
	Cell c;
	c.setCurrentState(true);
	bool isAlive = c.IsAliveInNextGeneration(4);
	EXPECT_FALSE(isAlive);
}
