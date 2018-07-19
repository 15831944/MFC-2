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

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);

/***********************************************************
	part 1 插列单位
		InsertColumn(0, _T("工号"), LVCFMT_LEFT, 150);	
***********************************************************/
	pList->InsertColumn(0, _T("工号"), LVCFMT_LEFT, 150);
	pList->InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 150);
	pList->InsertColumn(2, _T("工资"), LVCFMT_LEFT, 150);
	pList->InsertColumn(3, _T("入职日期"), LVCFMT_LEFT, 246);

/***********************************************************
	part 2 列表背景颜色
		SetBkColor(RGB(205, 226, 252));	
***********************************************************/
	pList->SetBkColor(RGB(205, 226, 252));

/***********************************************************
	part 3 列表框文字背景颜色
		SetTextBkColor(RGB(205, 226, 252));
***********************************************************/
	pList->SetTextBkColor(RGB(205, 226, 252));

/***********************************************************
	part 4 列表框文字颜色
		 SetTextColor(RGB(0, 0, 255));
***********************************************************/
	pList->SetTextColor(RGB(0, 0, 255));

/***********************************************************
	part 5 列表框风格设置
		 SetExtendedStyle(LVS_EX_AUTOCHECKSELECT)	有个方框,可以选择全选
		 SetExtendedStyle(LVS_EX_CHECKBOXES)		每个选择都由个方框,供多选
		 SetExtendedStyle(LVS_EX_FULLROWSELECT);	选中之后,整行高亮
		 SetExtendedStyle(LVS_EX_GRIDLINES);		出现网格状,数据分行分块
		 SetExtendedStyle(LVS_EX_HIDELABELS);		隐藏标签
		 SetExtendedStyle(LVS_EX_ONECLICKACTIVATE); 鼠标指向选项后,鼠标会变图标,改成手指不再是箭头
		 SetExtendedStyle(LVS_EX_TRANSPARENTBKGND); 列表框的背景颜色和字体背景颜色跟父框一样
		 SetExtendedStyle(LVS_EX_TWOCLICKACTIVATE); 鼠标选中选项后,鼠标在该项的范围内,鼠标图标变回手指,不再是件箭头,移出选项还是箭头
		 SetExtendedStyle(LVS_EX_AUTOSIZECOLUMNS)	????
		 SetExtendedStyle(LVS_EX_AUTOAUTOARRANGE)	????
		 SetExtendedStyle(LVS_EX_BORDERSELECT);		????
		 SetExtendedStyle(LVS_EX_COLUMNOVERFLOW);	????
		 SetExtendedStyle(LVS_EX_COLUMNSNAPPOINTS);	????
		 SetExtendedStyle(LVS_EX_DOUBLEBUFFER);		油漆通过双缓冲,从而减少闪烁.这种扩展风格也使阿尔法混合字幕选择系统上,它是支持
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
		 SetExtendedStyle(LVS_EX_UNDERLINECOLD); 点击项目以下划线文本显示,要求LVS_EX_TWOCLICKACTIVATE也设置
		 SetExtendedStyle(LVS_EX_UNDERLINEHOT); 鼠标移到项目以下划线文本显示,要求LVS_EX_ONECLICKACTIVATE或LVS_EX_TWOCLICKACTIVATE也设置
***********************************************************/
	pList->SetExtendedStyle(LVS_EX_AUTOCHECKSELECT | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES |LVS_EX_DOUBLEBUFFER);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWorksDlg::OnPaint()
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

HCURSOR CWorksDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWorksDlg::OnBnClickedWorkLookup()
{
	// TODO: 在此添加控件通知处理程序代码
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
			error.Format(_T("工号: %d, 已经存在!"), _tstoi(str));
			AfxMessageBox(error);

/***********************************************************
	part 8 返回指针指定的地方
		SetFocus();	
***********************************************************/
/***********************************************************
	part 9 默认指定1的位置
		Works.rc里面, Ctrl + d 可以重设默认的1的标记,点一下就为1
***********************************************************/
			SetFocus();

/***********************************************************
	part 15 文本框
		IDC_WORK_NUB
		IDC_WORK_NAME
		IDC_WORK_WAGE
		IDC_WORK_WAGE	置空
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
	part 6 获取行数
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
		AfxMessageBox(_T("工号不能为空"));
		return;
	}
	if (name.IsEmpty())
	{
		AfxMessageBox(_T("姓名不能为空"));
		return;
	}
	if (wage.IsEmpty())
	{
		AfxMessageBox(_T("工资不能为空"));
		return;
	}

/***********************************************************
	part 7 检查号码是否存在:TRUE 可以插入, FALSE 不可以插入
***********************************************************/
	if (CheckNumber(nub) == FALSE)
	{
		return;
	}
/***********************************************************
	part 8 	插入0行,后面加内容(0行1列)
		InsertItem(0, nub);
***********************************************************/
	pList->InsertItem(row, nub);

/***********************************************************
	part 9 	必须先:InsertItem(0, nub),再可以设置0行1列数据
		SetItemText(0, 1, nub);
***********************************************************/
	pList->SetItemText(row, 1, name);
	pList->SetItemText(row, 2, wage);
	pList->SetItemText(row, 3, date);
}


/***********************************************************
	part 10 返回列的索引
		GetSelectedColumn() 
***********************************************************/
/***********************************************************
	part 11 从零开始的选中标记或-1;如果未选中标记。标记以后永远为1
		GetSelectionMark() 
***********************************************************/
/***********************************************************
	part 12 选定项的数量列表视图控件的。
		GetSelectedCount() 
***********************************************************/
void CWorksDlg::OnBnClickedWorkDele()
{
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	if (!pList->GetSelectedCount())
	{
			AfxMessageBox(_T("请选中一行再删除!"));
			return;
	}
	int nSel = pList->GetSelectionMark();

/***********************************************************
	part 11 获取第几行第几列的的文字
		GetItemText(x ,y) 
***********************************************************/
	CString str = pList->GetItemText(nSel, 1);
	if (AfxMessageBox(_T("你确定要删除 ") + str + _T(" 吗?"), MB_YESNO) == IDYES)
	{
/***********************************************************
	part 12 删除第y行
		DeleteItem(y) 
***********************************************************/
		pList->DeleteItem(nSel);
	}
}


void CWorksDlg::OnBnClickedWorkModify()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CWorksDlg::FileError(int error)
{
	switch (error)
	{
	case CFileException::genericException:
		AfxMessageBox(_T("Error: 发生了未指定的错误。\n"));
		break;
	case CFileException::fileNotFound:
		AfxMessageBox(_T("Error: 未能定位该文件。\n"));
		break;
	case CFileException::badPath:
		AfxMessageBox(_T("Error: 全部或部分路径无效。\n"));
		break;
	case CFileException::tooManyOpenFiles:
		AfxMessageBox(_T("Error: 已超出允许打开的文件数。\n"));
		break;
	case CFileException::accessDenied:
		AfxMessageBox(_T("Error: 无法访问该文件。\n"));
		break;
	case CFileException::invalidFile:
		AfxMessageBox(_T("Error: 已尝试使用无效的文件句柄。\n"));
		break;
	case CFileException::removeCurrentDir:
		AfxMessageBox(_T("Error: 无法移除当前工作目录。\n"));
		break;
	case CFileException::directoryFull:
		AfxMessageBox(_T("Error: 没有更多的目录项。\n"));
		break;
	case CFileException::badSeek:
		AfxMessageBox(_T("Error: 已在尝试设置文件指针时出错。\n"));
		break;
	case CFileException::hardIO:
		AfxMessageBox(_T("Error: 出现了硬件错误。\n"));
	case CFileException::sharingViolation:
		AfxMessageBox(_T("Error: 未加载 SHARE.EXE 或共享区域已被锁定。\n"));
		break;
	case CFileException::lockViolation:
		AfxMessageBox(_T("Error: 已尝试锁定已经锁定的区域。\n"));
		break;
	case CFileException::diskFull:
		AfxMessageBox(_T("Error: 磁盘已满。\n"));
		break;
	case CFileException::endOfFile:
		AfxMessageBox(_T("Error: 已到达文件末尾。\n"));
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
	part 13 路径必须是存在的,不然打开失败!
		file.Open;  
***********************************************************/
	if (!file.Open(FileName, CFile::modeCreate | CFile::modeWrite, &error))
	{
/***********************************************************
	part 14 文件错误集
		FileError()
***********************************************************/
		FileError(error.m_cause);
		return;
	}

	while()
	file.Close();
}





