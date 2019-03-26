#include "WithVirtualMethod.h"

class ClassWithDependency
{
private:
	WithVirtualMethod* withVirtualMethod;
public:
	ClassWithDependency(WithVirtualMethod* withvirtual) : withVirtualMethod(withvirtual) {}

	int doSomething(int input)
	{
		return 2 * withVirtualMethod->useDB(input);
	}

	std::string unintrestingCall(int input)
	{
		return  withVirtualMethod->getUserName(input);
	}

};
