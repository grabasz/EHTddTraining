#include "pch.h"

class FizzBuzz
{
public:
	std::string GetFizzBuzz(int input)
	{			
		if(input % 15 == 0)
		{
			return "FizzBuzz";
		}
		if (input % 5 == 0)
		{
			return "Buzz";
		}
		if (input % 3 == 0)
		{
			return "Fizz";
		}
    	return std::to_string(input);
	};
};

TEST(FizzBuzzTests, ShouldReturnFizzForThree)
{
	FizzBuzz fizzBuzz;
	std::string result = fizzBuzz.GetFizzBuzz(3);

	EXPECT_EQ("Fizz", result);	
}

TEST(FizzBuzzTests, ShouldReturnBuzzForFive)
{
	FizzBuzz fizzBuzz;
	std::string result = fizzBuzz.GetFizzBuzz(5);

	EXPECT_EQ("Buzz", result);
}

TEST(FizzBuzzTests, ShouldReturnBuzzForMultiForTen)
{
	FizzBuzz fizzBuzz;
	std::string result = fizzBuzz.GetFizzBuzz(10);

	EXPECT_EQ("Buzz", result);
}

TEST(FizzBuzzTests, ShouldReturnNumberFor13)
{
	FizzBuzz fizzBuzz;
	std::string result = fizzBuzz.GetFizzBuzz(13);

	EXPECT_EQ("13", result);
}

TEST(FizzBuzzTests, ShouldReturnNumberFor1)
{
	FizzBuzz fizzBuzz;
	std::string result = fizzBuzz.GetFizzBuzz(1);

	EXPECT_EQ("1", result);
}


TEST(FizzBuzzTests, ShouldReturnFizzBuzz15)
{
	FizzBuzz fizzBuzz;
	std::string result = fizzBuzz.GetFizzBuzz(15);

	EXPECT_EQ("FizzBuzz", result);
}

TEST(FizzBuzzTests, ShouldReturnFizzBuzz30)
{
	FizzBuzz fizzBuzz;
	std::string result = fizzBuzz.GetFizzBuzz(30);

	EXPECT_EQ("FizzBuzz", result);
}

TEST(FizzBuzzTests, ShouldReturnFizzBuzz20)
{
	FizzBuzz fizzBuzz;
	std::string result = fizzBuzz.GetFizzBuzz(20);

	EXPECT_EQ("Buzz", result);
}

TEST(FizzBuzzTests, ShouldReturnFizzBuzz6)
{
	FizzBuzz fizzBuzz;
	std::string result = fizzBuzz.GetFizzBuzz(6);

	EXPECT_EQ("Fizz", result);
}