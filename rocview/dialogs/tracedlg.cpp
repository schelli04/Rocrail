/*
 Rocrail - Model Railroad Software

 Copyright (C) 2002-2015 Rob Versluis, Rocrail.net

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

#include "tracedlg.h"
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/defs.h"
#endif

#include "rocs/public/system.h"
#include "rocs/public/file.h"

#include "rocview/public/guiapp.h"
#include "rocview/wrapper/public/Gui.h"


TraceDlg::TraceDlg( wxWindow* parent ):TraceDlgGen( parent )
{
  m_TraceFile = NULL;
  initLabels();
  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);
}

TraceDlg::~TraceDlg() {
  if( m_TraceFile != NULL) {
    StrOp.free(m_TraceFile);
  }
}


void TraceDlg::initLabels() {
  SetTitle(wxGetApp().getMsg( "trace" ));

  m_ObjectType->Append(wxT(""));
  m_ObjectType->Append(wxT("OLoc"));
  m_ObjectType->Append(wxT("OBlock"));
  m_ObjectType->Append(wxT("OStage"));
  m_ObjectType->Append(wxT("OSwitch"));
  m_ObjectType->Append(wxT("OSignal"));
  m_ObjectType->Append(wxT("OOutput"));
  m_ObjectType->Append(wxT("ORoute"));

  m_labType->SetLabel( wxGetApp().getMsg( "type" ) );
  m_labID->SetLabel( wxGetApp().getMsg( "id" ) );
  m_Open->SetLabel( wxGetApp().getMsg( "open" ) + wxT("...") );
  m_Search->SetLabel( wxGetApp().getMsg( "search" ) );

  // Buttons
  m_stdButtonOK->SetLabel( wxGetApp().getMsg( "ok" ) );
  m_stdButtonHelp->SetLabel( wxGetApp().getMsg( "help" ) );
}


void TraceDlg::onOpen( wxCommandEvent& event )
{
  wxFileDialog* fdlg = new wxFileDialog(this, _T("Search trace"),
      wxString(".",wxConvUTF8), _T(""),
      _T("TRC files (*.trc)|*.trc"), wxFD_OPEN);
  if( fdlg->ShowModal() == wxID_OK ) {
    if( m_TraceFile != NULL) {
      StrOp.free(m_TraceFile);
      m_TraceFile = NULL;
    }
    if( FileOp.exist(fdlg->GetPath().mb_str(wxConvUTF8)) ) {
      SetTitle(wxGetApp().getMsg( "trace" ) + wxT(": ") + fdlg->GetPath() );
      m_TraceFile = StrOp.dup(fdlg->GetPath().mb_str(wxConvUTF8));
      onSearch(event);
    }
  }
}

void TraceDlg::onObjectType( wxCommandEvent& event ) {
  event.Skip();
}

void TraceDlg::onSearch( wxCommandEvent& event ) {
  if( m_TraceFile != NULL) {
    m_Trace->Clear();
    iOFile f = FileOp.inst( m_TraceFile, OPEN_READONLY );
    char* buffer = (char*)allocMem( FileOp.size( f ) +1 );
    while( FileOp.readStr(f, buffer)) {
      if( m_ID->GetValue().Len() > 0 ) {
        if( StrOp.find(buffer, m_ID->GetValue().mb_str(wxConvUTF8) ) == NULL )
          continue;
      }
      if( m_ObjectType->GetSelection() > 0 ) {
        if( StrOp.find(buffer, m_ObjectType->GetStringSelection().mb_str(wxConvUTF8) ) == NULL )
          continue;
      }

      m_Trace->Append(wxString(buffer,wxConvUTF8));
    }
    FileOp.base.del( f );
  }
}


void TraceDlg::onHelp( wxCommandEvent& event )
{
  wxGetApp().openLink( "tracefilter" );
}

void TraceDlg::onOK( wxCommandEvent& event )
{
  wxGetApp().getFrame()->resetTraceRef();
  Destroy();
}

void TraceDlg::onClose( wxCloseEvent& event ) {
  wxGetApp().getFrame()->resetTraceRef();
  Destroy();
}
