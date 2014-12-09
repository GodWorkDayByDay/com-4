
#ifndef __YZ_ZSTREAM_H__
#define __YZ_ZSTREAM_H__

class ZThreadModule
{
public:
	static STDMETHODIMP_(LONG) Increment(PLONG pl) { return InterlockedIncrement(pl); }
	static STDMETHODIMP_(LONG) Decrement(PLONG pl) { return InterlockedDecrement(pl); }
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
	z_stdptr() { m_ptr = NULL; }

	z_stdptr(T* p)
	{
		m_ptr = p;
		if (m_ptr)
			m_ptr->AddRef();
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

	T* operator->()
	{
		return m_ptr;
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

