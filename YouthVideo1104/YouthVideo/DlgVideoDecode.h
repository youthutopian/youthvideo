#pragma once


// CDlgVideoDecode 对话框

class CDlgVideoDecode : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgVideoDecode)

public:
	CDlgVideoDecode(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgVideoDecode();

// 对话框数据
	enum { IDD = IDD_DLG_VIDEODECODE };

protected:
	virtual void			DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL			OnInitDialog();

	DECLARE_MESSAGE_MAP()
	afx_msg void			OnBnClickedCancel();
	void					OnCustomdrawMyList ( NMHDR* pNMHDR, LRESULT* pResult );
public:
	void					SystemClear();
	CListCtrl               m_lcDecodeframe;
};
