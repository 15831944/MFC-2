#include "stdafx.h"
#include "Works.h"
#include "WorksDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWorksDlg::CWorksDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WORKS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWorksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWorksDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_WORK_LOOKUP, &CWorksDlg::OnBnClickedWorkLookup)
	ON_BN_CLICKED(IDC_WORK_ADD, &CWorksDlg::OnBnClickedWorkAdd)
	ON_BN_CLICKED(IDC_WORK_DELE, &CWorksDlg::OnBnClickedWorkDele)
	ON_BN_CLICKED(IDC_WORK_MODIFY, &CWorksDlg::OnBnClickedWorkModify)
	ON_BN_CLICKED(IDC_WORK_SAVE, &CWorksDlg::OnBnClickedWorkSave)
END_MESSAGE_MAP()

BOOL CWorksDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);

/***********************************************************
	part 1 ���е�λ
		InsertColumn(0, _T("����"), LVCFMT_LEFT, 150);	
***********************************************************/
	pList->InsertColumn(0, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(1, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(2, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(3, _T("��ְ����"), LVCFMT_LEFT, 246);

/***********************************************************
	part 2 �б�����ɫ
		SetBkColor(RGB(205, 226, 252));	
***********************************************************/
	pList->SetBkColor(RGB(205, 226, 252));

/***********************************************************
	part 3 �б�����ֱ�����ɫ
		SetTextBkColor(RGB(205, 226, 252));
***********************************************************/
	pList->SetTextBkColor(RGB(205, 226, 252));

/***********************************************************
	part 4 �б��������ɫ
		 SetTextColor(RGB(0, 0, 255));
***********************************************************/
	pList->SetTextColor(RGB(0, 0, 255));

/***********************************************************
	part 5 �б��������
		 SetExtendedStyle(LVS_EX_AUTOCHECKSELECT)	�и�����,����ѡ��ȫѡ
		 SetExtendedStyle(LVS_EX_CHECKBOXES)		ÿ��ѡ���ɸ�����,����ѡ
		 SetExtendedStyle(LVS_EX_FULLROWSELECT);	ѡ��֮��,���и���
		 SetExtendedStyle(LVS_EX_GRIDLINES);		��������״,���ݷ��зֿ�
		 SetExtendedStyle(LVS_EX_HIDELABELS);		���ر�ǩ
		 SetExtendedStyle(LVS_EX_ONECLICKACTIVATE); ���ָ��ѡ���,�����ͼ��,�ĳ���ָ�����Ǽ�ͷ
		 SetExtendedStyle(LVS_EX_TRANSPARENTBKGND); �б��ı�����ɫ�����屳����ɫ������һ��
		 SetExtendedStyle(LVS_EX_TWOCLICKACTIVATE); ���ѡ��ѡ���,����ڸ���ķ�Χ��,���ͼ������ָ,�����Ǽ���ͷ,�Ƴ�ѡ��Ǽ�ͷ
		 SetExtendedStyle(LVS_EX_AUTOSIZECOLUMNS)	????
		 SetExtendedStyle(LVS_EX_AUTOAUTOARRANGE)	????
		 SetExtendedStyle(LVS_EX_BORDERSELECT);		????
		 SetExtendedStyle(LVS_EX_COLUMNOVERFLOW);	????
		 SetExtendedStyle(LVS_EX_COLUMNSNAPPOINTS);	????
		 SetExtendedStyle(LVS_EX_DOUBLEBUFFER);		����ͨ��˫����,�Ӷ�������˸.������չ���Ҳʹ�����������Ļѡ��ϵͳ��,����֧��
		 SetExtendedStyle(LVS_EX_FLATSB);			????
		 SetExtendedStyle(LVS_EX_HEADERDRAGDROP);	????
		 SetExtendedStyle(LVS_EX_HEADERINALLVIEWS); ????
		 SetExtendedStyle(LVS_EX_INFOTIP);			????
		 SetExtendedStyle(LVS_EX_JUSTIFYCOLUMNS);	????
		 SetExtendedStyle(LVS_EX_LABELTIP);			????
		 SetExtendedStyle(LVS_EX_MULTIWORKAREAS);	????
		 SetExtendedStyle(LVS_EX_REGIONAL);			????
		 SetExtendedStyle(LVS_EX_SIMPLESELECT);		????
		 SetExtendedStyle(LVS_EX_SINGLEROW);		????
		 SetExtendedStyle(LVS_EX_SUBITEMIMAGES);	????
		 SetExtendedStyle(LVS_EX_TRACKSELECT);		????
		 SetExtendedStyle(LVS_EX_TRANSPARENTSHADOWTEXT);	????
		 SetExtendedStyle(LVS_EX_UNDERLINECOLD); �����Ŀ���»����ı���ʾ,Ҫ��LVS_EX_TWOCLICKACTIVATEҲ����
		 SetExtendedStyle(LVS_EX_UNDERLINEHOT); ����Ƶ���Ŀ���»����ı���ʾ,Ҫ��LVS_EX_ONECLICKACTIVATE��LVS_EX_TWOCLICKACTIVATEҲ����
***********************************************************/
	pList->SetExtendedStyle(LVS_EX_AUTOCHECKSELECT | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |LVS_EX_DOUBLEBUFFER);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CWorksDlg::OnPaint()
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

HCURSOR CWorksDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWorksDlg::OnBnClickedWorkLookup()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL CWorksDlg::CheckNumber(LPCTSTR str)
{
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	int row = pList->GetItemCount();
	int i = 0;
	while (i < row)
	{
		if (pList->GetItemText(i, 0) == str)
		{
			CString error;
			error.Format(_T("����: %d, �Ѿ�����!"), _tstoi(str));
			AfxMessageBox(error);

/***********************************************************
	part 8 ����ָ��ָ���ĵط�
		SetFocus();	
***********************************************************/
/***********************************************************
	part 9 Ĭ��ָ��1��λ��
		Works.rc����, Ctrl + d ��������Ĭ�ϵ�1�ı��,��һ�¾�Ϊ1
***********************************************************/
			SetFocus();

/***********************************************************
	part 15 �ı���
		IDC_WORK_NUB
		IDC_WORK_NAME
		IDC_WORK_WAGE
		IDC_WORK_WAGE	�ÿ�
***********************************************************/
			SetDlgItemText(IDC_WORK_NUB, NULL);
			SetDlgItemText(IDC_WORK_NAME, NULL);
			SetDlgItemText(IDC_WORK_WAGE, NULL);
			SetDlgItemText(IDC_WORK_DATE, NULL);
			return FALSE;
		}
		++i;
	}
	return TRUE;
}
void CWorksDlg::OnBnClickedWorkAdd()
{
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);

/***********************************************************
	part 6 ��ȡ����
		GetItemCount();	
***********************************************************/
	int row = pList->GetItemCount();
	int i = 0;
	CString nub, name, wage, date;
	GetDlgItemText(IDC_WORK_NUB, nub);
	GetDlgItemText(IDC_WORK_NAME, name);
	GetDlgItemText(IDC_WORK_WAGE, wage);
	GetDlgItemText(IDC_WORK_DATE, date);
	if (nub.IsEmpty())
	{
		AfxMessageBox(_T("���Ų���Ϊ��"));
		return;
	}
	if (name.IsEmpty())
	{
		AfxMessageBox(_T("��������Ϊ��"));
		return;
	}
	if (wage.IsEmpty())
	{
		AfxMessageBox(_T("���ʲ���Ϊ��"));
		return;
	}

/***********************************************************
	part 7 �������Ƿ����:TRUE ���Բ���, FALSE �����Բ���
***********************************************************/
	if (CheckNumber(nub) == FALSE)
	{
		return;
	}
/***********************************************************
	part 8 	����0��,���������(0��1��)
		InsertItem(0, nub);
***********************************************************/
	pList->InsertItem(row, nub);

/***********************************************************
	part 9 	������:InsertItem(0, nub),�ٿ�������0��1������
		SetItemText(0, 1, nub);
***********************************************************/
	pList->SetItemText(row, 1, name);
	pList->SetItemText(row, 2, wage);
	pList->SetItemText(row, 3, date);
}


/***********************************************************
	part 10 �����е�����
		GetSelectedColumn() 
***********************************************************/
/***********************************************************
	part 11 ���㿪ʼ��ѡ�б�ǻ�-1;���δѡ�б�ǡ�����Ժ���ԶΪ1
		GetSelectionMark() 
***********************************************************/
/***********************************************************
	part 12 ѡ����������б���ͼ�ؼ��ġ�
		GetSelectedCount() 
***********************************************************/
void CWorksDlg::OnBnClickedWorkDele()
{
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	if (!pList->GetSelectedCount())
	{
			AfxMessageBox(_T("��ѡ��һ����ɾ��!"));
			return;
	}
	int nSel = pList->GetSelectionMark();

/***********************************************************
	part 11 ��ȡ�ڼ��еڼ��еĵ�����
		GetItemText(x ,y) 
***********************************************************/
	CString str = pList->GetItemText(nSel, 1);
	if (AfxMessageBox(_T("��ȷ��Ҫɾ�� ") + str + _T(" ��?"), MB_YESNO) == IDYES)
	{
/***********************************************************
	part 12 ɾ����y��
		DeleteItem(y) 
***********************************************************/
		pList->DeleteItem(nSel);
	}
}


void CWorksDlg::OnBnClickedWorkModify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CWorksDlg::FileError(int error)
{
	switch (error)
	{
	case CFileException::genericException:
		AfxMessageBox(_T("Error: ������δָ���Ĵ���\n"));
		break;
	case CFileException::fileNotFound:
		AfxMessageBox(_T("Error: δ�ܶ�λ���ļ���\n"));
		break;
	case CFileException::badPath:
		AfxMessageBox(_T("Error: ȫ���򲿷�·����Ч��\n"));
		break;
	case CFileException::tooManyOpenFiles:
		AfxMessageBox(_T("Error: �ѳ�������򿪵��ļ�����\n"));
		break;
	case CFileException::accessDenied:
		AfxMessageBox(_T("Error: �޷����ʸ��ļ���\n"));
		break;
	case CFileException::invalidFile:
		AfxMessageBox(_T("Error: �ѳ���ʹ����Ч���ļ������\n"));
		break;
	case CFileException::removeCurrentDir:
		AfxMessageBox(_T("Error: �޷��Ƴ���ǰ����Ŀ¼��\n"));
		break;
	case CFileException::directoryFull:
		AfxMessageBox(_T("Error: û�и����Ŀ¼�\n"));
		break;
	case CFileException::badSeek:
		AfxMessageBox(_T("Error: ���ڳ��������ļ�ָ��ʱ����\n"));
		break;
	case CFileException::hardIO:
		AfxMessageBox(_T("Error: ������Ӳ������\n"));
	case CFileException::sharingViolation:
		AfxMessageBox(_T("Error: δ���� SHARE.EXE ���������ѱ�������\n"));
		break;
	case CFileException::lockViolation:
		AfxMessageBox(_T("Error: �ѳ��������Ѿ�����������\n"));
		break;
	case CFileException::diskFull:
		AfxMessageBox(_T("Error: ����������\n"));
		break;
	case CFileException::endOfFile:
		AfxMessageBox(_T("Error: �ѵ����ļ�ĩβ��\n"));
		break;		
	}
	return;
}
void CWorksDlg::OnBnClickedWorkSave()
{
	CFile file;
	CFileException error;
	CString FileName = _T("./data/WorksData.dat");

/***********************************************************
	part 13 ·�������Ǵ��ڵ�,��Ȼ��ʧ��!
		file.Open;  
***********************************************************/
	if (!file.Open(FileName, CFile::modeCreate | CFile::modeWrite, &error))
	{
/***********************************************************
	part 14 �ļ�����
		FileError()
***********************************************************/
		FileError(error.m_cause);
		return;
	}

	while()
	file.Close();
}





