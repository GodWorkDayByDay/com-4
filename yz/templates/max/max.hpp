/*
	@author	yz
	@date	2014/10/27
*/

namespace yz
{
	template <typename T>
	T const& max(T const& lhs, T const& rhs)
	{
		return lhs < rhs ? rhs : lhs;
	}
}
