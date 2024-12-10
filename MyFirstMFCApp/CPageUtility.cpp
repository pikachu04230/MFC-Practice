// CPageUtility.cpp: 實作檔案
//

#include "pch.h"
#include "MyFirstMFCApp.h"
#include "afxdialogex.h"
#include "CPageUtility.h"


// CPageUtility 對話方塊

IMPLEMENT_DYNAMIC(CPageUtility, CDialogEx)

CPageUtility::CPageUtility(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAGE_UTILITY, pParent)
	, m_pCurrentTimeDlg(nullptr)
{

}

CPageUtility::~CPageUtility()
{
}

void CPageUtility::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPageUtility, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_WELCOME_DLG, &CPageUtility::OnBnClickedButtonWelcomeDlg)
	ON_BN_CLICKED(IDC_BUTTON_PROGRESS_DLG, &CPageUtility::OnBnClickedButtonProgressDlg)
	ON_BN_CLICKED(IDC_BUTTON_NCPA, &CPageUtility::OnBnClickedButtonNcpa)
	ON_BN_CLICKED(IDC_BUTTON_CURRENTTIME, &CPageUtility::OnBnClickedButtonCurrenttime)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CPageUtility 訊息處理常式


void CPageUtility::OnBnClickedButtonWelcomeDlg()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CWelcomeDlg dlg;
	dlg.DoModal();
}


void CPageUtility::OnBnClickedButtonProgressDlg()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CProgressDlg dlg;
	dlg.DoModal();
}


void CPageUtility::OnBnClickedButtonNcpa()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	ShellExecute(NULL, NULL, L"ncpa.cpl", NULL, NULL, SW_SHOWNORMAL);
}


void CPageUtility::OnBnClickedButtonCurrenttime()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (m_pCurrentTimeDlg != nullptr && IsWindow(m_pCurrentTimeDlg->m_hWnd))
	{
		m_pCurrentTimeDlg->ShowWindow(SW_SHOW);
		m_pCurrentTimeDlg->SetFocus();
	}
	else
	{
		m_pCurrentTimeDlg = new CCurrentTime();
		m_pCurrentTimeDlg->Create(IDD_CURRENTTIME, this);
		m_pCurrentTimeDlg->ShowWindow(SW_SHOW);
	}
}


void CPageUtility::OnDestroy()
{
	// TODO: 在此加入您的訊息處理常式程式碼
	if (m_pCurrentTimeDlg != nullptr)
	{
		m_pCurrentTimeDlg->DestroyWindow();
		delete m_pCurrentTimeDlg;
		m_pCurrentTimeDlg = nullptr;
	}

	CDialogEx::OnDestroy();
}
