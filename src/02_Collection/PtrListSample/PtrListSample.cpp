#define _AFXDLL
#include <afx.h>
#include <Afxtempl.h>
#include <iostream>

int main()
{
    CPtrList list;
    list.AddTail((void*)"test");
    list.AddTail((void*)"string");
    list.AddTail((void*)"data");

    POSITION pos = list.GetHeadPosition();
    while (pos != NULL) {
        void *pData = list.GetAt(pos);
        std::cout << (char*)list.GetAt(pos) << std::endl;
        list.GetNext(pos);
    }
	return 0;
}

