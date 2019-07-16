#include "pch.h"
#include "Customer.h"
#include "Movie.h"

class CustomerTest : public testing::Test
{
public:
	std::shared_ptr<Customer> _customer;
	std::shared_ptr<Movie> _regularMovie ;
	std::shared_ptr<Movie> _newReleaseMovie ;
	std::shared_ptr<Movie> _childrenMovie ;
	void SetUp() override
	{
		_customer = std::make_shared<Customer>("Client");
		_regularMovie = std::make_shared<Movie>("Gone with the Wind", Movie::REGULAR);
		_newReleaseMovie = std::make_shared<Movie>("Star Wars", Movie::NEW_RELEASE);
		_childrenMovie = std::make_shared<Movie>("Madagascar", Movie::CHILDRENS);
	};

	void TearDown() override
	{
		_customer.reset();
		_regularMovie.reset();
		_newReleaseMovie.reset();
		_childrenMovie.reset();
	};
};

TEST_F(CustomerTest, TestCustomer)
{
	ASSERT_NE(nullptr, _customer.get());
}

TEST_F(CustomerTest, TestAddRental)
{
	Rental rental1 = Rental(*_regularMovie, 3); // 3 day rental
	_customer->addRental(rental1);
}

TEST_F(CustomerTest, TestGetName)
{
	ASSERT_EQ("Client", _customer->getName());
}

TEST_F(CustomerTest, StatementForRegularMovie)
{
	Rental rental1 = Rental(*_regularMovie, 3); // 3 day rental
	_customer->addRental(rental1);
	std::string expected = "Rental Record for Client\n"
		"\tGone with the Wind\t3.5\n"
		"Amount owed is 3.5\n"
		"You earned 1 frequent renter points";
	
	const std::string statement = _customer->statement();
	
	ASSERT_EQ(expected, statement);
}

TEST_F(CustomerTest, StatementForNewReleaseMovie)
{
	Rental rental1 = Rental(*_newReleaseMovie, 3); // 3 day rental
	_customer->addRental(rental1);
	std::string expected = "Rental Record for Client\n"
		"\tStar Wars\t9\n"
		"Amount owed is 9\n"
		"You earned 2 frequent renter points";
	
	std::string statement = _customer->statement();

	ASSERT_EQ(expected, statement);
}

TEST_F(CustomerTest, StatementForChildrensMovie)
{
		Rental rental1 = Rental(*_childrenMovie, 3); // 3 day rental
		_customer->addRental(rental1);
		std::string expected = "Rental Record for Client\n"
			"\tMadagascar\t1.5\n"
			"Amount owed is 1.5\n"
			"You earned 1 frequent renter points";

		std::string statement = _customer->statement();

		ASSERT_EQ(expected, statement);
}

TEST_F(CustomerTest, StatementForManyMovies)
{
	Rental rental1 = Rental(*_childrenMovie, 6); // 6 day 
	Rental rental2 = Rental(*_newReleaseMovie, 2); // 2 day rental
	Rental rental3 = Rental(*_regularMovie, 8); // 8 day rental
	
	_customer->addRental(rental1).
		addRental(rental2).
		addRental(rental3);

	std::string expected = "Rental Record for Client\n"
		"\tMadagascar\t6\n"
		"\tStar Wars\t6\n"
		"\tGone with the Wind\t11\n"
		"Amount owed is 23\n"
		"You earned 4 frequent renter points";
	std::string statement = _customer->statement();

	ASSERT_EQ(expected, statement);
}