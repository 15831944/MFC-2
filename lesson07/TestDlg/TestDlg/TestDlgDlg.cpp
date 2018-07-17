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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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
	part 1 ������װ
	1)	RECT  rect1;	�ܶ����õĺ���û��װ
	CRect rect;
	inline CRect::operator LPRECT() throw()
	{
	return this;
	}
	��Ҫȡ��ַ:	GetClientRect(&rect1);
	ֱ����:	GetClientRect(rect);
	����Ҫȡ��ַ,�Զ�����ȡ��ַ
********************************************************/

/********************************************************
	part 2 ��������
	2)	��������ָ�봫�ȽϿ�(ָ������С:���Ǹ��ڴ��ַ)
		�ö���,�����ж���Ҫ�����,��
********************************************************/

/********************************************************
	part 3 �����ȡ
	3)	GetClientRect()		//��ȡ�ͻ�������
							//Ӧ�ó������Ͻ�0,0��ʼ
********************************************************/

/********************************************************
	part 4 �����ȡ
	4)	GetwindownsRect()	//��ȡ��Ļ����
							//��Ļ���Ͻ�0,0��ʼ
********************************************************/

/********************************************************
	part 5 �ػ�����
	5)	OnPaint()	//��ͼ, һֱ�ڻ�ͼ
					//��������б��ڸ�,�ͻ�,ֻ��û���ڸǵĲ���
	void CTestDlgDlg::OnPaint()
	{
		//W��Ϣ:	M_PAINT
		CPaintDC dc(this);
		CRect rect;
		CPoint point;

		GetClientRect(rect);
		//dc.Ellipse(rect);
		dc.Rectangle(rect);

		//point = rect.CenterPoint(); //����pointΪ���ĵ�
		//point.Offset(-50, 50);		//����point�����ĵ�λ������:50�����ص�, ����:50�����ص�
		point.Offset(30, 200);

		dc.MoveTo(point);
		dc.LineTo(rect.BottomRight());
		dc.MoveTo(point);
		dc.LineTo(rect.right, rect.top);
	}
********************************************************/
/********************************************************
	part 6 �Լ�ģ��CPoint��
	6)	����ͼ->�����->c++��->����, ��Ļ���;
		ѡ���Լ�ϲ���ĺ���:
		Ȼ���CPointͷ�ļ����ƹ���,��CPoint.cpp�ļ����ƹ���
********************************************************/
/********************************************************
	part 7 �Լ�ģ��CRect��
	7)	����ͼ->�����->c++��->����, ��Ļ���;
		ѡ���Լ�ϲ���ĺ���:
		Ȼ���CRectͷ�ļ����ƹ���,��CRect.cpp�ļ����ƹ���
********************************************************/
/********************************************************
	part 8 operator ����*()
	8)	//������,�������Ҫ����ָ��,�Զ���ָ��
		operator RECT*()
		{
			return this;
		}
********************************************************/
/********************************************************
	part 9 ΪʲôҪ����������ͬ�ĺ�����?
	9)	constֻ������:
		void test(const CRect rect); 
		//ֻ������ֻ�ܵ���ֻ������,����thisָ��ָ�������
		//��ʱ��Ҫ���Ĳ��������const��,���Ժ���������a.
		//���ֻ���������û��ֻ�����Եĺ���,�ͻᱨ��
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
	part 10 �ַ�������
	1)	char(խ),				wchat_t(��),				TCHAR(�Զ�����)
	2)	LPSTR(char *),			LPWSTR(wchar_t*),			LPTSTR(TCHAR*):����Ͳ�������
	3)	LPCSTR(const char*),	LPCWSTR(const wchar_t*),	LPCTSTR(const TCHAR*):������ָ��,�����޸�����(����ֵ)
********************************************************/

void CTestDlgDlg::OnPaint()
{
	//W��Ϣ:	M_PAINT
	CPaintDC dc(this);
	CRect rect;
	rectx rectx;
	pointx pointX;

	GetClientRect(rectx);
	GetClientRect(rect);
	dc.Rectangle(rectx);

	pointX.Offset(10, 200); //�Լ�д����

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

