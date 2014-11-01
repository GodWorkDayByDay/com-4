#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> const& ivec);

int main()
{
	vector<int> ivec1;
	vector<int> ivec2;

	ivec1.push_back(1);
	ivec1.push_back(2);
	ivec1.push_back(3);
	ivec2.push_back(4);

	cout << "before swap." << endl;
	printVec(ivec1);
	// printVec(ivec2);

	ivec1.swap(ivec2);
	cout << "after swap." << endl;
	printVec(ivec1);
	// printVec(ivec2);

	return 0;
}

void printVec(vector<int> const& ivec)
{
	for (vector<int>::const_iterator it = ivec.begin(); it != ivec.end(); ++it)
	{
		cout << *it << endl;
	}
}