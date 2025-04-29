
// HelloMfc.h: HelloMfc ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀÇ ±âº» Çì´õ ÆÄÀÏ
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH¿¡ ´ëÇØ ÀÌ ÆÄÀÏÀ» Æ÷ÇÔÇÏ±â Àü¿¡ 'pch.h'¸¦ Æ÷ÇÔÇÕ´Ï´Ù."
#endif

#include "resource.h"       // ÁÖ ±âÈ£ÀÔ´Ï´Ù.


// CHelloMfcApp:
// ÀÌ Å¬·¡½ºÀÇ ±¸Çö¿¡ ´ëÇØ¼­´Â HelloMfc.cppÀ»(¸¦) ÂüÁ¶ÇÏ¼¼¿ä.
//

class CHelloMfcApp : public CWinApp
{
public:
	CHelloMfcApp() noexcept;


// ÀçÁ¤ÀÇÀÔ´Ï´Ù.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ±¸ÇöÀÔ´Ï´Ù.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHelloMfcApp theApp;
