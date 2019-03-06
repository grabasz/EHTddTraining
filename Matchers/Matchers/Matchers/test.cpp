#include "pch.h"
#include "gmock/gmock.h"

using ::testing::Gt;
using ::testing::_;


class DatabaseConnection {
public:
	virtual std::string GetUserWithId(int id) = 0;
};

class DatabaseConnectionMock : public DatabaseConnection
{
public:
	MOCK_METHOD1(GetUserWithId,std::string(int));
};

class ClassWithConnectionToDB
{
	DatabaseConnection& connection_;
public:

	ClassWithConnectionToDB(DatabaseConnection& connection): connection_(std::move(connection)) {}

	void PrintUserWithId(int id) const
	{
		std::string user = connection_.GetUserWithId(id);
	}
};


TEST(TestCaseName, ShouldFailFor9GreaterThan10) {
	DatabaseConnectionMock databaseConnectionMock;
	ClassWithConnectionToDB classWithConnection(databaseConnectionMock);
	EXPECT_CALL(databaseConnectionMock, GetUserWithId(Gt(10))/*MATCHER*/);

	/*Should fail*/
	classWithConnection.PrintUserWithId(9);
}

TEST(TestCaseName, ShouldPassForAnyTypeArgument) {
	DatabaseConnectionMock databaseConnectionMock;
	ClassWithConnectionToDB classWithConnection(databaseConnectionMock);
	EXPECT_CALL(databaseConnectionMock, GetUserWithId(_)/*ALWAYS MATCHING*/);

	/*Should pass*/
	classWithConnection.PrintUserWithId(9);
}