#include <iostream>
#define _AFXDLL
#include <afx.h>
#include <Afxtempl.h>

int main()
{
	const char* pszBuffer = "Hello";
	const wchar_t* pwszTest = L"World";

	std::cout << pszBuffer << std::endl;
	std::cout << (const char*)pwszTest << std::endl;

	TCHAR szBuffer[32] = { TEXT("TEST") };
	return 0;
}
