/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2012 Rob Versluis, Rocrail.net

 Without an official permission commercial use is not permitted.
 Forking this project is not permitted.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef __dcc232dlg__
#define __dcc232dlg__

/**
@file
Subclass of dcc232gen, which is generated by wxFormBuilder.
*/

#include "dcc232dlggen.h"

#include "rocs/public/node.h"

/** Implementing dcc232gen */
class DCC232Dlg : public dcc232gen
{
  void initLabels();
  void initValues();
  void evaluate();
  void onOK( wxCommandEvent& event );
  void onCancel( wxCommandEvent& event );
  iONode m_Props;
  const char* m_Devices;

public:
	/** Constructor */
	DCC232Dlg( wxWindow* parent, iONode props, const char* devices=NULL );
};

#endif // __dcc232dlg__
