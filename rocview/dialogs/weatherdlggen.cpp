///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "weatherdlggen.h"

///////////////////////////////////////////////////////////////////////////

WeatherDlgGen::WeatherDlgGen( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_WeatherBook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_DayPanel = new wxPanel( m_WeatherBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labOutputs = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Outputs"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labOutputs->Wrap( -1 );
	fgSizer1->Add( m_labOutputs, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_Outputs = new wxTextCtrl( m_DayPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Outputs->SetMinSize( wxSize( 160,-1 ) );
	
	fgSizer1->Add( m_Outputs, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labMaxBri = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Max brightness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labMaxBri->Wrap( -1 );
	fgSizer1->Add( m_labMaxBri, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_MaxBri = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer1->Add( m_MaxBri, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labMinBri = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Min brightness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labMinBri->Wrap( -1 );
	fgSizer1->Add( m_labMinBri, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_MinBri = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer1->Add( m_MinBri, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labColorSliding = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Color sliding"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labColorSliding->Wrap( -1 );
	fgSizer1->Add( m_labColorSliding, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_ColorSliding = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 120, 0 );
	fgSizer1->Add( m_ColorSliding, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer2->Add( fgSizer1, 0, wxEXPAND, 5 );
	
	m_SlidingDaylight = new wxCheckBox( m_DayPanel, wxID_ANY, wxT("Sliding daylight"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_SlidingDaylight, 0, wxALL, 5 );
	
	m_SunriseBox = new wxStaticBoxSizer( new wxStaticBox( m_DayPanel, wxID_ANY, wxT("Sunrise") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labSunriseTime = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labSunriseTime->Wrap( -1 );
	fgSizer2->Add( m_labSunriseTime, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SunriseHour = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, 0, 23, 0 );
	fgSizer2->Add( m_SunriseHour, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticText5 = new wxStaticText( m_DayPanel, wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer2->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_SunriseMin = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	fgSizer2->Add( m_SunriseMin, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_SunriseBox->Add( fgSizer2, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labRGBSunrise = new wxStaticText( m_DayPanel, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRGBSunrise->Wrap( -1 );
	fgSizer8->Add( m_labRGBSunrise, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_SunriseRed = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer8->Add( m_SunriseRed, 0, wxALL, 5 );
	
	m_SunriseGreen = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer8->Add( m_SunriseGreen, 0, wxALL, 5 );
	
	m_SunriseBlue = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer8->Add( m_SunriseBlue, 0, wxALL, 5 );
	
	m_SunriseBox->Add( fgSizer8, 0, 0, 5 );
	
	bSizer2->Add( m_SunriseBox, 1, wxEXPAND|wxALL, 5 );
	
	m_SunsetBox = new wxStaticBoxSizer( new wxStaticBox( m_DayPanel, wxID_ANY, wxT("Sunset") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labSunsetTime = new wxStaticText( m_DayPanel, wxID_ANY, wxT("Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labSunsetTime->Wrap( -1 );
	fgSizer21->Add( m_labSunsetTime, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_SunsetHour = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, 0, 23, 0 );
	fgSizer21->Add( m_SunsetHour, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticText51 = new wxStaticText( m_DayPanel, wxID_ANY, wxT(":"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	fgSizer21->Add( m_staticText51, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_SunsetMin = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 70,-1 ), wxSP_ARROW_KEYS, 0, 59, 0 );
	fgSizer21->Add( m_SunsetMin, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_SunsetBox->Add( fgSizer21, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer81;
	fgSizer81 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer81->SetFlexibleDirection( wxBOTH );
	fgSizer81->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labRGBSunset = new wxStaticText( m_DayPanel, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRGBSunset->Wrap( -1 );
	fgSizer81->Add( m_labRGBSunset, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_SunsetRed = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer81->Add( m_SunsetRed, 0, wxALL, 5 );
	
	m_SunsetGreen = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer81->Add( m_SunsetGreen, 0, wxALL, 5 );
	
	m_SunsetBlue = new wxSpinCtrl( m_DayPanel, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer81->Add( m_SunsetBlue, 0, wxALL, 5 );
	
	m_SunsetBox->Add( fgSizer81, 1, wxEXPAND, 5 );
	
	bSizer2->Add( m_SunsetBox, 0, wxEXPAND|wxALL, 5 );
	
	m_DayPanel->SetSizer( bSizer2 );
	m_DayPanel->Layout();
	bSizer2->Fit( m_DayPanel );
	m_WeatherBook->AddPage( m_DayPanel, wxT("Day"), false );
	m_NightPanel = new wxPanel( m_WeatherBook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer5;
	fgSizer5 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer5->AddGrowableCol( 1 );
	fgSizer5->SetFlexibleDirection( wxBOTH );
	fgSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_labOutputsNight = new wxStaticText( m_NightPanel, wxID_ANY, wxT("Outputs"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labOutputsNight->Wrap( -1 );
	fgSizer5->Add( m_labOutputsNight, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_OutputsNight = new wxTextCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_OutputsNight->SetMinSize( wxSize( 160,-1 ) );
	
	fgSizer5->Add( m_OutputsNight, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_labBrightnessNight = new wxStaticText( m_NightPanel, wxID_ANY, wxT("Brightness"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labBrightnessNight->Wrap( -1 );
	fgSizer5->Add( m_labBrightnessNight, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_BrightnessNight = new wxSpinCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer5->Add( m_BrightnessNight, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_labRGBNight = new wxStaticText( m_NightPanel, wxID_ANY, wxT("RGB"), wxDefaultPosition, wxDefaultSize, 0 );
	m_labRGBNight->Wrap( -1 );
	fgSizer5->Add( m_labRGBNight, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxFlexGridSizer* fgSizer6;
	fgSizer6 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer6->SetFlexibleDirection( wxBOTH );
	fgSizer6->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_RedNight = new wxSpinCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer6->Add( m_RedNight, 0, wxALL, 5 );
	
	m_GreenNight = new wxSpinCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer6->Add( m_GreenNight, 0, wxALL, 5 );
	
	m_BlueNight = new wxSpinCtrl( m_NightPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 255, 0 );
	fgSizer6->Add( m_BlueNight, 0, wxALL, 5 );
	
	fgSizer5->Add( fgSizer6, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	m_NightPanel->SetSizer( fgSizer5 );
	m_NightPanel->Layout();
	fgSizer5->Fit( m_NightPanel );
	m_WeatherBook->AddPage( m_NightPanel, wxT("Night"), false );
	
	bSizer1->Add( m_WeatherBook, 1, wxEXPAND | wxALL, 5 );
	
	m_StdButtons = new wxStdDialogButtonSizer();
	m_StdButtonsOK = new wxButton( this, wxID_OK );
	m_StdButtons->AddButton( m_StdButtonsOK );
	m_StdButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_StdButtons->AddButton( m_StdButtonsCancel );
	m_StdButtonsHelp = new wxButton( this, wxID_HELP );
	m_StdButtons->AddButton( m_StdButtonsHelp );
	m_StdButtons->Realize();
	bSizer1->Add( m_StdButtons, 0, wxALL|wxEXPAND|wxALIGN_RIGHT, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_StdButtonsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onCancel ), NULL, this );
	m_StdButtonsHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onHelp ), NULL, this );
	m_StdButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onOK ), NULL, this );
}

WeatherDlgGen::~WeatherDlgGen()
{
	// Disconnect Events
	m_StdButtonsCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onCancel ), NULL, this );
	m_StdButtonsHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onHelp ), NULL, this );
	m_StdButtonsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WeatherDlgGen::onOK ), NULL, this );
	
}
