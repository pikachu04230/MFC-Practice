
// MyFirstMFCAppDlg.cpp: 實作檔案
//

#include "pch.h"
#include "framework.h"
#include "MyFirstMFCApp.h"
#include "MyFirstMFCAppDlg.h"
#include "CWelcomeDlg.h"
#include "CProgressDlg.h"
#include "CCurrentTime.h"
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
	, m_InputText1(_T(""))
	, m_InputText2(_T(""))
	, m_nAddend1(0)
	, m_nAddend2(0)
	, m_nResult(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyFirstMFCAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_InputText1);
	DDX_Text(pDX, IDC_EDIT2, m_InputText2);
	DDX_Text(pDX, IDC_CALCULATOR_NUM1, m_nAddend1);
	DDX_Text(pDX, IDC_CALCULATOR_NUM2, m_nAddend2);
	DDX_Text(pDX, IDC_CALCULATOR_RESULT, m_nResult);
}

BEGIN_MESSAGE_MAP(CMyFirstMFCAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyFirstMFCAppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyFirstMFCAppDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyFirstMFCAppDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyFirstMFCAppDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyFirstMFCAppDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDOK, &CMyFirstMFCAppDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CALCULATE, &CMyFirstMFCAppDlg::OnBnClickedCalculate)
	ON_BN_CLICKED(IDC_BUTTON_NCPA, &CMyFirstMFCAppDlg::OnBnClickedButtonNcpa)
	ON_BN_CLICKED(IDC_WELCOME_DLG_BUTTON, &CMyFirstMFCAppDlg::OnBnClickedWelcomeDlgButton)
	ON_BN_CLICKED(IDC_PROGRESS_DLG_BUTTON, &CMyFirstMFCAppDlg::OnBnClickedProgressDlgButton)
	ON_BN_CLICKED(IDC_CURRENTTIME, &CMyFirstMFCAppDlg::OnBnClickedCurrenttime)
	ON_WM_DESTROY()
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
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pListBox->AddString(_T("項目 L1"));
	pListBox->AddString(_T("項目 L2"));
	pListBox->AddString(_T("項目 L3"));
	pComboBox->AddString(_T("項目 C1"));
	pComboBox->AddString(_T("項目 C2"));
	pComboBox->AddString(_T("項目 C3"));

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



void CMyFirstMFCAppDlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int nResponse = AfxMessageBox(_T("按鈕1被點擊了！"), MB_ABORTRETRYIGNORE|MB_ICONSTOP);

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);

	switch (nResponse)
	{
	case IDRETRY:
	case IDABORT:
		pEdit->SetWindowText(_T("按鈕1被點擊了"));
		break;
	case IDIGNORE:
		pEdit->SetWindowText(_T("被無視了"));
		break;
	default:
		pEdit->SetWindowText(_T("Error"));
		break;
	}
}

void CMyFirstMFCAppDlg::OnBnClickedButton2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (UpdateData(TRUE))
	{
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		if (pEdit == nullptr) {
			AfxMessageBox(_T("無法找到編輯框控制項！"));
			return;
		}

		int nStartChar, nEndChar;
		CString msg;

		// 確保編輯框內有文本
		int nTextLength = pEdit->GetWindowTextLength();
		if (nTextLength > 0) {
			pEdit->GetSel(nStartChar, nEndChar);  // 獲取選中的文本範圍

			if (nStartChar == nEndChar)
			{
				AfxMessageBox(_T("你沒有選擇任何文字..."));
			}
			else
			{
				msg.Format(_T("你選了%d~%d，嘻嘻！"), nStartChar, nEndChar);

				int nResponse = AfxMessageBox(msg, MB_RETRYCANCEL | MB_ICONERROR);

				if (nResponse == IDRETRY)
				{
					// 設置選中從字符 0 到 3 的範圍
					pEdit->SetSel(0, 3);
					AfxMessageBox(_T("幫你把前三個字選起來"), MB_ICONINFORMATION);
				}
				else
				{
					pEdit->SetSel(0, 5);
					AfxMessageBox(_T("幫你把前五個字選起來"), MB_ICONINFORMATION);
				}
			}
			// 設置焦點回到編輯框，這樣選擇的文字會顯示出來
			pEdit->SetFocus();
		}
		else {
			AfxMessageBox(_T("文本框內沒有足夠的文本！"));
		}
	}
}
void CMyFirstMFCAppDlg::OnBnClickedButton3()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int nResponse = AfxMessageBox(_T("你確定要繼續嗎？"), MB_YESNO | MB_ICONWARNING);
	if (nResponse == IDYES) {
		// 使用者選擇了 "Yes"
		if (UpdateData(TRUE)) {
			if (m_InputText2.GetLength() > 0)
			{
				AfxMessageBox(m_InputText2, MB_ICONINFORMATION);
			}
			else
			{
				AfxMessageBox(_T("請輸入密碼!"), MB_ICONERROR);
			}
		}
	}
	else {
		// 使用者選擇了 "No"
		AfxMessageBox(_T("Oh No!"), MB_ICONERROR);
	}
}

void CMyFirstMFCAppDlg::OnBnClickedButton4()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	int count = pListBox->GetCount();
	CString s;
	s.Format(_T("項目 L%d"), count+1);
	pListBox->AddString(s);
}


void CMyFirstMFCAppDlg::OnBnClickedButton5()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	int count = pListBox->GetCount();
	if (count > 0)
	{
		pListBox->DeleteString(count-1);	// Delete last
	}
	else
	{
		AfxMessageBox(_T("No item to delete!"));
	}
}


void CMyFirstMFCAppDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO1);

	// Show ListBox Chosen items
	int nSelCount = pListBox->GetSelCount();
	if (nSelCount > 0)
	{
		CString msg = _T("ListBox Selected:\n");
		int nCount = pListBox->GetCount();
		int nChosen = 0;
		bool firstLine = true;
		for (int i = 0; i < nCount; i++)
		{
			if (pListBox->GetSel(i))
			{
				CString sItem;
				pListBox->GetText(i, sItem);
				if (firstLine)
				{
					msg += sItem;
					firstLine = false;
				}
				else
				{
					msg += _T("\n") + sItem;
				}
			}
		}
		AfxMessageBox(msg, MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		AfxMessageBox(_T("No item Selected in ListBox!"), MB_OK | MB_ICONERROR);
	}

	// Show ComboBox Chosen items
	int nIndex = pComboBox->GetCurSel();
	if (nIndex != CB_ERR)
	{
		CString msg, sItem;
		pComboBox->GetLBText(nIndex, sItem);
		msg = _T("ComboBox Selected:\n") + sItem;
		AfxMessageBox(msg, MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		AfxMessageBox(_T("No item Selected in ComboBox!"), MB_OK | MB_ICONERROR);
	}

	// Show Edit2 text
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString msg;
	UpdateData(TRUE);
	if (pEdit->GetWindowTextLength() > 0)
	{
		msg = _T("Your password is: ") + m_InputText2;
		AfxMessageBox(msg, MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		msg = _T("No password filled!");
		AfxMessageBox(msg, MB_ICONERROR);
	}

	CDialogEx::OnOK();
}


void CMyFirstMFCAppDlg::OnBnClickedCalculate()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(TRUE);
	m_nResult = m_nAddend1 + m_nAddend2;
	UpdateData(FALSE);
}


void CMyFirstMFCAppDlg::OnBnClickedButtonNcpa()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	ShellExecute(NULL, NULL, L"ncpa.cpl", NULL, NULL, SW_SHOWNORMAL);
}


void CMyFirstMFCAppDlg::OnBnClickedWelcomeDlgButton()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CWelcomeDlg dlg;
	dlg.DoModal();
}


void CMyFirstMFCAppDlg::OnBnClickedProgressDlgButton()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CProgressDlg dlg;
	dlg.DoModal();
}


void CMyFirstMFCAppDlg::OnBnClickedCurrenttime()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (m_pCurrentTimeDlg != nullptr && IsWindow(m_pCurrentTimeDlg->m_hWnd))
	{
		m_pCurrentTimeDlg->ShowWindow(SW_SHOW);
		m_pCurrentTimeDlg->SetFocus();
	}
	else
	{
		m_pCurrentTimeDlg = new CCurrentTime();
		m_pCurrentTimeDlg->Create(IDD_CURRENTTIME, this);
		m_pCurrentTimeDlg->ShowWindow(SW_SHOW);
	}
}


void CMyFirstMFCAppDlg::OnDestroy()
{
	// TODO: 在此加入您的訊息處理常式程式碼
	if (m_pCurrentTimeDlg != nullptr)
	{
		m_pCurrentTimeDlg->DestroyWindow();
		delete m_pCurrentTimeDlg;
		m_pCurrentTimeDlg = nullptr;
	}

	CDialogEx::OnDestroy();
}
