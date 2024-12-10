// CWelcomeDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MyFirstMFCApp.h"
#include "afxdialogex.h"
#include "CWelcomeDlg.h"


// CWelcomeDlg 對話方塊

IMPLEMENT_DYNAMIC(CWelcomeDlg, CDialogEx)

CWelcomeDlg::CWelcomeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_WELCOME, pParent)
{

}

CWelcomeDlg::~CWelcomeDlg()
{
}

void CWelcomeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWelcomeDlg, CDialogEx)
END_MESSAGE_MAP()


// CWelcomeDlg 訊息處理常式
