
#include "stdafx.h"

#include "dictionary.h"


IMPLEMENT_IID(IID_IDictionary, "f93a434a-321f-4019-a441-54b37d7d7adc",
	0xf93a434a, 0x321f, 0x4019, 0xa4, 0x41, 0x54, 0xb3, 0x7d, 0x7d, 0x7a, 0xdc);

IMPLEMENT_CLSID(CLSID_ZDictionary, "38242a5d-fd93-4bf0-b4f0-31de4cd8cf19",
	0x38242a5d, 0xfd93, 0x4bf0, 0xb4, 0xf0, 0x31, 0xde, 0x4c, 0xd8, 0xcf, 0x19);

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
