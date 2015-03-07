/***************************************************************
 * Name:      WordpadApp.h
 * Purpose:   Defines Application Class
 * Author:    Barracuda72 (barracuda72@bk.ru)
 * Created:   2015-02-14
 * Copyright: Barracuda72 (http://lleo.aha.ru/na)
 * License:
 **************************************************************/

#ifndef WORDPADAPP_H
#define WORDPADAPP_H

#include <wx/app.h>
#include <wx/wx.h>
#include <wx/aboutdlg.h>
#include <wx/richtext/richtextprint.h>
#include <wx/richtext/richtextxml.h>
#include <wx/colordlg.h>
#include <wx/richtext/richtextstyledlg.h>
#include <wx/richtext/richtextformatdlg.h>
#include <wx/fdrepdlg.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>

class WordpadApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WORDPADAPP_H
