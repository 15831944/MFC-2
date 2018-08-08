
// zhw_project_bcDlg.h : 头文件
//

#pragma once


// Czhw_project_bcDlg 对话框
class Czhw_project_bcDlg : public CDHtmlDialog
{
// 构造
public:
	Czhw_project_bcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHW_PROJECT_BC_DIALOG, IDH = IDR_HTML_ZHW_PROJECT_BC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	HRESULT OnButtonMIN(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);



	afx_msg void ConnectNet();
	afx_msg void OnButtonRun();
	afx_msg void OnButtonStop();
	void OnBnClickedBtnRun2();
// 实现
protected:
	/**************************************************************
	part 4 屏蔽掉网页弹出的ActiveX安全警告对话框。
		1) virtual BOOL IsExternalDispatchSafe() { return TRUE; }
	**************************************************************/
	virtual BOOL IsExternalDispatchSafe() { return TRUE; }
	/**************************************************************
	part 5 屏蔽右击菜单
		1) virtual HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved);
	**************************************************************/
	virtual HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved);
	/**************************************************************
	part 6拦截一些系统快捷键
		1) STDMETHOD(TranslateAccelerator)(LPMSG lpMsg, const GUID *pguidCmdGroup, DWORD nCmdID);
	**************************************************************/
	//STDMETHOD(TranslateAccelerator)(LPMSG lpMsg, const GUID *pguidCmdGroup, DWORD nCmdID);


protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
	DECLARE_DISPATCH_MAP()
public:
	CRect rect;
	CComboBox *m_CB_Guige;
	CComboBox *m_CB_Task;
	CListCtrl *m_list;
	CListCtrl *m_listR;
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
};
