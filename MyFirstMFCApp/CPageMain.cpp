// CPageMain.cpp: 實作檔案
//

#include "pch.h"
#include "MyFirstMFCApp.h"
#include "afxdialogex.h"
#include "CPageMain.h"


// CPageMain 對話方塊

IMPLEMENT_DYNAMIC(CPageMain, CDialogEx)

CPageMain::CPageMain(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAGE_MAIN, pParent)
	, m_InputText_PWD(_T(""))
{

}

CPageMain::~CPageMain()
{
}

void CPageMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PWD, m_InputText_PWD);
}


BEGIN_MESSAGE_MAP(CPageMain, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PWD_COMFIRM, &CPageMain::OnBnClickedButtonPwdComfirm)
	ON_BN_CLICKED(IDC_BUTTON_ADD_ITEM, &CPageMain::OnBnClickedButtonAddItem)
	ON_BN_CLICKED(IDC_BUTTON_REMOVE_ITEM, &CPageMain::OnBnClickedButtonRemoveItem)
	ON_BN_CLICKED(IDC_BUTTON_CHECK_BOXES, &CPageMain::OnBnClickedButtonCheckBoxes)
END_MESSAGE_MAP()


// CPageMain 訊息處理常式


BOOL CPageMain::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此加入額外的初始化
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pListBox->AddString(_T("項目 L1"));
	pListBox->AddString(_T("項目 L2"));
	pListBox->AddString(_T("項目 L3"));
	pComboBox->AddString(_T("項目 C1"));
	pComboBox->AddString(_T("項目 C2"));
	pComboBox->AddString(_T("項目 C3"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void CPageMain::OnBnClickedButtonPwdComfirm()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int nResponse = AfxMessageBox(_T("你確定要繼續嗎？"), MB_YESNO | MB_ICONWARNING);
	if (nResponse == IDYES) {
		// 使用者選擇了 "Yes"
		if (UpdateData(TRUE)) {
			if (m_InputText_PWD.GetLength() > 0)
			{
				AfxMessageBox(m_InputText_PWD, MB_ICONINFORMATION);
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


void CPageMain::OnBnClickedButtonAddItem()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	int count = pListBox->GetCount();
	CString s;
	s.Format(_T("項目 L%d"), count + 1);
	pListBox->AddString(s);
}


void CPageMain::OnBnClickedButtonRemoveItem()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	int count = pListBox->GetCount();
	if (count > 0)
	{
		pListBox->DeleteString(count - 1);	// Remove last
	}
	else
	{
		AfxMessageBox(_T("No item to remove!"));
	}
}


void CPageMain::OnBnClickedButtonCheckBoxes()
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
}
