#pragma once


// CDlgVideoDecode �Ի���

class CDlgVideoDecode : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgVideoDecode)

public:
	CDlgVideoDecode(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgVideoDecode();

// �Ի�������
	enum { IDD = IDD_DLG_VIDEODECODE };

protected:
	virtual void			DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL			OnInitDialog();

	DECLARE_MESSAGE_MAP()
	afx_msg void			OnBnClickedCancel();
	void					OnCustomdrawMyList ( NMHDR* pNMHDR, LRESULT* pResult );
public:
	void					SystemClear();
	CListCtrl               m_lcDecodeframe;
};
