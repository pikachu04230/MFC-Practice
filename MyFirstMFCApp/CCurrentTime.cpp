// CCurrentTime.cpp: 實作檔案
//

#include "pch.h"
#include "MyFirstMFCApp.h"
#include "afxdialogex.h"
#include "CCurrentTime.h"


// CCurrentTime 對話方塊

IMPLEMENT_DYNAMIC(CCurrentTime, CDialogEx)

CCurrentTime::CCurrentTime(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_CURRENTTIME, pParent)
{

}

CCurrentTime::~CCurrentTime()
{
}

void CCurrentTime::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCurrentTime, CDialogEx)
	ON_WM_NCDESTROY()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_HIDE, &CCurrentTime::OnBnClickedButtonHide)
END_MESSAGE_MAP()


// CCurrentTime 訊息處理常式


BOOL CCurrentTime::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此加入額外的初始化
	SetTimer(1, 1000, nullptr);

	m_font.CreatePointFont(240, _T("Arial"));
	CStatic *pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TIME);
	pStatic->SetFont(&m_font);

	CTime time = CTime::GetCurrentTime();
	CString strTime = time.Format(_T("%H:%M:%S"));
	SetDlgItemText(IDC_STATIC_TIME, strTime);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void CCurrentTime::PostNcDestroy()
{
	// TODO: 在此加入您的訊息處理常式程式碼
	delete this;
}


void CCurrentTime::OnClose()
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	DestroyWindow();
}

void CCurrentTime::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	if (nIDEvent == 1)
	{
		CTime time = CTime::GetCurrentTime();
		CString strTime = time.Format(_T("%H:%M:%S"));
		SetDlgItemText(IDC_STATIC_TIME, strTime);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CCurrentTime::OnBnClickedButtonHide()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	ShowWindow(SW_HIDE);
}
