#include "assert.h"
#include "windows.h"
#include "zstream.h"

int main()
{
	z_stdptr<IStream> spStream;
	CreateZStream(&spStream, "b.txt");


	return 0;
}