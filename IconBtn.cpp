// IconBtn.cpp: 实现文件
//

#include "stdafx.h"
#include "System_Accelerator.h"
#include "IconBtn.h"


// CIconBtn

IMPLEMENT_DYNAMIC(CIconBtn, CButton)

CIconBtn::CIconBtn()
{
	m_ImageList.Create(32, 32, ILC_COLOR24 | ILC_MASK, 1, 0);			// 创建图像列表
	
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONINETCPL));			// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONMMSYS)); 				// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONTIMEDATE));			// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONDESK)); 				// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONACCESS));				// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONMOUSE)); 				// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONKEYBOARD));			// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONINTL)); 				// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONAPPWIZ));				// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONHDWWIZ)); 			// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONSYSDM));				// 加载图标
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICONCOMPUTER)); 			// 加载图标

	IsPressed = FALSE;//初始化按钮状态
}

CIconBtn::~CIconBtn()
{
}


BEGIN_MESSAGE_MAP(CIconBtn, CButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()



// CIconBtn 消息处理程序




void CIconBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	if (m_pImageList)
	{
		UINT state = lpDrawItemStruct->itemState; // 获取状态
		// 获取图像列中图像大小
		IMAGEINFO imageinfo;
		m_ImageList.GetImageInfo(m_ImageIndex, &imageinfo);
		CSize imagesize;
		imagesize.cx = imageinfo.rcImage.right - imageinfo.rcImage.left;
		imagesize.cy = imageinfo.rcImage.bottom - imageinfo.rcImage.top;
		// 在按钮垂直方向居中显示位图
		CRect rect;
		GetClientRect(rect);
		CPoint point;
		point.x = 5;
		point.y = (rect.Height() - imagesize.cy) / 2;
		m_ImageList.Draw(&dc, m_ImageIndex, point, ILD_NORMAL | ILD_TRANSPARENT);
		CRect focusRect(rect);
		focusRect.DeflateRect(2, 2, 2, 2);
		// 按钮被选中或者获得焦点时
		if ((state&ODS_SELECTED) || (state&ODS_FOCUS))
		{
			CPen pen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));
			CBrush brush;
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.SelectObject(&pen);
			// 绘制焦点矩形
			dc.DrawFocusRect(focusRect);
			// 绘制立体效果
			dc.DrawEdge(rect, BDR_RAISEDINNER | BDR_RAISEDOUTER, BF_BOTTOMLEFT | BF_TOPRIGHT);
			 //获得焦点时绘制黑色边框
			dc.Draw3dRect(rect, RGB(0, 0, 0), RGB(0, 0, 0));
		}
		else 
		{
			CPen pen(PS_DOT, 1, RGB(192, 192, 192));
			CBrush brush;
			brush.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&brush);
			dc.SelectObject(&pen);
			dc.Rectangle(focusRect);
			dc.DrawEdge(rect, BDR_RAISEDINNER | BDR_RAISEDOUTER, BF_BOTTOMLEFT | BF_TOPRIGHT);
		}
		if (IsPressed) // 在按钮被按下时绘制按下效果
		{
			dc.DrawFocusRect(focusRect);
			dc.DrawEdge(rect, BDR_SUNKENINNER | BDR_SUNKENOUTER, BF_BOTTOMLEFT | BF_TOPRIGHT);
			dc.Draw3dRect(rect, RGB(0, 0, 0), RGB(0, 0, 0));
			
		}
		// 绘制按钮文本
		CString text;
		GetWindowText(text);
		rect.DeflateRect(point.x + imagesize.cx, 0, 0, 0);
		dc.SetBkMode(TRANSPARENT);
		dc.DrawText(text, rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
}


void CIconBtn::OnLButtonDown(UINT nFlags, CPoint point)
{
	IsPressed = TRUE;
	CButton::OnLButtonDown(nFlags, point);
}


void CIconBtn::OnLButtonUp(UINT nFlags, CPoint point)
{
	IsPressed = FALSE;
	CButton::OnLButtonUp(nFlags, point);
}


void CIconBtn::SetImageIndex(UINT Index)
{
	m_ImageIndex = Index;
}

HBRUSH CIconBtn::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CButton::OnCtlColor(pDC, pWnd, nCtlColor);
	CBitmap m_BKGround;
	m_BKGround.LoadBitmap(IDB_BITMAP2);
		// 定义一个位图画刷
		CBrush m_Brush(&m_BKGround);
		CRect rect;
		GetClientRect(rect);
		// 选中画刷
		pDC->SelectObject(&m_Brush);
		// 填充客户区域
		pDC->FillRect(rect, &m_Brush);
		return m_Brush;
}
