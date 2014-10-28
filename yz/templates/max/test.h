#include <iostream>

namespace test
{
	class Integer : public std::ostream
	{
	public:
		Integer() { cout << "Integer()" << endl; }
		~Integer() { m_val = 10; cout << "~Integer(). " << endl; }
		Integer(int val) : m_val(val) { cout << "Integer(int val)" << endl; }
		// void print() { cout << "val: " << m_val	<< endl; }

	private:
		int m_val;

		friend bool operator<(Integer const& lhs, Integer const& rhs);
		friend ostream& operator<< (ostream& os, Integer const& rhs);
	};

	inline bool operator<(Integer const& lhs, Integer const& rhs)
	{
		return lhs.m_val < rhs.m_val ? true : false;
	}

	ostream& operator<< (ostream& os, Integer const& rhs)
	{
		os << "val: " << rhs.m_val << endl;
		return os;
	}
}
