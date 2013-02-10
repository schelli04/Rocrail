/*
 Copyright (C) 2002-2012 Rob Versluis, Rocrail.net

 Without an official permission commercial use is not permitted.
 Forking this project is not permitted.
 */
#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "ecosdlg.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "ecosdlg.h"

#include "rocrail/wrapper/public/DigInt.h"
#include "rocview/public/guiapp.h"
#include "rocs/public/strtok.h"

////@begin XPM images
////@end XPM images

/*!
 * ECoSCtrlDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( ECoSCtrlDialog, wxDialog )

/*!
 * ECoSCtrlDialog event table definition
 */

BEGIN_EVENT_TABLE( ECoSCtrlDialog, wxDialog )

////@begin ECoSCtrlDialog event table entries
    EVT_RADIOBOX( ID_SUBLIB, ECoSCtrlDialog::OnSublibSelected )

    EVT_BUTTON( wxID_OK, ECoSCtrlDialog::OnOkClick )

    EVT_BUTTON( wxID_CANCEL, ECoSCtrlDialog::OnCancelClick )

////@end ECoSCtrlDialog event table entries

END_EVENT_TABLE()

/*!
 * ECoSCtrlDialog constructors
 */

ECoSCtrlDialog::ECoSCtrlDialog()
{
    Init();
}

ECoSCtrlDialog::ECoSCtrlDialog( wxWindow* parent, iONode props, const char* devices )
{
  Create(parent, -1, wxString::From8BitData(wDigInt.getlib(props)).Upper());
  m_Props = props;
  m_Devices = devices;
  initLabels();
  initValues();

  if( StrOp.equals( wDigInt.mcs2, wDigInt.getlib( m_Props ) ) ) {
    m_Port->Enable(false);
    this->SetTitle( _T("CS2") );
  }
  else {
    m_FBMod->Enable(false);
  }

  GetSizer()->Fit(this);
  GetSizer()->SetSizeHints(this);

  GetSizer()->Layout();
}


void ECoSCtrlDialog::initLabels() {
  m_labIID->SetLabel( wxGetApp().getMsg( "iid" ) );
  m_labDevice->SetLabel( wxGetApp().getMsg( "device" ) );
  m_labHost->SetLabel( wxGetApp().getMsg( "host" ) );
  m_labPort->SetLabel( wxGetApp().getMsg( "port" ) );
  m_labFBMod->SetLabel( wxGetApp().getMsg( "sensors" ) );
  m_labVersion->SetLabel( wxGetApp().getMsg( "version" ) );
  m_SubLib->SetLabel( wxGetApp().getMsg( "type" ) );
  m_OptionsBox->SetLabel( wxGetApp().getMsg( "options" ) );
  m_SystemInfo->SetLabel( wxGetApp().getMsg( "systeminfo" ) );
  m_LocoList->SetLabel( wxGetApp().getMsg( "loctable" ) );
}

void ECoSCtrlDialog::initValues() {
  if( m_Props == NULL )
    return;

  m_IID->SetValue( wxString( wDigInt.getiid( m_Props ), wxConvUTF8 ) );
  m_Device->SetValue( wxString( wDigInt.getdevice( m_Props ), wxConvUTF8 ) );
  if( m_Devices != NULL ) {
    iOStrTok tok = StrTokOp.inst(m_Devices, ',');
    while( StrTokOp.hasMoreTokens(tok) ) {
      m_Device->Append( wxString( StrTokOp.nextToken(tok), wxConvUTF8 ) );
    }
    StrTokOp.base.del(tok);
  }

  m_Host->SetValue( wxString( wDigInt.gethost( m_Props ), wxConvUTF8 ) );

  char* val = StrOp.fmt( "%d", wDigInt.getport( m_Props ) );
  m_Port->SetValue( wxString( val, wxConvUTF8 ) );
  StrOp.free( val );
  m_FBMod->SetValue( wDigInt.getfbmod( m_Props ) );
  m_Version->SetValue( wDigInt.getprotver( m_Props ) );

  if( StrOp.equals( wDigInt.sublib_serial, wDigInt.getsublib(m_Props) )) {
    m_SubLib->SetSelection(1);
  }
  m_SystemInfo->SetValue( wDigInt.issysteminfo( m_Props ) );
  m_LocoList->SetValue( wDigInt.islocolist( m_Props ) );

  SublibSelected();

}


void ECoSCtrlDialog::evaluate() {
  if( m_Props == NULL )
    return;
  wDigInt.setiid( m_Props, m_IID->GetValue().mb_str(wxConvUTF8) );
  wDigInt.setdevice( m_Props, m_Device->GetValue().mb_str(wxConvUTF8) );
  wDigInt.sethost( m_Props, m_Host->GetValue().mb_str(wxConvUTF8) );
  wDigInt.setport( m_Props, atoi( m_Port->GetValue().mb_str(wxConvUTF8) ) );
  wDigInt.setfbmod( m_Props, m_FBMod->GetValue() );
  wDigInt.setprotver( m_Props, m_Version->GetValue() );
  if( m_SubLib->GetSelection() == 1 )
    wDigInt.setsublib(m_Props, wDigInt.sublib_serial );
  else
    wDigInt.setsublib(m_Props, wDigInt.sublib_default );
  wDigInt.setsysteminfo( m_Props, m_SystemInfo->IsChecked()?True:False );
  wDigInt.setlocolist( m_Props, m_LocoList->IsChecked()?True:False );

}


/*!
 * Dialog creator
 */

bool ECoSCtrlDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin ECoSCtrlDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end ECoSCtrlDialog creation
    return true;
}

/*!
 * Dialog destructor
 */

ECoSCtrlDialog::~ECoSCtrlDialog()
{
////@begin ECoSCtrlDialog destruction
////@end ECoSCtrlDialog destruction
}

/*!
 * Member initialisation
 */

void ECoSCtrlDialog::Init()
{
////@begin ECoSCtrlDialog member initialisation
    m_labIID = NULL;
    m_IID = NULL;
    m_labDevice = NULL;
    m_Device = NULL;
    m_labHost = NULL;
    m_Host = NULL;
    m_labPort = NULL;
    m_Port = NULL;
    m_labFBMod = NULL;
    m_FBMod = NULL;
    m_labVersion = NULL;
    m_Version = NULL;
    m_SubLib = NULL;
    m_OptionsBox = NULL;
    m_SystemInfo = NULL;
    m_LocoList = NULL;
    m_OK = NULL;
    m_Cancel = NULL;
////@end ECoSCtrlDialog member initialisation
}

/*!
 * Control creation for Dialog
 */

void ECoSCtrlDialog::CreateControls()
{
////@begin ECoSCtrlDialog content construction
    ECoSCtrlDialog* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxPanel* itemPanel3 = new wxPanel( itemDialog1, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
    itemBoxSizer2->Add(itemPanel3, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    itemPanel3->SetSizer(itemBoxSizer4);

    wxFlexGridSizer* itemFlexGridSizer5 = new wxFlexGridSizer(0, 2, 0, 0);
    itemFlexGridSizer5->AddGrowableCol(1);
    itemBoxSizer4->Add(itemFlexGridSizer5, 0, wxGROW|wxALL, 5);

    m_labIID = new wxStaticText( itemPanel3, wxID_ANY, _("IID"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_labIID, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_IID = new wxTextCtrl( itemPanel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_IID, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labDevice = new wxStaticText( itemPanel3, wxID_ANY, _("Device"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_labDevice, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_DeviceStrings;
    m_Device = new wxComboBox( itemPanel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_DeviceStrings, wxCB_DROPDOWN );
    itemFlexGridSizer5->Add(m_Device, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labHost = new wxStaticText( itemPanel3, wxID_ANY, _("Host"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_labHost, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Host = new wxTextCtrl( itemPanel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0 );
    itemFlexGridSizer5->Add(m_Host, 1, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labPort = new wxStaticText( itemPanel3, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_labPort, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_Port = new wxTextCtrl( itemPanel3, wxID_ANY, _("15471"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    m_Port->SetMaxLength(5);
    itemFlexGridSizer5->Add(m_Port, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labFBMod = new wxStaticText( itemPanel3, wxID_ANY, _("FBmod"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_labFBMod, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_FBMod = new wxSpinCtrl( itemPanel3, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 64, 0 );
    itemFlexGridSizer5->Add(m_FBMod, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_labVersion = new wxStaticText( itemPanel3, wxID_ANY, _("Version"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer5->Add(m_labVersion, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_Version = new wxSpinCtrl( itemPanel3, wxID_ANY, _T("0"), wxDefaultPosition, wxSize(80, -1), wxSP_ARROW_KEYS, 0, 10, 0 );
    itemFlexGridSizer5->Add(m_Version, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxArrayString m_SubLibStrings;
    m_SubLibStrings.Add(_("&Ethernet"));
    m_SubLibStrings.Add(_("&Serial"));
    m_SubLib = new wxRadioBox( itemPanel3, ID_SUBLIB, _("SubType"), wxDefaultPosition, wxDefaultSize, m_SubLibStrings, 1, wxRA_SPECIFY_ROWS );
    m_SubLib->SetSelection(0);
    itemBoxSizer4->Add(m_SubLib, 0, wxALIGN_LEFT|wxALL, 5);

    m_OptionsBox = new wxStaticBox(itemPanel3, wxID_ANY, _("Options"));
    wxStaticBoxSizer* itemStaticBoxSizer19 = new wxStaticBoxSizer(m_OptionsBox, wxVERTICAL);
    itemBoxSizer4->Add(itemStaticBoxSizer19, 0, wxGROW|wxALL, 5);

    m_SystemInfo = new wxCheckBox( itemPanel3, wxID_ANY, _("System info"), wxDefaultPosition, wxDefaultSize, 0 );
    m_SystemInfo->SetValue(false);
    itemStaticBoxSizer19->Add(m_SystemInfo, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_LocoList = new wxCheckBox( itemPanel3, wxID_ANY, _("Loco list"), wxDefaultPosition, wxDefaultSize, 0 );
    m_LocoList->SetValue(false);
    itemStaticBoxSizer19->Add(m_LocoList, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer22 = new wxStdDialogButtonSizer;

    itemBoxSizer2->Add(itemStdDialogButtonSizer22, 0, wxALIGN_RIGHT|wxALL, 5);
    m_OK = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_OK->SetDefault();
    itemStdDialogButtonSizer22->AddButton(m_OK);

    m_Cancel = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer22->AddButton(m_Cancel);

    itemStdDialogButtonSizer22->Realize();

////@end ECoSCtrlDialog content construction
}

/*!
 * Should we show tooltips?
 */

bool ECoSCtrlDialog::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap ECoSCtrlDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin ECoSCtrlDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end ECoSCtrlDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon ECoSCtrlDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin ECoSCtrlDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end ECoSCtrlDialog icon retrieval
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void ECoSCtrlDialog::OnOkClick( wxCommandEvent& event )
{
  evaluate();
  EndModal( wxID_OK );
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void ECoSCtrlDialog::OnCancelClick( wxCommandEvent& event )
{
  EndModal( 0 );
}


/*!
 * wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_SUBLIB
 */

void ECoSCtrlDialog::OnSublibSelected( wxCommandEvent& event )
{
  SublibSelected();
}

void ECoSCtrlDialog::SublibSelected()
{
  if( m_SubLib->GetSelection() == 1 ) {
    m_Host->Enable(false);
    m_Port->Enable(false);
    m_Device->Enable(true);
  }
  else {
    m_Host->Enable(true);
    m_Port->Enable(StrOp.equals( wDigInt.mcs2, wDigInt.getlib( m_Props ) )?false:true);
    m_Device->Enable(false);
  }
}
