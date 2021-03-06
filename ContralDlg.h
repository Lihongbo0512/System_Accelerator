#pragma once

#include "IconBtn.h"
// ContralDlg 对话框

class ContralDlg : public CDialog
{
	DECLARE_DYNAMIC(ContralDlg)

public:
	ContralDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ContralDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ContralDlg };
#endif
	CIconBtn m_Computer;
	CIconBtn m_Timedate;
	CIconBtn m_Sysdm;
	CIconBtn m_Mouse;
	CIconBtn m_Mmsys;
	CIconBtn m_Keyboard;
	CIconBtn m_Intl;
	CIconBtn m_Hdwwiz;
	CIconBtn m_Desk;
	CIconBtn m_Appwiz;
	CIconBtn m_Access;
	CIconBtn m_Internet;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButinternet();
	afx_msg void OnBnClickedButmmsys();
	afx_msg void OnBnClickedButtimedate();
	afx_msg void OnBnClickedButdesk();
	afx_msg void OnBnClickedButaccess();
	afx_msg void OnBnClickedButmouse();
	afx_msg void OnBnClickedButkeyboard();
	afx_msg void OnBnClickedButintl();
	afx_msg void OnBnClickedButappwiz();
	afx_msg void OnBnClickedButhdwwiz();
	afx_msg void OnBnClickedButsysdm();
	afx_msg void OnBnClickedButcomputer();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
};
