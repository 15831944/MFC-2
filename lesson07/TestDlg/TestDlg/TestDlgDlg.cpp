#include "stdafx.h"
#include "TestDlg.h"
#include "TestDlgDlg.h"
#include "afxdialogex.h"

//============================

#include "pointx.h"
#include "rectx.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CTestDlgDlg::CTestDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTDLG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestDlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

BOOL CTestDlgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

/********************************************************
	part 1 函数封装
	1)	RECT  rect1;	很多有用的函数没封装
	CRect rect;
	inline CRect::operator LPRECT() throw()
	{
	return this;
	}
	需要取地址:	GetClientRect(&rect1);
	直接用:	GetClientRect(rect);
	不需要取地址,自动帮你取地址
********************************************************/

/********************************************************
	part 2 函数传参
	2)	传参数用指针传比较快(指针内容小:就是个内存地址)
		用对象传,对象有多大就要传多大,慢
********************************************************/

/********************************************************
	part 3 坐标获取
	3)	GetClientRect()		//获取客户端坐标
							//应用程序左上角0,0开始
********************************************************/

/********************************************************
	part 4 坐标获取
	4)	GetwindownsRect()	//获取屏幕坐标
							//屏幕左上角0,0开始
********************************************************/

/********************************************************
	part 5 重画机制
	5)	OnPaint()	//画图, 一直在画图
					//这个程序有被遮盖,就画,只画没被遮盖的部分
	void CTestDlgDlg::OnPaint()
	{
		//W消息:	M_PAINT
		CPaintDC dc(this);
		CRect rect;
		CPoint point;

		GetClientRect(rect);
		//dc.Ellipse(rect);
		dc.Rectangle(rect);

		//point = rect.CenterPoint(); //设置point为中心点
		//point.Offset(-50, 50);		//设置point在中心店位置左移:50个像素点, 下移:50个像素点
		point.Offset(30, 200);

		dc.MoveTo(point);
		dc.LineTo(rect.BottomRight());
		dc.MoveTo(point);
		dc.LineTo(rect.right, rect.top);
	}
********************************************************/
/********************************************************
	part 6 自己模仿CPoint类
	6)	类视图->添加类->c++类->类名, 类的基类;
		选择自己喜欢的函数:
		然后从CPoint头文件复制过来,从CPoint.cpp文件复制过来
********************************************************/
/********************************************************
	part 7 自己模仿CRect类
	7)	类视图->添加类->c++类->类名, 类的基类;
		选择自己喜欢的函数:
		然后从CRect头文件复制过来,从CRect.cpp文件复制过来
********************************************************/
/********************************************************
	part 8 operator 基类*()
	8)	//传对象,如果对面要的是指针,自动换指针
		operator RECT*()
		{
			return this;
		}
********************************************************/
/********************************************************
	part 9 为什么要设置两个相同的函数呢?
	9)	const只读函数:
		void test(const CRect rect); 
		//只读对象只能调用只读函数,保护this指针指向的数据
		//这时候要传的参数必须的const的,所以函数会启动a.
		//如果只读对象调用没有只读属性的函数,就会报错
	a.	const CPoint& rectx::TopLeft()
		{
		return *((CPoint*)this);
		}

	b.	CPoint& rectx::TopLeft()
		{
		return *((CPoint*)this);
		}
********************************************************/
/********************************************************
	part 10 字符串类型
	1)	char(窄),				wchat_t(宽),				TCHAR(自动适配)
	2)	LPSTR(char *),			LPWSTR(wchar_t*),			LPTSTR(TCHAR*):输出型参数常用
	3)	LPCSTR(const char*),	LPCWSTR(const wchar_t*),	LPCTSTR(const TCHAR*):保护性指针,不能修改内容(做左值)
********************************************************/

void CTestDlgDlg::OnPaint()
{
	//W消息:	M_PAINT
	CPaintDC dc(this);
	CRect rect;
	rectx rectx;
	pointx pointX;

	GetClientRect(rectx);
	GetClientRect(rect);
	dc.Rectangle(rectx);

	pointX.Offset(10, 200); //自己写的类

	int nub = rectx.Widthx();

	dc.MoveTo(pointX);
	//rectx.Size();
	//rectx.BottomRight();
	dc.LineTo(rectx.BottomRight());
	dc.MoveTo(pointX);
	dc.LineTo(rectx.right, rectx.top);
}

HCURSOR CTestDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

