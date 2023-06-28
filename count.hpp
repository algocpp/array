
// algocpp/array/count.hpp
//
// This file is part of algocpp and is copyrighted by algocpp.
// If used, it must comply with the MIT License.

#include <vector>
#include <algorithm>

#ifndef ALGOCPP_ARRAY_COUNT
#define ALGOCPP_ARRAY_COUNT

namespace algocpp
{
	namespace array
	{
		template <typename _Tp>
		inline long long count(std::vector<_Tp> v, _Tp x)
		{
			std::sort(v.begin(), v.end());

			auto l = std::lower_bound(v.begin(), v.end(), x);
			auto u = std::upper_bound(v.begin(), v.end(), x);

			if (*l != x)
			{
				return 0;
			}

			if (*u > v.back())
			{
				return v.size() - (l - v.begin());
			}
			else
			{
				return (u - v.begin()) - (l - v.begin());
			}
		}
	}
}

#endif // ALGOCPP_ARRAY_COUNT
