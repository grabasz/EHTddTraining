#include "pch.h"
#include "gmock/gmock.h"

class NumberCreator
{
public:
	virtual std::shared_ptr<int> CreateNumberPointer() = 0;
};

class NumberCreatorMock : public NumberCreator
{
public:
	MOCK_METHOD0(CreateNumberPointer, std::shared_ptr<int>() );
};

class ClassWithDependency
{
private:
	NumberCreator& _classWithVirtual;
public:

	ClassWithDependency(NumberCreator& classWithVirtual): _classWithVirtual(classWithVirtual)
	{
	}

	int PrintNumber()
	{
		std::shared_ptr<int> number = _classWithVirtual.CreateNumberPointer();
		return *number;
	}

};

std::shared_ptr<int> CreateIntNumber()
{
	return std::make_shared<int>(4);
}

TEST(TestCaseName, TestName) {
	NumberCreatorMock numberCreatorMock;
	ClassWithDependency classWithDependency(numberCreatorMock);

	ON_CALL(numberCreatorMock, CreateNumberPointer()).WillByDefault(testing::Invoke(CreateIntNumber));
	int actual = classWithDependency.PrintNumber();

	EXPECT_EQ(4, actual);

}