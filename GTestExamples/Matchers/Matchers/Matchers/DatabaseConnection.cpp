
#include <string>
#include "DatabaseConnection.h"

ClassWithConnectionToDB::ClassWithConnectionToDB(DatabaseConnection& connection) : connection_(connection)
{
}

void ClassWithConnectionToDB::PrintUserWithId(int id) const
{
	std::string user = connection_.GetUserWithId(id);
}

void ClassWithConnectionToDB::PrintUserWithName(std::string name) const
{
	std::string user = connection_.GetUserWithName(name);
}