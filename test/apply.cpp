
#include "../apply.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <array>
#include <functional>
using namespace algocpp::array;

inline constexpr int func(int x, int y) noexcept
{
	return x + y;
}

TEST(vector, lambda)
{
	std::vector<int> a = {1, 2, 3}, b = {4, 5, 6};
	std::vector<int> result = {5, 7, 9};
	EXPECT_EQ(apply(a, b, [](int x, int y)
					{ return x + y; }),
			  result);
}

TEST(vector, function)
{
	std::vector<int> a = {1, 2, 3}, b = {4, 5, 6};
	std::vector<int> result = {5, 7, 9};
	EXPECT_EQ(apply(a, b, func),
			  result);
}

TEST(vector, std_function)
{
	std::vector<int> a = {1, 2, 3}, b = {4, 5, 6};
	std::vector<int> result = {5, 7, 9};
	std::function<int(int, int)> f = func;
	EXPECT_EQ(apply(a, b, f),
			  result);
}

TEST(list, lambda)
{
	std::list<int> a = {1, 2, 3}, b = {4, 5, 6};
	std::list<int> result = {5, 7, 9};
	EXPECT_EQ(apply(a, b, [](int x, int y)
					{ return x + y; }),
			  result);
}

TEST(list, function)
{
	std::list<int> a = {1, 2, 3}, b = {4, 5, 6};
	std::list<int> result = {5, 7, 9};
	EXPECT_EQ(apply(a, b, func),
			  result);
}

TEST(list, std_function)
{
	std::list<int> a = {1, 2, 3}, b = {4, 5, 6};
	std::list<int> result = {5, 7, 9};
	std::function<int(int, int)> f = func;
	EXPECT_EQ(apply(a, b, f),
			  result);
}

TEST(array, lambda)
{
	std::array<int, 3> a = {1, 2, 3}, b = {4, 5, 6};
	std::array<int, 3> result = {5, 7, 9};
	EXPECT_EQ(apply(a, b, [](int x, int y)
					{ return x + y; }),
			  result);
}

TEST(array, function)
{
	std::array<int, 3> a = {1, 2, 3}, b = {4, 5, 6};
	std::array<int, 3> result = {5, 7, 9};
	EXPECT_EQ(apply(a, b, func),
			  result);
}

TEST(array, std_function)
{
	std::array<int, 3> a = {1, 2, 3}, b = {4, 5, 6};
	std::array<int, 3> result = {5, 7, 9};
	std::function<int(int, int)> f = func;
	EXPECT_EQ(apply(a, b, f),
			  result);
}
