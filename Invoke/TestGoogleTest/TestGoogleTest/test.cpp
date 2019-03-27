#include "pch.h"
#include "gmock/gmock.h"

class NumberCreator
{
public:
	virtual std::shared_ptr<int> CreateNumberPointer() = 0;

	virtual bool TryReplacePointerValue(std::shared_ptr<int>& ptr) = 0;
};

class NumberCreatorMock : public NumberCreator
{
public:
	MOCK_METHOD0(CreateNumberPointer, std::shared_ptr<int>() );
	MOCK_METHOD1(TryReplacePointerValue, bool(std::shared_ptr<int>&) );
};

class ClassWithDependency
{
private:
	NumberCreator& _classWithVirtual;
public:

	ClassWithDependency(NumberCreator& classWithVirtual): _classWithVirtual(classWithVirtual)
	{
	}

	int GetNumber()
	{
		std::shared_ptr<int> number = _classWithVirtual.CreateNumberPointer();
		return *number;
	}

	int GetNumberPointer()
	{
		std::shared_ptr<int> number;
		bool result = _classWithVirtual.TryReplacePointerValue(number);
		if (result)
			return *number;

		return 0;
	}
};

TEST(TestCaseName, InvokeWithLambda)
{
	NumberCreatorMock numberCreatorMock;
	ClassWithDependency classWithDependency(numberCreatorMock);
	const int value = 4;
	ON_CALL(numberCreatorMock, CreateNumberPointer()).
		WillByDefault(
			testing::Invoke([&value]()
				{
					return std::make_shared<int>(value);
				}
			));
	int actual = classWithDependency.GetNumber();

EXPECT_EQ(value, actual);
}

TEST(TestCaseName, InovkeAndDoAll)
{
	NumberCreatorMock numberCreatorMock;
	ClassWithDependency classWithDependency(numberCreatorMock);
	const int expected = 4;

	EXPECT_CALL(numberCreatorMock, TryReplacePointerValue(testing::_)).
		WillOnce(
			DoAll(testing::SetArgReferee<0>(std::make_shared<int>(expected)), testing::Return(true))
		);

	int actual = classWithDependency.GetNumberPointer();

EXPECT_EQ(expected, actual);
}
