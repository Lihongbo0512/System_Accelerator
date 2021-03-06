// ContralDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "System_Accelerator.h"
#include "ContralDlg.h"
#include "afxdialogex.h"


// ContralDlg 对话框

IMPLEMENT_DYNAMIC(ContralDlg, CDialog)

ContralDlg::ContralDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ContralDlg, pParent)
{

}

ContralDlg::~ContralDlg()
{
}

void ContralDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTCOMPUTER, m_Computer);
	DDX_Control(pDX, IDC_BUTTIMEDATE, m_Timedate);
	DDX_Control(pDX, IDC_BUTSYSDM, m_Sysdm);
	DDX_Control(pDX, IDC_BUTMOUSE, m_Mouse);
	DDX_Control(pDX, IDC_BUTMMSYS, m_Mmsys);
	DDX_Control(pDX, IDC_BUTKEYBOARD, m_Keyboard);
	DDX_Control(pDX, IDC_BUTINTL, m_Intl);
	DDX_Control(pDX, IDC_BUTHDWWIZ, m_Hdwwiz);
	DDX_Control(pDX, IDC_BUTDESK, m_Desk);
	DDX_Control(pDX, IDC_BUTAPPWIZ, m_Appwiz);
	DDX_Control(pDX, IDC_BUTACCESS, m_Access);
	DDX_Control(pDX, IDC_BUTINTERNET, m_Internet);
}


BEGIN_MESSAGE_MAP(ContralDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTINTERNET, &ContralDlg::OnBnClickedButinternet)
	ON_BN_CLICKED(IDC_BUTMMSYS, &ContralDlg::OnBnClickedButmmsys)
	ON_BN_CLICKED(IDC_BUTTIMEDATE, &ContralDlg::OnBnClickedButtimedate)
	ON_BN_CLICKED(IDC_BUTDESK, &ContralDlg::OnBnClickedButdesk)
	ON_BN_CLICKED(IDC_BUTACCESS, &ContralDlg::OnBnClickedButaccess)
	ON_BN_CLICKED(IDC_BUTMOUSE, &ContralDlg::OnBnClickedButmouse)
	ON_BN_CLICKED(IDC_BUTKEYBOARD, &ContralDlg::OnBnClickedButkeyboard)
	ON_BN_CLICKED(IDC_BUTINTL, &ContralDlg::OnBnClickedButintl)
	ON_BN_CLICKED(IDC_BUTAPPWIZ, &ContralDlg::OnBnClickedButappwiz)
	ON_BN_CLICKED(IDC_BUTHDWWIZ, &ContralDlg::OnBnClickedButhdwwiz)
	ON_BN_CLICKED(IDC_BUTSYSDM, &ContralDlg::OnBnClickedButsysdm)
	ON_BN_CLICKED(IDC_BUTCOMPUTER, &ContralDlg::OnBnClickedButcomputer)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// ContralDlg 消息处理程序


void ContralDlg::OnBnClickedButinternet()
{
	// 打开网络的设置窗口
	::ShellExecute(NULL, _T("OPEN"), "rundll32.exe",
		"shell32.dll Control_RunDLL inetcpl.cpl", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButmmsys()
{
	// 打开 声音的设置窗口
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL mmsys.cpl @1", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButtimedate()
{
	// 启动日期和时间设置
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL timedate.cpl", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButdesk()
{
	// 启动显示设置面板
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL desk.cpl", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButaccess()
{
	// 启动辅助选项
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL access.cpl", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButmouse()
{
	// 打开鼠标设置
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL main.cpl @0", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButkeyboard()
{
	// 启动键盘设置
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL main.cpl @1", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButintl()
{
	// 打开区域设置
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL intl.cpl", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButappwiz()
{
	// 启动添加软件设置
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL appwiz.cpl", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButhdwwiz()
{
	// 启动添加硬件设置
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL hdwwiz.cpl", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButsysdm()
{
	// 打开系统设置
	::ShellExecute(NULL, "OPEN", "rundll32.exe",
		"shell32.dll Control_RunDLL sysdm.cpl", NULL, SW_SHOW);
}


void ContralDlg::OnBnClickedButcomputer()
{
	// 启动计算机管理设置
	::ShellExecute(NULL, "OPEN", "compmgmt.msc",
		"shell32.dll Control_RunDLL compmgmt.cpl", NULL, SW_SHOW);
}


HBRUSH ContralDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	//CBitmap m_BKGround;
	//m_BKGround.LoadBitmap();
	if (nCtlColor == CTLCOLOR_DLG) {
		// 定义一个位图画刷
		CBrush m_Brush(RGB(110,255,120));
		CRect rect;
		GetClientRect(rect);
		// 选中画刷
		pDC->SelectObject(&m_Brush);
		// 填充客户区域
		pDC->FillRect(rect, &m_Brush);
		return m_Brush;
	}
	else {
		hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
	return hbr;
}


BOOL ContralDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Internet.SetImageIndex(0);            // Internet选项按钮显示图标
	m_Mmsys.SetImageIndex(1);               // 声音按钮显示图标
	m_Timedate.SetImageIndex(2);            // 时间和日期按钮显示图标
	m_Desk.SetImageIndex(3);                // 显示按钮显示图标
	m_Access.SetImageIndex(4);              // 辅助选项按钮显示图标
	m_Mouse.SetImageIndex(5);               // 鼠标按钮显示图标
	m_Keyboard.SetImageIndex(6);            // 键盘按钮显示图标
	m_Intl.SetImageIndex(7);                // 区域按钮显示图标
	m_Appwiz.SetImageIndex(8);              // 添加/删除程序按钮显示图标
	m_Hdwwiz.SetImageIndex(9);              // 添加硬件按钮显示图标
	m_Sysdm.SetImageIndex(10);              // 系统按钮显示图标
	m_Computer.SetImageIndex(11);           // 计算机管理按钮显示图标

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
