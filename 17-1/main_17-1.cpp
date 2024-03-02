#include <iostream>
#include <string>

int main() {
	{
		std::string string;
		std::wstring wstring;

		wchar_t wc;

		std::locale::global(std::locale(""));
		std::wcout.imbue(std::locale());

	}


	return 0;
}