#pragma once


// CLitterDLg 对话框

class CLitterDLg : public CDialog
{
	DECLARE_DYNAMIC(CLitterDLg)

public:
	CLitterDLg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLitterDLg();
public:
	void FileDelete(CString FilePath);    //递归地删除路径下的垃圾文件
	void DeleteLitterFile();              //删除指定磁盘下的垃圾文件
public:
	CListBox	m_List;					 //列表关联变量
	CComboBox	m_Combo;				 //下拉框关联变量
	HANDLE		m_hThread;               //线程句柄
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LitterDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBegin();
	afx_msg void OnBnClickedStop();
};
