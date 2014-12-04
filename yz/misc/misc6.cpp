#include <iostream>
#include "windows.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char path[MAX_PATH];
	cout << GetSystemDirectory(path, MAX_PATH) << endl;
	cout << GetWindowsDirectory(path, MAX_PATH) << endl;
	cout << GetCurrentDirectory(MAX_PATH, path) << endl;
	cout << SetCurrentDirectory("d:\\wpsenv") << endl;
	cout << GetCurrentDirectory(MAX_PATH, path) << endl;
	cout << GetTempPath(MAX_PATH, path) << endl;
	cout << GetTempFileName(".", NULL, 10, path) << endl;
	char *pPath;
	char res[MAX_PATH];
	cout << GetFullPathName(path, MAX_PATH, res, &pPath);

	return 0;
}