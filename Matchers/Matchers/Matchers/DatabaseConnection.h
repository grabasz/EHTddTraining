#pragma once
#include <string>
#include "gmock/gmock.h"

class DatabaseConnection {
public:
	virtual std::string GetUserWithId(int id) = 0;
	virtual std::string GetUserWithName(std::string) = 0;
};

class DatabaseConnectionMock : public DatabaseConnection
{
public:
	MOCK_METHOD1(GetUserWithId, std::string(int));
	MOCK_METHOD1(GetUserWithName, std::string(std::string));
};

class ClassWithConnectionToDB
{
	DatabaseConnection& connection_;
public:

	ClassWithConnectionToDB(DatabaseConnection& connection);
	
	void PrintUserWithId(int id) const;
	void PrintUserWithName(std::string name) const;
};


