#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include "WordpadApp.h"

#include "GUIDialog.h"

class ReplaceDialog : public ReplaceGUI
{
    public:
        ReplaceDialog(wxDialog *dlg);
        virtual ~ReplaceDialog();
        void SetFindData(wxRichTextCtrl * r, wxFindReplaceData *fr);
    protected:
        virtual void OnFindNextButtonClick( wxCommandEvent& event );
		virtual void OnReplaceButtonClick( wxCommandEvent& event );
		virtual void OnReplaceAllButtonClick( wxCommandEvent& event );
		virtual void OnCancelButtonClick( wxCommandEvent& event );
    private:
        wxRichTextCtrl *fd;
        wxFindReplaceData *fr_data;
};

#endif // REPLACEDIALOG_H
