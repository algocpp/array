
// algocpp/array/subarr.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#ifndef ALGOCPP_ARRAY_SUBARR
#define ALGOCPP_ARRAY_SUBARR

#include <vector>
#include <array>
#include <list>
#include <cstdint>
#include <stdexcept>

namespace algocpp
{
	namespace array
	{
		namespace base
		{
			template <typename T>
			inline std::vector<T> base_subarr(const std::vector<T> v, const unsigned long long pos, unsigned long long n = SIZE_MAX)
			{
				// Processing when returning to the end
				if (n == SIZE_MAX)
				{
					n = v.size() - pos;
				}

				if (pos > v.size() - 1 || pos + n > v.size())
				{
					throw std::out_of_range("You cannot get an array of length " + std::to_string(pos) + " starting from " + std::to_string(n) + ".");
				}

				std::vector<T> result(n);
				for (unsigned long long i = pos; i < pos + n; ++i)
				{
					result[i - pos] = v[i];
				}

				return result;
			}
		}

		template <typename T>
		inline std::vector<T> subarr(const std::vector<T> v, const unsigned long long pos, unsigned long long n = SIZE_MAX)
		{
			return base::base_subarr<T>(v, pos, n);
		}

		template <typename T>
		inline std::list<T> subarr(const std::list<T> v, const unsigned long long pos, unsigned long long n = SIZE_MAX)
		{
			std::vector<T> tmp = base::base_subarr<T>(std::vector<T>(v.begin(), v.end()), pos, n);
			return std::list<T>(tmp.begin(), tmp.end());
		}

		// TODO: Make it possible to call it with `std::array`.
		// template <typename T, std::size_t N, std::size_t len>
		// inline std::array<T, len> subarr(const std::array<T, N> v, const unsigned long long pos, unsigned long long n = SIZE_MAX)
		// {
		// 	std::vector<T> tmp = base::base_subarr<T>(std::vector<T>(v.begin(), v.end()), pos, n);
		// 	return std::array<T, len>(tmp.begin(), tmp.end());
		// }
	}
}

#endif // ALGOCPP_ARRAY_SUBARR
