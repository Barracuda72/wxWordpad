/***************************************************************
 * Name:      WordpadMain.cpp
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

#include "WordpadMain.h"
#include "DateTimeDialog.h"
#include "FindDialog.h"
#include "ReplaceDialog.h"

#define FILE_MASK "XML files (*.xml)|*.xml"

//helper functions

enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

WordpadDialog::WordpadDialog(wxDialog *dlg)
    : GUIDialog(dlg)
{

    InitAuiToolbars();

    // Initialise pointers to objects
    /*tool_copy  = m_toolBar->FindById(wxID_COPY);
    tool_cut   = m_toolBar->FindById(wxID_CUT);
    tool_paste = m_toolBar->FindById(wxID_PASTE);*/

    tool_copy = m_toolBarAui->FindTool(wxID_COPY);
    tool_cut   = m_toolBarAui->FindTool(wxID_CUT);
    tool_paste = m_toolBarAui->FindTool(wxID_PASTE);

    menu_copy  = m_Edit->FindChildItem(wxID_COPY);
    menu_cut   = m_Edit->FindChildItem(wxID_CUT);
    menu_paste = m_Edit->FindChildItem(wxID_PASTE);

    button_bold = m_formatBar->FindById(ctID_BOLD);

    //wxBitmap bmp = tool_cut->GetBitmap();
    //tool_cut->SetDisabledBitmap(wxBitmap(bmp.ConvertToImage().ConvertToGreyscale()));

    // Disable controls
    alive = true;
    DoUpdateControls();

    // THIS!!!
    wxRichTextBuffer::AddHandler(new wxRichTextXMLHandler);
    // Update font names
    m_combo_font->Clear();
    m_combo_font->Append(m_richText->GetAvailableFontNames());
    int n = m_combo_font->GetStrings().Index(_("Ubuntu"));
    m_combo_font->SetSelection(n);

    SetFilename(_(""));

    // Add style for lists
    m_richText->SetStyleSheet(new wxRichTextStyleSheet());

    // First
    defaultListStyle = new wxRichTextListStyleDefinition(_("Квадрат"));
    defaultListStyle->SetAttributes(0, 60, 60, wxTEXT_ATTR_BULLET_STYLE_STANDARD, _("standard/square"));

    m_richText->GetStyleSheet()->AddListStyle(defaultListStyle);

    // Second
    defaultListStyle = new wxRichTextListStyleDefinition(_("Круг"));
    defaultListStyle->SetAttributes(0, 60, 60, wxTEXT_ATTR_BULLET_STYLE_STANDARD, _("standard/circle"));

    m_richText->GetStyleSheet()->AddListStyle(defaultListStyle);

    // Fill font size box with values
    int i;
    wxArrayString p;
    //p->Alloc((36-8)/2 + 1);

    for (i = 8; i < 36; i+=2)
    {
        p.Add(wxString() << i);
    }
    m_combo_fontsize->Clear();
    m_combo_fontsize->Append(p);
    m_combo_fontsize->SetSelection(1);

    ApplyFontAndSize();

    m_richText->SetModified(false);

    // Find & Replace data
    fr_data = new wxFindReplaceData(-1);
    fr_data->SetFindString(_(""));
    fr_data->SetReplaceString(_(""));

    as = new wxArrayString;

    ReadConfig();
    FillRecentFiles();
}

void WordpadDialog::ReadConfig()
{
    wxFileConfig *config = new wxFileConfig(_("wordpad"), _("none"), _("wordpad.config"));

    // Recent files
    as->Clear();

    int i;
    wxString key;
    wxString value;

    for (i = 1; i < 6; i++)
    {
        key = wxString::FromUTF8("File") << i;

        if (config->HasEntry(key))
        {
            config->Read(key, &value);
            as->Add(value);
        } else
            break;
    }

    // Panels
#if 0
    int x, y;

    //config->Read(_("ToolbarUndocked"), &toolbar_dock, false);
    //config->Read(_("FormatbarUndocked"), &format_dock, false);

   // if (toolbar_dock)
    //{
        //m_toolBarDetached = toolbar_dock;
        config->Read(_("ToolbarXPos"), &x);
        config->Read(_("ToolbarYPos"), &y);
        m_toolBarAui->SetPosition(wxPoint(100, 200));
        //m_mgr->GetPane(m_toolBarAui).Float().FloatingPosition(100, 200);
        //m_toolBar->SetPosition(wxPoint(x, y));
    //}

    //if (format_dock)
    //{
     //   m_toolBarDetached = format_dock;
        config->Read(_("FormatbarXPos"), &x);
        config->Read(_("FormatbarYPos"), &y);
        m_formatBarAui->SetPosition(wxPoint(300,400));
        //m_mgr->GetPane(m_formatBarAui).Float().FloatingPosition(300, 400);
       // m_formatBar->SetPosition(wxPoint(x, y));
    //}
#endif
    wxString persp;

    config->Read(_("Perspective"), &persp, _(""));
 //   std::cout << persp.ToUTF8().data() << std::endl;
    if (!persp.IsEmpty())
        m_mgr->LoadPerspective(persp);

    delete config;

    m_toolBarAui->Show();
    m_formatBarAui->Show();
}

void WordpadDialog::FillRecentFiles()
{
    int i;
    for (i = 1; i < 6; i++)
        m_Recent->Remove(wxID_FILE+i);

    if (as->GetCount() == 0)
        (m_Recent->Append(wxID_FILE1, _("Пусто"))) -> Enable(false);
    else
        for (i = 1; i <= as->GetCount(); i++)
        {
            m_Recent->Append(wxID_FILE+i, as->Item(i-1));;
            this->Connect(wxID_FILE+i, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(WordpadDialog::OnRecentFileClicked));
        }
}

void WordpadDialog::WriteConfig()
{
    // Files

    wxFileConfig *config = new wxFileConfig(_("wordpad"), _("none"), _("wordpad.config"));

    int i;
    wxString key;

    for (i = 1; i <= as->GetCount(); i++)
    {
        key = wxString::FromUTF8("File") << i;

        config->Write(key, as->Item(i-1));
    }

    // Panels
#if 0
    //bool toolbar_dock = m_toolBarDetached;
    //bool format_dock = m_toolBarDetached; // HACK
    int x, y;

    //config->Write(_("ToolbarUndocked"), toolbar_dock);
    //config->Write(_("FormatbarUndocked"), format_dock);

    //if (toolbar_dock)
    //{
        m_toolBarAui->GetPosition(&x, &y);
        config->Write(_("ToolbarXPos"), x);
        config->Write(_("ToolbarYPos"), y);
    //}

    //if (format_dock)
    //{
        m_formatBarAui->GetPosition(&x, &y);
        config->Write(_("FormatbarXPos"), x);
        config->Write(_("FormatbarYPos"), y);
    //}
#endif
    config->Write(_("Perspective"), m_mgr->SavePerspective());

    config->Flush();
    delete config;
}

void WordpadDialog::AddFileToRecent(wxString & filename)
{
    int n = as->Index(filename);

    if (n == wxNOT_FOUND)
    {
        as->RemoveAt(4);
        as->Insert(filename, 0);
    } else if (n != 0){
        as->RemoveAt(n);
        as->Insert(filename, 0);
    }

    FillRecentFiles();
}

void WordpadDialog::OnRecentFileClicked( wxCommandEvent& event )
{
    int i = event.GetId() - wxID_FILE;
    //Dummy(wxString::FromUTF8("OnRecent") << i);
    wxString file = as->Item(i-1);
    LoadFile(file);
}

WordpadDialog::~WordpadDialog()
{
}

void WordpadDialog::OnClose(wxCloseEvent &event)
{
    DoClose();
}

// Helper function
void WordpadDialog::MoveToAui(wxToolBar *old, wxAuiToolBar *n, int id)
{
    wxToolBarToolBase *t = old->FindById(id);
    n->AddTool(t->GetId(), t->GetLabel(), t->GetBitmap(), t->GetShortHelp(), t->GetKind());
    old->DeleteTool(id);
    /*n->AddControl(t);
    old->RemoveTool(id);*/
}

void WordpadDialog::InitAuiToolbars()
{
    // Create wxAUI manager
    m_mgr = new wxAuiManager(this, wxAUI_MGR_ALLOW_FLOATING);

    // Create new Toolbar and duplicate all tools
    m_toolBarAui = new wxAuiToolBar(this, -1, m_toolBar->GetPosition(), m_toolBar->GetSize());
    m_toolBarAui->Hide();
    m_toolBarAui->SetName(_("Toolbar"));

    MoveToAui(m_toolBar, m_toolBarAui, wxID_NEW);
    MoveToAui(m_toolBar, m_toolBarAui, wxID_OPEN);
    MoveToAui(m_toolBar, m_toolBarAui, wxID_SAVE);
    MoveToAui(m_toolBar, m_toolBarAui, wxID_PRINT);
    MoveToAui(m_toolBar, m_toolBarAui, wxID_FIND);
    MoveToAui(m_toolBar, m_toolBarAui, wxID_REPLACE);
    MoveToAui(m_toolBar, m_toolBarAui, wxID_CUT);
    MoveToAui(m_toolBar, m_toolBarAui, wxID_COPY);
    MoveToAui(m_toolBar, m_toolBarAui, wxID_PASTE);
    MoveToAui(m_toolBar, m_toolBarAui, wxID_UNDO);
    MoveToAui(m_toolBar, m_toolBarAui, ctID_DATETIME);

    // Format bar

    m_formatBarAui = new wxAuiToolBar(this, -1, m_formatBar->GetPosition(), m_formatBar->GetSize());
    m_formatBarAui->Hide();
    m_formatBarAui->SetName(_("FormatBar"));

    //wxControl *t;
    //t = m_formatBar->FindControl(ctID_CBFONT);
    /*m_formatBar->RemoveChild(m_combo_font);
    m_formatBarAui->AddControl(m_combo_font);

    //t = m_formatBar->FindControl(ctID_CBFONTSIZE);
    m_formatBar->RemoveChild(m_combo_fontsize);
    m_formatBarAui->AddControl(m_combo_fontsize);

    //t = m_formatBar->FindControl(ctID_CBENCODING);
    m_formatBar->RemoveChild(m_combo_style);
    m_formatBarAui->AddControl(m_combo_style);*/
    //this->RemoveChild(m_panel_font);

    MoveToAui(m_formatBar, m_formatBarAui, ctID_BOLD);
    MoveToAui(m_formatBar, m_formatBarAui, ctID_ITALIC);
    MoveToAui(m_formatBar, m_formatBarAui, ctID_UNDERLINE);
    MoveToAui(m_formatBar, m_formatBarAui, ctID_TEXTCOLOR);
    MoveToAui(m_formatBar, m_formatBarAui, ctID_LEFT);
    MoveToAui(m_formatBar, m_formatBarAui, ctID_CENTER);
    MoveToAui(m_formatBar, m_formatBarAui, ctID_RIGHT);
    MoveToAui(m_formatBar, m_formatBarAui, ctID_LIST);

    m_mgr->AddPane(m_toolBarAui, wxAuiPaneInfo().ToolbarPane().Left().Name(_("PaneTool")).Floatable(true).Dockable(true).Float()/**/);
    m_mgr->AddPane(m_formatBarAui, wxAuiPaneInfo().ToolbarPane().Right().Name(_("PaneFormat")).Floatable(true).Dockable(true).Float()/**/);
    //m_mgr->AddPane(m_panel_font, wxAuiPaneInfo().DefaultPane());

    m_toolBar->Hide();
    m_formatBar->Hide();

    /*m_toolBar->Destroy();
    m_formatBar->Destroy();*/
    // tell the manager to "commit" all the changes just made
    m_mgr->Update();

    /*m_mgr->GetPane(m_toolBarAui).Float();
    m_mgr->GetPane(m_formatBarAui).Float();*/
}

/**
  * Generic actions
  */

/// Cleaning up on application exit
void WordpadDialog::DoClose()
{
    if (KeepUnsaved())
        return;
    alive = false;
    WriteConfig();
    Destroy();
}

/// Clear RichTextBox
void WordpadDialog::DoClear()
{
    m_richText->MoveHome(); // Reset caret position
    m_richText->Clear(); // Clear field
}

/// Update buttons and other things
void WordpadDialog::DoUpdateControls()
{
    if (alive)
    {
        //std::cout << m_mgr->SavePerspective().ToUTF8().data() << endl;
        bool selection  = m_richText->HasSelection();

        bool copy_avail  = m_richText->CanCopy() && selection;
        bool cut_avail   = m_richText->CanCut()  && selection;
        bool paste_avail = m_richText->CanPaste();

       /* tool_copy ->Enable(copy_avail);
        tool_cut  ->Enable(cut_avail);
        tool_paste->Enable(paste_avail);*/
        tool_copy ->SetActive(copy_avail);
        tool_cut  ->SetActive(cut_avail);
        tool_paste->SetActive(paste_avail);

        menu_copy ->Enable(copy_avail);
        menu_cut  ->Enable(cut_avail);
        //menu_paste->Enable(paste_avail);


        //button_bold->SetToggle(!m_richText->IsSelectionBold());
        //button_bold->SetToggle(!m_richText->IsSelectionBold());

        wxRichTextAttr style;
        m_richText->GetStyleForRange(GetCurrentRange(), style);

        wxString fname = style.GetFontFaceName();
        wxString fsize = wxString(_("")) << style.GetFontSize();

        //std::cout << fname.ToUTF8().data() << "-" << fsize.ToUTF8().data() << std::endl;

        int fi = m_combo_font->GetStrings().Index(fname);
        int si = m_combo_fontsize->GetStrings().Index(fsize);

        m_combo_font->SetSelection(fi);
        m_combo_fontsize->SetSelection(si);
#if 0
        std::cout << "Selection " << m_richText->HasSelection() <<
                 ", Bold " << m_richText->IsSelectionBold() <<
                 ", Toggle " << button_bold->IsToggled() << std::endl;
#endif

        // std::cout << "Copy available: " << copy_avail << std::endl;
    }
}

void WordpadDialog::ApplyFontAndSize()
{
    wxRichTextCharacterStyleDefinition *def;

    wxString fname = m_combo_font->GetStringSelection();
    wxString fsize = m_combo_fontsize->GetStringSelection();

    //wxString sname = fname<<_("-")<<fsize;

    // First, try to find existing style
    def = m_richText->GetStyleSheet()->FindCharacterStyle(fname);

    if (def == NULL)
    {
        // Style doesn't exist, add it
        def = new wxRichTextCharacterStyleDefinition(fname);

        wxRichTextAttr attr;
        attr.SetFontFaceName(fname);

        unsigned long sz = 0;
        fsize.ToULong(&sz);

        attr.SetFontSize(sz);

        attr.SetFlags(wxTEXT_ATTR_FONT_FACE);
        def->SetStyle(attr);

        m_richText->GetStyleSheet()->AddCharacterStyle(def);
    }
/*
    m_richText->ApplyStyle(def);
    m_richText->*/
    int pages = wxRICHTEXT_FORMAT_FONT;
    wxRichTextFormattingDialog formatDlg(pages, this);

    formatDlg.SetStyle(def->GetStyle());

    formatDlg.ApplyStyle(m_richText, GetCurrentRange(),
            wxRICHTEXT_SETSTYLE_WITH_UNDO/*|wxRICHTEXT_SETSTYLE_OPTIMIZE|wxRICHTEXT_SETSTYLE_CHARACTERS_ONLY*/);
}

void WordpadDialog::SetFilename(wxString a)
{
    if (!a.IsEmpty())
    {
        AddFileToRecent(a);
        this->SetTitle(a << _(" - Wordpad"));
    }
    else
        this->SetTitle(_("Wordpad"));

    m_richText->SetFilename(a);
}

bool WordpadDialog::KeepUnsaved()
{
    return m_richText->IsModified() &&
            (wxMessageBox(_("Документ не сохранен, продолжить?"), _("Подтвердите"),
            wxICON_QUESTION | wxYES_NO, this) == wxNO);
}

/// Handle 'Rich text updated' event
void WordpadDialog::OnRichTextUpdated( wxUpdateUIEvent& event )
{
    DoUpdateControls();
}

/// Handle 'text changed' event
void WordpadDialog::OnRichTextChanged( wxCommandEvent& event )
{
    DoUpdateControls();
}

void WordpadDialog::Dummy(wxString msg = _("none"))
{
    wxMessageBox(wxString::FromUTF8("Dummy: ") << msg);
}

void WordpadDialog::DoOpen()
{
    if (KeepUnsaved())
        return;

    wxFileDialog openFileDialog(this, _("Открыть файл XML"), _(""), _(""),
            _(FILE_MASK), wxFD_OPEN|wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    SetFilename(openFileDialog.GetPath());

    m_richText->LoadFile(openFileDialog.GetPath(), wxRICHTEXT_TYPE_XML);

    // std::cout << "Open: " << openFileDialog.GetPath().ToUTF8().data() << std::endl;
}

void WordpadDialog::LoadFile(wxString & file)
{
    if (KeepUnsaved())
        return;

    SetFilename(file);

    m_richText->LoadFile(file, wxRICHTEXT_TYPE_XML);
}

void WordpadDialog::DoSave()
{
    if (m_richText->IsModified())
    {
        if (m_richText->GetFilename().IsEmpty())
        {
            DoSaveAs();
        } else {
            m_richText->SaveFile(m_richText->GetFilename(), wxRICHTEXT_TYPE_XML);
            m_richText->SetModified(false);
        }
    }
    //Dummy(_("Save"));
}

void WordpadDialog::DoSaveAs()
{
    wxFileDialog saveFileDialog(this, _("Сохранить файл XML"), _(""), _(""),
                    _(FILE_MASK), wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() != wxID_CANCEL)
    {
        wxString fname = saveFileDialog.GetPath();

        if (!fname.EndsWith(_(".xml")))
            fname << _(".xml");

        SetFilename(fname);
        m_richText->SaveFile(fname, wxRICHTEXT_TYPE_XML);
        m_richText->SetModified(false);
    }

    //Dummy(_("SaveAs"));
}

void WordpadDialog::DoCreate()
{
    if (KeepUnsaved())
        return;
    DoClear();
    SetFilename(_(""));
    m_richText->SetModified(false);
    // Dummy(_("Create"));
}

void WordpadDialog::DoUndo()
{
    m_richText->Undo();
}

void WordpadDialog::DoRedo()
{
    m_richText->Redo();
}

void WordpadDialog::DoCut()
{
    m_richText->Cut();
}

void WordpadDialog::DoCopy()
{
    m_richText->Copy();
}

void WordpadDialog::DoPaste()
{
    m_richText->Paste();
}

void WordpadDialog::DoSelectAll()
{
    m_richText->SelectAll();
}

void WordpadDialog::DoFind()
{
    FindDialog fd(0L);
    fd.SetFindData(m_richText, fr_data);
    fd.ShowModal();
    //Dummy(_("Find"));
}

void WordpadDialog::DoFindNext()
{
    //Dummy(_("FindNext"));
    int cur_pos = fr_data->GetFlags();

    wxString content = m_richText->GetValue();
    cur_pos = content.find(fr_data->GetFindString(), cur_pos+1);
    m_richText->ScrollIntoView(cur_pos, WXK_PAGEDOWN);
    m_richText->SelectWord(cur_pos);

    fr_data->SetFlags(cur_pos);
}

void WordpadDialog::DoReplace()
{
    ReplaceDialog rd(0L);
    rd.SetFindData(m_richText, fr_data);
    rd.ShowModal();
    //Dummy(_("Replace"));
}

void WordpadDialog::DoDateTime()
{
    DateTimeDialog *d = new DateTimeDialog(0L);
    d->ShowModal();

    if (d->IsPicked())
        m_richText->WriteText(d->GetPicked());
    delete d;
}

/**
  * Format
  */

void WordpadDialog::DoBold()
{
    m_richText->ApplyBoldToSelection();
    //Dummy(_("Bold"));
}

void WordpadDialog::DoItalic()
{
    m_richText->ApplyItalicToSelection();
    //Dummy(_("Italic"));
}

void WordpadDialog::DoUnderline()
{
    m_richText->ApplyUnderlineToSelection();
    //Dummy(_("Underline"));
}

void WordpadDialog::DoTextColor()
{
    wxColourDialog c_dialog(this);
    if(c_dialog.ShowModal() != wxID_CANCEL)
    {
        m_richText->BeginTextColour(c_dialog.GetColourData().GetColour());
    }
    //Dummy(_("TextColor"));
}

void WordpadDialog::DoAlignCenter()
{
    m_richText->ApplyAlignmentToSelection(wxTEXT_ALIGNMENT_CENTER);
    //Dummy(_("Center"));
}

void WordpadDialog::DoAlignLeft()
{
    m_richText->ApplyAlignmentToSelection(wxTEXT_ALIGNMENT_LEFT);
    //Dummy(_("Left"));
}

void WordpadDialog::DoAlignRight()
{
    m_richText->ApplyAlignmentToSelection(wxTEXT_ALIGNMENT_RIGHT);
    //Dummy(_("Right"));
}

wxRichTextRange WordpadDialog::GetCurrentRange()
{
    wxRichTextRange range;

#if 1
    if (!m_richText->HasSelection())
    {
        int n = m_richText->GetInsertionPoint();
        range = wxRichTextRange(n-1, n);
    } else
        range = m_richText->GetSelectionRange();
#else
    if (m_richText->HasSelection())
        range = m_richText->GetSelectionRange();
    else
        range = wxRichTextRange(0, m_richText->GetLastPosition()+1);
#endif

    return range;
}

// Hack
void WordpadDialog::DoList()
{
    m_richText->PromoteList(1, GetCurrentRange(), defaultListStyle);
    //Dummy(_("List"));
}

void WordpadDialog::DoFormatFont()
{
    wxRichTextRange range = GetCurrentRange();

    int pages = wxRICHTEXT_FORMAT_FONT;

    wxRichTextFormattingDialog formatDlg(pages, this);

    formatDlg.GetStyle(m_richText, range);

    if (formatDlg.ShowModal() == wxID_OK)
    {
        formatDlg.ApplyStyle(m_richText, range,
            wxRICHTEXT_SETSTYLE_WITH_UNDO|wxRICHTEXT_SETSTYLE_OPTIMIZE|wxRICHTEXT_SETSTYLE_CHARACTERS_ONLY);
    }
    //Dummy(_("Format font"));
}

void WordpadDialog::DoFormatMarker()
{
    wxRichTextStyleSheet* sheet = m_richText->GetStyleSheet();
    int flags = wxRICHTEXT_ORGANISER_BROWSE_NUMBERING;
    wxRichTextStyleOrganiserDialog dlg(flags, sheet, m_richText, this, wxID_ANY, _("Маркеры и списки"));

    if (dlg.ShowModal() == wxID_OK)
    {
        if (dlg.GetSelectedStyleDefinition())
        {
            defaultListStyle = (wxRichTextListStyleDefinition *)dlg.GetSelectedStyleDefinition();
            dlg.ApplyStyle();
        }
    }
}

void WordpadDialog::DoFormatParagraph()
{
 /*   ParagraphDialog *pd = new ParagraphDialog(0L);
    pd->ShowModal();
    //Dummy(_("Format paragraph"));
    delete pd;*/
    int pages = wxRICHTEXT_FORMAT_INDENTS_SPACING;
    wxRichTextRange range = GetCurrentRange();

    wxRichTextFormattingDialog formatDlg(pages, this);
    formatDlg.GetStyle(m_richText, range);

    if (formatDlg.ShowModal() == wxID_OK)
    {
        formatDlg.ApplyStyle(m_richText, range);
    }
}

void WordpadDialog::DoFontSelected()
{
    //Dummy(_("Font selected"));
    ApplyFontAndSize();
}

void WordpadDialog::DoFontSizeSelected()
{
    //Dummy(_("Font size selected"));
    ApplyFontAndSize();
}

/*
void WordpadDialog::DoOpen()
{
    Dummy();
}
*/
/// Sets control visibility based on checkbox state
void WordpadDialog::SetVisibility(wxWindow *control, wxCommandEvent &flag)
{
    if (flag.IsChecked())
    {
        control->Show();
        control->GetParent()->SetSize(control->GetParent()->GetBestSize());
    } else {
        control->Hide();
        control->GetParent()->SetSize(0, 0);
    }
}

/// Opens 'Print' dialog
void WordpadDialog::DoPrint()
{
    wxRichTextPrinting *p = new wxRichTextPrinting();
    p->SetTitle(_("Печать"));
    p->PrintBuffer(this->m_richText->GetBuffer());
    delete p;
}

/// Opens 'Preview' dialog
void WordpadDialog::DoPreview()
{
    wxRichTextPrinting *p = new wxRichTextPrinting();
    p->SetTitle(_("Предварительный просмотр"));
    p->PreviewBuffer(this->m_richText->GetBuffer());
    delete p;
}

/**
  * Comboboxes
  */
void WordpadDialog::OnComboFontSelected( wxCommandEvent& event )
{
    DoFontSelected();
}

void WordpadDialog::OnComboFontSizeSelected( wxCommandEvent& event )
{
    DoFontSizeSelected();
}

/**
  * Toolbox
  */

/// Create
void WordpadDialog::OnToolCreate( wxCommandEvent& event )
{
    DoCreate();
}

/// Open
void WordpadDialog::OnToolOpen( wxCommandEvent& event )
{
    DoOpen();
}

/// Save
void WordpadDialog::OnToolSave( wxCommandEvent& event )
{
    DoSave();
}

/// Print
void WordpadDialog::OnToolPrint( wxCommandEvent& event )
{
    DoPrint();
}

/// Find
void WordpadDialog::OnToolFind( wxCommandEvent& event )
{
    DoFind();
}

/// Replace
void WordpadDialog::OnToolReplace( wxCommandEvent& event )
{
    DoReplace();
}

/// Cut
void WordpadDialog::OnToolCut( wxCommandEvent& event )
{
    DoCut();
}

/// Copy
void WordpadDialog::OnToolCopy( wxCommandEvent& event )
{
    DoCopy();
}

/// Paste
void WordpadDialog::OnToolPaste( wxCommandEvent& event )
{
    DoPaste();
}

/// Undo
void WordpadDialog::OnToolUndo( wxCommandEvent& event )
{
    DoUndo();
}

/// Insert Date/Time
void WordpadDialog::OnToolDateTime( wxCommandEvent& event )
{
    DoDateTime();
}

/**
  * Format box
  */

/// Bold
void WordpadDialog::OnFormatBold( wxCommandEvent& event )
{
    DoBold();
}

/// Italic
void WordpadDialog::OnFormatItalic( wxCommandEvent& event )
{
    DoItalic();
}

/// Underline
void WordpadDialog::OnFormatUnderline( wxCommandEvent& event )
{
    DoUnderline();
}

/// Change text color
void WordpadDialog::OnFormatTextcolor( wxCommandEvent& event )
{
    DoTextColor();
}

/// Justify left
void WordpadDialog::OnFormatLeft( wxCommandEvent& event )
{
    DoAlignLeft();
}

/// Justify center
void WordpadDialog::OnFormatCenter( wxCommandEvent& event )
{
    DoAlignCenter();
}

/// Justify right
void WordpadDialog::OnFormatRight( wxCommandEvent& event )
{
    DoAlignRight();
}

/// Insert list
void WordpadDialog::OnFormatList( wxCommandEvent& event )
{
    DoList();
}

/**
  * Menu functions
  */

/**
  * File
  */

/// Create
void WordpadDialog::OnFileCreate( wxCommandEvent& event )
{
    DoCreate();
}

/// Open
void WordpadDialog::OnFileOpen( wxCommandEvent& event )
{
    DoOpen();
}

/// Save
void WordpadDialog::OnFileSave( wxCommandEvent& event )
{
    DoSave();
}

/// Save as
void WordpadDialog::OnFileSaveAs( wxCommandEvent& event )
{
    DoSaveAs();
}

/// Print
void WordpadDialog::OnFilePrint( wxCommandEvent& event )
{
    DoPrint();
}

/// Print preview
void WordpadDialog::OnFilePreview( wxCommandEvent& event )
{
    DoPreview();
}

/// Quit
void WordpadDialog::OnFileQuit(wxCommandEvent &event)
{
    DoClose();
}

/**
  * Edit
  */

/// Undo
void WordpadDialog::OnEditUndo( wxCommandEvent& event )
{
    DoUndo();
}

/// Redo
void WordpadDialog::OnEditRedo( wxCommandEvent& event )
{
    DoRedo();
}

/// Cut
void WordpadDialog::OnEditCut( wxCommandEvent& event )
{
    DoCut();
}

/// Copy
void WordpadDialog::OnEditCopy( wxCommandEvent& event )
{
    DoCopy();
}

/// Paste
void WordpadDialog::OnEditPaste( wxCommandEvent& event )
{
    DoPaste();
}

/// Clear
void WordpadDialog::OnEditClear(wxCommandEvent &event)
{
    DoClear();
}

void WordpadDialog::OnEditSelectAll( wxCommandEvent& event )
{
    DoSelectAll();
}

/// Search
void WordpadDialog::OnEditSearch( wxCommandEvent& event )
{
    DoFind();
}

/// Search next
void WordpadDialog::OnEditSearchNext( wxCommandEvent& event )
{
    DoFindNext();
}

/// Replace
void WordpadDialog::OnEditReplace( wxCommandEvent& event )
{
    DoReplace();
}

/**
  * View
  */

/// Tools panel
void WordpadDialog::OnToolPanelVisibility( wxCommandEvent& event )
{
    SetVisibility(m_toolBarAui, event);
}

/// Format panel
void WordpadDialog::OnFormatPanelVisibility( wxCommandEvent& event )
{
    SetVisibility(m_formatBarAui, event);
}

/// Status bar
void WordpadDialog::OnStatusBarVisibility( wxCommandEvent& event )
{
    SetVisibility(m_statusBar, event);
}

/**
  * Insert
  */

/// Insert Date/Time
void WordpadDialog::OnInsertDateTime( wxCommandEvent& event )
{
    DoDateTime();
}

/**
  * Format
  */
/// Marker
void WordpadDialog::OnFormatMarker( wxCommandEvent& event )
{
    DoFormatMarker();
}

/// Font
void WordpadDialog::OnFormatFont( wxCommandEvent& event )
{
    DoFormatFont();
}

/// Paragraph
void WordpadDialog::OnFormatParagraph( wxCommandEvent& event )
{
    DoFormatParagraph();
}

/**
  * Help
  */
/// About
void WordpadDialog::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);

    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName(_("wxWordpad"));
    aboutInfo.SetVersion(_("v1.0 Beta"));
    aboutInfo.SetDescription(wxString::FromUTF8("My wxWidgets-based wordpad clone\nPowered by ") << msg);
    aboutInfo.SetCopyright(_("(C) 2015"));
    aboutInfo.SetWebSite(_("http://github.com/Barracuda72/wxWordpad"));
    aboutInfo.AddDeveloper(_("Barracuda72 <barracuda72@bk.ru>"));
    wxAboutBox(aboutInfo);
}
