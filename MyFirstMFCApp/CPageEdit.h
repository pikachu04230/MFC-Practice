#pragma once
#include "afxdialogex.h"


// CPageEdit 對話方塊

class CPageEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CPageEdit)

public:
	CPageEdit(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CPageEdit();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_EDIT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CString m_InputText_Edit;
	afx_msg void OnBnClickedButtonEditInteraction();
	afx_msg void OnBnClickedButtonChosen();
};
