#include "pch.h"
#include "Customer.h"
#include "Movie.h"

class CustomerTest : public testing::Test
{
	void SetUp() override
	{
	};

	void TearDown() override
	{
	};
};

TEST_F(CustomerTest, TestCustomer)
{
	Customer* c = new Customer;
	ASSERT_NE(nullptr, c);
	delete c;
}

TEST_F(CustomerTest, TestAddRental)
{
	Customer customer2 = Customer("Julia");
	Movie movie1 = Movie("Gone with the Wind", Movie::REGULAR);
	Rental rental1 = Rental(movie1, 3); // 3 day rental
	customer2.addRental(rental1);
}

TEST_F(CustomerTest, TestGetName)
{
	Customer c = Customer("David");
	ASSERT_EQ("David", c.getName());
}


TEST_F(CustomerTest, StatementForRegularMovie)
{
	Movie movie1 = Movie("Gone with the Wind", Movie::REGULAR);
	Rental rental1 = Rental(movie1, 3); // 3 day rental
	Customer customer2 = Customer("Sallie");
	customer2.addRental(rental1);

	std::string expected = "Rental Record for Sallie\n"
		"\tGone with the Wind\t3.5\n"
		"Amount owed is 3.5\n"
		"You earned 1 frequent renter points";
	const std::string statement = customer2.statement();
	ASSERT_EQ(expected, statement);
}

TEST_F(CustomerTest, StatementForNewReleaseMovie)
{
		Movie movie1 = Movie("Star Wars", Movie::NEW_RELEASE);
	Rental rental1 = Rental(movie1, 3); // 3 day rental
	Customer customer2 = Customer("Sallie");
	customer2.addRental(rental1);
		
	std::string expected = "Rental Record for Sallie\n"
		"\tStar Wars\t9\n"
		"Amount owed is 9\n"
		"You earned 2 frequent renter points";
	std::string statement = customer2.statement();

	ASSERT_EQ(expected, statement);
}


TEST_F(CustomerTest, StatementForChildrensMovie)
{
		Movie movie1 = Movie("Madagascar", Movie::CHILDRENS);
		Rental rental1 = Rental(movie1, 3); // 3 day rental
		Customer customer2 = Customer("Sallie");

		customer2.addRental(rental1);
			
		std::string expected = "Rental Record for Sallie\n"
			"\tMadagascar\t1.5\n"
			"Amount owed is 1.5\n"
			"You earned 1 frequent renter points";
		std::string statement = customer2.statement();

		ASSERT_EQ(expected, statement);
}

TEST_F(CustomerTest, StatementForManyMovies)
{
		Movie movie1 = Movie("Madagascar", Movie::CHILDRENS);
	Rental rental1 = Rental(movie1, 6); // 6 day rental
	Movie movie2 = Movie("Star Wars", Movie::NEW_RELEASE);
	Rental rental2 = Rental(movie2, 2); // 2 day rental
	Movie movie3 = Movie("Gone with the Wind", Movie::REGULAR);
	Rental rental3 = Rental(movie3, 8); // 8 day rental
	Customer customer1
		= Customer("David");
	customer1.addRental(rental1).
		addRental(rental2).
		addRental(rental3);

	std::string expected = "Rental Record for David\n"
		"\tMadagascar\t6\n"
		"\tStar Wars\t6\n"
		"\tGone with the Wind\t11\n"
		"Amount owed is 23\n"
		"You earned 4 frequent renter points";
	std::string statement = customer1.statement();
	ASSERT_EQ(expected, statement);

}
