#include <iostream>
#include <vector>
#include "windows.h"
using namespace std;


int main()
{
	char TempFilePath[MAX_PATH];
	char TempFileName[MAX_PATH];
	if(!GetTempPath(sizeof(TempFilePath),TempFilePath)) {
		return -1;
	}
	if(!GetTempFileName(TempFilePath, "FAX", 0, TempFileName)) {
		return -1;
	}

	return 0;
}
