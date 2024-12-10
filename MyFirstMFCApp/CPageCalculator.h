#pragma once
#include "afxdialogex.h"


// CPageCalculator 對話方塊

class CPageCalculator : public CDialogEx
{
	DECLARE_DYNAMIC(CPageCalculator)

public:
	CPageCalculator(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CPageCalculator();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_CALCULATOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonCalculate();
	int m_nAddend1;
	int m_nAddend2;
	int m_nResult;
};
