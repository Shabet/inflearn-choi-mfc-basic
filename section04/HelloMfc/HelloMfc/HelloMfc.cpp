
// HelloMfc.cpp: ¾ÖÇÃ¸®ÄÉÀÌ¼Ç¿¡ ´ëÇÑ Å¬·¡½º µ¿ÀÛÀ» Á¤ÀÇÇÕ´Ï´Ù.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "HelloMfc.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloMfcApp

BEGIN_MESSAGE_MAP(CHelloMfcApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CHelloMfcApp::OnAppAbout)
END_MESSAGE_MAP()


// CHelloMfcApp »ý¼º

CHelloMfcApp::CHelloMfcApp() noexcept
{

	// ´Ù½Ã ½ÃÀÛ °ü¸®ÀÚ Áö¿ø
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀ» °ø¿ë ¾ð¾î ·±Å¸ÀÓ Áö¿øÀ» »ç¿ëÇÏ¿© ºôµåÇÑ °æ¿ì(/clr):
	//     1) ÀÌ Ãß°¡ ¼³Á¤Àº ´Ù½Ã ½ÃÀÛ °ü¸®ÀÚ Áö¿øÀÌ Á¦´ë·Î ÀÛµ¿ÇÏ´Â µ¥ ÇÊ¿äÇÕ´Ï´Ù.
	//     2) ÇÁ·ÎÁ§Æ®¿¡¼­ ºôµåÇÏ·Á¸é System.Windows.Forms¿¡ ´ëÇÑ ÂüÁ¶¸¦ Ãß°¡ÇØ¾ß ÇÕ´Ï´Ù.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ¾Æ·¡ ¾ÖÇÃ¸®ÄÉÀÌ¼Ç ID ¹®ÀÚ¿­À» °íÀ¯ ID ¹®ÀÚ¿­·Î ¹Ù²Ù½Ê½Ã¿À(±ÇÀå).
	// ¹®ÀÚ¿­¿¡ ´ëÇÑ ¼­½Ä: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("HelloMfc.AppID.NoVersion"));

	// TODO: ¿©±â¿¡ »ý¼º ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
	// InitInstance¿¡ ¸ðµç Áß¿äÇÑ ÃÊ±âÈ­ ÀÛ¾÷À» ¹èÄ¡ÇÕ´Ï´Ù.
}

// À¯ÀÏÇÑ CHelloMfcApp °³Ã¼ÀÔ´Ï´Ù.

CHelloMfcApp theApp;


// CHelloMfcApp ÃÊ±âÈ­

BOOL CHelloMfcApp::InitInstance()
{
	// ¾ÖÇÃ¸®ÄÉÀÌ¼Ç ¸Å´ÏÆä½ºÆ®°¡ ComCtl32.dll ¹öÀü 6 ÀÌ»óÀ» »ç¿ëÇÏ¿© ºñÁÖ¾ó ½ºÅ¸ÀÏÀ»
	// »ç¿ëÇÏµµ·Ï ÁöÁ¤ÇÏ´Â °æ¿ì, Windows XP »ó¿¡¼­ ¹Ýµå½Ã InitCommonControlsEx()°¡ ÇÊ¿äÇÕ´Ï´Ù. 
	// InitCommonControlsEx()¸¦ »ç¿ëÇÏÁö ¾ÊÀ¸¸é Ã¢À» ¸¸µé ¼ö ¾ø½À´Ï´Ù.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ÀÀ¿ë ÇÁ·Î±×·¥¿¡¼­ »ç¿ëÇÒ ¸ðµç °ø¿ë ÄÁÆ®·Ñ Å¬·¡½º¸¦ Æ÷ÇÔÇÏµµ·Ï
	// ÀÌ Ç×¸ñÀ» ¼³Á¤ÇÏ½Ê½Ã¿À.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// OLE ¶óÀÌºê·¯¸®¸¦ ÃÊ±âÈ­ÇÕ´Ï´Ù.
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// RichEdit ÄÁÆ®·ÑÀ» »ç¿ëÇÏ·Á¸é AfxInitRichEdit2()°¡ ÀÖ¾î¾ß ÇÕ´Ï´Ù.
	// AfxInitRichEdit2();

	// Ç¥ÁØ ÃÊ±âÈ­
	// ÀÌµé ±â´ÉÀ» »ç¿ëÇÏÁö ¾Ê°í ÃÖÁ¾ ½ÇÇà ÆÄÀÏÀÇ Å©±â¸¦ ÁÙÀÌ·Á¸é
	// ¾Æ·¡¿¡¼­ ÇÊ¿ä ¾ø´Â Æ¯Á¤ ÃÊ±âÈ­
	// ·çÆ¾À» Á¦°ÅÇØ¾ß ÇÕ´Ï´Ù.
	// ÇØ´ç ¼³Á¤ÀÌ ÀúÀåµÈ ·¹Áö½ºÆ®¸® Å°¸¦ º¯°æÇÏ½Ê½Ã¿À.
	// TODO: ÀÌ ¹®ÀÚ¿­À» È¸»ç ¶Ç´Â Á¶Á÷ÀÇ ÀÌ¸§°ú °°Àº
	// ÀûÀýÇÑ ³»¿ëÀ¸·Î ¼öÁ¤ÇØ¾ß ÇÕ´Ï´Ù.
	SetRegistryKey(_T("·ÎÄÃ ¾ÖÇÃ¸®ÄÉÀÌ¼Ç ¸¶¹ý»ç¿¡¼­ »ý¼ºµÈ ¾ÖÇÃ¸®ÄÉÀÌ¼Ç"));


	// ÁÖ Ã¢À» ¸¸µé±â À§ÇØ ÀÌ ÄÚµå¿¡¼­´Â »õ ÇÁ·¹ÀÓ Ã¢ °³Ã¼¸¦
	// ¸¸µç ´ÙÀ½ ÀÌ¸¦ ¾ÖÇÃ¸®ÄÉÀÌ¼ÇÀÇ ÁÖ Ã¢ °³Ã¼·Î ¼³Á¤ÇÕ´Ï´Ù.
	CFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// ÇÁ·¹ÀÓÀ» ¸¸µé¾î ¸®¼Ò½º¿Í ÇÔ²² ·ÎµåÇÕ´Ï´Ù.
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,
		nullptr);





	// Ã¢ ÇÏ³ª¸¸ ÃÊ±âÈ­µÇ¾úÀ¸¹Ç·Î ÀÌ¸¦ Ç¥½ÃÇÏ°í ¾÷µ¥ÀÌÆ®ÇÕ´Ï´Ù.
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

int CHelloMfcApp::ExitInstance()
{
	//TODO: Ãß°¡ÇÑ Ãß°¡ ¸®¼Ò½º¸¦ Ã³¸®ÇÕ´Ï´Ù.
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CHelloMfcApp ¸Þ½ÃÁö Ã³¸®±â


// ÀÀ¿ë ÇÁ·Î±×·¥ Á¤º¸¿¡ »ç¿ëµÇ´Â CAboutDlg ´ëÈ­ »óÀÚÀÔ´Ï´Ù.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// ´ëÈ­ »óÀÚ µ¥ÀÌÅÍÀÔ´Ï´Ù.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV Áö¿øÀÔ´Ï´Ù.

// ±¸ÇöÀÔ´Ï´Ù.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// ´ëÈ­ »óÀÚ¸¦ ½ÇÇàÇÏ±â À§ÇÑ ÀÀ¿ë ÇÁ·Î±×·¥ ¸í·ÉÀÔ´Ï´Ù.
void CHelloMfcApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CHelloMfcApp ¸Þ½ÃÁö Ã³¸®±â



