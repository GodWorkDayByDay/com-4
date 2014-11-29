#include "stdafx.h"

#include "dictionary.h"
#include "dictfact.h"

IMPLEMENT_IID(IDictionary, "f93a434a-321f-4019-a441-54b37d7d7adc",
	0xf93a434a, 0x321f, 0x4019, 0xa4, 0x41, 0x54, 0xb3, 0x7d, 0x7d, 0x7a, 0xdc);

IMPLEMENT_CLSID(ZDictionary, "38242a5d-fd93-4bf0-b4f0-31de4cd8cf19",
	0x38242a5d, 0xfd93, 0x4bf0, 0xb4, 0xf0, 0x31, 0xde, 0x4c, 0xd8, 0xcf, 0x19);

extern ULONG g_DictionaryNumber = 0;
extern ULONG g_LockNumber = 0;

extern "C" HRESULT __stdcall DllGetClassObject(const CLSID& rclsid, const IID& riid, void** ppv)
{
	if (rclsid == CLSID_ZDictionary)
	{
		ZDictionaryFactory *pDictFact = new ZDictionaryFactory;
		if (NULL == pDictFact)
			return E_OUTOFMEMORY;

		HRESULT hr = pDictFact->QueryInterface(IID_IClassFactory, ppv);
		return hr;
	}
	else
	{
		return CLASS_E_CLASSNOTAVAILABLE;
	}
	return S_OK;
}

extern "C" HRESULT __stdcall DllCanUnloadNow()
{
	if (0 == g_LockNumber && 0 == g_DictionaryNumber)
		return S_OK;
	else
		return S_FALSE;
}
