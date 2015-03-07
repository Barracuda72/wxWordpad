/***************************************************************
 * Name:      WordpadMain.h
 * Purpose:   Defines Application Frame
 * Author:    Barracuda72 (barracuda72@bk.ru)
 * Created:   2015-02-14
 * Copyright: Barracuda72 (http://lleo.aha.ru/na)
 * License:
 **************************************************************/

#ifndef WORDPADMAIN_H
#define WORDPADMAIN_H



#include "WordpadApp.h"

#include "GUIDialog.h"

class WordpadDialog: public GUIDialog
{
    public:
        WordpadDialog(wxDialog *dlg);
        ~WordpadDialog();
    private:
        virtual void OnClose(wxCloseEvent& event);
        void SetVisibility(wxWindow *control, wxCommandEvent &flag);
        virtual void OnRichTextChanged( wxCommandEvent& event );
        virtual void OnRichTextUpdated( wxUpdateUIEvent& event ); // HACK
        virtual void OnComboFontSelected( wxCommandEvent& event );
		virtual void OnComboFontSizeSelected( wxCommandEvent& event );
		virtual void OnRecentFileClicked( wxCommandEvent& event );

        void DoUpdateControls();
        bool KeepUnsaved();
        void SetFilename(wxString a);
        void ReadConfig();
        void WriteConfig();
        void FillRecentFiles();
        void AddFileToRecent(wxString & filename);
        void LoadFile(wxString & filename);

        void Dummy(wxString msg);

        void DoCreate();
        void DoSave();
        void DoSaveAs();
        void DoOpen();
        void DoPrint();
        void DoPreview();
        void DoClose();

        void DoUndo();
        void DoRedo();
        void DoCopy();
        void DoPaste();
        void DoCut();
        void DoSelectAll();
        void DoClear();
        void DoFind();
        void DoFindNext();
        void DoReplace();
        void DoDateTime();

        void DoBold();
        void DoItalic();
        void DoUnderline();
        void DoTextColor();
        void DoAlignCenter();
        void DoAlignLeft();
        void DoAlignRight();
        void DoList();

        void DoFormatMarker();
        void DoFormatFont();
        void DoFormatParagraph();

        void DoFontSelected();
        void DoFontSizeSelected();
        void ApplyFontAndSize();
        wxRichTextRange GetCurrentRange();
        void InitAuiToolbars();
        void MoveToAui(wxToolBar *old, wxAuiToolBar *n, int id);

        /// Toolbox
        virtual void OnToolCreate( wxCommandEvent& event );
		virtual void OnToolOpen( wxCommandEvent& event );
		virtual void OnToolSave( wxCommandEvent& event );
		virtual void OnToolPrint( wxCommandEvent& event );
		virtual void OnToolFind( wxCommandEvent& event );
		virtual void OnToolReplace( wxCommandEvent& event );
		virtual void OnToolCut( wxCommandEvent& event );
		virtual void OnToolCopy( wxCommandEvent& event );
		virtual void OnToolPaste( wxCommandEvent& event );
		virtual void OnToolUndo( wxCommandEvent& event );
		virtual void OnToolDateTime( wxCommandEvent& event );

		/// Format box
		virtual void OnFormatBold( wxCommandEvent& event );
		virtual void OnFormatItalic( wxCommandEvent& event );
		virtual void OnFormatUnderline( wxCommandEvent& event );
		virtual void OnFormatTextcolor( wxCommandEvent& event );
		virtual void OnFormatLeft( wxCommandEvent& event );
		virtual void OnFormatCenter( wxCommandEvent& event );
		virtual void OnFormatRight( wxCommandEvent& event );
		virtual void OnFormatList( wxCommandEvent& event );

        /// File
		virtual void OnFileCreate( wxCommandEvent& event );
		virtual void OnFileOpen( wxCommandEvent& event );
		virtual void OnFileSave( wxCommandEvent& event );
		virtual void OnFileSaveAs( wxCommandEvent& event );
		virtual void OnFilePrint( wxCommandEvent& event );
		virtual void OnFilePreview( wxCommandEvent& event );
		virtual void OnFileQuit( wxCommandEvent& event );

		/// Edit
		virtual void OnEditUndo( wxCommandEvent& event );
		virtual void OnEditRedo( wxCommandEvent& event );
		virtual void OnEditCut( wxCommandEvent& event );
		virtual void OnEditCopy( wxCommandEvent& event );
		virtual void OnEditPaste( wxCommandEvent& event );
		virtual void OnEditClear( wxCommandEvent& event );
		virtual void OnEditSelectAll( wxCommandEvent& event );
		virtual void OnEditSearch( wxCommandEvent& event );
		virtual void OnEditSearchNext( wxCommandEvent& event );
		virtual void OnEditReplace( wxCommandEvent& event );

		/// View
		virtual void OnToolPanelVisibility( wxCommandEvent& event );
		virtual void OnFormatPanelVisibility( wxCommandEvent& event );
		virtual void OnStatusBarVisibility( wxCommandEvent& event );

		/// Insert
		virtual void OnInsertDateTime( wxCommandEvent& event );

		/// Format
        virtual void OnFormatMarker( wxCommandEvent& event );
		virtual void OnFormatFont( wxCommandEvent& event );
		virtual void OnFormatParagraph( wxCommandEvent& event );

        /// Help
        virtual void OnAbout(wxCommandEvent& event);

        /// Buttons/menu items that need to be changed
        /*wxToolBarToolBase *tool_copy;
        wxToolBarToolBase *tool_cut;
        wxToolBarToolBase *tool_paste;*/
        wxAuiToolBarItem *tool_copy;
        wxAuiToolBarItem *tool_cut;
        wxAuiToolBarItem *tool_paste;

        wxToolBarToolBase *button_bold;

        wxMenuItem *menu_copy;
        wxMenuItem *menu_cut;
        wxMenuItem *menu_paste;

        bool alive;
        wxRichTextListStyleDefinition* defaultListStyle;
        wxFindReplaceData *fr_data;
        wxArrayString *as;
        wxAuiManager *m_mgr;
        wxAuiToolBar *m_toolBarAui;
        wxAuiToolBar *m_formatBarAui;
};
#endif // WORDPADMAIN_H
