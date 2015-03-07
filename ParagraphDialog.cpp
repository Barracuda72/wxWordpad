#include "ParagraphDialog.h"

ParagraphDialog::ParagraphDialog(wxDialog *dlg)
    : ParagraphGUI(dlg)
{
    //ctor
}

ParagraphDialog::~ParagraphDialog()
{
    //dtor
}

void ParagraphDialog::OnOkButtonClicked( wxCommandEvent& event )
{
}

void ParagraphDialog::OnCancelButtonClicked( wxCommandEvent& event )
{
    this->Hide();
}
