
#include "stdafx.h"

#include "dictionary.h"
#include "dictfact.h"

extern ULONG g_LockNumber;
extern ULONG g_DictionaryNumber;

ZDictionaryFactory::ZDictionaryFactory()
{
	m_ref = 1;
}

ZDictionaryFactory::~ZDictionaryFactory()
{

}

HRESULT __stdcall ZDictionaryFactory::QueryInterface(const IID& iid, void **ppv)
{
	if (IID_IClassFactory == iid)
		*ppv = static_cast<IUnknown*>(this);
	else if (IID_IUnknown == iid)
		*ppv = static_cast<IClassFactory*>(this);
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}

	((IUnknown*)(*ppv))->AddRef();
	return S_OK;
}

ULONG __stdcall ZDictionaryFactory::AddRef()
{
	++m_ref;
	return (ULONG)m_ref;
}

ULONG __stdcall ZDictionaryFactory::Release()
{
	--m_ref;
	if (0 == m_ref)
	{
		delete this;
		return 0;
	}
	return (ULONG)m_ref;
}

HRESULT __stdcall ZDictionaryFactory::CreateInstance(IUnknown *pUnkOuter, const IID& riid, void **ppvObject)
{
	ZDictionary *pDict;
	HRESULT hr = E_OUTOFMEMORY;
	*ppvObject = NULL;

	if (pUnkOuter != NULL)
		return CLASS_E_NOAGGREGATION;

	pDict = new ZDictionary;

	hr = pDict->QueryInterface(riid, ppvObject);
	if (FAILED(hr))
	{
		--g_DictionaryNumber;
		delete pDict;
	}
	return hr;
}

HRESULT __stdcall ZDictionaryFactory::LockServer(BOOL bLock)
{
	if (bLock)
		++g_LockNumber;
	else
		--g_LockNumber;

	return S_OK;
}

