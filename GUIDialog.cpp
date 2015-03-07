///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 14 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIDialog.h"

#include "res/document_new.xpm"
#include "res/document_open.xpm"
#include "res/document_print.xpm"
#include "res/document_save.xpm"
#include "res/edit_copy.xpm"
#include "res/edit_cut.xpm"
#include "res/edit_find.xpm"
#include "res/edit_find_replace.xpm"
#include "res/edit_paste.xpm"
#include "res/edit_undo_ltr.xpm"
#include "res/format_justify_center.xpm"
#include "res/format_justify_left.xpm"
#include "res/format_justify_right.xpm"
#include "res/format_text_bold.xpm"
#include "res/format_text_color.xpm"
#include "res/format_text_italic.xpm"
#include "res/format_text_underline.xpm"
#include "res/list.xpm"
#include "res/tdateedit.xpm"

///////////////////////////////////////////////////////////////////////////

GUIDialog::GUIDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 800,400 ), wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_toolBar = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_DOCKABLE|wxTB_HORIZONTAL ); 
	m_toolBar->AddTool( wxID_NEW, wxT("tool"), wxBitmap( document_new_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( wxID_OPEN, wxT("tool"), wxBitmap( document_open_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( wxID_SAVE, wxT("tool"), wxBitmap( document_save_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( wxID_PRINT, wxT("tool"), wxBitmap( document_print_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( wxID_FIND, wxT("tool"), wxBitmap( edit_find_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( wxID_REPLACE, wxT("tool"), wxBitmap( edit_find_replace_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( wxID_CUT, wxT("tool"), wxBitmap( edit_cut_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( wxID_COPY, wxT("tool"), wxBitmap( edit_copy_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( wxID_PASTE, wxT("tool"), wxBitmap( edit_paste_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( wxID_UNDO, wxT("tool"), wxBitmap( edit_undo_ltr_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->AddTool( ctID_DATETIME, wxT("tool"), wxBitmap( tdateedit_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_toolBar->Realize();
	
	bSizer3->Add( m_toolBar, 0, 0, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	m_combo_font = new wxComboBox( this, ctID_CBFONT, wxT("Arial"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	bSizer32->Add( m_combo_font, 0, wxALL, 5 );
	
	m_combo_fontsize = new wxComboBox( this, ctID_CBFONTSIZE, wxT("10"), wxDefaultPosition, wxSize( 60,-1 ), 0, NULL, wxCB_READONLY ); 
	bSizer32->Add( m_combo_fontsize, 0, wxALL, 5 );
	
	m_combo_style = new wxComboBox( this, ctID_CBENCODING, wxT("Юникод (UTF-8)"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY ); 
	bSizer32->Add( m_combo_style, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer32, 1, wxEXPAND, 5 );
	
	m_formatBar = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_DOCKABLE|wxTB_HORIZONTAL ); 
	m_formatBar->AddTool( ctID_BOLD, wxT("tool"), wxBitmap( format_text_bold_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_formatBar->AddTool( ctID_ITALIC, wxT("tool"), wxBitmap( format_text_italic_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_formatBar->AddTool( ctID_UNDERLINE, wxT("tool"), wxBitmap( format_text_underline_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_formatBar->AddTool( ctID_TEXTCOLOR, wxT("tool"), wxBitmap( format_text_color_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_formatBar->AddTool( ctID_LEFT, wxT("tool"), wxBitmap( format_justify_left_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_formatBar->AddTool( ctID_CENTER, wxT("tool"), wxBitmap( format_justify_center_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_formatBar->AddTool( ctID_RIGHT, wxT("tool"), wxBitmap( format_justify_right_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_formatBar->AddTool( ctID_LIST, wxT("tool"), wxBitmap( list_xpm ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString ); 
	m_formatBar->Realize();
	
	bSizer4->Add( m_formatBar, 0, wxEXPAND, 5 );
	
	bSizer3->Add( bSizer4, 0, wxSHAPED, 5 );
	
	m_richText = new wxRichTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	bSizer3->Add( m_richText, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer3 );
	this->Layout();
	m_menubar = new wxMenuBar( 0 );
	m_File = new wxMenu();
	wxMenuItem* m_Create;
	m_Create = new wxMenuItem( m_File, wxID_NEW, wxString( wxT("Созд&ать") ) + wxT('\t') + wxT("CTRL+N"), wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_Create );
	
	wxMenuItem* m_Open;
	m_Open = new wxMenuItem( m_File, wxID_OPEN, wxString( wxT("&Открыть") ) + wxT('\t') + wxT("CTRL+O"), wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_Open );
	
	wxMenuItem* m_Save;
	m_Save = new wxMenuItem( m_File, wxID_SAVE, wxString( wxT("&Сохранить") ) + wxT('\t') + wxT("CTRL+S"), wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_Save );
	
	wxMenuItem* m_SaveAs;
	m_SaveAs = new wxMenuItem( m_File, wxID_SAVEAS, wxString( wxT("Сохранить &как...") ) , wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_SaveAs );
	
	wxMenuItem* m_separator1;
	m_separator1 = m_File->AppendSeparator();
	
	wxMenuItem* m_Print;
	m_Print = new wxMenuItem( m_File, wxID_PRINT, wxString( wxT("&Печать") ) + wxT('\t') + wxT("CTRL+P"), wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_Print );
	
	wxMenuItem* m_PrintPreview;
	m_PrintPreview = new wxMenuItem( m_File, wxID_PREVIEW, wxString( wxT("Пред&варительный просмотр") ) , wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_PrintPreview );
	
	m_Recent = new wxMenu();
	m_File->Append( -1, wxT("Последние"), m_Recent );
	
	wxMenuItem* m_separator2;
	m_separator2 = m_File->AppendSeparator();
	
	wxMenuItem* m_Exit;
	m_Exit = new wxMenuItem( m_File, wxID_EXIT, wxString( wxT("В&ыход") ) , wxEmptyString, wxITEM_NORMAL );
	m_File->Append( m_Exit );
	
	m_menubar->Append( m_File, wxT("&Файл") ); 
	
	m_Edit = new wxMenu();
	wxMenuItem* m_Undo;
	m_Undo = new wxMenuItem( m_Edit, wxID_UNDO, wxString( wxT("&Отменить") ) + wxT('\t') + wxT("CTRL+Z"), wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_Undo );
	
	wxMenuItem* m_Redo;
	m_Redo = new wxMenuItem( m_Edit, wxID_REDO, wxString( wxT("&Повторить") ) + wxT('\t') + wxT("CTRL+Y"), wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_Redo );
	
	wxMenuItem* m_separator3;
	m_separator3 = m_Edit->AppendSeparator();
	
	wxMenuItem* m_Cut;
	m_Cut = new wxMenuItem( m_Edit, wxID_CUT, wxString( wxT("&Вырезать") ) + wxT('\t') + wxT("CTRL+X"), wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_Cut );
	
	wxMenuItem* m_Copy;
	m_Copy = new wxMenuItem( m_Edit, wxID_COPY, wxString( wxT("&Копировать") ) + wxT('\t') + wxT("CTRL+C"), wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_Copy );
	
	wxMenuItem* m_Paste;
	m_Paste = new wxMenuItem( m_Edit, wxID_PASTE, wxString( wxT("Вст&авить") ) + wxT('\t') + wxT("CTRL+V"), wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_Paste );
	
	wxMenuItem* m_Clear;
	m_Clear = new wxMenuItem( m_Edit, wxID_CLEAR, wxString( wxT("О&чистить") ) , wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_Clear );
	
	wxMenuItem* m_SelectAll;
	m_SelectAll = new wxMenuItem( m_Edit, wxID_SELECTALL, wxString( wxT("Выделить в&се") ) + wxT('\t') + wxT("CTRL+A"), wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_SelectAll );
	
	wxMenuItem* m_separator4;
	m_separator4 = m_Edit->AppendSeparator();
	
	wxMenuItem* m_Search;
	m_Search = new wxMenuItem( m_Edit, wxID_FIND, wxString( wxT("&Найти") ) + wxT('\t') + wxT("CTRL+F"), wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_Search );
	
	wxMenuItem* m_SearchNext;
	m_SearchNext = new wxMenuItem( m_Edit, ctID_FINDNEXT, wxString( wxT("На&йти далее...") ) + wxT('\t') + wxT("F3"), wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_SearchNext );
	
	wxMenuItem* m_Replace;
	m_Replace = new wxMenuItem( m_Edit, wxID_REPLACE, wxString( wxT("&Заменить") ) + wxT('\t') + wxT("CTRL+R"), wxEmptyString, wxITEM_NORMAL );
	m_Edit->Append( m_Replace );
	
	m_menubar->Append( m_Edit, wxT("&Правка") ); 
	
	m_View = new wxMenu();
	wxMenuItem* m_ToolPanel;
	m_ToolPanel = new wxMenuItem( m_View, ctID_TOOLPANEL, wxString( wxT("Панель &инструментов") ) , wxEmptyString, wxITEM_CHECK );
	m_View->Append( m_ToolPanel );
	m_ToolPanel->Check( true );
	
	wxMenuItem* m_FormatPanel;
	m_FormatPanel = new wxMenuItem( m_View, ctID_FORMATPANEL, wxString( wxT("П&анель форматирования") ) , wxEmptyString, wxITEM_CHECK );
	m_View->Append( m_FormatPanel );
	m_FormatPanel->Check( true );
	
	wxMenuItem* m_StatusBar;
	m_StatusBar = new wxMenuItem( m_View, ctID_STATUSBAR, wxString( wxT("&Строка состояния") ) , wxEmptyString, wxITEM_CHECK );
	m_View->Append( m_StatusBar );
	m_StatusBar->Check( true );
	
	m_menubar->Append( m_View, wxT("&Вид") ); 
	
	m_Insert = new wxMenu();
	wxMenuItem* m_DateTime;
	m_DateTime = new wxMenuItem( m_Insert, ctID_DATETIME, wxString( wxT("&Дата и время") ) , wxEmptyString, wxITEM_NORMAL );
	m_Insert->Append( m_DateTime );
	
	m_menubar->Append( m_Insert, wxT("Вст&авка") ); 
	
	m_Format = new wxMenu();
	wxMenuItem* m_Marker;
	m_Marker = new wxMenuItem( m_Format, ctID_MARKER, wxString( wxT("&Маркер") ) , wxEmptyString, wxITEM_NORMAL );
	m_Format->Append( m_Marker );
	
	wxMenuItem* m_Font;
	m_Font = new wxMenuItem( m_Format, ctID_FONT, wxString( wxT("&Шрифт") ) , wxEmptyString, wxITEM_NORMAL );
	m_Format->Append( m_Font );
	
	wxMenuItem* m_Paragraph;
	m_Paragraph = new wxMenuItem( m_Format, ctID_PARAGRAPH, wxString( wxT("&Абзац") ) , wxEmptyString, wxITEM_NORMAL );
	m_Format->Append( m_Paragraph );
	
	m_menubar->Append( m_Format, wxT("Фор&мат") ); 
	
	m_Help = new wxMenu();
	wxMenuItem* m_About;
	m_About = new wxMenuItem( m_Help, wxID_ABOUT, wxString( wxT("&О программе") ) , wxEmptyString, wxITEM_NORMAL );
	m_Help->Append( m_About );
	
	m_menubar->Append( m_Help, wxT("&Справка") ); 
	
	this->SetMenuBar( m_menubar );
	
	m_statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	this->Connect( wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolCreate ) );
	this->Connect( wxID_OPEN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolOpen ) );
	this->Connect( wxID_SAVE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolSave ) );
	this->Connect( wxID_PRINT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolPrint ) );
	this->Connect( wxID_FIND, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolFind ) );
	this->Connect( wxID_REPLACE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolReplace ) );
	this->Connect( wxID_CUT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolCut ) );
	this->Connect( wxID_COPY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolCopy ) );
	this->Connect( wxID_PASTE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolPaste ) );
	this->Connect( wxID_UNDO, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolUndo ) );
	this->Connect( ctID_DATETIME, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolDateTime ) );
	m_combo_font->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIDialog::OnComboFontSelected ), NULL, this );
	m_combo_fontsize->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIDialog::OnComboFontSizeSelected ), NULL, this );
	this->Connect( ctID_BOLD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatBold ) );
	this->Connect( ctID_ITALIC, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatItalic ) );
	this->Connect( ctID_UNDERLINE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatUnderline ) );
	this->Connect( ctID_TEXTCOLOR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatTextcolor ) );
	this->Connect( ctID_LEFT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatLeft ) );
	this->Connect( ctID_CENTER, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatCenter ) );
	this->Connect( ctID_RIGHT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatRight ) );
	this->Connect( ctID_LIST, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatList ) );
	m_richText->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIDialog::OnRichTextChanged ), NULL, this );
	m_richText->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( GUIDialog::OnRichTextUpdated ), NULL, this );
	this->Connect( m_Create->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileCreate ) );
	this->Connect( m_Open->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileOpen ) );
	this->Connect( m_Save->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileSave ) );
	this->Connect( m_SaveAs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileSaveAs ) );
	this->Connect( m_Print->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFilePrint ) );
	this->Connect( m_PrintPreview->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFilePreview ) );
	this->Connect( m_Exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileQuit ) );
	this->Connect( m_Undo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditUndo ) );
	this->Connect( m_Redo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditRedo ) );
	this->Connect( m_Cut->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditCut ) );
	this->Connect( m_Copy->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditCopy ) );
	this->Connect( m_Paste->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditPaste ) );
	this->Connect( m_Clear->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditClear ) );
	this->Connect( m_SelectAll->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditSelectAll ) );
	this->Connect( m_Search->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditSearch ) );
	this->Connect( m_SearchNext->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditSearchNext ) );
	this->Connect( m_Replace->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditReplace ) );
	this->Connect( m_ToolPanel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnToolPanelVisibility ) );
	this->Connect( m_FormatPanel->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFormatPanelVisibility ) );
	this->Connect( m_StatusBar->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnStatusBarVisibility ) );
	this->Connect( m_DateTime->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnInsertDateTime ) );
	this->Connect( m_Marker->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFormatMarker ) );
	this->Connect( m_Font->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFormatFont ) );
	this->Connect( m_Paragraph->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFormatParagraph ) );
	this->Connect( m_About->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnAbout ) );
}

GUIDialog::~GUIDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIDialog::OnClose ) );
	this->Disconnect( wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolCreate ) );
	this->Disconnect( wxID_OPEN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolOpen ) );
	this->Disconnect( wxID_SAVE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolSave ) );
	this->Disconnect( wxID_PRINT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolPrint ) );
	this->Disconnect( wxID_FIND, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolFind ) );
	this->Disconnect( wxID_REPLACE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolReplace ) );
	this->Disconnect( wxID_CUT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolCut ) );
	this->Disconnect( wxID_COPY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolCopy ) );
	this->Disconnect( wxID_PASTE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolPaste ) );
	this->Disconnect( wxID_UNDO, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolUndo ) );
	this->Disconnect( ctID_DATETIME, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnToolDateTime ) );
	m_combo_font->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIDialog::OnComboFontSelected ), NULL, this );
	m_combo_fontsize->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIDialog::OnComboFontSizeSelected ), NULL, this );
	this->Disconnect( ctID_BOLD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatBold ) );
	this->Disconnect( ctID_ITALIC, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatItalic ) );
	this->Disconnect( ctID_UNDERLINE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatUnderline ) );
	this->Disconnect( ctID_TEXTCOLOR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatTextcolor ) );
	this->Disconnect( ctID_LEFT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatLeft ) );
	this->Disconnect( ctID_CENTER, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatCenter ) );
	this->Disconnect( ctID_RIGHT, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatRight ) );
	this->Disconnect( ctID_LIST, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIDialog::OnFormatList ) );
	m_richText->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIDialog::OnRichTextChanged ), NULL, this );
	m_richText->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( GUIDialog::OnRichTextUpdated ), NULL, this );
	this->Disconnect( wxID_NEW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileCreate ) );
	this->Disconnect( wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileOpen ) );
	this->Disconnect( wxID_SAVE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileSave ) );
	this->Disconnect( wxID_SAVEAS, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileSaveAs ) );
	this->Disconnect( wxID_PRINT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFilePrint ) );
	this->Disconnect( wxID_PREVIEW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFilePreview ) );
	this->Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFileQuit ) );
	this->Disconnect( wxID_UNDO, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditUndo ) );
	this->Disconnect( wxID_REDO, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditRedo ) );
	this->Disconnect( wxID_CUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditCut ) );
	this->Disconnect( wxID_COPY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditCopy ) );
	this->Disconnect( wxID_PASTE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditPaste ) );
	this->Disconnect( wxID_CLEAR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditClear ) );
	this->Disconnect( wxID_SELECTALL, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditSelectAll ) );
	this->Disconnect( wxID_FIND, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditSearch ) );
	this->Disconnect( ctID_FINDNEXT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditSearchNext ) );
	this->Disconnect( wxID_REPLACE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnEditReplace ) );
	this->Disconnect( ctID_TOOLPANEL, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnToolPanelVisibility ) );
	this->Disconnect( ctID_FORMATPANEL, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFormatPanelVisibility ) );
	this->Disconnect( ctID_STATUSBAR, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnStatusBarVisibility ) );
	this->Disconnect( ctID_DATETIME, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnInsertDateTime ) );
	this->Disconnect( ctID_MARKER, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFormatMarker ) );
	this->Disconnect( ctID_FONT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFormatFont ) );
	this->Disconnect( ctID_PARAGRAPH, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnFormatParagraph ) );
	this->Disconnect( wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIDialog::OnAbout ) );
	
}

DateTimeGUI::DateTimeGUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Доступные форматы:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer5->Add( m_staticText1, 0, wxALL, 5 );
	
	m_listBox1 = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer5->Add( m_listBox1, 0, wxALL|wxEXPAND, 5 );
	
	bSizer3->Add( bSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_button_ok = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_ok->SetDefault(); 
	bSizer4->Add( m_button_ok, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	m_button_cancel = new wxButton( this, wxID_ANY, wxT("Отмена"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button_cancel, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	bSizer3->Add( bSizer4, 1, 0, 5 );
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_listBox1->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( DateTimeGUI::OnListBoxDoubleClick ), NULL, this );
	m_button_ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DateTimeGUI::OnOkButtonClick ), NULL, this );
	m_button_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DateTimeGUI::OnCancelButtonClick ), NULL, this );
}

DateTimeGUI::~DateTimeGUI()
{
	// Disconnect Events
	m_listBox1->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( DateTimeGUI::OnListBoxDoubleClick ), NULL, this );
	m_button_ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DateTimeGUI::OnOkButtonClick ), NULL, this );
	m_button_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DateTimeGUI::OnCancelButtonClick ), NULL, this );
	
}

FindGUI::FindGUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Текст:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer9->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_find = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), 0 );
	bSizer9->Add( m_textCtrl_find, 0, wxALL|wxEXPAND, 5 );
	
	bSizer7->Add( bSizer9, 1, wxEXPAND, 5 );
	
	m_checkBox_whole = new wxCheckBox( this, wxID_ANY, wxT("Слово целиком"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_checkBox_whole, 0, wxALL, 5 );
	
	m_checkBox_ignoreCase = new wxCheckBox( this, wxID_ANY, wxT("Игнорировать регистр"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_checkBox_ignoreCase, 0, wxALL, 5 );
	
	bSizer6->Add( bSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_button_ok = new wxButton( this, wxID_ANY, wxT("Найти далее"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button_ok, 0, wxALL, 5 );
	
	m_button_cancel = new wxButton( this, wxID_ANY, wxT("Закрыть"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button_cancel, 0, wxALL, 5 );
	
	bSizer6->Add( bSizer8, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer6 );
	this->Layout();
	bSizer6->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindGUI::OnFindNextButtonClick ), NULL, this );
	m_button_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindGUI::OnCancelButtonClick ), NULL, this );
}

FindGUI::~FindGUI()
{
	// Disconnect Events
	m_button_ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindGUI::OnFindNextButtonClick ), NULL, this );
	m_button_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( FindGUI::OnCancelButtonClick ), NULL, this );
	
}

ReplaceGUI::ReplaceGUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Текст:    "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer91->Add( m_staticText21, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_find = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), 0 );
	bSizer91->Add( m_textCtrl_find, 0, wxALL|wxEXPAND, 5 );
	
	bSizer7->Add( bSizer91, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Замена:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer9->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_textCtrl_replace = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), 0 );
	bSizer9->Add( m_textCtrl_replace, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	bSizer7->Add( bSizer9, 1, wxEXPAND, 5 );
	
	m_checkBox_whole = new wxCheckBox( this, wxID_ANY, wxT("Слово целиком"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_checkBox_whole, 0, wxALL, 5 );
	
	m_checkBox_ignoreCase = new wxCheckBox( this, wxID_ANY, wxT("Игнорировать регистр"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_checkBox_ignoreCase, 0, wxALL, 5 );
	
	bSizer6->Add( bSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_button_ok = new wxButton( this, wxID_ANY, wxT("Найти далее"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button_ok, 0, wxALIGN_LEFT|wxALL, 5 );
	
	m_button_replace = new wxButton( this, wxID_ANY, wxT("Заменить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button_replace, 0, wxALL, 5 );
	
	m_button_replace_all = new wxButton( this, wxID_ANY, wxT("Заменить все"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button_replace_all, 0, wxALL, 5 );
	
	m_button_cancel = new wxButton( this, wxID_ANY, wxT("Закрыть"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button_cancel, 0, wxALIGN_LEFT|wxALL, 5 );
	
	bSizer6->Add( bSizer8, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer6 );
	this->Layout();
	bSizer6->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button_ok->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReplaceGUI::OnFindNextButtonClick ), NULL, this );
	m_button_replace->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReplaceGUI::OnReplaceButtonClick ), NULL, this );
	m_button_replace_all->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReplaceGUI::OnReplaceAllButtonClick ), NULL, this );
	m_button_cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReplaceGUI::OnCancelButtonClick ), NULL, this );
}

ReplaceGUI::~ReplaceGUI()
{
	// Disconnect Events
	m_button_ok->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReplaceGUI::OnFindNextButtonClick ), NULL, this );
	m_button_replace->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReplaceGUI::OnReplaceButtonClick ), NULL, this );
	m_button_replace_all->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReplaceGUI::OnReplaceAllButtonClick ), NULL, this );
	m_button_cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReplaceGUI::OnCancelButtonClick ), NULL, this );
	
}
