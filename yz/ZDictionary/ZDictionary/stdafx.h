#include "windows.h"
#include <string>

#define IMPLEMENT_GUID(var, sz, x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8)	\
	EXTERN_C const GUID var													\
	= {x, s1, s2, { c1, c2, c3, c4, c5, c6, c7, c8 }};

#define IMPLEMENT_CLSID(Com, sz, x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8)	\
	IMPLEMENT_GUID(CLSID_##Com, sz,											\
	x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8)

#define IMPLEMENT_IID(Intf, sz, x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8)	\
	IMPLEMENT_GUID(IID_##Intf, sz,											\
	x, s1, s2, c1, c2, c3, c4, c5, c6, c7, c8);
