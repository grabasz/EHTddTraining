#include "pch.h"

class Prime
{
public:
	bool isPrime(int i)
	{
		for (int index = 2; index < i; index++)
			if (i % index == 0)
				return false;
		
		return true;
	}
};

class PrimeTest: public ::testing::TestWithParam<int>
{};

class NotPrimeTest : public ::testing::TestWithParam<int>
{};


TEST_P(PrimeTest,ShoudNumberBePrime)
{
	Prime p;
	bool result = p.isPrime(GetParam());
	EXPECT_TRUE(result);
}

TEST_P(NotPrimeTest, ShoudNotNumberBePrime)
{
	Prime p;
	bool result = p.isPrime(GetParam());
	EXPECT_FALSE(result);
}

INSTANTIATE_TEST_CASE_P(Prime, PrimeTest, testing::Values(1, 2, 3, 5, 7));
INSTANTIATE_TEST_CASE_P(IsNotPrime, NotPrimeTest, testing::Values(4, 6, 8, 9, 10));