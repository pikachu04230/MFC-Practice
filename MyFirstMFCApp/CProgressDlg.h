#pragma once
#include "afxdialogex.h"


// CProgressDlg 對話方塊

class CProgressDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProgressDlg)

public:
	CProgressDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CProgressDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_ProgressBar;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedStartButton();
};
