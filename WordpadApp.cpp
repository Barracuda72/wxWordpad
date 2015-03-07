/***************************************************************
 * Name:      WordpadApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Barracuda72 (barracuda72@bk.ru)
 * Created:   2015-02-14
 * Copyright: Barracuda72 (http://lleo.aha.ru/na)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "WordpadApp.h"
#include "WordpadMain.h"

IMPLEMENT_APP(WordpadApp);

bool WordpadApp::OnInit()
{
    
    WordpadDialog* dlg = new WordpadDialog(0L);
    
    dlg->Show();
    return true;
}
