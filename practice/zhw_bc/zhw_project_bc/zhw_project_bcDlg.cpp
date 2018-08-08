#include "stdafx.h"
#include "zhw_project_bc.h"
#include "zhw_project_bcDlg.h"
#include "afxdialogex.h"



#include "bc_tools.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_DHTML_EVENT_MAP(Czhw_project_bcDlg)
	DHTML_EVENT_ONCLICK(_T("shrink"), OnButtonCancel)
	DHTML_EVENT_ONCLICK(_T("prompt_img"), OnButtonMIN)//最小化
END_DHTML_EVENT_MAP()

BEGIN_DISPATCH_MAP(Czhw_project_bcDlg, CDHtmlDialog)
	DISP_FUNCTION(Czhw_project_bcDlg, "states", ConnectNet, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(Czhw_project_bcDlg, "stops", OnButtonStop, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(Czhw_project_bcDlg, "starts", OnButtonRun, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

Czhw_project_bcDlg::Czhw_project_bcDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(IDD_DLG_BxS, IDR_HTML_BxS_DLG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	EnableAutomation();
}

void Czhw_project_bcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Czhw_project_bcDlg, CDHtmlDialog)
	ON_WM_MOUSEACTIVATE()
END_MESSAGE_MAP()


/***************************************************************
part 2 禁止脚本错误提示 
	1) m_pBrowserApp->put_Silent(VARIANT_TRUE);
***************************************************************/
/***************************************************************
part 3 启动HTML(JS部分按钮)
	1)  EnableAutomation();	//	构造函数初始化
	2)  SetExternalDispatch(GetIDispatch(TRUE));	// 启动初始化
	3)  DECLARE_DISPATCH_MAP()	//头文件中声明
	4)	BEGIN_DISPATCH_MAP(Czhw_project_bcDlg, CDHtmlDialog)	//	定义消息队列
			DISP_FUNCTION(Czhw_project_bcDlg, "states", ConnectNet, VT_EMPTY, VTS_NONE)
			DISP_FUNCTION(Czhw_project_bcDlg, "stops", OnButtonStop, VT_EMPTY, VTS_NONE)
			DISP_FUNCTION(Czhw_project_bcDlg, "starts", OnButtonRun, VT_EMPTY, VTS_NONE)
		END_DISPATCH_MAP()
***************************************************************/
/***************************************************************
part 7 网页导入
	1) 	char chConfigPath[128] = { 0 };
		GetCurrentDirectoryA(sizeof(chConfigPath), chConfigPath);
		char src_file[MAX_PATH];
		sprintf_s(src_file, sizeof(src_file), "%s\\html\\box_single.htm", chConfigPath);
		char file_dst[MAX_PATH];
		sprintf_s(file_dst, sizeof(file_dst), "%s\\res\\run\\box_single.htm", chConfigPath);
		char dst_content[MAX_PATH];
		sprintf_s(dst_content, sizeof(dst_content), "file:///%s", chConfigPath);
		CBcTools::dcf_file_replace_content(src_file, file_dst, "$RESDIR$", CBcTools::replace_char(dst_content, '\\', '/'));
		Navigate(CString(file_dst));
***************************************************************/
/***************************************************************
part 8 下拉框宽高设置
	1) 	设置按钮的高度
	((CComboBox*)GetDlgItem(IDC_CB_PTASK))->SendMessage(CB_SETITEMHEIGHT, -1, 18);
	2)	设置列表项的高度
	((CComboBox*)GetDlgItem(IDC_CB_PTASK))->SendMessage(CB_SETITEMHEIGHT, 0, 18);
***************************************************************/
BOOL Czhw_project_bcDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	m_list = (CListCtrl*)GetDlgItem(IDC_LIST_BOX);
	m_listR = (CListCtrl*)GetDlgItem(IDC_LIST_SINGLE);
	m_CB_Guige = new CComboBox;
	m_CB_Task = new CComboBox;

									// <2>将自身暴露给Script引擎
	SetExternalDispatch(GetIDispatch(TRUE));
	//禁止脚本错误提示 
	m_pBrowserApp->put_Silent(VARIANT_TRUE);
	//m_pBrowserApp->put_FullScreen(VARIANT_TRUE);
	//m_pBrowserApp->put_Top(0);
	//m_pBrowserApp->put_Left(-1);
	//m_pBrowserApp->put_Height(680);
	//m_pBrowserApp->put_Width(1020);


	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	char chConfigPath[128] = { 0 };
	GetCurrentDirectoryA(sizeof(chConfigPath), chConfigPath);
	char src_file[MAX_PATH];
	sprintf_s(src_file, sizeof(src_file), "%s\\html\\box_single.htm", chConfigPath);
	char file_dst[MAX_PATH];
	sprintf_s(file_dst, sizeof(file_dst), "%s\\res\\run\\box_single.htm", chConfigPath);
	char dst_content[MAX_PATH];
	sprintf_s(dst_content, sizeof(dst_content), "file:///%s", chConfigPath);
	CBcTools::dcf_file_replace_content(src_file, file_dst, "$RESDIR$", CBcTools::replace_char(dst_content, '\\', '/'));

	Navigate(CString(file_dst));








	CMenu* pSysMenu = GetSystemMenu(FALSE);
	// 获取编程语言列表视图控件的位置和大小    ========箱码
	m_list->GetClientRect(&rect);
	// 为列表视图控件添加全行选中和栅格风格   
	m_list->SetExtendedStyle(m_list->GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 为列表视图控件添加三列   
	m_list->InsertColumn(0, _T("序号"), LVCFMT_CENTER, rect.Width() / 10, 0);//如果设置宽度为1，为避免添加的图标都显示在第一列上
	m_list->InsertColumn(1, _T("二维码"), LVCFMT_CENTER, rect.Width() * 4 / 10, 1);
	m_list->InsertColumn(2, _T("时间"), LVCFMT_CENTER, rect.Width() * 2 / 10, 2);
	m_list->InsertColumn(3, _T("打码结果"), LVCFMT_CENTER, rect.Width() * 3 / 20, 3);
	m_list->InsertColumn(4, _T("数量"), LVCFMT_CENTER, rect.Width() * 3 / 20, 4);
	// 设置背景颜色
	m_list->SetBkColor(RGB(227, 235, 227));
	m_list->SetTextBkColor(RGB(227, 235, 227));


	// 获取编程语言列表视图控件的位置和大小   ========单品码
	m_listR->GetClientRect(&rect);
	// 为列表视图控件添加全行选中和栅格风格   
	m_listR->SetExtendedStyle(m_listR->GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 为列表视图控件添加三列   
	m_listR->InsertColumn(0, _T("序号"), LVCFMT_CENTER, rect.Width() / 8, 0);//如果设置宽度为1，为避免添加的图标都显示在第一列上
	m_listR->InsertColumn(1, _T("二维码"), LVCFMT_CENTER, rect.Width() * 7 / 8, 1);
	// 设置背景颜色
	m_listR->SetBkColor(RGB(227, 235, 227));
	m_listR->SetTextBkColor(RGB(227, 235, 227));



	//设置按钮的高度  
	((CComboBox*)GetDlgItem(IDC_CB_PTASK))->SendMessage(CB_SETITEMHEIGHT, -1, 18);
	//设置列表项的高度  
	((CComboBox*)GetDlgItem(IDC_CB_PTASK))->SendMessage(CB_SETITEMHEIGHT, 0, 18);

	//设置按钮的高度  
	((CComboBox*)GetDlgItem(IDC_CB_GUIGE))->SendMessage(CB_SETITEMHEIGHT, -1, 18);
	//设置列表项的高度  
	((CComboBox*)GetDlgItem(IDC_CB_GUIGE))->SendMessage(CB_SETITEMHEIGHT, 0, 18);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Czhw_project_bcDlg::OnPaint()
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
		CDHtmlDialog::OnPaint();
	}
}

HCURSOR Czhw_project_bcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


HRESULT Czhw_project_bcDlg::OnButtonMIN(IHTMLElement* /*pElement*/)
{
	::SendMessage(this->m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
	return S_OK;
}

HRESULT Czhw_project_bcDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}

/**************************************************************************************
part 1 鼠标点击窗口,是窗口同步跟踪
	1) 类向导->消息->MouseActivate
	2) PostMessage(WM_SYSCOMMAND, 0xF012, 0);
**************************************************************************************/
int Czhw_project_bcDlg::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message)
{
	PostMessage(WM_SYSCOMMAND, 0xF012, 0);

	return CDHtmlDialog::OnMouseActivate(pDesktopWnd, nHitTest, message);
}
void Czhw_project_bcDlg::OnBnClickedBtnRun2()
{
	//if (!m_dRunFlg)
	//{
	//	AfxMessageBox("请先连接服务器!");
	//	return;
	//}

	//SetProdIDAndTaskID();
	//CString cstrTmp = "";
	//GetDlgItem(IDC_CB_PTASK)->GetWindowText(cstrTmp);  //获得组合框中的选中内容
	//if ((cstrTmp.IsEmpty()) || (cstrTmp == ""))
	//{
	//	AfxMessageBox("请选择生产任务!");
	//	return;
	//}

	//m_dRunFlg = 1;
	m_CB_Task->EnableWindow(FALSE);
	m_CB_Guige->EnableWindow(FALSE);
	//g_ctrl_work_state = 1;
	/* 隐藏窗口 */
	GetDlgItem(IDC_CB_PTASK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CB_GUIGE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ED_GDS_NAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ED_TASK_C)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SingleNub)->ShowWindow(SW_HIDE);
	//==================1.获得打印机要的常量信息，并发送给打印机
	//接收由打印机发来的字段名
	//if (g_bSendMegState == 1)
	//{
	//	if (CBcHdPrint::RecvHeadfieldsMsg())
	//	{
	//		g_bSendMegState = 2;
	//	}
	//}

	//if (g_bSendMegState == 2)
	//{
	//	SendConstValueToPrint(g_current_print_num);
	//	g_bSendMegState = 3;
	//}
}
void Czhw_project_bcDlg::OnButtonRun()
{
	AfxMessageBox(_T("TEST"));
	//if (m_dRunFlg == 1) return;
	IHTMLDocument2* pDoc = NULL;
	CDHtmlDialog::GetDHtmlDocument(&pDoc);

	DISPPARAMS param = { 0 };
	VARIANT vtRet;


	//OnBnClickedBtnRun2();

	//if (m_dRunFlg == 1)
	//{
	vtRet.bVal = TRUE;
	CBcTools::CallJSFunction(pDoc, _T("OnButtonRun"), param, &vtRet, NULL, NULL);
	//}
	//singleCode_num = GetDlgItemInt(IDC_SingleNub, NULL, TRUE);
	//SetDlgItemInt(IDC_SingleNub, singleCode_num);
	//if (!m_sigModify)
	//{
	//	GetDlgItem(IDC_SingleNub)->EnableWindow(FALSE);
	//	m_sigModify = true;
	//}
}

void Czhw_project_bcDlg::OnButtonStop()
{
	AfxMessageBox(_T("TEST"));
	//OnOK();
}
void Czhw_project_bcDlg::ConnectNet()
{
	AfxMessageBox(_T("TEST"));
	//OnOK();
}
/**************************************************************
part 5 屏蔽右击菜单
	1) virtual HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved);
**************************************************************/
HRESULT Czhw_project_bcDlg::ShowContextMenu(DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved)
{
	return S_OK;
}
