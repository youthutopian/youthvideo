#pragma once


// CDlgAudioDecode �Ի���

class CDlgAudioDecode : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAudioDecode)

public:
	CDlgAudioDecode(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgAudioDecode();

// �Ի�������
	enum { IDD = IDD_DLG_AUDIODECODE };

protected:
	virtual void			DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL			OnInitDialog();
	CListCtrl				m_lcAudioDecode;
	afx_msg void			OnBnClickedCancel();
	void					SystemClear();
};
