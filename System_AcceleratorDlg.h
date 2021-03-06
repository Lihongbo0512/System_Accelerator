
// System_AcceleratorDlg.h: 头文件
//

#pragma once

#include "ContralDlg.h"
#include "DiskDlg.h"
#include "LitterDLg.h"
#include "TaskDlg.h"


#define fTitle        1           //标题
#define fMinButton    2           //最小化框
#define fCloseButton  4           //关闭按钮
#define fAll          7           //所有标识


// CSystemAcceleratorDlg 对话框
class CSystemAcceleratorDlg : public CDialogEx
{
// 构造
public:
	CSystemAcceleratorDlg(CWnd* pParent = nullptr);	// 标准构造函数

	//绘制窗口标题文本
	void DrawCaption();
	//绘制标题栏及按钮
	void DrawDialog(UINT Flags);

	void DestroyWindowBox(int num);
	void CreateDialogBox(int num);
private:
	//按钮状态
	enum CButtonState
	{
		bsNone,
		bsMin,
		bsClose
	};

	// 四个TabCtrl的子对话框
	ContralDlg     *m_pContralDlg; // 控制面板操作模块
	CDiskDlg        *m_pDiskDlg;    // 磁盘空间整理模块
	CLitterDLg      *m_pLitterDlg;  // 垃圾文件清理模块
	CTaskDlg        *m_pTaskDlg;    // 系统任务管理模块

	CString m_Caption;            //窗口标题
	CButtonState m_ButtonState;   //按钮状态
	int m_CaptionHeight;          //标题栏的高度
	int m_TitleDrawHeight;        //标题栏实际绘制高度
	int m_ButtonWidth;            //按钮位图宽度
	int m_ButtonHeight;           //按钮位图高度
	int m_BorderWidth;            //边框宽度
	int m_BorderHeight;           //边框高度
	COLORREF m_CaptionColor;      //标题字体颜色
	CFont m_CaptionFont;          //标题字体
	BOOL m_IsDrawForm;            //是否重绘按钮
	CRect m_TitleRect;            //标题栏区域
	CRect m_MinRect;              //最小化按钮区域
	CRect m_CloseRect;            //关闭按钮区域



// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Frame };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CStatic m_Select;
	CStatic m_Frame;
	int m_Num;
	CBitmap m_BKGround;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNcMouseMove(UINT nHitTest, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnStnClickedContral();
	afx_msg void OnStnClickedDisk();
	afx_msg void OnStnClickedLitter();
	afx_msg void OnStnClickedTask();
	afx_msg void OnNcPaint();
	afx_msg void OnMove(int x, int y);
};
