#pragma once
#include "afxdialogex.h"


// CPageMain 對話方塊

class CPageMain : public CDialogEx
{
	DECLARE_DYNAMIC(CPageMain)

public:
	CPageMain(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CPageMain();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonPwdComfirm();
	CString m_InputText_PWD;
	afx_msg void OnBnClickedButtonAddItem();
	afx_msg void OnBnClickedButtonRemoveItem();
	afx_msg void OnBnClickedButtonCheckBoxes();
};
