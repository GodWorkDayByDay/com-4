
#ifndef __YZ_ZSTREAM_H__
#define __YZ_ZSTREAM_H__

class ZStream : public IStream
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

#endif  /* __YZ_ZSTREAM_H__ */
