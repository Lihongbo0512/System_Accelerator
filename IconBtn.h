#pragma once


// CIconBtn

class CIconBtn : public CButton
{
	DECLARE_DYNAMIC(CIconBtn)

public:
	CIconBtn();
	virtual ~CIconBtn();
	void SetImageIndex(UINT Index);
public:
	CImageList  m_ImageList;
	CImageList* m_pImageList;	// 图像列表指针
	int			m_ImageIndex;	// 图标索引
	BOOL		IsPressed;		// 按钮是否被按下
protected:
	DECLARE_MESSAGE_MAP()

public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};


