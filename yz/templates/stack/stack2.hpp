/*
	@author yz
	@date 2014/10/27
*/

#include <stdexcept>

namespace yz
{
	template <typename T, int MAXSIZE = 20>
	class stack2
	{
	public:
		stack2();
		void push(T const& rhs);
		void pop();
		size_t size() const;
		bool empty() const;
		bool full() const;
		T top() const;

	private:
		T elems[MAXSIZE];
		size_t numElems;
	};

	template <typename T, int MAXSIZE>
	stack2<T, MAXSIZE>::stack2() : numElems(0)
	{

	}

	template <typename T, int MAXSIZE>
	void stack2<T, MAXSIZE>::push(T const& rhs)
	{
		if (MAXSIZE == numElems)
			throw std::out_of_range("stack2<>::push(): stack is full");
		elems[numElems++] = rhs;
	}

	template <typename T, int MAXSIZE>
	void stack2<T, MAXSIZE>::pop()
	{
		if (numElems <= 0)
			throw std::out_of_range("stack2<>::pop(): empty stack");
		--numElems;
	}

	template <typename T, int MAXSIZE>
	size_t stack2<T, MAXSIZE>::size() const
	{
		return numElems;
	}

	template <typename T, int MAXSIZE>
	bool stack2<T, MAXSIZE>::empty() const
	{
		return numElems == 0;
	}

	template <typename T, int MAXSIZE>
	bool stack2<T, MAXSIZE>::full() const
	{
		return numElems == MAXSIZE;
	}

	template <typename T, int MAXSIZE>
	T stack2<T, MAXSIZE>::top() const
	{
		if (numElems <= 0)
			throw std::out_of_range("stack2<>::top(): empty stack");
		return elems[numElems - 1];
	} 
}