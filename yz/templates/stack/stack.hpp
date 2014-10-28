/*
	@author yz
	@date 2014/10/27
*/
#ifndef __YZ_STACK_HPP__
#define __YZ_STACK_HPP__

#include <deque>
#include <string>

namespace yz
{
	template <typename T, typename Sequence = std::deque<T> >
	class stack
	{
	public:
		void push(T const&);
		void pop();
		T top() const;
		bool empty() const;
		size_t size() const;

	private:
		Sequence elems;
	};

	template <typename T, typename Sequence>
	void stack<T, Sequence>::push(T const& rhs)
	{
		elems.push_back(rhs);
	}

	template <typename T, typename Sequence>
	void stack<T, Sequence>::pop()
	{
		elems.pop_back();
	}

	template <typename T, typename Sequence>
	T stack<T, Sequence>::top() const
	{
		return elems.back();
	}

	template <typename T, typename Sequence>
	bool stack<T, Sequence>::empty() const
	{
		return elems.empty();
	}

	template <typename T, typename Sequence>
	size_t stack<T, Sequence>::size() const
	{
		return elems.size();
	}
}

// Specialization
namespace yz
{
	template <typename Sequence = std::deque<std::string> >
	class stack<std::string, Sequence>
	{
	public:
		void push(std::string const&);
		void pop();
		std::string top() const;
		bool empty() const;
		size_t size() const;

	private:
		Sequence elems;
	};

	template <typename Sequence>
	void stack<std::string, Sequence>::push(std::string const& rhs)
	{
		elems.push_back(rhs);
	}

	template <typename Sequence>
	void stack<std::string, Sequence>::pop()
	{
		elems.pop_back();
	}

	template <typename Sequence>
	std::string stack<std::string, Sequence>::top() const
	{
		return elems.back();
	}

	template <typename Sequence>
	bool stack<std::string, Sequence>::empty() const
	{
		elems.empty();
	}

	template <typename Sequence>
	size_t stack<std::string, Sequence>::size() const
	{
		return elems.size();
	}
}

#endif /* __YZ_STACK_HPP__ */
