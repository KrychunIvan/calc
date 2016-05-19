
// calacDlg.h : файл заголовка
//

#pragma once
#include <string>

// диалоговое окно CcalacDlg
class CcalacDlg : public CDialogEx
{
// Создание
public:
	CcalacDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALAC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	CString WorkField;
	afx_msg void OnBnClickedButtonEql();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMult();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonClear();
};
