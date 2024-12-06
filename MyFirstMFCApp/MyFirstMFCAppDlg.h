
// MyFirstMFCAppDlg.h: 標頭檔
//

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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString m_InputText1;
	CString m_InputText2;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedOk();
	// Calculator num1
	int m_nAddend1;
	// Calculator num2
	int m_nAddend2;
	// Calculator Result
	int m_nResult;
	afx_msg void OnBnClickedCalculate();
};
