
// mfc_shell_control.h : mfc_shell_control アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"       // メイン シンボル


// CmfcshellcontrolApp:
// このクラスの実装については、mfc_shell_control.cpp を参照してください
//

class CmfcshellcontrolApp : public CWinAppEx
{
public:
	CmfcshellcontrolApp() noexcept;


// オーバーライド
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 実装
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CmfcshellcontrolApp theApp;
