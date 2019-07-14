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

//[Test]
//public void TestGetName()
//{
//	Customer c = new Customer("David");
//	Assert.AreEqual("David", c.getName());
//}
//[Test]
//public void StatementForRegularMovie()
//{
//	Movie movie1 = new Movie("Gone with the Wind", Movie.REGULAR);
//	Rental rental1 = new Rental(movie1, 3); // 3 day rental
//	Customer customer2 =
//		new CustomerBuilder()
//		.withName("Sallie")
//		.withRentals(rental1)
//		.build();
//	string expected = "Rental Record for Sallie\n" +
//		"\tGone with the Wind\t3.5\n" +
//		"Amount owed is 3.5\n" +
//		"You earned 1 frequent renter points";
//	string statement = customer2.statement();
//	Assert.AreEqual(expected, statement);
//}
//
//[Test]
//public void StatementForNewReleaseMovie()
//{
//	Movie movie1 = new Movie("Star Wars", Movie.NEW_RELEASE);
//	Rental rental1 = new Rental(movie1, 3); // 3 day rental
//	Customer customer2 =
//		new CustomerBuilder()
//		.withName("Sallie")
//		.withRentals(rental1)
//		.build();
//	string expected = "Rental Record for Sallie\n" +
//		"\tStar Wars\t9\n" +
//		"Amount owed is 9\n" +
//		"You earned 2 frequent renter points";
//	string statement = customer2.statement();
//	Assert.AreEqual(expected, statement);
//}
//
//[Test]
//public void StatementForChildrensMovie()
//{
//	Movie movie1 = new Movie("Madagascar", Movie.CHILDRENS);
//	Rental rental1 = new Rental(movie1, 3); // 3 day rental
//	Customer customer2
//		= new CustomerBuilder()
//		.withName("Sallie")
//		.withRentals(rental1)
//		.build();
//	string expected = "Rental Record for Sallie\n" +
//		"\tMadagascar\t1.5\n" +
//		"Amount owed is 1.5\n" +
//		"You earned 1 frequent renter points";
//	string statement = customer2.statement();
//	Assert.AreEqual(expected, statement);
//}
//
//[Test]
//public void StatementForManyMovies()
//{
//	Movie movie1 = new Movie("Madagascar", Movie.CHILDRENS);
//	Rental rental1 = new Rental(movie1, 6); // 6 day rental
//	Movie movie2 = new Movie("Star Wars", Movie.NEW_RELEASE);
//	Rental rental2 = new Rental(movie2, 2); // 2 day rental
//	Movie movie3 = new Movie("Gone with the Wind", Movie.REGULAR);
//	Rental rental3 = new Rental(movie3, 8); // 8 day rental
//	Customer customer1
//		= new CustomerBuilder()
//		.withName("David")
//		.withRentals(rental1, rental2, rental3)
//		.build();
//	string expected = "Rental Record for David\n" +
//		"\tMadagascar\t6\n" +
//		"\tStar Wars\t6\n" +
//		"\tGone with the Wind\t11\n" +
//		"Amount owed is 23\n" +
//		"You earned 4 frequent renter points";
//	string statement = customer1.statement();
//	Assert.AreEqual(expected, statement);
//}
