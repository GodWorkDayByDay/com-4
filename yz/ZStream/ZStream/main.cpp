#include "assert.h"
#include "windows.h"
#include "zstream.h"

int main()
{
	z_stdptr<IStream> spStream;
	CreateZStream(&spStream, "Debug/b.txt");


	return 0;
}