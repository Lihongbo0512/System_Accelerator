
// System_AcceleratorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "System_Accelerator.h"
#include "System_AcceleratorDlg.h"
#include "afxdialogex.h"
#include "ContralDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSystemAcceleratorDlg 对话框



CSystemAcceleratorDlg::CSystemAcceleratorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Frame, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//标题颜色
	m_CaptionColor = RGB(200, 150, 100);
	//标题文本
	m_Caption = "System Accelerator";
	//标题文本字体
	m_CaptionFont.CreateFont(14, 10, 0, 3, 600, 0, 0, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, FF_ROMAN, "宋体");
}

void CSystemAcceleratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BITMAPSelect, m_Select);
	DDX_Control(pDX, IDC_Frame, m_Frame);
}

BEGIN_MESSAGE_MAP(CSystemAcceleratorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCMOUSEMOVE()
	ON_WM_MOUSEMOVE()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCACTIVATE()
	ON_WM_CLOSE()
	ON_WM_CTLCOLOR()
	ON_STN_CLICKED(IDC_Contral, &CSystemAcceleratorDlg::OnStnClickedContral)
	ON_STN_CLICKED(IDC_Disk, &CSystemAcceleratorDlg::OnStnClickedDisk)
	ON_STN_CLICKED(IDC_Litter, &CSystemAcceleratorDlg::OnStnClickedLitter)
	ON_STN_CLICKED(IDC_Task, &CSystemAcceleratorDlg::OnStnClickedTask)
	ON_WM_NCPAINT()
	ON_WM_MOVE()
END_MESSAGE_MAP()


// CSystemAcceleratorDlg 消息处理程序

BOOL CSystemAcceleratorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
									
									
	// 初始化
	m_Num = 0;
	//this->MoveWindow(100, 100, 970, 550);				//设置窗口大小
	m_pTaskDlg = new CTaskDlg;
	m_pTaskDlg->Create(IDD_CTaskDlg, this);			    // 创建系统任务管理模块
	m_Select.ShowWindow(SW_HIDE);                       // 隐藏选中效果图片
	SetWindowText("System Accelerator");               // 设置主窗体标题
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_Min1);                       // 加载最小化按钮位图
	BITMAPINFO bInfo;
	bitmap.GetObject(sizeof(bInfo), &bInfo);            // 获得图片信息
	m_ButtonWidth = bInfo.bmiHeader.biWidth;            // 位图宽度
	m_ButtonHeight = bInfo.bmiHeader.biHeight;          // 位图高度
	bitmap.DeleteObject();

	// 背景图片
	m_BKGround.LoadBitmap(IDB_BkGround);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSystemAcceleratorDlg::OnPaint()
{
	
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		//绘制标题栏
		DrawDialog(fAll);
		m_IsDrawForm = TRUE;
		
	}
	
	
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSystemAcceleratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//绘制窗口标题文本
void CSystemAcceleratorDlg::DrawCaption()
{
	// 标题文本不为空
	if (!m_Caption.IsEmpty()) {
		CDC *pDC = GetWindowDC();                 // 获得窗口设备上下文
		pDC->SetBkMode(TRANSPARENT);              // 设置背景透明
		pDC->SetTextColor(m_CaptionColor);        // 设置文本颜色
		pDC->SetTextAlign(TA_CENTER);             // 居中显示
		CRect rect;
		GetClientRect(rect);                      // 获得窗口客户区域
		pDC->SelectObject(&m_CaptionFont);        // 设置字体
		pDC->TextOut(rect.Width() / 2,              // 绘制文本
			m_CaptionHeight / 3 + 2,
			m_Caption);
		ReleaseDC(pDC);                           // 释放设备上下文
	}
}


//绘制标题栏及按钮
void CSystemAcceleratorDlg::DrawDialog(UINT Flags)
{
	CRect WinRC, FactRC;
	//获取窗口区域
	GetWindowRect(WinRC);
	//复制区域
	FactRC.CopyRect(CRect(0, 0, WinRC.Width(), WinRC.Height()));
	//获取边框的高
	m_BorderHeight = GetSystemMetrics(SM_CYBORDER);
	//获取边框的宽
	m_BorderWidth = GetSystemMetrics(SM_CXBORDER);
	//获取标题栏的高度
	m_CaptionHeight = GetSystemMetrics(SM_CYCAPTION);
	//获取设备上下文
	CWindowDC WindowsDC(this);
	//创建内存兼容DC
	CDC memDC;
	memDC.CreateCompatibleDC(&WindowsDC);

	if (Flags & fTitle)//绘制标题
	{
		CBitmap bmpTitle, *OldObj;
		BITMAPINFO bitmapinfo;
		DeleteObject(bmpTitle);
		//加载标题栏文字
		bmpTitle.LoadBitmap(IDB_BITMAP3);
		//获取位图大小
		bmpTitle.GetObject(sizeof(bitmapinfo),&bitmapinfo);
		//选中该位图
		OldObj = memDC.SelectObject(&bmpTitle);
		int width = bitmapinfo.bmiHeader.biWidth;
		int height = bitmapinfo.bmiHeader.biHeight;

		m_TitleDrawHeight = (m_CaptionHeight + 4>height) ?
			m_CaptionHeight + 4 : height;

		CRect rr(FactRC.left,0,FactRC.right,m_TitleDrawHeight);
		m_TitleRect.CopyRect(rr);
		WindowsDC.StretchBlt(m_TitleRect.left,m_TitleRect.top,
								m_TitleRect.Width(),m_TitleRect.Height(),
									&memDC,0,0,width,height,SRCCOPY);

		bmpTitle.Detach();
		memDC.SelectObject(OldObj);
	}

	//最小化按钮的大小
	m_MinRect.CopyRect(CRect(m_TitleRect.right - 70, (m_TitleDrawHeight +
		2 * m_BorderWidth - m_ButtonHeight) / 2,
		m_ButtonWidth, m_ButtonHeight));

	//关闭按钮的大小
	m_CloseRect.CopyRect(CRect(m_TitleRect.right - 40, (m_TitleDrawHeight +
		2 * m_BorderWidth - m_ButtonHeight) / 2,
		m_ButtonWidth, m_ButtonHeight));

	// 绘制最小化按钮
	if (Flags & fMinButton) {
		CBitmap bitmapMinBtn, *OldObj;
		BITMAPINFO bitmapInfo;
		DeleteObject(bitmapMinBtn);
		bitmapMinBtn.LoadBitmap(IDB_Min1);
		// 获取位图大小
		bitmapMinBtn.GetObject(sizeof(bitmapInfo), &bitmapInfo);
		OldObj = memDC.SelectObject(&bitmapMinBtn);
		int width = bitmapInfo.bmiHeader.biWidth;
		int height = bitmapInfo.bmiHeader.biHeight;
		WindowsDC.StretchBlt(m_MinRect.left, m_MinRect.top, m_MinRect.right,
			m_MinRect.bottom, &memDC, 0, 0, width, height, SRCCOPY);
		memDC.SelectObject(OldObj);
		bitmapMinBtn.Detach();
	}

	// 绘制关闭按钮
	if (Flags & fCloseButton) {
		CBitmap bitmapCloseBtn, *OldObj;
		BITMAPINFO bitmapInfo;
		DeleteObject(bitmapCloseBtn);
		bitmapCloseBtn.LoadBitmap(IDB_Close1);
		// 获取位图大小
		bitmapCloseBtn.GetObject(sizeof(bitmapInfo), &bitmapInfo);
		OldObj = memDC.SelectObject(&bitmapCloseBtn);
		int width = bitmapInfo.bmiHeader.biWidth;
		int height = bitmapInfo.bmiHeader.biHeight;
		WindowsDC.StretchBlt(m_CloseRect.left, m_CloseRect.top, m_CloseRect.right,
			m_CloseRect.bottom, &memDC, 0, 0, width, height, SRCCOPY);
		memDC.SelectObject(OldObj);
		bitmapCloseBtn.Detach();
	}
	DrawCaption();
}


//当鼠标移动到标题栏按钮上时，标题栏按钮产生热点效果，移开时取消热点效果。
void CSystemAcceleratorDlg::OnNcMouseMove(UINT nHitTest, CPoint point)
{

	CRect tempMin, tempMax, tempClose, ClientRect;
	CWindowDC WindowDC(this);   // 获得窗口设备上下文
	CDC memDC;
	memDC.CreateCompatibleDC(&WindowDC);    // 创建内存兼容的设备上下文
	BITMAPINFO bInfo;
	CBitmap LeftLine;
	int x, y;
	GetWindowRect(ClientRect);   // 获得客户区域
								 // 设置最小化按钮区域
	tempMin.CopyRect(CRect(m_MinRect.left + ClientRect.left,
		ClientRect.top + m_MinRect.top,
		m_MinRect.right + m_MinRect.left + ClientRect.left,
		m_MinRect.bottom + m_MinRect.top + ClientRect.top));
	// 设置关闭按钮区域
	tempClose.CopyRect(CRect(m_CloseRect.left + ClientRect.left,
		ClientRect.top + m_CloseRect.top,
		m_CloseRect.right + m_CloseRect.left +
		ClientRect.left,
		m_CloseRect.bottom + m_CloseRect.top +
		ClientRect.top));
	// 鼠标在最小化按钮上移动时,更改按钮显示的位图
	if (tempMin.PtInRect(point)) {
		// 按钮状态不是最小化
		if (m_ButtonState != bsMin) {
			// 加载最小化热点位图
			LeftLine.LoadBitmap(IDB_Min2);
			LeftLine.GetObject(sizeof(bInfo), &bInfo);

			x = bInfo.bmiHeader.biWidth; // 位图宽度
			y = bInfo.bmiHeader.biHeight;// 位图高度
			memDC.SelectObject(&LeftLine);
			// 绘制最小化按钮热点效果
			WindowDC.StretchBlt(m_MinRect.left, m_MinRect.top, m_MinRect.right,
				m_MinRect.bottom, &memDC, 0, 0, x, y, SRCCOPY);
			m_IsDrawForm = FALSE;
			// 设置按钮状态
			m_ButtonState = bsMin;
			LeftLine.Detach();
		}
	}
	// 鼠标在关闭按钮上移动时,更改按钮显示的位图
	else if (tempClose.PtInRect(point)) {
		if (m_ButtonState != bsClose) {
			// 加载关闭按钮热点位图
			LeftLine.LoadBitmap(IDB_Close2);
			LeftLine.GetObject(sizeof(bInfo), &bInfo);
			x = bInfo.bmiHeader.biWidth; // 位图宽度
			y = bInfo.bmiHeader.biHeight;// 位图高度
			memDC.SelectObject(&LeftLine);
			// 绘制关闭按钮热点效果
			WindowDC.StretchBlt(m_CloseRect.left, m_CloseRect.top, m_CloseRect.right
				, m_CloseRect.bottom, &memDC, 0, 0, x, y, SRCCOPY);
			m_IsDrawForm = FALSE;
			m_ButtonState = bsClose;
			LeftLine.Detach();
		}
	}
	// 鼠标不在标题栏按钮上
	else {
		// 按钮具有热点效果
		if (m_IsDrawForm == FALSE) {
			// 是最小化按钮
			if (m_ButtonState == bsMin) {
				DrawDialog(fMinButton);   // 重绘最小化按钮
			}
			// 是关闭按钮
			else if (m_ButtonState == bsClose) {
				DrawDialog(fCloseButton);
			}
		}
		m_ButtonState = bsNone;
	}
	LeftLine.DeleteObject();
	ReleaseDC(&memDC);
	CDialogEx::OnNcMouseMove(nHitTest, point);
}




void CSystemAcceleratorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_IsDrawForm == FALSE) {               // 按钮具有热点效果
		if (m_ButtonState == bsMin) {          // 是最小化按钮
			DrawDialog(fMinButton);           // 重绘最小化按钮
		}
		else if (m_ButtonState == bsClose) {   // 是关闭按钮
			DrawDialog(fCloseButton);         // 重绘关闭按钮
		}
	}
	m_ButtonState = bsNone;
	CDialogEx::OnMouseMove(nFlags, point);
}

//响应标题栏按钮的鼠标单击事件
void CSystemAcceleratorDlg::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	switch (m_ButtonState) {                   // 判断按钮状态
	case bsClose: {                     // 关闭按钮
		OnCancel();                       // 关闭窗口
	}
				  break;
	case bsMin: {                       // 最小化按钮
		ShowWindow(SW_SHOWMINIMIZED);     // 最小化窗体
	}
				break;
	}
	CDialogEx::OnNcLButtonDown(nHitTest, point);
}



//窗口的非客户区被激活，在该消息中重绘窗口
BOOL CSystemAcceleratorDlg::OnNcActivate(BOOL bActive)
{
	DrawDialog(fAll);   // 绘制标题栏
	return CDialogEx::OnNcActivate(bActive);
}


void CSystemAcceleratorDlg::OnClose()
{
	if (m_Num != 0) {
		DestroyWindowBox(m_Num);    // 销毁当前显示的模块
	}
	m_pTaskDlg->DestroyWindow();    // 销毁系统任务管理模块

	CDialogEx::OnClose();
}


HBRUSH CSystemAcceleratorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if (nCtlColor == CTLCOLOR_DLG) {                 // 如果是对话框
		CBrush m_Brush(&m_BKGround);                // 定义一个位图画刷
		CRect rect;
		GetClientRect(rect);                        // 获取客户区大小
		pDC->SelectObject(&m_Brush);                // 选中画刷
		pDC->FillRect(rect, &m_Brush);              // 填充客户区域
		return m_Brush;                             // 返回新的画刷
	}
	else {
		hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
	if (nCtlColor == CTLCOLOR_STATIC) {              // 如果是静态文本控件
		pDC->SetBkMode(TRANSPARENT);                // 设置背景透明
	}
	return hbr;
}


void CSystemAcceleratorDlg::OnStnClickedContral()
{
	if (m_Num != 0) 
	{
		DestroyWindowBox(m_Num);								 // 销毁当前打开的模块
	}
	CreateDialogBox(1);											 // 显示控制面板操作模块
	CRect rect, rc;
	GetDlgItem(IDC_Contral)->GetClientRect(&rect);				 // 获得控件的客户区域
	GetDlgItem(IDC_Contral)->MapWindowPoints(this, rect);		 // 设置窗体中的位置
	m_Select.GetClientRect(&rc);
	m_Select.MoveWindow(rect.left - 20,							 // 移动选中效果图片控件
		rect.top - 6,
		rc.Width(),
		rc.Height(), TRUE);
	m_Select.ShowWindow(SW_SHOW);								 // 显示选中效果图片控件
	Invalidate();												 // 使窗体无效(重绘窗体)
}


void CSystemAcceleratorDlg::OnStnClickedDisk()
{
	if (m_Num != 0) {
		DestroyWindowBox(m_Num);
	}
	CreateDialogBox(2);
	CRect rect, rc;
	GetDlgItem(IDC_Disk)->GetClientRect(&rect);
	GetDlgItem(IDC_Disk)->MapWindowPoints(this, rect);
	m_Select.GetClientRect(&rc);
	m_Select.MoveWindow(rect.left - 20, rect.top - 6, rc.Width(), rc.Height(), TRUE);
	m_Select.ShowWindow(SW_SHOW);
	Invalidate();
}


void CSystemAcceleratorDlg::OnStnClickedLitter()
{
	if (m_Num != 0) {
		DestroyWindowBox(m_Num);
	}
	CreateDialogBox(3);
	CRect rect, rc;
	GetDlgItem(IDC_Litter)->GetClientRect(&rect);
	GetDlgItem(IDC_Litter)->MapWindowPoints(this, rect);
	m_Select.GetClientRect(&rc);
	m_Select.MoveWindow(rect.left - 20, rect.top - 6, rc.Width(), rc.Height(), TRUE);
	m_Select.ShowWindow(SW_SHOW);
	Invalidate();
}


void CSystemAcceleratorDlg::OnStnClickedTask()
{
	if (m_Num != 0) {
		DestroyWindowBox(m_Num);
	}
	CreateDialogBox(4);
	CRect rect, rc;
	GetDlgItem(IDC_Task)->GetClientRect(&rect);
	GetDlgItem(IDC_Task)->MapWindowPoints(this, rect);
	m_Select.GetClientRect(&rc);
	m_Select.MoveWindow(rect.left - 20, rect.top - 6, rc.Width(), rc.Height(), TRUE);
	m_Select.ShowWindow(SW_SHOW);
	Invalidate();
}

void CSystemAcceleratorDlg::CreateDialogBox(int num)
{
	CRect fRect;
	m_Frame.GetClientRect(&fRect);               // 获得图片控件的客户区域
	m_Frame.MapWindowPoints(this, fRect);        // 设置模块的显示位置
	switch (num) {                               // 判断显示的模块
	case 1:							// 控制面板操作模块
		m_pContralDlg = new ContralDlg;		  	 // 创建对话框
		m_pContralDlg->Create(IDD_ContralDlg, this);
		m_pContralDlg->MoveWindow(fRect);		 // 移动位置(显示位置)
		m_pContralDlg->ShowWindow(SW_SHOW);	     // 显示对话框
		break;
	case 2:                        // 磁盘空间整理模块
		m_pDiskDlg = new CDiskDlg;				 // 创建对话框
		m_pDiskDlg->Create(IDD_DiskDlg, this);
		m_pDiskDlg->MoveWindow(fRect);			 // 移动位置(显示位置)
		m_pDiskDlg->ShowWindow(SW_SHOW);		 // 显示对话框
		break;
	case 3:                        // 垃圾文件整理模块
		m_pLitterDlg = new CLitterDLg;			// 创建对话框
		m_pLitterDlg->Create(IDD_LitterDlg, this);
		m_pLitterDlg->MoveWindow(fRect);		// 移动位置(显示位置)
		m_pLitterDlg->ShowWindow(SW_SHOW);		// 显示对话框
		break;
	case 4:                       // 系统任务管理模块
		m_pTaskDlg->MoveWindow(fRect);			// 移动位置(显示位置)
		m_pTaskDlg->ShowWindow(SW_SHOW);		// 显示对话框
		break;
	}
	m_Num = num;
}


void CSystemAcceleratorDlg::DestroyWindowBox(int num)
{
	switch (num) {                           // 判断销毁的模块
	case 1:                             // 控制面板操作模块
		m_pContralDlg->DestroyWindow(); // 销毁对话框
		break;
	case 2:                             // 磁盘空间整理模块
		m_pDiskDlg->DestroyWindow();    // 销毁对话框
		break;
	case 3:                             // 垃圾文件整理模块
		m_pLitterDlg->DestroyWindow();  // 销毁对话框
		break;
	case 4:                             // 系统任务管理模块
		m_pTaskDlg->ShowWindow(FALSE);  // 隐藏对话框
		break;
	}
}

void CSystemAcceleratorDlg::OnNcPaint()
{
	DrawDialog(fAll);
}


void CSystemAcceleratorDlg::OnMove(int x, int y)
{	DrawDialog(fAll);
	CDialogEx::OnMove(x, y);


}
