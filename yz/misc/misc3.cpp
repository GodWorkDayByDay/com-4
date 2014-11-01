#include <iostream>
#include "Windows.h"
using namespace std;

struct Data
{
	int a : 1;
	int b : 1;
	int reserved : 30;
	int c;
	int d;
};

int main()
{
	Data data;
	data.a = 1;
	data.b = 1;
	data.reserved = 0;
	data.c = 10;
	data.d = 32;

	HANDLE fileHandle = CreateFile(L"a.bin"
						, GENERIC_WRITE
						, FILE_SHARE_WRITE, NULL
						, CREATE_ALWAYS
						, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD nWrite;
	WriteFile(fileHandle, &data, sizeof(Data), &nWrite, NULL);
	WCHAR outputStr[30];
	wsprintf(outputStr, L"write length: %d", nWrite);
	OutputDebugString(outputStr);
	CloseHandle(fileHandle);

	return 0;
}