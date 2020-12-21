
// YouthVideoDlg.h : 头文件
//
#include "DlgAudioDecode.h"
#include "DlgVideoDecode.h"
#pragma once

//多线程
UINT Thread_Play(LPVOID lpParam);
//存储播放地址


// CYouthVideoDlg 对话框
class CYouthVideoDlg : public CDialogEx
{
// 构造
public:
	CYouthVideoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_YOUTHVIDEO_MAIN };

	protected:
	virtual void			DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON					m_hIcon;

	// 生成的消息映射函数
	virtual BOOL			OnInitDialog();
	afx_msg void			OnPaint();
	afx_msg HCURSOR			OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit					m_decoder_name;
	CEdit					m_pix_fmt;
	CEdit					m_wxh;
	CEdit					m_bitrate;
	CEdit					m_extention;
	CEdit					m_metadata;
	CEdit					m_framerate;
	CEdit					m_decoder_name_au;
	CEdit					m_sample_rate_au;
	CEdit					m_inputurl;
	CEdit					m_channels_au;
	CEdit					m_aqsize;
	CEdit					m_vqsize;
	CEdit					m_duration;
	CEdit					m_currentclock;
	CEdit					m_avdiff;
	CEdit					m_timelong;
	CEdit					m_input_format;
	CEdit					m_input_protocol;
	CSliderCtrl				m_playprogress;
	CSpinButtonCtrl			m_spin_delay;
	afx_msg void			OnBnClickedStop();
	afx_msg void			OnBnClickedSeekStep();
	afx_msg void			OnBnClickedFullscreen();
	afx_msg void			OnBnClickedSeekB();
	afx_msg void			OnBnClickedPause();
	afx_msg void			OnBnClickedSeekF();
	afx_msg void			OnBnClickedOk();
	afx_msg void			OnCancel();
	int						GetURL();
	char					url[MAX_URL_LENGTH];
	afx_msg void			OnBnClickedInputurlbutton();
	void					ResetBtn();
	void					ActiveBtn();
	void					SystemClear();
	void					FreeSubWindow();
	void					InitSubWindow();
	CDlgAudioDecode			*m_pAudioDecode;
	CDlgVideoDecode			*m_pVideoDecode;
	afx_msg void OnBnClickedVideodecode();
	afx_msg void OnBnClickedAudiodecode();
};
