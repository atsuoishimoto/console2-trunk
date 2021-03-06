
#pragma once

#include "DlgSettingsBase.h"

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

class DlgSettingsConsole 
	: public DlgSettingsBase
{
	public:

		DlgSettingsConsole(CComPtr<IXMLDOMElement>& pOptionsRoot);

		BEGIN_DDX_MAP(DlgSettingsConsole)
			DDX_TEXT(IDC_SHELL, m_strShell)
			DDX_TEXT(IDC_INIT_DIR, m_strInitialDir)
			DDX_CHECK(IDC_CHECK_START_HIDDEN, m_nStartHidden)
			DDX_UINT(IDC_CHANGE_REFRESH, m_consoleSettings.dwChangeRefreshInterval)
			DDX_UINT(IDC_REFRESH, m_consoleSettings.dwRefreshInterval)
			DDX_UINT(IDC_ROWS, m_consoleSettings.dwRows)
			DDX_UINT(IDC_COLUMNS, m_consoleSettings.dwColumns)
			DDX_CHECK(IDC_CHECK_SAVE_SIZE, m_nSaveSize)
			DDX_UINT(IDC_BUFFER_ROWS, m_consoleSettings.dwBufferRows)
			DDX_UINT(IDC_BUFFER_COLUMNS, m_consoleSettings.dwBufferColumns)
		END_DDX_MAP()

		BEGIN_MSG_MAP(DlgSettingsConsole)
			MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
			MESSAGE_HANDLER(WM_CTLCOLORSTATIC, OnCtlColorStatic)
			COMMAND_ID_HANDLER(IDOK, OnCloseCmd)
			COMMAND_ID_HANDLER(IDCANCEL, OnCloseCmd)
			COMMAND_HANDLER(IDC_BTN_BROWSE_SHELL, BN_CLICKED, OnClickedBtnBrowseShell)
			COMMAND_HANDLER(IDC_BTN_BROWSE_DIR, BN_CLICKED, OnClickedBtnBrowseDir)
			COMMAND_HANDLER(IDC_BTN_RESET_COLORS, BN_CLICKED, OnClickedBtnResetColors)
			COMMAND_RANGE_CODE_HANDLER(IDC_CLR_00, IDC_CLR_15, BN_CLICKED, OnClickedClrBtn)
		END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//		LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//		LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//		LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

		LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
		LRESULT OnCtlColorStatic(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

		LRESULT OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

		LRESULT OnClickedBtnBrowseShell(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
		LRESULT OnClickedBtnBrowseDir(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
		LRESULT OnClickedBtnResetColors(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
		LRESULT OnClickedClrBtn(WORD /*wNotifyCode*/, WORD wID, HWND hWndCtl, BOOL& /*bHandled*/);

	private:

		ConsoleSettings				m_consoleSettings;

		CString						m_strShell;
		CString						m_strInitialDir;

		int							m_nStartHidden;
		int							m_nSaveSize;
};

//////////////////////////////////////////////////////////////////////////////
