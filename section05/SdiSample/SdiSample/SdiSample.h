
// SdiSample.h : main header file for the SdiSample application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSdiSampleApp:
// See SdiSample.cpp for the implementation of this class
//

class CSdiSampleApp : public CWinApp
{
public:
	CSdiSampleApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSdiSampleApp theApp;
