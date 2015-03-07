#include "ReplaceDialog.h"

ReplaceDialog::ReplaceDialog(wxDialog *dlg)
    : ReplaceGUI(dlg)
{
    //ctor
}

ReplaceDialog::~ReplaceDialog()
{
    //dtor
}

void ReplaceDialog::OnFindNextButtonClick( wxCommandEvent& event )
{
    int cur_pos = fr_data->GetFlags();
    fr_data->SetFindString(m_textCtrl_find->GetValue());
    fr_data->SetReplaceString(m_textCtrl_replace->GetValue());

    wxString content = fd->GetValue();
    cur_pos = content.find(m_textCtrl_find->GetValue(), cur_pos+1);
    fd->ScrollIntoView(cur_pos, WXK_PAGEDOWN);
    fd->SelectWord(cur_pos);

    fr_data->SetFlags(cur_pos);
}

void ReplaceDialog::OnReplaceButtonClick( wxCommandEvent& event )
{
    int cur_pos = fr_data->GetFlags();
    fr_data->SetFindString(m_textCtrl_find->GetValue());
    fr_data->SetReplaceString(m_textCtrl_replace->GetValue());

    cur_pos = fd->GetValue().find(fr_data->GetFindString(), cur_pos);
    if (cur_pos != -1)
    {
        //fd->Replace(cur_pos, cur_pos + fr_data->GetFindString().Length(), fr_data->GetReplaceString());
        fd->Remove(cur_pos, cur_pos + fr_data->GetFindString().Length());
        fd->SetInsertionPoint(cur_pos);
        fd->WriteText(fr_data->GetReplaceString());

        cur_pos = fd->GetValue().find(fr_data->GetFindString(), cur_pos+1);
        fd->ScrollIntoView(cur_pos, WXK_PAGEDOWN);
        fd->SelectWord(cur_pos);
    }

    fr_data->SetFlags(cur_pos);
}

void ReplaceDialog::OnReplaceAllButtonClick( wxCommandEvent& event )
{
    int cur_pos = fr_data->GetFlags();
    fr_data->SetFindString(m_textCtrl_find->GetValue());
    fr_data->SetReplaceString(m_textCtrl_replace->GetValue());

    while ((cur_pos = fd->GetValue().find(fr_data->GetFindString(), cur_pos)) != -1)
    {
        //fd->Replace(cur_pos, cur_pos + fr_data->GetFindString().Length(), fr_data->GetReplaceString());
        fd->Remove(cur_pos, cur_pos + fr_data->GetFindString().Length());
        fd->SetInsertionPoint(cur_pos);
        fd->WriteText(fr_data->GetReplaceString());
        //cur_pos = content.find(m_textCtrl_find->GetValue(), cur_pos+1);
        fd->SelectWord(cur_pos);
    }

    fr_data->SetFlags(cur_pos);
}

void ReplaceDialog::OnCancelButtonClick( wxCommandEvent& event )
{
    this->Hide();
}

void ReplaceDialog::SetFindData(wxRichTextCtrl * r, wxFindReplaceData *fr)
{
    fd = r;
    fr_data = fr;

    m_textCtrl_find->SetValue(fr_data->GetFindString());
    m_textCtrl_replace->SetValue(fr_data->GetReplaceString());
}
