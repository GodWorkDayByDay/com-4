#include "windows.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "QtCore/QTime"
#include <iostream>
using namespace std;

int main()
{
	WCHAR fileName[] = L"c:/1.yz";
	DWORD dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
	DWORD dwShareMode = 0;
	SECURITY_ATTRIBUTES *psa = NULL;
	DWORD dwCreationDisposition = OPEN_EXISTING;
	DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_ARCHIVE;
	HANDLE hTemplateFile = NULL;

	HANDLE hFile = CreateFile(fileName, dwDesiredAccess, dwShareMode, psa, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		cerr << "CreateFile fails." << endl;
		return -1;
	}

	LARGE_INTEGER li = { 0 };
	SetFilePointerEx(hFile, li, &li, FILE_END);

	li.LowPart = 0;
	li.HighPart = 0;
	SetFilePointerEx(hFile, li, &li, FILE_CURRENT);

	char buf[] = "0123456789";

	DWORD dwWritten = -1;
	BOOL bRet = WriteFile(hFile, buf, 10, &dwWritten, NULL);
	if (0 == bRet)
	{
		cerr << "WriteFile fails." << endl;
		return -1;
	}

	DWORD attrs = GetFileAttributes(fileName);
	DWORD dwAttrs = FILE_ATTRIBUTE_NORMAL;
	SetFileAttributes(fileName, dwAttrs);
	attrs = GetFileAttributes(fileName);

	CloseHandle(hFile);

	WCHAR absPath[MAX_PATH];
	GetTempPath(MAX_PATH, absPath);
	wcout << absPath << endl;

	GetCurrentDirectory(MAX_PATH, absPath);
	wcout << absPath << endl;

	SetCurrentDirectory(L"c:\\");

	GetCurrentDirectory(MAX_PATH, absPath);
	wcout << absPath << endl;

	UINT ret = GetTempFileName(L"c:\\", L"abcdef", 0, absPath);
	wcout << absPath << endl;

	WCHAR fullName[MAX_PATH];
	ret = GetFullPathName(absPath, MAX_PATH, fullName, NULL);
	wcout << wcslen(L"\\\\") << endl;


	return 0;
}
