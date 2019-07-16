#include "pch.h"
#include "gmock/gmock.h"
#include "WithVirtualMock.h"
#include "ClassWithDependency.h"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::NiceMock;
using ::testing::StrictMock;

TEST(TestCaseName, ShouldMockVerifyUseDBMethod) {
	WithVirtualMock with_virtual_mock;
	EXPECT_CALL(with_virtual_mock, useDB(1)).Times(AtLeast(1)).WillOnce(Return(1));
	ClassWithDependency class_with_dependency(&with_virtual_mock);

	int acatual = class_with_dependency.doSomething(1);
	ASSERT_EQ(2,acatual);
}

TEST(TestCaseName, ShouldInSequenceWork) {
	WithVirtualMock with_virtual_mock;
	ClassWithDependency class_with_dependency(&with_virtual_mock);
	
	testing::Sequence s;
	EXPECT_CALL(with_virtual_mock, useDB(1)).InSequence(s).WillRepeatedly(Return(1));
	EXPECT_CALL(with_virtual_mock, useDB(1)).InSequence(s).WillRepeatedly(Return(1));
	EXPECT_CALL(with_virtual_mock, useDB(2)).InSequence(s).WillOnce(Return(1));
	
	class_with_dependency.doSomething(1);
	class_with_dependency.doSomething(1);
	class_with_dependency.doSomething(2);
}

TEST(TestCaseName, ShouldOnCallNotFailTestIfIsNotCalled) {
	//arrange
	WithVirtualMock with_virtual_mock;
	ON_CALL(with_virtual_mock, useDB(12345)).WillByDefault(Return(1));
	ClassWithDependency class_with_dependency(&with_virtual_mock);

	//act
	auto result = class_with_dependency.doSomething(1);

	//assert
	EXPECT_EQ(0, result);
}

TEST(TestCaseName, ExpectCallVsOnCall) {
	WithVirtualMock with_virtual_mock;
	ON_CALL(with_virtual_mock, useDB(100)).WillByDefault(Return(1)); //just instruction, what should happan for given parameter/matcher
										//WillByDefault is intended to setup default returns 
	//EXPECT_CALL(with_virtual_mock, useDB(100)).Times(AtLeast(1)).WillOnce(Return(1)); //will fail, some kind of assertion
	ClassWithDependency class_with_dependency(&with_virtual_mock);

	int acatual = class_with_dependency.doSomething(1);
	ASSERT_EQ(0, acatual); // not satified ON_CALL returns default value for int == 0
}

TEST(TestCaseName, ShouldShowWarningForUnintrestedCall) {
	//arrange
	WithVirtualMock with_virtual_mock;
	EXPECT_CALL(with_virtual_mock, useDB(12345)).WillRepeatedly(Return(1)); //assert...

	ClassWithDependency class_with_dependency(&with_virtual_mock);

	//act
	auto result = class_with_dependency.doSomething(12345);
	class_with_dependency.unintrestingCall(1);

	//assert
	EXPECT_EQ(2, result);
}

TEST(TestCaseName, ShouldNotShowWarningForUnintrestedCallWhenUsingNiceMock) {
	//arrange
	NiceMock<WithVirtualMock> with_virtual_mock;
	ClassWithDependency class_with_dependency(&with_virtual_mock);

	EXPECT_CALL(with_virtual_mock, useDB(12345)).WillRepeatedly(Return(1)); //assert...

	//act
	auto result = class_with_dependency.doSomething(12345);
	class_with_dependency.unintrestingCall(1);

	//assert
	EXPECT_EQ(2, result);
}

TEST(TestCaseName, ShouldFailForUnintrestedCallWhenUsingStrictMock) {
	//arrange
	StrictMock<WithVirtualMock> with_virtual_mock;
	ClassWithDependency class_with_dependency(&with_virtual_mock);

	EXPECT_CALL(with_virtual_mock, useDB(12345)).WillRepeatedly(Return(1)); //assert...
	
	//act
	auto result = class_with_dependency.doSomething(12345);
	//class_with_dependency.unintrestingCall(1); //Will Fail!!!

	//assert
	EXPECT_EQ(2, result);
}