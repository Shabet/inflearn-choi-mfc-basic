#define _AFXDLL
#include <afx.h>
#include <Afxtempl.h>
#include <iostream>

int main()
{
    CMapStringToPtr map;
    map.SetAt(_T("test1"), (void*)"test");
    map.SetAt(_T("test2"), (void*)"string");
    map.SetAt(_T("test3"), (void*)"data");

    void* pResult = nullptr;
    map.Lookup(_T("test2"), pResult);
    if (pResult != nullptr)
        std::cout << (char*)pResult << std::endl;


	return 0;
}

