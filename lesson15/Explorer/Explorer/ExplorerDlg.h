#pragma once

//
//LPCTSTR CExplorerDlg::m_weeks[] =
//{
//	_T("������"), _T("����һ"), _T("���ڶ�"), _T("������"), 
//	_T("������"), _T("������"), _T("������"), NULL
//};
//


class CExplorerDlg : public CDialogEx
{
public:
	inline static BOOL IsHidden(const WIN32_FIND_DATA &c_file)
	{
		if (c_file.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
			return TRUE;
		if (!_tcscmp(c_file.cFileName, _T(".")))
			return TRUE;
		if (!_tcscmp(c_file.cFileName, _T("..")))
			return TRUE;
		return FALSE;
	}
	inline static BOOL IsHidden(const CFileFind &c_file)
	{
		if (c_file.IsHidden())
			return TRUE;
		if (!_tcscmp(c_file.GetFileName(), _T(".")))
			return TRUE;
		if (!_tcscmp(c_file.GetFileName(), _T(".")))
			return TRUE;
		return FALSE;
	}

	inline static void FileSize(const CFileFind &c_file, CString& str)
	{
		if (c_file.GetLength() > 1024 && c_file.GetLength() < 1024 * 1024)
			str.Format(_T("%dKB"), c_file.GetLength() / 1024);
		else if (c_file.GetLength() > 1024 * 1024 && c_file.GetLength() < 1024 * 1024 * 1024)
			str.Format(_T("%dMB"), c_file.GetLength() / 1024 * 1024);
		else if (c_file.GetLength() > 1024 * 1024 * 1024)
			str.Format(_T("%dGB"), c_file.GetLength() / 1024 * 1024 * 1024);
	}
	static LPCTSTR m_weeks[];
public:
	CExplorerDlg(CWnd* pParent = NULL);	// ��׼���캯��

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPLORER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	virtual void OnOK();
};
