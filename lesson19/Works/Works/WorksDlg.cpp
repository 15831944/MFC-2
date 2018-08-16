#include "stdafx.h"
#include "Works.h"
#include "WorksDlg.h"
#include "afxdialogex.h"

#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWorksDlg::CWorksDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WORKS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_Row = 0;
	m_bModify = FALSE;
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
	ON_BN_CLICKED(IDCANCEL, &CWorksDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

/***********************************************************
	part 1 ���е�λ
		InsertColumn(0, _T("����"), LVCFMT_LEFT, 150);
***********************************************************/
/***********************************************************
	part 2 �б�����ɫ
		SetBkColor(RGB(205, 226, 252));
***********************************************************/
/***********************************************************
	part 3 �б�����ֱ�����ɫ
		SetTextBkColor(RGB(205, 226, 252));
***********************************************************/
/***********************************************************
	part 4 �б��������ɫ
		SetTextColor(RGB(0, 0, 255));
***********************************************************/
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
BOOL CWorksDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(1, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(2, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(3, _T("��ְ����"), LVCFMT_LEFT, 246);

	pList->SetBkColor(RGB(205, 226, 252));
	pList->SetTextBkColor(RGB(205, 226, 252));
	pList->SetTextColor(RGB(0, 0, 255));
	pList->SetExtendedStyle(LVS_EX_AUTOCHECKSELECT | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |LVS_EX_DOUBLEBUFFER);
	
	free(pList);
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


/***********************************************************
	part 17 tData.ParseDateTime(����ʱ�����, ���)֮��ת����
		info.tData.Format(_T("%Y��%m��%d��"));
***********************************************************/
void CWorksDlg::OnBnClickedWorkLookup()
{

	CFile file;
	CFileException error;
	if (!file.Open(_T("./data/WorksData.dat"), CFile::modeRead, &error))
	{
		FileError(error.m_cause);
		return;
	}
	ULONGLONG FileLength = file.GetLength();
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	SInfo info;
	int count = FileLength/sizeof(SInfo);
	CString str;
	COleDateTime data;
	while (m_Row < count)
	{
		file.Read(&info, sizeof(info));
		str.Format(_T("%d"), info.nNumb);
		pList->InsertItem(m_Row, str);
		pList->SetItemText(m_Row, 1, info.sName);
		str.Format(_T("%0.2f"), info.fSala);
		pList->SetItemText(m_Row, 2, str);
		str = info.tData.Format(_T("%Y��%m��%d��"));
		pList->SetItemText(m_Row, 3, str);
		++m_Row;
	}
	free(pList);
}


/***********************************************************
	part 8 ����ָ��ָ���ĵط�
		SetFocus();
***********************************************************/
/***********************************************************
	part 9 Ĭ��ָ��1��λ��
		Works.rc����, Ctrl + d ��������Ĭ�ϵ�1�ı��,��һ�¾�Ϊ1
***********************************************************/
/***********************************************************
	part 15 �ı���
		IDC_WORK_NUB
		IDC_WORK_NAME
		IDC_WORK_WAGE
		IDC_WORK_WAGE	�ÿ�
***********************************************************/
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
			SetFocus();
			SetDlgItemText(IDC_WORK_NUB, NULL);
			SetDlgItemText(IDC_WORK_NAME, NULL);
			SetDlgItemText(IDC_WORK_WAGE, NULL);
			SetDlgItemText(IDC_WORK_DATE, NULL);
			return FALSE;
		}
		++i;
	}
	free(pList);
	return TRUE;
}

/***********************************************************
	part 6 ��ȡ����
		GetItemCount();
***********************************************************/
/***********************************************************
	part 7 �������Ƿ����:TRUE ���Բ���, FALSE �����Բ���
***********************************************************/
/***********************************************************
	part 8 	����0��,���������(0��1��)
		InsertItem(0, nub);
***********************************************************/
/***********************************************************
	part 9 	������:InsertItem(0, nub),�ٿ�������0��1������
		SetItemText(0, 1, nub);
***********************************************************/
void CWorksDlg::OnBnClickedWorkAdd()
{
	CInputDlg dlg;
	dlg.DoModal();
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);
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
	if (CheckNumber(nub) == FALSE)
	{
		return;
	}
	pList->InsertItem(row, nub);
	pList->SetItemText(row, 1, name);
	pList->SetItemText(row, 2, wage);
	pList->SetItemText(row, 3, date);
	m_bModify = TRUE;
	free(pList);
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
/***********************************************************
	part 11 ��ȡ�ڼ��еڼ��еĵ�����
	GetItemText(x ,y)
***********************************************************/
/***********************************************************
	part 12 ɾ����y��
		DeleteItem(y)

void CWorksDlg::OnBnClickedWorkDele()
{
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	if (!pList->GetSelectedCount())
	{
			AfxMessageBox(_T("��ѡ��һ����ɾ��!"));
			return;
	}
	int nSel = pList->GetSelectionMark();
	CString str = pList->GetItemText(nSel, 1);
	if (AfxMessageBox(_T("��ȷ��Ҫɾ�� ") + str + _T(" ��?"), MB_YESNO) == IDYES)
	{

		pList->DeleteItem(nSel);
	}
}
***********************************************************/

/***********************************************************
	part 20 ѡ�еڼ��к͵ڼ�+n�н���ɾ��
	POSITION pos = pList->GetFirstSelectedItemPosition();
	��ȡѡ�е������б�ı�ͷ
***********************************************************/
void CWorksDlg::OnBnClickedWorkDele()
{
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	POSITION pos = pList->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(_T("��ѡ��һ����ɾ��!\n"));
		return;
	}
	else
	{
		while (pos)
		{
			int nItem = pList->GetNextSelectedItem(pos);
			CString str = pList->GetItemText(nItem, 0);
			if (IDNO == AfxMessageBox(_T("��ȷ��Ҫɾ�����λ: ") + str + _T("����Ϣ��?"), MB_YESNO))
				continue;
			pList->DeleteItem(nItem);
		}
		m_bModify = TRUE;
	}
	free(pList);
}


void CWorksDlg::OnBnClickedWorkModify()
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	
/***********************************************************
	part 18 ѡ�еڼ��к͵ڼ�+n�н����޸�
		POSITION pos = pList->GetFirstSelectedItemPosition();
		��ȡѡ�е������б�ı�ͷ
***********************************************************/
/***********************************************************
	part 19 ��ѡ���б���в���
		int nItem = pList->GetNextSelectedItem(pos);
		��ȡ�б������
***********************************************************/
	POSITION pos = pList->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(_T("��ѡ��һ�����޸�!\n"));
		return;
	}
	else
	{
		while (pos)
		{

			int nItem = pList->GetNextSelectedItem(pos);
			CString str = pList->GetItemText(nItem, 0);
			if (IDNO == AfxMessageBox(_T("��ȷ��Ҫ�޸ı��λ: ") + str + _T("����Ϣ��?"), MB_YESNO))
				continue;

			if(GetDlgItemText(IDC_WORK_NUB, str))
				pList->SetItemText(nItem, 0, str);

			if(GetDlgItemText(IDC_WORK_NAME, str))
				pList->SetItemText(nItem, 1, str);

			if(GetDlgItemText(IDC_WORK_WAGE, str))
				pList->SetItemText(nItem, 2, str);

			if (GetDlgItemText(IDC_WORK_DATE, str))
				pList->SetItemText(nItem, 3, str);
		}
		m_bModify = TRUE;
	}
	free(pList);
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
/***********************************************************
	part 13 ·�������Ǵ��ڵ�,��Ȼ��ʧ��!
		file.Open;
***********************************************************/
/***********************************************************
	part 14 �ļ�����
		FileError()
***********************************************************/
/***********************************************************
	part 16 ʱ�亯��
		COleDateTime tData;
		tData.ParseDateTime(����ʱ�����, ���)
***********************************************************/
void CWorksDlg::OnBnClickedWorkSave()
{
	CFile file;
	CFileException error;
	CString FileName = _T("./data/WorksData.dat");
	if (!file.Open(FileName, CFile::modeCreate | CFile::modeWrite, &error))
	{

		FileError(error.m_cause);
		return;
	}
	SInfo info;
	int i = 0;
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	while (i < pList->GetItemCount())
	{
		info.nNumb = _tstoi(pList->GetItemText(i, 0));
		memcpy(info.sName, pList->GetItemText(i, 1), sizeof(info.sName));
		info.fSala = _tstof(pList->GetItemText(i, 2));

		info.tData.ParseDateTime(pList->GetItemText(i, 3), VAR_DATEVALUEONLY);

		file.Write(&info, sizeof(info));
		++i;
	}
	file.Close();
	m_bModify = FALSE;
	free(pList);
}







void CWorksDlg::OnBnClickedCancel()
{
	if (m_bModify)
	{
		if (IDYES == AfxMessageBox(_T("�Ƿ񱣴�Ķ���������? "), MB_YESNO | MB_ICONQUESTION))
		{
			OnBnClickedWorkSave();
		}	
	}	
	CDialogEx::OnCancel();
}
