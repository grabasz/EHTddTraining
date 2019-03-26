#pragma once

class WithVirtualMethod
{
public:
	virtual int useDB(int input)
	{
		return 3 * input;
	}

	virtual std::string getUserName(int input)
	{
		return "UserName";
	}
};