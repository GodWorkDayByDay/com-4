
#include "stdafx.h"

#include "dictionary.h"


extern ULONG g_DictionaryNumber;

ZDictionary::ZDictionary()
{
	++g_DictionaryNumber;

	m_ref = 1;
}

ZDictionary::~ZDictionary()
{

}

HRESULT ZDictionary::QueryInterface(const IID& iid, void **ppv)
{
	if (IID_IUnknown == iid)
		*ppv = static_cast<IUnknown*>(this);
	else if (IID_IDictionary == iid)
		*ppv = static_cast<IDictionary*>(this);
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	((IUnknown*)(*ppv))->AddRef();
	return S_OK;
}

ULONG ZDictionary::AddRef()
{
	++m_ref;
	return (ULONG)m_ref;
}

ULONG ZDictionary::Release()
{
	--m_ref;
	if (0 == m_ref)
	{
		--g_DictionaryNumber;
		delete this;
		return 0;
	}
	return (ULONG)m_ref;
}

BOOL ZDictionary::Initialize()
{
	return FALSE;
}

BOOL ZDictionary::LoadLibrary()
{
	return FALSE;
}

BOOL ZDictionary::InsertWord(BSTR, BSTR)
{

	return FALSE;
}

void ZDictionary::DeleteWord(BSTR)
{

}

BOOL ZDictionary::LookUpWord(BSTR, BSTR*)
{

	return FALSE;
}

BOOL ZDictionary::RestoreLibrary(BSTR)
{

	return FALSE;
}

void ZDictionary::FreeLibrary()
{

}
