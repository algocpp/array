
// algocpp/array/operator/plus.hpp
//
// this file is part of algocpp and is copyrighted by algocpp.
// if used, it must comply with the mit license.

#ifndef ALGOCPP_ARRAY_OPERATOR_PLUS
#define ALGOCPP_ARRAY_OPERATOR_PLUS

#include <vector>

template <typename Tp>
inline std::vector<Tp> operator+(const std::vector<Tp> &a, const std::vector<Tp> &b)
{
	std::vector<Tp> result(a.size() + b.size());
	for (unsigned long long i = 0; i < a.size(); i++)
	{
		result[i] = a[i];
	}

	for (unsigned long long i = a.size(); i < a.size() + b.size(); i++)
	{
		result[i] = b[i - a.size()];
	}

	return result;
}

template <typename Tp>
std::vector<Tp> operator+(const std::vector<Tp> &a, const Tp &b)
{
	return a + std::vector<Tp>{b};
}

template <typename Tp>
std::vector<Tp> operator+=(std::vector<Tp> &a, const std::vector<Tp> &b)
{
	a = a + b;

	return a;
}

template <typename Tp>
std::vector<Tp> operator+=(std::vector<Tp> &a, const Tp &b)
{
	a.emplace_back(b);

	return a;
}

#endif // ALGOCPP_ARRAY_OPERATOR_PLUS
