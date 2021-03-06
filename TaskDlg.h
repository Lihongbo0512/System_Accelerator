#pragma once

#include "CustomMenu.h"
// CTaskDlg 对话框

class CTaskDlg : public CDialog
{
	DECLARE_DYNAMIC(CTaskDlg)

public:
	CTaskDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTaskDlg();

	void ShowList(int num);


	CCustomMenu m_Menu;	// 自定义菜单
	CListCtrl	m_Grid;
	
	CTabCtrl	m_Tab;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CTaskDlg };
	
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMenuref();													//刷新
	afx_msg void OnMenustop();													//结束任务
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnNMRClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
