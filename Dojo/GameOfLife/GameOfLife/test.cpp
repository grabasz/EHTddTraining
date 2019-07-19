#include "pch.h"

//RULES
//1. Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
//2. Any live cell with more than three live neighbours dies, as if by overcrowding.
//3. Any live cell with two or three live neighbours lives on to the next generation.
//4. Any dead cell with exactly three live neighbours becomes a live cell.

class Cell
{
public:
	Cell(bool isAlive): cellIsAlive(isAlive)
	{
	}

	bool getCellIsAlive()
	{
		return cellIsAlive;
	}

	bool IsAlive(int numberOfNeighbours)
	{
		if (!cellIsAlive)
		{
			return numberOfNeighbours == 3;
		}

		return numberOfNeighbours < 4 && numberOfNeighbours > 1;
	}

private:
	bool cellIsAlive;
};

TEST(GameOfLifeTests, ShouldCellNotBeAliveForOneNeighbour)
{
	Cell c(false);
	auto result = c.IsAlive(1);

EXPECT_FALSE(result);
}

TEST(GameOfLifeTests, ShouldCellWillBeAliveForTwoNeighbours)
{
	Cell c(true);
	
	auto result = c.IsAlive(2);

EXPECT_TRUE(result);
}

TEST(GameOfLifeTests, ShouldCellBeDeadWhenIsAlreadyDeadWithTwoNeighbours)
{
	Cell c(false);
	auto result = c.IsAlive(2);

EXPECT_FALSE(result);
}

TEST(GameOfLifeTests, ShouldCellBeDeadWhenAlreadyDeadFourNeighbours)
{
	Cell c(false);
	auto result = c.IsAlive(4);

EXPECT_FALSE(result);
}


TEST(GameOfLifeTests, ShouldCellBeDeadWhenAlreadyAliveFourNeighbours)
{
	Cell c(true);
	const auto result = c.IsAlive(4);

EXPECT_FALSE(result);
}
