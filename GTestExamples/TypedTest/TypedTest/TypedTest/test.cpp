#include "pch.h"
#include <list>
#include "gtest/gtest-typed-test.h"
using namespace ::testing;

template <typename T>
class FooTest : public ::testing::Test {
public:
	typedef std::list<T> List;
	static T shared_;
	T value_;
};
template<typename T> T FooTest<T>::shared_;

typedef Types<char, int, unsigned int> MyTypes;
TYPED_TEST_CASE(FooTest, MyTypes);

TYPED_TEST(FooTest, DoesBlah) {
	// Inside a test, refer to the special name TypeParam to get the type
	// parameter.  Since we are inside a derived class template, C++ requires
	// us to visit the members of FooTest via 'this'.
	TypeParam n = this->value_;

	// To visit static members of the fixture, add the 'TestFixture::'
	// prefix.
	n += TestFixture::shared_;

	// To refer to typedefs in the fixture, add the 'typename TestFixture::'
	// prefix.  The 'typename' is required to satisfy the compiler.
	typename TestFixture::List values;

	values.push_back(n);
}