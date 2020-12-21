// DlgAudioDecode.cpp : 实现文件
//

#include "stdafx.h"
#include "YouthVideo.h"
#include "DlgAudioDecode.h"
#include "afxdialogex.h"


// CDlgAudioDecode 对话框

IMPLEMENT_DYNAMIC(CDlgAudioDecode, CDialogEx)

CDlgAudioDecode::CDlgAudioDecode(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAudioDecode::IDD, pParent)
{

}

CDlgAudioDecode::~CDlgAudioDecode()
{
}

void CDlgAudioDecode::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_LIST_DECODEFRAME,m_lcAudioDecode);
}


BEGIN_MESSAGE_MAP(CDlgAudioDecode, CDialogEx)
END_MESSAGE_MAP()


// CDlgAudioDecode 消息处理程序


BOOL CDlgAudioDecode::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString resloader;
	resloader.LoadString(IDS_AUDIODECODE);
	SetWindowText(resloader);
	//整行选择；有表格线；表头；单击激活
	DWORD dwExStyle=LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE;
	m_lcAudioDecode.ModifyStyle(0,LVS_SINGLESEL|LVS_REPORT|LVS_SHOWSELALWAYS);
	m_lcAudioDecode.SetExtendedStyle(dwExStyle);

	resloader.LoadString(IDS_AUDIODECODE_NUM);
	m_lcAudioDecode.InsertColumn(0,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_AUDIODECODE_SIZE);
	m_lcAudioDecode.InsertColumn(1,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_AUDIODECODE_PTS);
	m_lcAudioDecode.InsertColumn(2,resloader,LVCFMT_CENTER,60,0);
	resloader.LoadString(IDS_AUDIODECODE_DTS);
	m_lcAudioDecode.InsertColumn(3,resloader,LVCFMT_CENTER,60,0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// Òì³£: OCX ÊôÐÔÒ³Ó¦·µ»Ø FALSE
}

void CDlgAudioDecode::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);
}

void CDlgAudioDecode::SystemClear(){
	m_lcAudioDecode.DeleteAllItems();
}
