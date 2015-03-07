#include "FindDialog.h"

FindDialog::FindDialog(wxDialog *dlg)
    : FindGUI(dlg)
{
    //ctor
}

FindDialog::~FindDialog()
{
    //dtor
}

void FindDialog::OnFindNextButtonClick( wxCommandEvent& event )
{
    int cur_pos = fr_data->GetFlags();
    fr_data->SetFindString(m_textCtrl_find->GetValue());

    wxString content = fd->GetValue();
    cur_pos = content.find(m_textCtrl_find->GetValue(), cur_pos+1);
    fd->ScrollIntoView(cur_pos, WXK_PAGEDOWN);
    fd->SelectWord(cur_pos);

    fr_data->SetFlags(cur_pos);
}

void FindDialog::OnCancelButtonClick( wxCommandEvent& event )
{
    this->Hide();
}

void FindDialog::SetFindData(wxRichTextCtrl * r, wxFindReplaceData *fr)
{
    fd = r;
    fr_data = fr;
    m_textCtrl_find->SetValue(fr_data->GetFindString());
}
