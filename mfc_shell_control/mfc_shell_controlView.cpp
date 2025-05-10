﻿
// mfc_shell_controlView.cpp : CmfcshellcontrolView クラスの実装
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "mfc_shell_control.h"
#endif

#include "mfc_shell_controlDoc.h"
#include "mfc_shell_controlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmfcshellcontrolView

IMPLEMENT_DYNCREATE(CmfcshellcontrolView, CView)

BEGIN_MESSAGE_MAP(CmfcshellcontrolView, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmfcshellcontrolView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CmfcshellcontrolView コンストラクション/デストラクション

CmfcshellcontrolView::CmfcshellcontrolView() noexcept
{
	// TODO: 構築コードをここに追加します。

}

CmfcshellcontrolView::~CmfcshellcontrolView()
{
}

BOOL CmfcshellcontrolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CmfcshellcontrolView 描画

void CmfcshellcontrolView::OnDraw(CDC* /*pDC*/)
{
	CmfcshellcontrolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CmfcshellcontrolView の印刷


void CmfcshellcontrolView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmfcshellcontrolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CmfcshellcontrolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CmfcshellcontrolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

void CmfcshellcontrolView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmfcshellcontrolView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmfcshellcontrolView の診断

#ifdef _DEBUG
void CmfcshellcontrolView::AssertValid() const
{
	CView::AssertValid();
}

void CmfcshellcontrolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmfcshellcontrolDoc* CmfcshellcontrolView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmfcshellcontrolDoc)));
	return (CmfcshellcontrolDoc*)m_pDocument;
}
#endif //_DEBUG


// CmfcshellcontrolView メッセージ ハンドラー
