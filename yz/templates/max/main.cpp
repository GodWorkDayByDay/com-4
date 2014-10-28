#include <iostream>
#include "max.hpp"
#include "test.h"
using namespace std;
using namespace yz;
using namespace test;

int main()
{
	cout << max(100, 2) << endl;

	cout << "section 1." << endl;
	Integer const& i = max(Integer(10), Integer(88));
	// Integer const ii = max(Integer(100), Integer(100));
	cout << "section 2." << endl;

	cout << i << endl;
	// i.print();
	// ii.print();
	// cout << ii << endl;

	return 0;
}