#include "assert.h"
#include "windows.h"
#include "zstream.h"

int main()
{
	z_stdptr<ZStream> spStream;
	CreateZStream(&spStream);

	spStream->Init("a.txt");
	spStream->Close();

	return 0;
}