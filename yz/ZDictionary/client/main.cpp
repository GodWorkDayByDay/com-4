#include <iostream>
#include "windows.h"
#include <objbase.h>
#include "..\ZDictionary\dictionary.h"
#include "..\ZDictionary\guid.c"

using namespace std;

int main()
{
	if (S_OK != CoInitialize(NULL))
	{
		return -1;
	}

	GUID clsidDict;
	HRESULT hr = CLSIDFromProgID(L"yz.dictionary", &clsidDict);
	if (FAILED(hr))
	{
		return -1;
	}

	IUnknown *pUnk;
	hr = CoCreateInstance(clsidDict, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pUnk);
	if (FAILED(hr))
	{
		return -1;
	}

	IDictionary *pDict;
	hr = pUnk->QueryInterface(IID_IDictionary, (void**)&pDict);

	if (FAILED(hr))
	{
		pUnk->Release();
		return -1;
	}

	pDict->Initialize();

	pDict->Release();
	pUnk->Release();
	pUnk->Release();

	CoUninitialize();

	return 0;
}

