#include "windows.h"
#include <assert.h>

#include "zstream.h"

STDMETHODIMP ZStream::Read(void *pv, ULONG cb, ULONG *pcbRead)
{
	return S_OK;
}

STDMETHODIMP ZStream::Write(const void *pv, ULONG cb, ULONG *pcbWritten)
{
	return S_OK;
}

STDMETHODIMP ZStream::Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER *plibNewPosition)
{
	DWORD dwMoveMethod;
	switch (dwOrigin)
	{
	case STREAM_SEEK_SET: dwMoveMethod = FILE_BEGIN; break;
	case STREAM_SEEK_CUR: dwMoveMethod = FILE_CURRENT; break;
	case STREAM_SEEK_END: dwMoveMethod = FILE_END; break;
	default: 
		return STG_E_INVALIDFUNCTION;
	}

	SetFilePointerEx(m_hFile, dlibMove, (PLARGE_INTEGER)plibNewPosition, dwMoveMethod);

	return S_OK;
}

STDMETHODIMP ZStream::SetSize(ULARGE_INTEGER libNewSize)
{
	assert(libNewSize.HighPart == 0);
	FlushFileBuffers(m_hFile);
	SetFilePointer(m_hFile, libNewSize.LowPart, NULL, FILE_BEGIN);

	return S_OK;
}

STDMETHODIMP ZStream::CopyTo(IStream *pstm, ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead, ULARGE_INTEGER *pcbWritten)
{

	return S_OK;
}

STDMETHODIMP ZStream::Commit(DWORD grfCommitFlags)
{

	return S_OK;
}

STDMETHODIMP ZStream::Revert(void)
{

	return S_OK;
}

STDMETHODIMP ZStream::LockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType)
{

	return S_OK;
}

STDMETHODIMP ZStream::UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType)
{

	return S_OK;
}

STDMETHODIMP ZStream::Stat(STATSTG *pstatstg, DWORD grfStatFlag)
{

	return S_OK;
}

STDMETHODIMP ZStream::Clone(IStream **ppstm)
{

	return S_OK;
}

HRESULT ZStream::Init(char *name)
{
	m_hFile = CreateFile(name, GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	return S_OK;
}

void ZStream::Close()
{
	CloseHandle(m_hFile);
}

HRESULT CreateZStream(IStream **ppv, char *name)
{
	*ppv = new ZStream(name);

	return S_OK;
}