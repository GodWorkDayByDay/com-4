#include <iostream>
#include <vector>
#include "stack.hpp"
#include "stack2.hpp"
using namespace std;
using namespace yz;

int main()
{
	stack<int> istk;
	istk.push(10);
	istk.push(8);
	istk.push(6);
	cout << "size: " << istk.size() << endl;
	cout << "top: " << istk.top() << endl;
	istk.pop();
	cout << "top: " << istk.top() << endl;
	cout << "size: " << istk.size() << endl;

	stack<string> strstk;
	strstk.push(string("hello"));
	strstk.push(string("fuck"));
	strstk.pop();
	cout <<"size: " << strstk.size() << endl;
	strstk.push(string("world"));
	cout <<"size: " << strstk.size() << endl;
	cout << strstk.top().c_str() << endl;

	stack<double, vector<double> > dblstk;
	dblstk.push(1.1);
	cout << dblstk.empty() << endl;

	try
	{
		stack2<int, 2> istk2;
		istk2.push(10);
		istk2.push(9);
		cout << "before push the 3rd element" << endl;
		istk2.push(8);
		cout << "after push the 3rd element" << endl;
		istk2.pop();
		cout << "size: " << istk2.size() << endl;
		cout << "empty: " << istk2.empty() << endl;
		cout << "full: " << istk2.full() << endl;
		cout << "top: " << istk2.top() << endl;
	}
	catch(std::exception &ex)
	{
		std::cerr << "exception caught: " << ex.what() << endl;
	}

	return 0;
}