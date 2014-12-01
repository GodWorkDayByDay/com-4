#include "stdafx.h"

#include "dictionary.h"
#include "dictfact.h"
#include "Registry.h"

extern ULONG g_DictionaryNumber = 0;
extern ULONG g_LockNumber = 0;
HMODULE g_hModule;

BOOL APIENTRY DllMain( HANDLE hModule, 
	DWORD  ul_reason_for_call, 
	LPVOID lpReserved
	)
{
	g_hModule = (HMODULE)hModule;
	return TRUE;
}

extern "C" HRESULT __stdcall DllGetClassObject(const CLSID& rclsid, const IID& riid, void** ppv)
{
	if (rclsid == CLSID_ZDictionary)
	{
		ZDictionaryFactory *pDictFact = new ZDictionaryFactory;
		if (NULL == pDictFact)
			return E_OUTOFMEMORY;

		HRESULT hr = pDictFact->QueryInterface(IID_IClassFactory, ppv);
		((IUnknown*)(*ppv))->Release();
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

extern "C" HRESULT __stdcall DllRegisterServer()
{
	char szModule[MAX_PATH];
	DWORD dwResult = ::GetModuleFileName(g_hModule, szModule, MAX_PATH);
	if (dwResult == 0)
		return E_FAIL;
	return RegisterServer(CLSID_ZDictionary,
							szModule,
							"yz.dictionary",
							"dictionary component",
							NULL);
}

extern "C" HRESULT __stdcall DllUnregisterServer()
{
	return UnregisterServer(CLSID_ZDictionary, "yz.dicitonary", NULL);
}
