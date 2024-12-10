
// MyFirstMFCAppDlg.h: 標頭檔
//
#include "CPageMain.h"
#include "CPageEdit.h"
#include "CPageCalculator.h"
#include "CPageUtility.h"

#pragma once


// CMyFirstMFCAppDlg 對話方塊
class CMyFirstMFCAppDlg : public CDialogEx
{
// 建構
public:
	CMyFirstMFCAppDlg(CWnd* pParent = nullptr);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYFIRSTMFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CPageMain*			m_pPageMain;
	CPageEdit*			m_pPageEdit;
	CPageCalculator*	m_pPageCalculator;
	CPageUtility*		m_pPageUtility;

	CTabCtrl m_tabCtrl;
	afx_msg void OnTcnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult);
};
