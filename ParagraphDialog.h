#ifndef PARAGRAPHDIALOG_H
#define PARAGRAPHDIALOG_H

#include "GUIDialog.h"

#include "WordpadApp.h"

class ParagraphDialog : public ParagraphGUI
{
    public:
        ParagraphDialog(wxDialog *dlg);
        virtual ~ParagraphDialog();
    protected:
		virtual void OnOkButtonClicked( wxCommandEvent& event );
		virtual void OnCancelButtonClicked( wxCommandEvent& event );
    private:
};

#endif // PARAGRAPHDIALOG_H
