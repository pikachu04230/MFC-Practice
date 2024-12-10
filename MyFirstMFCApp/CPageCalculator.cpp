// CPageCalculator.cpp: 實作檔案
//

#include "pch.h"
#include "MyFirstMFCApp.h"
#include "afxdialogex.h"
#include "CPageCalculator.h"


// CPageCalculator 對話方塊

IMPLEMENT_DYNAMIC(CPageCalculator, CDialogEx)

CPageCalculator::CPageCalculator(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAGE_CALCULATOR, pParent)
	, m_nAddend1(0)
	, m_nAddend2(0)
	, m_nResult(0)
{

}

CPageCalculator::~CPageCalculator()
{
}

void CPageCalculator::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CALCULATOR_NUM1, m_nAddend1);
	DDX_Text(pDX, IDC_EDIT_CALCULATOR_NUM2, m_nAddend2);
	DDX_Text(pDX, IDC_EDIT_CALCULATOR_RESULT, m_nResult);
}


BEGIN_MESSAGE_MAP(CPageCalculator, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CPageCalculator::OnBnClickedButtonCalculate)
END_MESSAGE_MAP()


// CPageCalculator 訊息處理常式


void CPageCalculator::OnBnClickedButtonCalculate()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(TRUE);
	m_nResult = m_nAddend1 + m_nAddend2;
	UpdateData(FALSE);
}
