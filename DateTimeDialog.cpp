/***************************************************************
 * Name:      DateTimeDialog.cpp
 * Purpose:   Code for Application Frame
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

#include "DateTimeDialog.h"
#include <wx/datetime.h>

DateTimeDialog::DateTimeDialog(wxDialog *dlg)
    : DateTimeGUI(dlg)
{
    m_listBox1->Clear();

    wxDateTime dt(time(NULL));

    m_listBox1->Append(dt.FormatDate());
    m_listBox1->Append(dt.FormatISODate());
    m_listBox1->Append(dt.FormatTime());
    m_listBox1->Append(dt.FormatISOTime());
    m_listBox1->Append(dt.Format(_("%d.%m.%y %H:%M:%S")));
}

DateTimeDialog::~DateTimeDialog()
{
    //dtor
}

bool DateTimeDialog::IsPicked()
{
    return m_listBox1->GetSelection() != wxNOT_FOUND;
}

void DateTimeDialog::Apply()
{
    int n = m_listBox1->GetSelection();
    if (n != wxNOT_FOUND)
        picked = m_listBox1->GetString(n);
    else
        picked = _("");
    Close();
}

void DateTimeDialog::OnListBoxDoubleClick( wxCommandEvent& event )
{
    Apply();
}

void DateTimeDialog::OnOkButtonClick( wxCommandEvent& event )
{
    Apply();
}

void DateTimeDialog::OnCancelButtonClick( wxCommandEvent& event )
{
    picked = _("");
    Close();
}

wxString DateTimeDialog::GetPicked()
{
    return picked;
}
