#define _AFXDLL
#include <afx.h>
#include <Afxtempl.h>
#include <iostream>

int main()
{
    CString strTest = _T("Test string");
    wprintf(_T("%s\n"), strTest);

    CString strLeft = _T("data"), strRight = _T("data1");
    wprintf(_T("%d\n"), strLeft == strRight);
    wprintf(_T("%d\n"), strLeft != strRight);

    CString strFind = _T("Test String Data");
    wprintf(_T("%d\n"), strFind.Find(_T("String")));
    wprintf(_T("%d\n"), strFind.Find(_T("string")));

    CString strTrim = _T(" \t\nTrim sample ");
    wprintf(_T("%s\n"), strTrim.Trim());

    CString strFormat;
    strFormat.Format(_T("%d, %s"), 256, _T("Test"));
    wprintf(_T("%s\n"), strFormat);
    return 0;
}
