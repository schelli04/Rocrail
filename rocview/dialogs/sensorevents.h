/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2014 Rob Versluis, Rocrail.net

 


 This program is free software; you can redistribute it and/or
 as published by the Free Software Foundation; either version 2
 modify it under the terms of the GNU General Public License
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef __sensorevents__
#define __sensorevents__

/**
@file
Subclass of SensorEventsGen, which is generated by wxFormBuilder.
*/

#include "sensoreventsgen.h"

//// end generated include
#include "rocs/public/node.h"

/** Implementing SensorEventsGen */
class SensorEventsDlg : public SensorEventsGen
{
  void initLabels();
  void initValues();

  iONode m_FbEvent;
  int    m_SortCol;

	public:
		/** Constructor */
		SensorEventsDlg( wxWindow* parent );
	//// end generated class members
		void onRefresh( wxCommandEvent& event );
		void onOK( wxCommandEvent& event );
		void onClose( wxCloseEvent& event );
		void onReset( wxCommandEvent& event );
		void onListSelected( wxListEvent& event );
		void onColClick( wxListEvent& event );
		void onDrag( wxListEvent& event );
		bool Validate();
		void onHelp( wxCommandEvent& event );
};

#endif // __sensorevents__
