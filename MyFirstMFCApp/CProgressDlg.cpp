// CProgressDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MyFirstMFCApp.h"
#include "afxdialogex.h"
#include "CProgressDlg.h"


// CProgressDlg 對話方塊

IMPLEMENT_DYNAMIC(CProgressDlg, CDialogEx)

CProgressDlg::CProgressDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_PROGRESS, pParent)
{

}

CProgressDlg::~CProgressDlg()
{
}

void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS_BAR, m_ProgressBar);
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialogEx)
	ON_BN_CLICKED(IDC_START_BUTTON, &CProgressDlg::OnBnClickedStartButton)
END_MESSAGE_MAP()


// CProgressDlg 訊息處理常式

BOOL CProgressDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此加入額外的初始化
	// 
	// 設定進度條範圍與初始值
	m_ProgressBar.SetRange(0, 100);
	m_ProgressBar.SetPos(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void CProgressDlg::OnBnClickedStartButton()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CStatic* title = (CStatic*)GetDlgItem(IDC_STATIC);
	title->SetWindowTextW(_T("請稍候..."));
	LPCWSTR ps_cmd = L"ping 8.8.8.8";

	for (int i = 0; i <= 100; ++i) {
		m_ProgressBar.SetPos(i);
		Sleep(25);
	}

	EndDialog(IDOK);
}
