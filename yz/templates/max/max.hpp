/*
	@author	yz
	@date	2014/10/27
*/
#ifndef __YZ_MAX_HPP__
#define __YZ_MAX_HPP__

namespace yz
{
	template <typename T>
	T const& max(T const& lhs, T const& rhs)
	{
		return lhs < rhs ? rhs : lhs;
	}
}

#endif /* __YZ_MAX_HPP__ */
