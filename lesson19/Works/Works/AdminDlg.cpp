#include "stdafx.h"
#include "Works.h"
#include "AdminDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CAdminDlg, CDialogEx)

CAdminDlg::CAdminDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRIRO_DLG, pParent)
{

}

CAdminDlg::~CAdminDlg()
{
}

void CAdminDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAdminDlg, CDialogEx)
	ON_BN_CLICKED(IDC_WORK_ADD, &CAdminDlg::OnBnClickedWorkAdd)
	ON_BN_CLICKED(IDC_WORK_DELE, &CAdminDlg::OnBnClickedWorkDele)
	ON_BN_CLICKED(IDC_WORK_MODIFY, &CAdminDlg::OnBnClickedWorkModify)
//	ON_WM_DESTROY()
END_MESSAGE_MAP()


/**********************************************
part 3 �����б��
	1)	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
		int nCount = pList->GetItemCount();
		pList->GetItemText(i, 0)
**********************************************/
BOOL CAdminDlg::Check(CString str)
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	int i = 0;
	int nCount = pList->GetItemCount();

	while (i < nCount)
	{
		if (pList->GetItemText(i, 0) == str)
			return TRUE;
		++i;
	}
	free(pList);
	return FALSE;
}
/*********************************************
part 4 ��ȡ�б�ؼ��ж���������
	1)	 pList->GetItemCount;
*********************************************/
/*********************************************
part 5 �����б�ؼ�
	1)	pList->InsertItem(n, str)
	2)	pList->SetItemText(n, 1, str)
*********************************************/
/*********************************************
part 10	д����ÿ�
	1)	SetDlgItemText(IDC_PASSWORK, _T(""));
*********************************************/
/*********************************************
part 11	д���ȡ�����
	1)	GetDlgItem(IDC_ACCOUNT)->SetFocus();
*********************************************/
void CAdminDlg::OnBnClickedWorkAdd()
{
	CString str;
	GetDlgItemText(IDC_ACCOUNT, str);
	if (Check(str))
	{
		AfxMessageBox(_T("�˻��Ѵ���, ����������!\n"));
		return;
	}

	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	int n = pList->GetItemCount();
	pList->InsertItem(n, str);
	GetDlgItemText(IDC_PASSWORK, str);
	pList->SetItemText(n, 1, str);
	GetDlgItemText(IDC_PRIOR, str);
	pList->SetItemText(n, 2, str);

	SetDlgItemText(IDC_PASSWORK, _T(""));
	SetDlgItemText(IDC_ACCOUNT, _T(""));
	
	GetDlgItem(IDC_ACCOUNT)->SetFocus();

	m_bModify = TRUE;
	free(pList);
}


void CAdminDlg::OnBnClickedWorkDele()
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	POSITION pos = pList->GetFirstSelectedItemPosition();
	if (!pos)
	{
		AfxMessageBox(_T("��ѡ��һ���˻���ɾ��!"));
		return;
	}
	int nRet = pList->GetNextSelectedItem(pos);
	if (!pList->GetItemText(nRet, 0).CompareNoCase(_T("admin")))
		return;
	if (AfxMessageBox(_T("ȷ��Ҫɾ�� ") + pList->GetItemText(nRet, 0) + _T(" ��?"), MB_YESNO) == IDYES)
	{
		m_bModify = TRUE;
		pList->DeleteItem(nRet);
	}
	free(pList);
}


void CAdminDlg::OnBnClickedWorkModify()
{

	m_bModify = TRUE;
}

/*********************************************
part 8 ��¼ʱ��������
*********************************************/
/*********************************************
part 9 �ļ���ȡ
	1)	CFile file;
		int nRet = file.Open(_T("admin.dat"), CFile::modeRead);
		if (!nRet)
		{
			AfxMessageBox(_T("��������ʧ��!"));
			return;
		}
		while (file.Read(&admin, sizeof(admin)) == sizeof(SAdmin))
		{

		}
		file.Closre();
*********************************************/
void CAdminDlg::LoadFile()
{
	CFile file;
	int nRet = file.Open(_T("admin.dat"), CFile::modeRead);
	if (!nRet)
	{
		return;
	}
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	SAdmin admin;
	int i = 0;
	while (file.Read(&admin, sizeof(admin)) == sizeof(SAdmin))
	{
		pList->InsertItem(i, admin.sName);
		pList->SetItemText(i, 1, admin.sPass);
		pList->SetItemText(i, 2, admin.nPrior ? _T("��ͨ") : _T("�߼�"));
		++i;
	}
	free(pList);
}

/*********************************************
part 1 ������ťĬ����ʾ
	1)	CComboBox* pCombox = (CComboBox*)GetDlgItem(IDC_PRIOR);
		pCombox->SetCurSel(0);	//0��ʾ��һ��,,1��ʾ�ڶ���
*********************************************/
/*********************************************
part 2 �����б�ؼ� �б���
	1)	pList->InsertColumn(0, _T("�˻�"), 0, 160);
*********************************************/
BOOL CAdminDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* pCombox = (CComboBox*)GetDlgItem(IDC_PRIOR);
	pCombox->SetCurSel(1);
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0, _T("�˻�"), 0, 160);
	pList->InsertColumn(1, _T("����"), 0, 160);
	pList->InsertColumn(2, _T("Ȩ��"), 0, 110);
	LoadFile();
	m_bModify = FALSE;
	free(pList);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


//void CAdminDlg::OnDestroy()
//{
//	CDialogEx::OnDestroy();
//}
/****************************************************
part 6 �ļ�����
	1)	int nRet = file.Open(_T("Admin.dat"), CFile::modeCreate | CFile::modeWrite);
		if (nRet)
		{
			AfxMessageBox(_T("�����˻���Ϣʧ��!"));
			return;
		}
		while()
			file.Write(&admin, sizeof(admin));
		file.Close();
****************************************************/
void CAdminDlg::SaveFile()
{
	SAdmin admin;
	CFile file;
	int nRet = file.Open(_T("Admin.dat"), CFile::modeCreate | CFile::modeWrite);
	if (!nRet)
	{
		AfxMessageBox(_T("�����˻���Ϣʧ��!"));
		return;
	}
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	int i = 0;
	int nCount = pList->GetItemCount();
	while(i < nCount)
	{
		pList->GetItemText(i, 0, admin.sName, _countof(admin.sName));
		pList->GetItemText(i, 1, admin.sPass, _countof(admin.sPass));
		if (pList->GetItemText(i, 2) == _T("��ͨ"))
			admin.nPrior = 1;
		else
			admin.nPrior = 0;

		file.Write(&admin, sizeof(admin));
		++i;
	}
	file.Close();
	free(pList);
}
/**********************************************************
part 7 �˳�ʱ����
**********************************************************/
void CAdminDlg::OnCancel()
{
	if (m_bModify)
	{
		int nRet = AfxMessageBox(_T("�Ƿ񽫸Ķ������ļ�?\n"), MB_YESNOCANCEL);
		if (IDCANCEL == nRet)
			return;
		if (IDYES)
			SaveFile();
	}

	EndDialog(IDCANCEL);
	CDialogEx::OnCancel();
}





