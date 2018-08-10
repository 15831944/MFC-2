
// WorksDlg.h : ͷ�ļ�
//

#pragma once


// CWorksDlg �Ի���
class CWorksDlg : public CDialogEx
{
	struct SInfo
	{
		int nNumb;
		TCHAR sName[20];
		float fSala;
		//CTime tData;
		COleDateTime tData;
	};
// ����
public:
	CWorksDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WORKS_DIALOG };
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
public:
	afx_msg void OnBnClickedWorkLookup();
	afx_msg void OnBnClickedWorkAdd();
	afx_msg void OnBnClickedWorkDele();
	afx_msg void OnBnClickedWorkModify();
	afx_msg void OnBnClickedWorkSave();
	// �������Ƿ����
	BOOL CheckNumber(LPCTSTR str);
	// �ļ�����
	void FileError(int error);

public:
	afx_msg void OnBnClickedCancel();
private:
	int m_Row;
	BOOL m_bModify;
};
