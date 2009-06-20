#ifndef __powermandlg__
#define __powermandlg__

/**
@file
Subclass of powermandlggen, which is generated by wxFormBuilder.
*/

#include "powermandlggen.h"

/** Implementing powermandlggen */
class PowerManDlg : public powermandlggen
{
protected:
	// Handlers for powermandlggen events.
	void OnAddBooster( wxCommandEvent& event );
	void OnDelBooster( wxCommandEvent& event );
	void OnAddModule( wxCommandEvent& event );
	void OnDelModule( wxCommandEvent& event );
	void OnAddBlock( wxCommandEvent& event );
	void OnDelBlock( wxCommandEvent& event );
	void OnApply( wxCommandEvent& event );
	void OnCancel( wxCommandEvent& event );
	void OnOK( wxCommandEvent& event );
	
public:
	/** Constructor */
	PowerManDlg( wxWindow* parent );
};

#endif // __powermandlg__
