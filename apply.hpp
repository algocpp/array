
// algocpp/array/apply.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#ifndef ALGOCPP_ARRAY_APPLY
#define ALGOCPP_ARRAY_APPLY

#include <vector>
#include <array>
#include <list>
#include <functional>
#include <stdexcept>
#include <iostream>
#include <cxxabi.h>

namespace algocpp
{
	namespace array
	{
		/// @brief Passing two arrays to a function
		/// The values of the two arrays are passed one by one to the function, and the result is returned as a new array.
		/// The computational complexity is @c O(N) , where @c N is the length of the array.
		/// If the array lengths are not equal, an exception is thrown.
		/// The behavior when the function is other than T(T,T) is undefined.
		/// @tparam T Array value type
		/// @tparam funcs function type
		/// @param a Array to be the first argument of the function
		/// @param b Array to be the second argument of the function
		/// @param func Function to which a value is entered
		/// @return Array of results of inputting arguments a and b to function func, respectively
		/// @exception @c std::invaid_argument
		template <typename T, typename funcs>
		inline std::vector<T> apply(std::vector<T> a, std::vector<T> b, funcs func)
		{
			if (a.size() != b.size())
			{
				throw std::invalid_argument("Arrays must be of equal length.");
			}

			std::vector<T> result(a.size());
			for (unsigned long long i = 0; i < a.size(); ++i)
			{
				result[i] = func(a[i], b[i]);
			}

			return result;
		}

		/// @brief Passing two arrays to a function
		/// The values of the two arrays are passed one by one to the function, and the result is returned as a new array.
		/// The computational complexity is @c O(N) , where @c N is the length of the array.
		/// The behavior when the function is other than T(T,T) is undefined.
		/// @tparam T Array value type
		/// @tparam N Array length
		/// @tparam funcs function type
		/// @param a Array to be the first argument of the function
		/// @param b Array to be the second argument of the function
		/// @param func Function to which a value is entered
		/// @return Array of results of inputting arguments a and b to function func, respectively
		template <typename T, std::size_t N, typename funcs>
		inline std::array<T, N> apply(std::array<T, N> a, std::array<T, N> b, funcs func) noexcept
		{
			std::array<T, N> result;
			for (unsigned long long i = 0; i < a.size(); ++i)
			{
				result[i] = func(a[i], b[i]);
			}

			return result;
		}

		/// @brief Passing two arrays to a function
		/// The values of the two arrays are passed one by one to the function, and the result is returned as a new array.
		/// The computational complexity is @c O(N) , where @c N is the length of the array.
		/// If the array lengths are not equal, an exception is thrown.
		/// The behavior when the function is other than T(T,T) is undefined.
		/// @tparam T Array value type
		/// @tparam funcs function type
		/// @param a Array to be the first argument of the function
		/// @param b Array to be the second argument of the function
		/// @param func Function to which a value is entered
		/// @return Array of results of inputting arguments a and b to function func, respectively
		/// @exception @c std::invaid_argument
		template <typename T, typename funcs>
		inline std::list<T> apply(std::list<T> a, std::list<T> b, funcs func)
		{
			if (a.size() != b.size())
			{
				throw std::invalid_argument("Arrays must be of equal length.");
			}

			std::vector<T> A(a.begin(), a.end()), B(b.begin(), b.end());
			std::vector<T> result = apply(A, B, func);

			return std::list<T>(result.begin(), result.end());
		}
	}
}

#endif // ALGOCPP_ARRAY_APPLY
