#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // °ÅÀÇ »ç¿ëµÇÁö ¾Ê´Â ³»¿ëÀº Windows Çì´õ¿¡¼­ Á¦¿ÜÇÕ´Ï´Ù.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ÀÏºÎ CString »ý¼ºÀÚ´Â ¸í½ÃÀûÀ¸·Î ¼±¾ðµË´Ï´Ù.

// MFCÀÇ °øÅë ºÎºÐ°ú ¹«½Ã °¡´ÉÇÑ °æ°í ¸Þ½ÃÁö¿¡ ´ëÇÑ ¼û±â±â¸¦ ÇØÁ¦ÇÕ´Ï´Ù.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ÇÙ½É ¹× Ç¥ÁØ ±¸¼º ¿ä¼ÒÀÔ´Ï´Ù.
#include <afxext.h>         // MFC È®ÀåÀÔ´Ï´Ù.


#include <afxdisp.h>        // MFC ÀÚµ¿È­ Å¬·¡½ºÀÔ´Ï´Ù.



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 °ø¿ë ÄÁÆ®·Ñ¿¡ ´ëÇÑ MFC Áö¿øÀÔ´Ï´Ù.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows °ø¿ë ÄÁÆ®·Ñ¿¡ ´ëÇÑ MFC Áö¿øÀÔ´Ï´Ù.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFCÀÇ ¸®º» ¹× ÄÁÆ®·Ñ ¸·´ë Áö¿ø









#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


