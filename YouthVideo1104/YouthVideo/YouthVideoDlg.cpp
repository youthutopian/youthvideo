
// YouthVideoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "YouthVideo.h"
#include "YouthVideoDlg.h"
#include "afxdialogex.h"
#include "Welcome.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CYouthVideoDlg 对话框




CYouthVideoDlg::CYouthVideoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CYouthVideoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYouthVideoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DECODER_NAME, m_decoder_name);
	//  DDX_Control(pDX, IDC_DECODER_TYPE, m_decoder_type);
	DDX_Control(pDX, IDC_PIX_FMT, m_pix_fmt);
	DDX_Control(pDX, IDC_WxH, m_wxh);
	DDX_Control(pDX, IDC_BITRATE, m_bitrate);
	DDX_Control(pDX, IDC_EXTENTION, m_extention);
	DDX_Control(pDX, IDC_METADATA, m_metadata);
	DDX_Control(pDX, IDC_FRAMERATE, m_framerate);
	DDX_Control(pDX, IDC_TIMELONG, m_timelong);

	DDX_Control(pDX, IDC_INPUT_FORMAT, m_input_format);
	DDX_Control(pDX, IDC_INPUT_PROTOCOL, m_input_protocol);
	DDX_Control(pDX, IDC_DECODER_AUDIO_NAME, m_decoder_name_au);
	DDX_Control(pDX, IDC_SAMPLE_RATE, m_sample_rate_au);
	DDX_Control(pDX, IDC_INPUTURL, m_inputurl);
	DDX_Control(pDX, IDC_CHANNELS, m_channels_au);
	DDX_Control(pDX, IDC_PLAY_PROGRESS, m_playprogress);
	DDX_Control(pDX, IDC_AQ_SIZE, m_aqsize);
	DDX_Control(pDX, IDC_VQ_SIZE, m_vqsize);
	DDX_Control(pDX, IDC_DURATION, m_duration);
	DDX_Control(pDX, IDC_CURRENT_CLOCK, m_currentclock);
	DDX_Control(pDX, IDC_AV_DIFF, m_avdiff);
}

BEGIN_MESSAGE_MAP(CYouthVideoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_STOP, &CYouthVideoDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_SEEK_STEP, &CYouthVideoDlg::OnBnClickedSeekStep)
	ON_BN_CLICKED(IDC_FULLSCREEN, &CYouthVideoDlg::OnBnClickedFullscreen)
	ON_BN_CLICKED(IDC_SEEK_B, &CYouthVideoDlg::OnBnClickedSeekB)
	ON_BN_CLICKED(IDC_PAUSE, &CYouthVideoDlg::OnBnClickedPause)
	ON_BN_CLICKED(IDC_SEEK_F, &CYouthVideoDlg::OnBnClickedSeekF)
	ON_BN_CLICKED(IDOK, &CYouthVideoDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_INPUTURLBUTTON, &CYouthVideoDlg::OnBnClickedInputurlbutton)
	ON_COMMAND(IDCANCEL, &CYouthVideoDlg::OnCancel)
	ON_BN_CLICKED(IDC_VIDEODECODE, &CYouthVideoDlg::OnBnClickedVideodecode)
	ON_BN_CLICKED(IDC_AUDIODECODE, &CYouthVideoDlg::OnBnClickedAudiodecode)
END_MESSAGE_MAP()


UINT Thread_Play(LPVOID lpParam){
	CYouthVideoDlg *dlg=(CYouthVideoDlg *)lpParam;
	ve_play(lpParam);
	//LPDWORD nExitCode=0;
	return 0;
}

// CYouthVideoDlg 消息处理程序

BOOL CYouthVideoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
#if 0
	CWelcome welcome;
	welcome.Create(IDB_WELCOME);
	welcome.CenterWindow();
	welcome.UpdateWindow();
	Sleep(2000);
	welcome.DestroyWindow();
#endif
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	m_inputurl.SetWindowTextW(_T("E:\\HelloYouth\\音视频处理学习\\小学期课程资料 - 基于FFmpeg+SDL的视频播放器的制作\\工具\\testvideo\\那些年，我们一起追的女孩.mp4"));
	ResetBtn();
	InitSubWindow();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CYouthVideoDlg::OnPaint()
{
	CDialogEx::OnPaint();
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CYouthVideoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CYouthVideoDlg::OnBnClickedStop()
{
	ve_quit();
	ResetBtn();	
}


void CYouthVideoDlg::OnBnClickedSeekStep()
{
	ve_seek_step();
}


void CYouthVideoDlg::OnBnClickedFullscreen()
{
	ve_play_fullcreen();
}


void CYouthVideoDlg::OnBnClickedSeekB()
{
	ve_seek(-60);
}


void CYouthVideoDlg::OnBnClickedPause()
{
	ve_play_pause();
}


void CYouthVideoDlg::OnBnClickedSeekF()
{
	ve_seek(60);
}


void CYouthVideoDlg::OnBnClickedOk()
{
	ve_reset_index();
	if(GetURL()==-1) return;
	AfxBeginThread(Thread_Play,this);
	ActiveBtn();
}

int CYouthVideoDlg::GetURL()
{
	LPTSTR urlstr=(LPTSTR)malloc(MAX_URL_LENGTH);
	m_inputurl.GetWindowText((LPTSTR)urlstr,MAX_URL_LENGTH);
#ifdef _UNICODE
	USES_CONVERSION;
	strcpy(url,W2A(urlstr));
#else
	strcpy(url,urlstr);
#endif
	if(strcmp(url,"")==0){
		CString resloader;
		//resloader.LoadString(IDS_MSGBOX_NOURL);
		resloader = "URL is null!";
		AfxMessageBox(resloader);
		return -1;
	}
	return 0;
}


void CYouthVideoDlg::OnBnClickedInputurlbutton()
{
	CString FilePathName;
	//文件过滤字符串。够长
	CString strfilter;
	strfilter.Append(_T("Common media formats|*.avi;*.wmv;*.wmp;*.wm;*.asf;*.rm;*.ram;*.rmvb;*.ra;*.mpg;*.mpeg;*.mpe;*.m1v;*.m2v;*.mpv2;"));
	strfilter.Append(_T("*.mp2v;*.dat;*.mp4;*.m4v;*.m4p;*.vob;*.ac3;*.dts;*.mov;*.qt;*.mr;*.3gp;*.3gpp;*.3g2;*.3gp2;*.swf;*.ogg;*.wma;*.wav;"));
	strfilter.Append(_T("*.mid;*.midi;*.mpa;*.mp2;*.mp3;*.m1a;*.m2a;*.m4a;*.aac;*.mkv;*.ogm;*.m4b;*.tp;*.ts;*.tpr;*.pva;*.pss;*.wv;*.m2ts;*.evo;"));
	strfilter.Append(_T("*.rpm;*.realpix;*.rt;*.smi;*.smil;*.scm;*.aif;*.aiff;*.aifc;*.amr;*.amv;*.au;*.acc;*.dsa;*.dsm;*.dsv;*.dss;*.pmp;*.smk;*.flic|"));
	strfilter.Append(_T("Windows Media Video(*.avi;*wmv;*wmp;*wm;*asf)|*.avi;*.wmv;*.wmp;*.wm;*.asf|"));
	strfilter.Append(_T("Windows Media Audio(*.wma;*wav;*aif;*aifc;*aiff;*mid;*midi;*rmi)|*.wma;*.wav;*.aif;*.aifc;*.aiff;*.mid;*.midi;*.rmi|"));
	strfilter.Append(_T("Real(*.rm;*ram;*rmvb;*rpm;*ra;*rt;*rp;*smi;*smil;*.scm)|*.rm;*.ram;*.rmvb;*.rpm;*.ra;*.rt;*.rp;*.smi;*.smil;*.scm|"));
	strfilter.Append(_T("MPEG Video(*.mpg;*mpeg;*mpe;*m1v;*m2v;*mpv2;*mp2v;*dat;*mp4;*m4v;*m4p;*m4b;*ts;*tp;*tpr;*pva;*pss;*.wv;)|"));
	strfilter.Append(_T("*.mpg;*.mpeg;*.mpe;*.m1v;*.m2v;*.mpv2;*.mp2v;*.dat;*.mp4;*.m4v;*.m4p;*.m4b;*.ts;*.tp;*.tpr;*.pva;*.pss;*.wv;|"));
	strfilter.Append(_T("MPEG Audio(*.mpa;*mp2;*m1a;*m2a;*m4a;*aac;*.m2ts;*.evo)|*.mpa;*.mp2;*.m1a;*.m2a;*.m4a;*.aac;*.m2ts;*.evo|"));
	strfilter.Append(_T("DVD(*.vob;*ifo;*ac3;*dts)|*.vob;*.ifo;*.ac3;*.dts|MP3(*.mp3)|*.mp3|CD Tracks(*.cda)|*.cda|"));
	strfilter.Append(_T("Quicktime(*.mov;*qt;*mr;*3gp;*3gpp;*3g2;*3gp2)|*.mov;*.qt;*.mr;*.3gp;*.3gpp;*.3g2;*.3gp2|"));
	strfilter.Append(_T("Flash Files(*.flv;*swf;*.f4v)|*.flv;*.swf;*.f4v|Playlist(*.smpl;*.asx;*m3u;*pls;*wvx;*wax;*wmx;*mpcpl)|*.smpl;*.asx;*.m3u;*.pls;*.wvx;*.wax;*.wmx;*.mpcpl|"));
	strfilter.Append(_T("Others(*.ivf;*au;*snd;*ogm;*ogg;*fli;*flc;*flic;*d2v;*mkv;*pmp;*mka;*smk;*bik;*ratdvd;*roq;*drc;*dsm;*dsv;*dsa;*dss;*mpc;*divx;*vp6;*.ape;*.flac;*.tta;*.csf)"));
	strfilter.Append(_T("|*.ivf;*.au;*.snd;*.ogm;*.ogg;*.fli;*.flc;*.flic;*.d2v;*.mkv;*.pmp;*.mka;*.smk;*.bik;*.ratdvd;*.roq;*.drc;*.dsm;*.dsv;*.dsa;*.dss;*.mpc;*.divx;*.vp6;*.ape;*.amr;*.flac;*.tta;*.csf|"));
	strfilter.Append(_T("All Files(*.*)|*.*||"));


	LPCTSTR lpszfilter=strfilter;
	CFileDialog dlg(TRUE,NULL,NULL,NULL,lpszfilter);///TRUE为OPEN对话框，FALSE为SAVE AS对话框 
	if(dlg.DoModal()==IDOK) {
		FilePathName=dlg.GetPathName();
		m_inputurl.SetWindowText(FilePathName);
	}
}

void CYouthVideoDlg::ResetBtn(){
	GetDlgItem(IDOK)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEEK_B)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEEK_F)->EnableWindow(FALSE);
	GetDlgItem(IDC_PAUSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_STOP)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEEK_STEP)->EnableWindow(FALSE);
	GetDlgItem(IDC_FULLSCREEN)->EnableWindow(FALSE);
	GetDlgItem(IDC_PLAY_PROGRESS)->EnableWindow(FALSE);

	//FIX
	GetDlgItem(IDC_RAWANALYSIS)->EnableWindow(FALSE);
	GetDlgItem(ID_DFANALYSIS)->EnableWindow(FALSE);
	GetDlgItem(IDC_VIDEODECODE)->EnableWindow(FALSE);
	GetDlgItem(IDC_AUDIODECODE)->EnableWindow(FALSE);
}

void CYouthVideoDlg::ActiveBtn(){
	GetDlgItem(IDOK)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEEK_B)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEEK_F)->EnableWindow(TRUE);
	GetDlgItem(IDC_PAUSE)->EnableWindow(TRUE);
	GetDlgItem(IDC_STOP)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEEK_STEP)->EnableWindow(TRUE);
	GetDlgItem(IDC_FULLSCREEN)->EnableWindow(TRUE);
	GetDlgItem(IDC_PLAY_PROGRESS)->EnableWindow(TRUE);

	//FIX
	GetDlgItem(IDC_RAWANALYSIS)->EnableWindow(TRUE);
	GetDlgItem(ID_DFANALYSIS)->EnableWindow(TRUE);
	GetDlgItem(IDC_VIDEODECODE)->EnableWindow(TRUE);
	GetDlgItem(IDC_AUDIODECODE)->EnableWindow(TRUE);
}

void CYouthVideoDlg::SystemClear()
{
	m_pVideoDecode->SystemClear();
	m_pAudioDecode->SystemClear();
	ve_reset_index();
}


void CYouthVideoDlg::OnCancel()
{
	CString resloader;
	resloader.LoadString(IDS_MSGBOX_EXIT);
	if(IDOK==AfxMessageBox(resloader,MB_OKCANCEL|MB_ICONINFORMATION)){
		//先点一下暂停
		OnBnClickedStop();
		//释放子窗口
		FreeSubWindow();
		CDialogEx::OnCancel();
	}
}

//初始化子窗口
void CYouthVideoDlg::InitSubWindow(){
	//子窗口-------------------------
	m_pVideoDecode = new CDlgVideoDecode;
	m_pAudioDecode = new CDlgAudioDecode;
	m_pVideoDecode->Create(IDD_DLG_VIDEODECODE);
	m_pAudioDecode->Create(IDD_DLG_AUDIODECODE);

}

//释放子窗口
void CYouthVideoDlg::FreeSubWindow(){
	m_pVideoDecode->DestroyWindow();
	m_pAudioDecode->DestroyWindow();
	delete m_pVideoDecode;
	delete m_pAudioDecode;
}


void CYouthVideoDlg::OnBnClickedVideodecode()
{
	m_pVideoDecode->ShowWindow(SW_SHOW);
}


void CYouthVideoDlg::OnBnClickedAudiodecode()
{
	m_pAudioDecode->ShowWindow(SW_SHOW);
}
