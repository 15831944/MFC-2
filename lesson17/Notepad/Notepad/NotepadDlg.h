
// NotepadDlg.h : ͷ�ļ�
//

#pragma once


// CNotepadDlg �Ի���
class CNotepadDlg : public CDialogEx
{
public:
	CFont m_font;
// ����
public:
	CNotepadDlg(CWnd* pParent = NULL);	// ��׼���캯��
	HACCEL m_hAccel;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOTEPAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnOnappexit();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnAppAbout();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose();
	afx_msg void OnEditClear();
	afx_msg void OnEditClearAll();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditDate();
	afx_msg void OnEditFind();
	afx_msg void OnEditFindnet();
	afx_msg void OnEditGo();
	afx_msg void OnEditPaste();
	afx_msg void OnEditReplace();
	afx_msg void OnEditUndo();
	afx_msg void OnEditSelectAll();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void ReadUTF8(CFile& file);
	void ReadUTF16(CFile& file);
	void ReadASCII(CFile& file);
	afx_msg void OnDestroy();
	afx_msg void OnFormatFont();
	afx_msg void OnFileOpen();
	afx_msg void OnFileNew();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	void LoadFile(LPCTSTR sFile);
};