#pragma once


// CDlgAudioDecode 对话框

class CDlgAudioDecode : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAudioDecode)

public:
	CDlgAudioDecode(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgAudioDecode();

// 对话框数据
	enum { IDD = IDD_DLG_AUDIODECODE };

protected:
	virtual void			DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL			OnInitDialog();
	CListCtrl				m_lcAudioDecode;
	afx_msg void			OnBnClickedCancel();
	void					SystemClear();
};
