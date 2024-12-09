#pragma once
#include "afxdialogex.h"


// CWelcomeDlg 對話方塊

class CWelcomeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWelcomeDlg)

public:
	CWelcomeDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CWelcomeDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WELCOME_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
};
