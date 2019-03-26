#pragma once
#include "WithVirtualMethod.h"
#include "gmock/gmock.h"

class WithVirtualMock : public WithVirtualMethod
{
public:
	MOCK_METHOD1(useDB, int(int input));
	MOCK_METHOD1(getUserName, std::string(int input));
};
