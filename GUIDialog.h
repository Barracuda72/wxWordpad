///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 14 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIDialog__
#define __GUIDialog__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/toolbar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class GUIDialog
///////////////////////////////////////////////////////////////////////////////
class GUIDialog : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			ctID_DATETIME = 1000,
			ctID_CBFONT,
			ctID_CBFONTSIZE,
			ctID_CBENCODING,
			ctID_BOLD,
			ctID_ITALIC,
			ctID_UNDERLINE,
			ctID_TEXTCOLOR,
			ctID_LEFT,
			ctID_CENTER,
			ctID_RIGHT,
			ctID_LIST,
			ctID_FINDNEXT,
			ctID_TOOLPANEL,
			ctID_FORMATPANEL,
			ctID_STATUSBAR,
			ctID_MARKER,
			ctID_FONT,
			ctID_PARAGRAPH,
		};
		
		wxToolBar* m_toolBar;
		wxComboBox* m_combo_font;
		wxComboBox* m_combo_fontsize;
		wxComboBox* m_combo_style;
		wxToolBar* m_formatBar;
		wxRichTextCtrl* m_richText;
		wxMenuBar* m_menubar;
		wxMenu* m_File;
		wxMenu* m_Recent;
		wxMenu* m_Edit;
		wxMenu* m_View;
		wxMenu* m_Insert;
		wxMenu* m_Format;
		wxMenu* m_Help;
		wxStatusBar* m_statusBar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnToolCreate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolPrint( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolFind( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolReplace( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolCut( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolPaste( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolUndo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolDateTime( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnComboFontSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnComboFontSizeSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatBold( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatItalic( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatUnderline( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatTextcolor( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatLeft( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatCenter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatRight( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatList( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRichTextChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRichTextUpdated( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnFileCreate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileSaveAs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilePrint( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFilePreview( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFileQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditUndo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditRedo( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditCut( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditPaste( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditClear( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditSelectAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditSearchNext( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditReplace( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnToolPanelVisibility( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatPanelVisibility( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStatusBarVisibility( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInsertDateTime( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatMarker( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatFont( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormatParagraph( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Wordpad"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,400 ), long style = wxCAPTION|wxCLOSE_BOX|wxDIALOG_NO_PARENT|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU );
		~GUIDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class DateTimeGUI
///////////////////////////////////////////////////////////////////////////////
class DateTimeGUI : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxListBox* m_listBox1;
		wxButton* m_button_ok;
		wxButton* m_button_cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnListBoxDoubleClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DateTimeGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Дата и время"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 295,194 ), long style = wxDEFAULT_DIALOG_STYLE );
		~DateTimeGUI();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class FindGUI
///////////////////////////////////////////////////////////////////////////////
class FindGUI : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrl_find;
		wxCheckBox* m_checkBox_whole;
		wxCheckBox* m_checkBox_ignoreCase;
		wxButton* m_button_ok;
		wxButton* m_button_cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFindNextButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		FindGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Найти"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~FindGUI();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ReplaceGUI
///////////////////////////////////////////////////////////////////////////////
class ReplaceGUI : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textCtrl_find;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrl_replace;
		wxCheckBox* m_checkBox_whole;
		wxCheckBox* m_checkBox_ignoreCase;
		wxButton* m_button_ok;
		wxButton* m_button_replace;
		wxButton* m_button_replace_all;
		wxButton* m_button_cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFindNextButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReplaceButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReplaceAllButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ReplaceGUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Заменить"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~ReplaceGUI();
	
};

#endif //__GUIDialog__
