#pragma once


// CDiskDlg 对话框

class CDiskDlg : public CDialog
{
	DECLARE_DYNAMIC(CDiskDlg)

public:
	CDiskDlg(CWnd* pParent = nullptr);     // 标准构造函数
	virtual ~CDiskDlg();
public:
	void DelFolder(CString path);		  //递归删除文件
	void Cleardisk(int num);              //清理用户选中的项目
public:
	CButton    m_CheckAll;
	CListCtrl	m_Grid;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DiskDlg };
	
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedCheckAll();
};
