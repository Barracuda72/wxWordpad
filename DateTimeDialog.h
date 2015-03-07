/***************************************************************
 * Name:      DateTimeDialog.h
 * Purpose:   Defines Application Frame
 * Author:    Barracuda72 (barracuda72@bk.ru)
 * Created:   2015-02-14
 * Copyright: Barracuda72 (http://lleo.aha.ru/na)
 * License:
 **************************************************************/

#ifndef DATETIMEDIALOG_H
#define DATETIMEDIALOG_H

#include "WordpadApp.h"

#include "GUIDialog.h"


class DateTimeDialog : public DateTimeGUI
{
    public:
        DateTimeDialog(wxDialog *dlg);
        ~DateTimeDialog();
        wxString GetPicked();
        bool IsPicked();
    protected:
        void Apply();
        virtual void OnOkButtonClick( wxCommandEvent& event );
        virtual void OnListBoxDoubleClick( wxCommandEvent& event );
		virtual void OnCancelButtonClick( wxCommandEvent& event );
    private:
        wxString picked;
};

#endif // DATETIMEDIALOG_H
