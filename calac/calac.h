
// calac.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CcalacApp:
// О реализации данного класса см. calac.cpp
//

class CcalacApp : public CWinApp
{
public:
	CcalacApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CcalacApp theApp;