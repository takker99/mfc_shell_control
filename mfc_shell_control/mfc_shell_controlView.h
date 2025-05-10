
// mfc_shell_controlView.h : CmfcshellcontrolView クラスのインターフェイス
//

#pragma once


class CmfcshellcontrolView : public CView
{
protected: // シリアル化からのみ作成します。
	CmfcshellcontrolView() noexcept;
	DECLARE_DYNCREATE(CmfcshellcontrolView)

// 属性
public:
	CmfcshellcontrolDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 実装
public:
	virtual ~CmfcshellcontrolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // mfc_shell_controlView.cpp のデバッグ バージョン
inline CmfcshellcontrolDoc* CmfcshellcontrolView::GetDocument() const
   { return reinterpret_cast<CmfcshellcontrolDoc*>(m_pDocument); }
#endif

