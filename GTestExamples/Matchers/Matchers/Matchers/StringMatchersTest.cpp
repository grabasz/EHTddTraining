#include "pch.h"
#include "gmock/gmock.h"
#include "DatabaseConnection.h"

using ::testing::ContainsRegex;
using ::testing::StrCaseEq;
using ::testing::HasSubstr;


TEST(TestCaseName, ShouldMatchLetters) {
	DatabaseConnectionMock databaseConnectionMock;
	ClassWithConnectionToDB classWithConnection(databaseConnectionMock);
	EXPECT_CALL(databaseConnectionMock, GetUserWithName(ContainsRegex("\\w.*"))/*word matcher*/);

	/*Should pass*/
	classWithConnection.PrintUserWithName("Bartek");
}

TEST(TestCaseName, ShouldMatchWithIgnoringCase) {
	DatabaseConnectionMock databaseConnectionMock;
	ClassWithConnectionToDB classWithConnection(databaseConnectionMock);
	EXPECT_CALL(databaseConnectionMock, GetUserWithName(StrCaseEq("bartek"))/*case insensitive matcher*/);

	/*Should pass*/
	classWithConnection.PrintUserWithName("Bartek");
}


TEST(TestCaseName, ShouldMatchWithSubstring) {
	DatabaseConnectionMock databaseConnectionMock;
	ClassWithConnectionToDB classWithConnection(databaseConnectionMock);
	EXPECT_CALL(databaseConnectionMock, GetUserWithName(HasSubstr("artek"))/*substring matcher*/);

	/*Should pass*/
	classWithConnection.PrintUserWithName("Bartek");
}