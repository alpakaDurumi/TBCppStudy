#include "AutoPtr.h"
#include "Resource.h"

AutoPtr<Resource> generateResource() {
	AutoPtr<Resource> res(new Resource(10000000));
	return res;
}

int main() {
	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();
	}

	return 0;
}