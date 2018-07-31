#include "stdafx.h"
#include "Explorer.h"
#include "ExplorerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CExplorerDlg::CExplorerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXPLORER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExplorerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExplorerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

BOOL CExplorerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0, _T("�ļ���"), 0, 300);
	pList->InsertColumn(1, _T("�޸�ʱ��"), 0, 180);
	pList->InsertColumn(2, _T("����"), 0, 120);
	pList->InsertColumn(3, _T("��С"), 0, 110);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CExplorerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
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


HCURSOR CExplorerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/********************************************************
part 1 _find()Ŀ¼����(C���Ժ���)
	1)	struct _finddata_t c_file;
		intptr_t hFile;
		if( (hFile = _findfirst( "*.c", &c_file )) == -1L )
			return;
		else{
		  do {
		  } while( _findnext( hFile, &c_file ) == 0 );
		  _findclose( hFile );
	    }
********************************************************/

/********************************************************
part 2	__time32_tʱ���ʽת��
	1)	COleDateTime time(c_file.time_write);
********************************************************/

/********************************************************
part 3	CString �����ַ������ҹؼ���ָ��λ
	1) int point =str.ReverseFind(_T('.'));
********************************************************/

/********************************************************
part 4	CString �ַ�����ȡһ��
	1) str.Mid(point)
********************************************************/

/********************************************************
part 5	�б�ؼ�
	1) CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	2) pList->DeleteAllItems();
	3) pList->InsertItem(countLine, c_file.name);
	4) pList->SetItemText(countLine, 2, str.Mid(point));

void CExplorerDlg::OnOK()
{
	struct _wfinddata_t c_file;
	intptr_t hFile;
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->DeleteAllItems();
	int countLine = 0;
	CString str;
	GetDlgItemText(IDC_ADDR, str);
	if ((hFile = _tfindfirst(str + _T("*.*"), &c_file)) == -1L)
		return;	
	else{
		do {
			if (!(c_file.attrib & _A_HIDDEN)){
				pList->InsertItem(countLine, c_file.name);
				COleDateTime time(c_file.time_write);
				str.Format(_T("%d/%02d/%02d/ %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), 
					time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
				pList->SetItemText(countLine, 1, str);
				str.Format(_T("%dKB"), c_file.size/1024);
				pList->SetItemText(countLine, 3, str);
			}
			str = c_file.name;
			int point =str.ReverseFind(_T('.'));
			if (point > 1)
				pList->SetItemText(countLine, 2, str.Mid(point));
			else
				pList->SetItemText(countLine, 2, _T("�ļ���"));
			++countLine;
		} while (_wfindnext(hFile, &c_file) == 0);
		_findclose(hFile);
	}
}
********************************************************/

/********************************************************
part 6 _find()Ŀ¼����(WIN32)
	1) 	WIN32_FIND_DATA c_file;
		HANDLE hFile;
		if ((hFile = FindFirstFile(str + _T("*.*"), &c_file)) == INVALID_HANDLE_VALUE || str.IsEmpty())
			return;
		else{
			do {
			} while (FindNextFile(hFile, &c_file));
			FindClose(hFile);
		}
********************************************************/
/********************************************************
part 7	��ȡ��������
	1) COleDateTime time(c_file.ftLastWriteTime);
	2) m_weeks[time.GetWeeks() - 1]

void CExplorerDlg::OnOK()
{
	WIN32_FIND_DATA c_file;
	HANDLE hFile;
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->DeleteAllItems();
	int countLine = 0;
	CString str;
	GetDlgItemText(IDC_ADDR, str);
	if ((hFile = FindFirstFile(str + _T("*.*"), &c_file)) == INVALID_HANDLE_VALUE || str.IsEmpty())
		return;
	else{
		do {
			if (!IsHidden(c_file)){
				pList->InsertItem(countLine, c_file.cFileName);
				COleDateTime time(c_file.ftLastWriteTime);
				str.Format(_T("%d/%02d/%02d/ %02d:%02d:%02d"), time.GetYear(), time.GetMonth(),
					time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
				pList->SetItemText(countLine, 1, str);
				str.Format(_T("%dKB"), c_file.nFileSizeLow / 1024);
				pList->SetItemText(countLine, 3, str);
			}		
			if (c_file.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				pList->SetItemText(countLine, 2, _T("�ļ���"));
			else{
				str = c_file.cFileName;
				int point = str.ReverseFind(_T('.'));
				pList->SetItemText(countLine, 2, str.Mid(point));
			}
			++countLine;
		} while (FindNextFile(hFile, &c_file));
		FindClose(hFile);
	}
}
********************************************************/
/********************************************************
part 8  _find()Ŀ¼����(C++)
	1) 	CFileFind c_file;
		BOOL hFile;
		if (!(hFile = c_file.FindFile(str + _T("\\*.*"))))
			return;
		else {
			while (hFile) {
				hFile = c_file.FindNextFile();
				if (!c_file.IsHidden() && !c_file.IsDots())
				{}
			}
			c_file.Close();
		}
********************************************************/
void CExplorerDlg::OnOK()
{
	CFileFind c_file;
	BOOL hFile;
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->DeleteAllItems();
	int countLine = 0;
	CString str;
	FILETIME ctime;
	GetDlgItemText(IDC_ADDR, str);
	if (!(hFile = c_file.FindFile(str + _T("\\*.*"))))
		return;
	else {
		while (hFile) {
			hFile = c_file.FindNextFile();
			if (!c_file.IsHidden() && !c_file.IsDots()){
				pList->InsertItem(countLine, c_file.GetFileName());
				c_file.GetLastWriteTime(&ctime);
				COleDateTime time(ctime);
				str.Format(_T("%d/%02d/%02d/ %02d:%02d:%02d"), time.GetYear(), time.GetMonth(),
					time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
				pList->SetItemText(countLine, 1, str);
				if (c_file.IsDirectory())			
					pList->SetItemText(countLine, 2, _T("�ļ���"));
				else {
					str = c_file.GetFileName();
					int point = str.ReverseFind(_T('.'));
					pList->SetItemText(countLine, 2, str.Mid(point));
					str.Format(_T("%dKB"), c_file.GetLength() / 1024);
					pList->SetItemText(countLine, 3, str);
				}
				++countLine;
			}
		} 
		c_file.Close();
	}
}
