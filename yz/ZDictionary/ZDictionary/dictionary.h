
#ifndef __YZ_DICTIONARY_H__
#define __YZ_DICTIONARY_H__

// {f93a434a-321f-4019-a441-54b37d7d7adc} 
DEFINE_GUID(IID_IDictionary, 
0xf93a434a, 0x321f, 0x4019, 0xa4, 0x41, 0x54, 0xb3, 0x7d, 0x7d, 0x7a, 0xdc);

interface IDictionary : public IUnknown
{
public:
	virtual BOOL Initialize() = 0;
	virtual BOOL LoadLibrary() = 0;
	virtual BOOL InsertWord(BSTR, BSTR) = 0;
	virtual void DeleteWord(BSTR) = 0;
	virtual BOOL LookUpWord(BSTR, BSTR*) = 0;
	virtual BOOL RestoreLibrary(BSTR) = 0;
	virtual void FreeLibrary() = 0;
};

// {38242a5d-fd93-4bf0-b4f0-31de4cd8cf19} 
DEFINE_GUID(CLSID_ZDictionary, 
0x38242a5d, 0xfd93, 0x4bf0, 0xb4, 0xf0, 0x31, 0xde, 0x4c, 0xd8, 0xcf, 0x19);

class ZDictionary : public IDictionary
{
public:
	ZDictionary();
	~ZDictionary();

public:
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void **ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();
	virtual BOOL Initialize();
	virtual BOOL LoadLibrary();
	virtual BOOL InsertWord(BSTR, BSTR);
	virtual void DeleteWord(BSTR);
	virtual BOOL LookUpWord(BSTR, BSTR*);
	virtual BOOL RestoreLibrary(BSTR);
	virtual void FreeLibrary();

private:
	int		m_ref;
	std::wstring	m_wstrName;
};

#endif /* __YZ_DICTIONARY_H__ */
