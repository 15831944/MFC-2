#include "stdafx.h"
#include "MamyTest.h"
#include "MamyTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMamyTestDlg::CMamyTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MAMYTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMamyTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMamyTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMamyTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMamyTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMamyTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMamyTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMamyTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMamyTestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMamyTestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMamyTestDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON12, &CMamyTestDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON9, &CMamyTestDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMamyTestDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMamyTestDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CMamyTestDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMamyTestDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMamyTestDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMamyTestDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMamyTestDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMamyTestDlg::OnBnClickedButton18)
END_MESSAGE_MAP()

BOOL CMamyTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMamyTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMamyTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/********************************************************
	part 1 operator +

********************************************************/
void CMamyTestDlg::OnBnClickedButton1()
{
	CString str1 = _T("aaaa");
	CString str2 = _T("123");
	CString str3;
	str3 = str1 + str2;
	str3 = _T('!') + str1;
	str3 = str2 + _T('!');
	str3 = str1 + L'A';
	str3 = L'A' + str2;
	MessageBox(str3);
}

/********************************************************
	part 2 Delete

********************************************************/
void CMamyTestDlg::OnBnClickedButton2()
{
	CString str(_T("Soccer is best, but hockey is quicker!"));
	SetWindowText(str);
	int n = str.Delete(6, 3);
	MessageBox(str);
}

/********************************************************
	part 3 Find

********************************************************/
void CMamyTestDlg::OnBnClickedButton3()
{
	CString s(_T("abcdef"));
	int nub = s.Find(_T("c"));
	if (nub> 0)
	{
		MessageBox(_T("找到了!"));
	}
	else
	{
		goto failed;
	}
	nub = s.Find(_T("de"));
	if (nub > 0)
	{
		MessageBox(_T("找到了!"));
	}
	else
	{
		goto failed;
	}
	return;
failed:
	MessageBox(_T("跪了!"));

}

/********************************************************
	part 4 operator +=

********************************************************/
void CMamyTestDlg::OnBnClickedButton4()
{
	CString s(_T("abc"));
	SetWindowText(s);
	MessageBox(_T("def"));
	MessageBox(s += _T("def"));

}

/********************************************************
	part 5 Compare

********************************************************/
void CMamyTestDlg::OnBnClickedButton5()
{
	CString s(_T("abc"));
	SetWindowText(s);
	int nub = s.Compare(_T("abc1"));
	if (nub > 0)
	{
		MessageBox(_T("题目被大了"));
	}
	else if (nub == 0)
	{
		MessageBox(_T("跟题目一样"));
	}
	else
	{
		MessageBox(_T("题目大了"));
	}
}

/********************************************************
	part 6 CompareNoCase

********************************************************/
void CMamyTestDlg::OnBnClickedButton6()
{
	CString s(_T("abc"));
	
	SetWindowText(s);

	int nub = s.CompareNoCase(_T("ABC"));
	if (nub > 0)
	{
		MessageBox(_T("题目被大了"));
	}
	else if (nub == 0)
	{
		MessageBox(_T("跟题目一样"));
	}
	else
	{
		MessageBox(_T("题目大了"));
	}
}

/********************************************************
	part 7 Format

********************************************************/
void CMamyTestDlg::OnBnClickedButton7()
{
	CAtlString str;
	str.Format(_T("Floating point: %.2f\n"), 12345.12345);
	MessageBox(str);
	str.Format(_T("Left-justified integer: %.6d\n"), 35);
	MessageBox(str);
}

/********************************************************
	part 8 Right

********************************************************/
void CMamyTestDlg::OnBnClickedButton8()
{
	CString s(_T("abcdef"));
	MessageBox(s.Right(10));
	MessageBox(s.Right(4));
	MessageBox(s.Right(2));
}

/********************************************************
	part 9 Left

********************************************************/
void CMamyTestDlg::OnBnClickedButton12()
{
	CString s(_T("abcdef"));
	MessageBox(s.Left(10));
	MessageBox(s.Left(4));
	MessageBox(s.Left(2));
}

/********************************************************
	part 10 Remove

********************************************************/
void CMamyTestDlg::OnBnClickedButton9()
{
	CString str(_T("This is a test."));
	SetWindowText(str);
	CString str1;
	int n = str.Remove(_T('t'));
	str1.Format(_T("---remove nub %d"), n);
	str += str1;
	MessageBox(str);
}

/********************************************************
	part 11 Replace

********************************************************/
void CMamyTestDlg::OnBnClickedButton10()
{
	CString strBang(_T("Hi, Everybody. I' m Ollen!"));
	SetWindowText(strBang);
	int n = strBang.Replace(_T("as"), _T("eby"));
	if (n)
	{
		MessageBox(strBang);
	}
	else
	{
		MessageBox(_T("没找到要替换的关键字!"));
	}
}

/********************************************************
	part 12 FindOneOf

********************************************************/
void CMamyTestDlg::OnBnClickedButton11()
{
	CString s(_T("abcdef"));
	CString s1;
	s1.Format(_T("%d"), s.FindOneOf(_T("by")));
	MessageBox(s1);
}

/********************************************************
	part 13 LoadString

********************************************************/
void CMamyTestDlg::OnBnClickedButton13()
{
	CString s;
	s.LoadString(IDS_STRING130);
	AfxMessageBox(s);
}

/********************************************************
	part 14 MakeReverse

********************************************************/
void CMamyTestDlg::OnBnClickedButton14()
{
	CString s(_T("abc"));
	MessageBox(s);
	s.MakeReverse();
	MessageBox(s);
}

/********************************************************
	part 15 Mid

********************************************************/
void CMamyTestDlg::OnBnClickedButton15()
{
	CString s(_T("abcdefaaaaaaa"));
	CString s1 = s.Mid(3,3);
	MessageBox(s1);
}

/********************************************************
	part 16 Insert

********************************************************/
void CMamyTestDlg::OnBnClickedButton16()
{
	CAtlString str(_T("SoccerBest"));
	int n = str.Insert(6, _T("is "));
	MessageBox(str);
	n = str.Insert(6, _T(' '));
	ASSERT(n == str.GetLength());
	MessageBox(str);
	n = str.Insert(23, _T('!'));
	ASSERT(n == str.GetLength());
	MessageBox(str);
}

/********************************************************
	part 17 ReverseFind
	1)	获取程序地址: GetModuleFileName
	2)	反向查找:	int nub = s1.ReverseFind(_T('\\')), 返回在字符串的位置
	2)	截取程序地址的全程序名: Mid(nub + 1, 1000);

********************************************************/
void CMamyTestDlg::OnBnClickedButton17()
{
	TCHAR s[256];
	GetModuleFileName(NULL, s, _countof(s));
	CString s1 = s;
	int nub = s1.ReverseFind(_T('\\'));
	if (nub < 0)
	{
		return;
	}
	MessageBox(s);
	CString s2 = s1.Mid(nub+1, 100);
	MessageBox(s2);
	s2 = s1.Mid(nub + 1, s2.GetLength() - 4);
	MessageBox(s2);
}

/********************************************************
	part 18 ReleaseBuffer
	1)	获取系统c:\windows\system32: ::GetSystemDirectory(str.GetBuffer(1000), 1000);
	str获取的内容,但str.GetLength();依然是0
	需要str.ReleaseBuffer();//必须配合GetBuffer来使用, 修复字符串长度功能

********************************************************/
void CMamyTestDlg::OnBnClickedButton18()
{
	CString str;
	int nub = str.GetLength();
	::GetSystemDirectory(str.GetBuffer(1000), 1000);
	nub = str.GetLength();
	str.ReleaseBuffer();//必须配合GetBuffer来使用, 修复字符串长度功能
	nub = str.GetLength();
	MessageBox(str);
}
