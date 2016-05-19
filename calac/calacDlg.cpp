
// calacDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "calac.h"
#include "calacDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CcalacDlg



CcalacDlg::CcalacDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALAC_DIALOG, pParent), WorkField(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalacDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WORK_FIELD, WorkField);
}

BEGIN_MESSAGE_MAP(CcalacDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_WORK_FIELD, &CcalacDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CcalacDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalacDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalacDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalacDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalacDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalacDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalacDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalacDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalacDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CcalacDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_EQL, &CcalacDlg::OnBnClickedButtonEql)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CcalacDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CcalacDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULT, &CcalacDlg::OnBnClickedButtonMult)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CcalacDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CcalacDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CcalacDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// обработчики сообщений CcalacDlg

BOOL CcalacDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	WorkField = L"0";
	UpdateData(FALSE);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CcalacDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CcalacDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CcalacDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcalacDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}
double a = 0;
double b = 0;
int Operation = 0;
int LastOperation = 0;
bool flagOperation = 0;
bool flagEql = 0;
bool flagDot = 1;

void CcalacDlg::OnBnClickedButton1()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql = 0;}
	WorkField += L"1";
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButton2()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql = 0;}
	WorkField += L"2";
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButton3()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql = 0;}
	WorkField += L"3";
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButton4()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql = 0;}
	WorkField += L"4";
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButton5()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql = 0;}
	WorkField += L"5";
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButton6()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql = 0;}
	WorkField += L"6";
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButton7()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql = 0;}
	WorkField += L"7";
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButton8()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql = 0;}
	WorkField += L"8";
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButton9()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql = 0;}
	WorkField += L"9";
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButton0()
{
	if (WorkField == L"0" || flagEql) {WorkField = "";flagEql	= 0;}
	WorkField += L"0";
	UpdateData(FALSE);
}

void CcalacDlg::OnBnClickedButtonDot()
{
	if (WorkField == L"0" || flagEql) 
	{
		WorkField = "0."; 
		flagEql = 0; 
		flagDot = 1;
	}
	else if (flagDot) 
	{ 
		flagDot = 0; 
		WorkField += L".";
	}
	UpdateData(FALSE);
}


void CcalacDlg::OnBnClickedButtonEql()
{
		UpdateData(TRUE);
		if (Operation == 0 && LastOperation!=0 && flagOperation)
		{
			switch (LastOperation)
			{
			case 1:a = a + b;WorkField.Format(_T("%lf"), a);break;
			case 2:a = a - b;WorkField.Format(_T("%lf"), a);break;
			case 3:a = a * b;WorkField.Format(_T("%lf"), a);break;
			case 4:
				if (b == 0)
					WorkField = L"Деление на ноль!";
				else
					a = a / b;WorkField.Format(_T("%lf"), a);break;
			}
		}
		else
		{
			CT2CA pszConvertedAnsiString(WorkField);
			std::string s(pszConvertedAnsiString);
			const char * c = s.c_str();
			b = atof(c);
			switch (Operation)
				{
				case 1:a = a + b;WorkField.Format(_T("%lf"), a);break;
				case 2:a = a - b;WorkField.Format(_T("%lf"), a);break;
				case 3:a = a * b;WorkField.Format(_T("%lf"), a);break;
				case 4:
					if (b == 0)
						WorkField = L"Деление на ноль!";
					else
						a = a / b;WorkField.Format(_T("%lf"), a);break;
				}
				
				LastOperation = Operation;
				Operation = 0;
				flagOperation = 1;
		}
		UpdateData(FALSE);
		flagEql = 1;
}
void CcalacDlg::OnBnClickedButtonPlus()
{
	UpdateData(TRUE);
	CT2CA pszConvertedAnsiString(WorkField);
	std::string s (pszConvertedAnsiString);
	const char * c = s.c_str();
	if (Operation == 0)
	{
		Operation = 1;
		a = atof(c);
		WorkField = L"0";
	}
	else 
	{
		flagOperation = 0;
		OnBnClickedButtonEql();
	}
		
	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButtonMinus()
{
	UpdateData(TRUE);
	CT2CA pszConvertedAnsiString(WorkField);
	std::string s(pszConvertedAnsiString);
	const char * c = s.c_str();
	if (Operation == 0)
	{
		Operation = 2;
		a = atof(c);
		WorkField = L"0";
	}
	else
	{
		flagOperation = 0;
		OnBnClickedButtonEql();
	}

	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButtonMult()
{
	UpdateData(TRUE);
	CT2CA pszConvertedAnsiString(WorkField);
	std::string s(pszConvertedAnsiString);
	const char * c = s.c_str();
	if (Operation == 0)
	{
		Operation = 3;
		a = atof(c);
		WorkField = L"0";
	}
	else
	{
		flagOperation = 0;
		OnBnClickedButtonEql();
	}

	UpdateData(FALSE);
}
void CcalacDlg::OnBnClickedButtonDiv()
{
	UpdateData(TRUE);
	CT2CA pszConvertedAnsiString(WorkField);
	std::string s(pszConvertedAnsiString);
	const char * c = s.c_str();
	if (Operation == 0)
	{
		Operation = 4;
		a = atof(c);
		WorkField = L"0";
	}
	else
	{
		flagOperation = 0;
		OnBnClickedButtonEql();
	}

	UpdateData(FALSE);
}

void CcalacDlg::OnBnClickedButtonClear()
{
	WorkField = L"0";
	Operation = 0;
	LastOperation = 0;
	a = 0;
	b = 0;
	flagOperation = 0;
	flagEql = 0;
	UpdateData(FALSE);
}
