// CPageEdit.cpp: 實作檔案
//

#include "pch.h"
#include "MyFirstMFCApp.h"
#include "afxdialogex.h"
#include "CPageEdit.h"


// CPageEdit 對話方塊

IMPLEMENT_DYNAMIC(CPageEdit, CDialogEx)

CPageEdit::CPageEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAGE_EDIT, pParent)
	, m_InputText_Edit(_T(""))
{

}

CPageEdit::~CPageEdit()
{
}

void CPageEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_InputText_Edit);
}


BEGIN_MESSAGE_MAP(CPageEdit, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EDIT_INTERACTION, &CPageEdit::OnBnClickedButtonEditInteraction)
	ON_BN_CLICKED(IDC_BUTTON_CHOSEN, &CPageEdit::OnBnClickedButtonChosen)
END_MESSAGE_MAP()


// CPageEdit 訊息處理常式


void CPageEdit::OnBnClickedButtonEditInteraction()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int nResponse = AfxMessageBox(_T("按鈕被點擊了！"), MB_ABORTRETRYIGNORE | MB_ICONSTOP);

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);

	switch (nResponse)
	{
	case IDABORT:
		pEdit->SetWindowText(_T("停也停不下來！"));
		break;
	case IDRETRY:
		pEdit->SetWindowText(_T("試再多次也一樣哦"));
		break;
	case IDIGNORE:
		pEdit->SetWindowText(_T("被無視了"));
		break;
	default:
		pEdit->SetWindowText(_T("Error"));
		break;
	}
}


void CPageEdit::OnBnClickedButtonChosen()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (UpdateData(TRUE))
	{
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT);
		if (pEdit == nullptr) {
			AfxMessageBox(_T("無法找到編輯框控制項！"));
			return;
		}

		int nStartChar = 0;
		int nEndChar = 0;
		CString msg = _T("");

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
				int length = nEndChar - nStartChar;
				CString subStr = m_InputText_Edit.Mid(nStartChar, length);
				msg = _T("你選了\"") + subStr + _T("\"，嘻嘻！");

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
