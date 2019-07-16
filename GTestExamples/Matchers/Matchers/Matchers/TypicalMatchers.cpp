#include "pch.h"
#include "gmock/gmock.h"
#include "DatabaseConnection.h"

using ::testing::Gt;
using ::testing::_;

TEST(TestCaseName, ShouldFailFor9GreaterThan10) {
	DatabaseConnectionMock databaseConnectionMock;
	ClassWithConnectionToDB classWithConnection(databaseConnectionMock);
	ON_CALL(databaseConnectionMock, GetUserWithId(_)).WillByDefault(testing::Return("User"));
	EXPECT_CALL(databaseConnectionMock, GetUserWithId(Gt(10))/*greater then 10*/);

	classWithConnection.PrintUserWithId(11);
}

TEST(TestCaseName, ShouldPassForAnyTypeArgument) {
	DatabaseConnectionMock databaseConnectionMock;
	ClassWithConnectionToDB classWithConnection(databaseConnectionMock);
	EXPECT_CALL(databaseConnectionMock, GetUserWithId(_)/*ALWAYS MATCHING*/).WillRepeatedly(testing::Return("User"));
	
	classWithConnection.PrintUserWithId(1);
	classWithConnection.PrintUserWithId(2);
}