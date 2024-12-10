
// MyFirstMFCAppDlg.cpp: 實作檔案
//

#include "pch.h"
#include "framework.h"
#include "MyFirstMFCApp.h"
#include "MyFirstMFCAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyFirstMFCAppDlg 對話方塊



CMyFirstMFCAppDlg::CMyFirstMFCAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYFIRSTMFCAPP_DIALOG, pParent)
	, m_pPageMain(nullptr)
	, m_pPageEdit(nullptr)
	, m_pPageCalculator(nullptr)
	, m_pPageUtility(nullptr)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyFirstMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_tabCtrl);
}

BEGIN_MESSAGE_MAP(CMyFirstMFCAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CMyFirstMFCAppDlg::OnTcnSelchangeTabMain)
END_MESSAGE_MAP()


// CMyFirstMFCAppDlg 訊息處理常式

BOOL CMyFirstMFCAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定
	// 新增標籤頁
	m_tabCtrl.InsertItem(0, _T("Main"));
	m_tabCtrl.InsertItem(1, _T("Edit"));
	m_tabCtrl.InsertItem(2, _T("Calculator"));
	m_tabCtrl.InsertItem(3, _T("Utility"));

	// 初始化子對話方塊
	m_pPageMain			= new CPageMain();
	m_pPageEdit			= new CPageEdit();
	m_pPageCalculator	= new CPageCalculator();
	m_pPageUtility		= new CPageUtility();

	// 建立子對話方塊
	m_pPageMain			->Create(IDD_PAGE_MAIN, this);
	m_pPageEdit			->Create(IDD_PAGE_EDIT, this);
	m_pPageCalculator	->Create(IDD_PAGE_CALCULATOR, this);
	m_pPageUtility		->Create(IDD_PAGE_UTILITY, this);


	// 顯示第一個子對話方塊
	m_pPageMain->ShowWindow(SW_SHOW);
	m_pPageEdit->ShowWindow(SW_HIDE);
	m_pPageCalculator->ShowWindow(SW_HIDE);
	m_pPageUtility->ShowWindow(SW_HIDE);

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMyFirstMFCAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMyFirstMFCAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMyFirstMFCAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMyFirstMFCAppDlg::OnTcnSelchangeTabMain(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int nSel = m_tabCtrl.GetCurSel();
	m_pPageMain			->ShowWindow(nSel == 0 ? SW_SHOW : SW_HIDE);
	m_pPageEdit			->ShowWindow(nSel == 1 ? SW_SHOW : SW_HIDE);
	m_pPageCalculator	->ShowWindow(nSel == 2 ? SW_SHOW : SW_HIDE);
	m_pPageUtility		->ShowWindow(nSel == 3 ? SW_SHOW : SW_HIDE);
	*pResult = 0;
}
