
// zhw_project_bcDlg.h : ͷ�ļ�
//

#pragma once


// Czhw_project_bcDlg �Ի���
class Czhw_project_bcDlg : public CDHtmlDialog
{
// ����
public:
	Czhw_project_bcDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHW_PROJECT_BC_DIALOG, IDH = IDR_HTML_ZHW_PROJECT_BC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	HRESULT OnButtonMIN(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);



	afx_msg void ConnectNet();
	afx_msg void OnButtonRun();
	afx_msg void OnButtonStop();
	void OnBnClickedBtnRun2();
// ʵ��
protected:
	/**************************************************************
	part 4 ���ε���ҳ������ActiveX��ȫ����Ի���
		1) virtual BOOL IsExternalDispatchSafe() { return TRUE; }
	**************************************************************/
	virtual BOOL IsExternalDispatchSafe() { return TRUE; }
	/**************************************************************
	part 5 �����һ��˵�
		1) virtual HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved);
	**************************************************************/
	virtual HRESULT STDMETHODCALLTYPE ShowContextMenu(DWORD dwID, POINT *ppt, IUnknown *pcmdtReserved, IDispatch *pdispReserved);
	/**************************************************************
	part 6����һЩϵͳ��ݼ�
		1) STDMETHOD(TranslateAccelerator)(LPMSG lpMsg, const GUID *pguidCmdGroup, DWORD nCmdID);
	**************************************************************/
	//STDMETHOD(TranslateAccelerator)(LPMSG lpMsg, const GUID *pguidCmdGroup, DWORD nCmdID);


protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
