/*
 Rocrail - Model Railroad Software

 Copyright (C) Rob Versluis <r.j.versluis@rocrail.net>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef __powermandlg__
#define __powermandlg__

/**
@file
Subclass of powermandlggen, which is generated by wxFormBuilder.
*/
#include "powermandlggen.h"
#include "basenotebook.h"

#include "rocs/public/node.h"

/** Implementing powermandlggen */
class PowerManDlg : public powermandlggen
{
  void initLabels();
  void initIndex();
  void initValues();
  bool evaluate();

  int m_TabAlign;
  int m_SetPage;
  iONode m_Props;

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
  void onSetPage( wxCommandEvent& event );
  void onSelect( wxCommandEvent& event );

public:
	/** Constructor */
	PowerManDlg( wxWindow* parent );
};

#endif // __powermandlg__
