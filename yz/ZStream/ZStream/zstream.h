
#ifndef __YZ_ZSTREAM_H__
#define __YZ_ZSTREAM_H__

class ZThreadModule
{
public:
	static STDMETHODIMP_(LONG) Increment(PLONG pl) { return InterlockedIncrement(pl); }
	static STDMETHODIMP_(LONG) Decrement(PLONG pl) { return InterlockedDecrement(pl); }
};

template <typename I>
class ZNonAddRefReleaseObj : public I
{
private:
	HRESULT STDMETHODCALLTYPE AddRef();
	HRESULT STDMETHODCALLTYPE Release();
};

template <typename T, typename ThreadModule = ZThreadModule>
class ZUnknwon
{
public:
	ZUnknwon()
	{
		m_ref = 1;
	}

	~ZUnknwon()
	{

	}

public:
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** ppv)
	{
		if (iid == __uuid(T) || iid == IUnknown)
		{
			(*ppv) = *this;
			AddRef();
			return S_OK;
		}
		else
			return E_NOINTERFACE;
	}

	UINT STDMETHODCALLTYPE AddRef()
	{
		return ThreadModule::Increment(&m_ref);
	}

	UINT STDMETHODCALLTYPE Release()
	{
		ULONG l = ThreadModule::Decrement(&m_ref);

		if (0 == l)
		{
			m_ref = -1;
			delete this;
		}
		return l;
	}

private:
	LONG m_ref;
};

template <typename T>
class z_stdptr
{
public:
	z_stdptr()
	{
		m_ptr = NULL;
	}

	z_stdptr(T* p)
	{
		m_ptr = p;
		if (m_ptr)
			m_ptr->AddRef();
	}

	z_stdptr(int _nil)
	{
		assert(NULL == _nil);
		m_ptr = NULL;
	}

	z_stdptr(const z_stdptr<T>& zp)
	{
		m_ptr = zp.m_ptr;
		if (m_ptr)
			m_ptr->AddRef();
	}

	~z_stdptr()
	{
		if (m_ptr)
			m_ptr->Release();
	}

	void attach(T* p)
	{
		if (m_ptr)
			m_ptr->Release();
		m_ptr = p;
	}

	T* detach();
	{
		T* _tmp = m_ptr;
		m_ptr = NULL;
		
		return _tmp;
	}

	T* operator=(T* p)
	{
		// notice self-copy
		if (p)
			p->AddRef();
		if (m_ptr)
			m_ptr->Release();

		return m_ptr = p;
	}

	T* operator=(int _nil)
	{
		assert(NULL == _nil);
		if (m_ptr)
		{
			m_ptr = Release();
			m_ptr = NULL;
		}
		return NULL;
	}

	T* operator=(const z_stdptr<T>& zp)
	{
		if (zp)
			zp.m_ptr->AddRef();
		if (m_ptr)
			m_ptr->Release();

		return m_ptr = zp.m_ptr;
	}

	template <class Type>
	T* operator=(const z_stdptr<Type>& zp)
	{
		if (zp->m_ptr)
			zp->AddRef();
		if (m_ptr)
			m_ptr->Release();

		return m_ptr = zp->m_ptr;
	}

	ZNonAddRefReleaseObj<T>* operator->()
	{
		return (ZNonAddRefReleaseObj<T>*)m_ptr;
	}

	T** operator&()
	{
		assert(NULL == m_ptr);
		return &m_ptr;
	}

	operator T*() const
	{
		return m_ptr;
	}
	
	T& operator*()
	{
		return *m_ptr;
	}

	bool operator==(T* p)
	{
		return m_ptr == p;
	}

	bool operator!=(T* p)
	{
		return m_ptr != p;
	}

	bool operator==(int _nil)
	{
		assert(NULL == _nil);
		return NULL == m_ptr;
	}

	bool operator!=(int _nil)
	{
		assert(NULL == _nil)
			return NULL == m_ptr;
	}

private:
	T *m_ptr;
};

class ZStream : public ZUnknwon<IStream>
{
public:
	STDMETHODIMP Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER *plibNewPosition);
	STDMETHODIMP SetSize(ULARGE_INTEGER libNewSize);
	STDMETHODIMP CopyTo(IStream *pstm, ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead, ULARGE_INTEGER *pcbWritten);
	STDMETHODIMP Commit(DWORD grfCommitFlags);
	STDMETHODIMP Revert(void);
	STDMETHODIMP LockRegion(ULARGE_INTEGER libOffset, LARGE_INTEGER cb, DWORD dwLockType); 
	STDMETHODIMP UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType);
	STDMETHODIMP Stat(STATSTG *pstatstg, DWORD grfStatFlag);
	STDMETHODIMP Clone(IStream **ppstm);

public:
	HRESULT Init(char *name);
	void Close();

private:
	HANDLE m_hFile;
};

HRESULT CreateZStream(ZStream **ppv);

#endif  /* __YZ_ZSTREAM_H__ */

