#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include "WordpadApp.h"

#include "GUIDialog.h"


class FindDialog : public FindGUI
{
    public:
        FindDialog(wxDialog *dlg);
        virtual ~FindDialog();
        void SetFindData(wxRichTextCtrl * r, wxFindReplaceData *fr);
    protected:
        virtual void OnFindNextButtonClick( wxCommandEvent& event );
		virtual void OnCancelButtonClick( wxCommandEvent& event );
    private:
        wxRichTextCtrl *fd;
        wxFindReplaceData *fr_data;
};

#endif // FINDDIALOG_H
