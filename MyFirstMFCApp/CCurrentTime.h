#pragma once
#include "afxdialogex.h"


// CCurrentTime 對話方塊

class CCurrentTime : public CDialogEx
{
	DECLARE_DYNAMIC(CCurrentTime)

public:
	CCurrentTime(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CCurrentTime();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CURRENTTIME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援
	CFont m_font;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void PostNcDestroy();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonHide();
};
