
#ifndef __YZ_DICTIONARY_H__
#define __YZ_DICTIONARY_H__

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
