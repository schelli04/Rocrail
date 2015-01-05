///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __tracedlggen__
#define __tracedlggen__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/listbox.h>
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class TraceDlgGen
///////////////////////////////////////////////////////////////////////////////
class TraceDlgGen : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_labHeader;
		wxListBox* m_Trace;
		wxStaticText* m_labType;
		wxComboBox* m_ObjectType;
		wxStaticText* m_labID;
		wxTextCtrl* m_ID;
		wxButton* m_Search;
		wxButton* m_Open;
		wxStdDialogButtonSizer* m_stdButton;
		wxButton* m_stdButtonOK;
		wxButton* m_stdButtonHelp;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onObjectType( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSearch( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOpen( wxCommandEvent& event ) { event.Skip(); }
		virtual void onHelp( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		TraceDlgGen( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Trace"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~TraceDlgGen();
	
};

#endif //__tracedlggen__
