
#ifndef __YZ_DICTFACT_H__
#define __YZ_DICTFACT_H__

class ZDictionaryFactory : public IClassFactory
{
public:
	ZDictionaryFactory();
	~ZDictionaryFactory();

public:
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void **ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();
	virtual HRESULT __stdcall CreateInstance(IUnknown *pUnkOuter, const IID& riid, void **ppvObject);
	virtual HRESULT __stdcall LockServer(BOOL bLock);

private:
	int m_ref;
};

#endif /* __YZ_DICTFACT_H__ */
