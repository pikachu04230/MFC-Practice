#pragma once
#include "afxdialogex.h"
#include "CWelcomeDlg.h"
#include "CCurrentTime.h"
#include "CProgressDlg.h"


// CPageUtility 對話方塊

class CPageUtility : public CDialogEx
{
	DECLARE_DYNAMIC(CPageUtility)

public:
	CPageUtility(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CPageUtility();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_UTILITY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CCurrentTime* m_pCurrentTimeDlg;
	afx_msg void OnBnClickedButtonWelcomeDlg();
	afx_msg void OnBnClickedButtonProgressDlg();
	afx_msg void OnBnClickedButtonNcpa();
	afx_msg void OnBnClickedButtonCurrenttime();
	afx_msg void OnDestroy();
};
