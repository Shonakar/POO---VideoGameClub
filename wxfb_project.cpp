///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

V_InicioS::V_InicioS( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );


	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Sistema de prestamos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer7->Add( m_staticText2, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer2->Add( bSizer7, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer3->Add( m_staticText3, 0, wxALL, 5 );

	m_TextUser = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_TextUser, 0, wxALL, 5 );


	bSizer2->Add( bSizer3, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer4->Add( m_staticText4, 0, wxALL, 5 );

	m_TextPass = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_TextPass, 0, wxALL, 5 );


	bSizer2->Add( bSizer4, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALIGN_LEFT, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_BtnCerrar = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_BtnCerrar, 0, wxALL, 5 );

	m_BtnIniciar = new wxButton( this, wxID_ANY, wxT("Iniciar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_BtnIniciar, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 1, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );


	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer6, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnCerrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_InicioS::ClickCerrar ), NULL, this );
	m_BtnIniciar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_InicioS::ClickIniciar ), NULL, this );
}

V_InicioS::~V_InicioS()
{
	// Disconnect Events
	m_BtnCerrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_InicioS::ClickCerrar ), NULL, this );
	m_BtnIniciar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_InicioS::ClickIniciar ), NULL, this );

}

V_Prestamos::V_Prestamos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxHORIZONTAL );

	m_FechaActual = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_FechaActual->Wrap( -1 );
	bSizer59->Add( m_FechaActual, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer8->Add( bSizer59, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_GrillaA = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaA->CreateGrid( 0, 9 );
	m_GrillaA->EnableEditing( true );
	m_GrillaA->EnableGridLines( true );
	m_GrillaA->EnableDragGridSize( false );
	m_GrillaA->SetMargins( 0, 0 );

	// Columns
	m_GrillaA->SetColSize( 0, 35 );
	m_GrillaA->SetColSize( 1, 100 );
	m_GrillaA->SetColSize( 2, 35 );
	m_GrillaA->SetColSize( 3, 100 );
	m_GrillaA->SetColSize( 4, 35 );
	m_GrillaA->SetColSize( 5, 140 );
	m_GrillaA->SetColSize( 6, 80 );
	m_GrillaA->SetColSize( 7, 80 );
	m_GrillaA->SetColSize( 8, 70 );
	m_GrillaA->EnableDragColMove( false );
	m_GrillaA->EnableDragColSize( true );
	m_GrillaA->SetColLabelSize( 30 );
	m_GrillaA->SetColLabelValue( 0, wxT("Id") );
	m_GrillaA->SetColLabelValue( 1, wxT("Cliente") );
	m_GrillaA->SetColLabelValue( 2, wxT("Id") );
	m_GrillaA->SetColLabelValue( 3, wxT("Usuario") );
	m_GrillaA->SetColLabelValue( 4, wxT("Id") );
	m_GrillaA->SetColLabelValue( 5, wxT("Juego") );
	m_GrillaA->SetColLabelValue( 6, wxT("Fecha Inicial") );
	m_GrillaA->SetColLabelValue( 7, wxT("Fecha Fin") );
	m_GrillaA->SetColLabelValue( 8, wxT("Estado") );
	m_GrillaA->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaA->EnableDragRowSize( true );
	m_GrillaA->SetRowLabelSize( 0 );
	m_GrillaA->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaA->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer11->Add( m_GrillaA, 1, wxEXPAND|wxLEFT, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_BtnNuevo = new wxButton( this, wxID_ANY, wxT("Nuevo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnNuevo, 0, wxALL, 5 );

	m_BtnFin = new wxButton( this, wxID_ANY, wxT("Finalizar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnFin, 0, wxALL, 5 );

	m_BtnInfUsu = new wxButton( this, wxID_ANY, wxT("Info Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnInfUsu, 0, wxALL, 5 );

	m_BtnInfClien = new wxButton( this, wxID_ANY, wxT("Info Cliente"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnInfClien, 0, wxALL, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_BtnTodos = new wxButton( this, wxID_ANY, wxT("Todos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_BtnTodos, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer12->Add( bSizer13, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer11->Add( bSizer12, 0, wxEXPAND|wxLEFT, 5 );


	bSizer8->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	m_BtnJuegos = new wxButton( this, wxID_ANY, wxT("Juegos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_BtnJuegos, 0, wxALL, 5 );

	m_BtnClientes = new wxButton( this, wxID_ANY, wxT("Clientes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_BtnClientes, 0, wxALL, 5 );

	m_BtnUsuarios = new wxButton( this, wxID_ANY, wxT("Usuarios"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_BtnUsuarios, 0, wxALL, 5 );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxVERTICAL );

	m_BtnCerrar = new wxButton( this, wxID_ANY, wxT("Cerrar Sesion"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer60->Add( m_BtnCerrar, 0, wxALL|wxALIGN_RIGHT, 5 );


	bSizer14->Add( bSizer60, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer14, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnNuevo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickNuevoA ), NULL, this );
	m_BtnFin->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickFinalizarA ), NULL, this );
	m_BtnInfUsu->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickInfUsuarioA ), NULL, this );
	m_BtnInfClien->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickInfClienA ), NULL, this );
	m_BtnTodos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::MostraTodos ), NULL, this );
	m_BtnJuegos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickListaJuegos ), NULL, this );
	m_BtnClientes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickListaClientes ), NULL, this );
	m_BtnUsuarios->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickListaUsuarios ), NULL, this );
	m_BtnCerrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickCerrarSesion ), NULL, this );
}

V_Prestamos::~V_Prestamos()
{
	// Disconnect Events
	m_BtnNuevo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickNuevoA ), NULL, this );
	m_BtnFin->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickFinalizarA ), NULL, this );
	m_BtnInfUsu->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickInfUsuarioA ), NULL, this );
	m_BtnInfClien->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickInfClienA ), NULL, this );
	m_BtnTodos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::MostraTodos ), NULL, this );
	m_BtnJuegos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickListaJuegos ), NULL, this );
	m_BtnClientes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickListaClientes ), NULL, this );
	m_BtnUsuarios->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickListaUsuarios ), NULL, this );
	m_BtnCerrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Prestamos::ClickCerrarSesion ), NULL, this );

}

D_Prestamos::D_Prestamos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );

	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Cliente"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer52->Add( m_staticText33, 0, wxALL, 5 );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("- Apellido y Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer53->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textNomyApe = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( m_textNomyApe, 1, wxALL, 5 );

	m_BtnBuscarC = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( m_BtnBuscarC, 0, wxALL, 5 );


	bSizer52->Add( bSizer53, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("- Id"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer54->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextId = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( m_TextId, 0, wxALL, 5 );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("- Codigo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer54->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextCodigo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( m_TextCodigo, 1, wxALL, 5 );


	bSizer52->Add( bSizer54, 1, wxEXPAND, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Juego"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer52->Add( m_staticText16, 0, wxALL, 5 );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("- Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer55->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextNomJ = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( m_TextNomJ, 1, wxALL, 5 );

	m_BtnBuscarJ = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( m_BtnBuscarJ, 0, wxALL, 5 );


	bSizer52->Add( bSizer55, 1, wxEXPAND, 5 );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Datos Prestamo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer52->Add( m_staticText18, 0, wxALL, 5 );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Fecha Inicio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer56->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextFechI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( m_TextFechI, 0, wxALL, 5 );

	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Fecha Fin"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer56->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextFechF = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( m_TextFechF, 0, wxALL, 5 );


	bSizer52->Add( bSizer56, 1, wxEXPAND, 5 );

	m_BtnCrear = new wxButton( this, wxID_ANY, wxT("Crear Prestamo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( m_BtnCrear, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer52 );
	this->Layout();
	bSizer52->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnBuscarC->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Prestamos::ClickBuscarClientes ), NULL, this );
	m_BtnBuscarJ->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Prestamos::ClickBuscarJuegos ), NULL, this );
	m_BtnCrear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Prestamos::ClickCrearA ), NULL, this );
}

D_Prestamos::~D_Prestamos()
{
	// Disconnect Events
	m_BtnBuscarC->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Prestamos::ClickBuscarClientes ), NULL, this );
	m_BtnBuscarJ->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Prestamos::ClickBuscarJuegos ), NULL, this );
	m_BtnCrear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Prestamos::ClickCrearA ), NULL, this );

}

V_Juegos::V_Juegos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_grillaJ = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grillaJ->CreateGrid( 0, 6 );
	m_grillaJ->EnableEditing( true );
	m_grillaJ->EnableGridLines( true );
	m_grillaJ->EnableDragGridSize( false );
	m_grillaJ->SetMargins( 0, 0 );

	// Columns
	m_grillaJ->SetColSize( 0, 50 );
	m_grillaJ->SetColSize( 1, 200 );
	m_grillaJ->SetColSize( 2, 80 );
	m_grillaJ->SetColSize( 3, 80 );
	m_grillaJ->SetColSize( 4, 80 );
	m_grillaJ->SetColSize( 5, 80 );
	m_grillaJ->EnableDragColMove( false );
	m_grillaJ->EnableDragColSize( true );
	m_grillaJ->SetColLabelSize( 30 );
	m_grillaJ->SetColLabelValue( 0, wxT("Id") );
	m_grillaJ->SetColLabelValue( 1, wxT("Nombre") );
	m_grillaJ->SetColLabelValue( 2, wxT("Precio") );
	m_grillaJ->SetColLabelValue( 3, wxT("Cantidad") );
	m_grillaJ->SetColLabelValue( 4, wxT("Disponibles") );
	m_grillaJ->SetColLabelValue( 5, wxT("Prestados") );
	m_grillaJ->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grillaJ->EnableDragRowSize( true );
	m_grillaJ->SetRowLabelSize( 0 );
	m_grillaJ->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grillaJ->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer11->Add( m_grillaJ, 1, wxEXPAND|wxLEFT, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_BtnNuevo = new wxButton( this, wxID_ANY, wxT("Nuevo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnNuevo, 0, wxALL, 5 );

	m_BtnPrecio = new wxButton( this, wxID_ANY, wxT("Modificar\nPrecio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnPrecio, 0, wxALL, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_BtnTodos = new wxButton( this, wxID_ANY, wxT("Todos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_BtnTodos, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer12->Add( bSizer13, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer11->Add( bSizer12, 0, wxEXPAND|wxLEFT, 5 );


	bSizer8->Add( bSizer11, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );

	m_BtnAgregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer56->Add( m_BtnAgregar, 0, wxALL, 5 );

	m_BtnQuitar = new wxButton( this, wxID_ANY, wxT("Quitar"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer56->Add( m_BtnQuitar, 0, wxALL, 5 );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );

	m_BtnPrestamos = new wxButton( this, wxID_ANY, wxT("Prestamos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_BtnPrestamos, 0, wxALL|wxALIGN_RIGHT, 5 );


	bSizer56->Add( bSizer59, 1, wxEXPAND, 5 );


	bSizer8->Add( bSizer56, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnNuevo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::ClickNuevoJ ), NULL, this );
	m_BtnPrecio->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::CambiarPrecio ), NULL, this );
	m_BtnTodos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::MostrarTodos ), NULL, this );
	m_BtnAgregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::AgregarUno ), NULL, this );
	m_BtnQuitar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::QuitarUno ), NULL, this );
	m_BtnPrestamos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::ClickVolverA ), NULL, this );
}

V_Juegos::~V_Juegos()
{
	// Disconnect Events
	m_BtnNuevo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::ClickNuevoJ ), NULL, this );
	m_BtnPrecio->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::CambiarPrecio ), NULL, this );
	m_BtnTodos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::MostrarTodos ), NULL, this );
	m_BtnAgregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::AgregarUno ), NULL, this );
	m_BtnQuitar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::QuitarUno ), NULL, this );
	m_BtnPrestamos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Juegos::ClickVolverA ), NULL, this );

}

D_Juegos::D_Juegos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer53->Add( m_staticText33, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextNom = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( m_TextNom, 1, wxALL, 5 );


	bSizer52->Add( bSizer53, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Precio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer54->Add( m_staticText34, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextPrecio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( m_TextPrecio, 0, wxALL, 5 );

	m_staticText35 = new wxStaticText( this, wxID_ANY, wxT("Cantidad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer54->Add( m_staticText35, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextCant = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( m_TextCant, 0, wxALL, 5 );


	bSizer52->Add( bSizer54, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxVERTICAL );

	m_BtnConfirmar = new wxButton( this, wxID_ANY, wxT("Confirmar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( m_BtnConfirmar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer52->Add( bSizer55, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer52 );
	this->Layout();
	bSizer52->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnConfirmar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Juegos::ClickConfirmar ), NULL, this );
}

D_Juegos::~D_Juegos()
{
	// Disconnect Events
	m_BtnConfirmar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Juegos::ClickConfirmar ), NULL, this );

}

D_GrillaJ::D_GrillaJ( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );

	m_GrillaJ = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaJ->CreateGrid( 0, 5 );
	m_GrillaJ->EnableEditing( true );
	m_GrillaJ->EnableGridLines( true );
	m_GrillaJ->EnableDragGridSize( false );
	m_GrillaJ->SetMargins( 200, 200 );

	// Columns
	m_GrillaJ->SetColSize( 0, 80 );
	m_GrillaJ->SetColSize( 1, 10 );
	m_GrillaJ->SetColSize( 2, 10 );
	m_GrillaJ->EnableDragColMove( false );
	m_GrillaJ->EnableDragColSize( true );
	m_GrillaJ->SetColLabelSize( 30 );
	m_GrillaJ->SetColLabelValue( 0, wxT("Id") );
	m_GrillaJ->SetColLabelValue( 1, wxT("Nombre") );
	m_GrillaJ->SetColLabelValue( 2, wxT("Precio") );
	m_GrillaJ->SetColLabelValue( 3, wxT("Cantidad") );
	m_GrillaJ->SetColLabelValue( 4, wxT("Disponibles") );
	m_GrillaJ->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaJ->EnableDragRowSize( true );
	m_GrillaJ->SetRowLabelSize( 30 );
	m_GrillaJ->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaJ->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer59->Add( m_GrillaJ, 0, wxALL, 5 );


	bSizer48->Add( bSizer59, 1, wxEXPAND, 5 );

	m_BtnElegir = new wxButton( this, wxID_ANY, wxT("Elegir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer48->Add( m_BtnElegir, 0, wxALL, 5 );


	this->SetSizer( bSizer48 );
	this->Layout();
	bSizer48->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnElegir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_GrillaJ::ClickElegir ), NULL, this );
}

D_GrillaJ::~D_GrillaJ()
{
	// Disconnect Events
	m_BtnElegir->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_GrillaJ::ClickElegir ), NULL, this );

}

V_Clientes::V_Clientes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_grillaC = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grillaC->CreateGrid( 0, 5 );
	m_grillaC->EnableEditing( true );
	m_grillaC->EnableGridLines( true );
	m_grillaC->EnableDragGridSize( false );
	m_grillaC->SetMargins( 0, 0 );

	// Columns
	m_grillaC->SetColSize( 0, 50 );
	m_grillaC->SetColSize( 1, 200 );
	m_grillaC->SetColSize( 2, 200 );
	m_grillaC->SetColSize( 3, 80 );
	m_grillaC->SetColSize( 4, 80 );
	m_grillaC->EnableDragColMove( false );
	m_grillaC->EnableDragColSize( true );
	m_grillaC->SetColLabelSize( 30 );
	m_grillaC->SetColLabelValue( 0, wxT("Id") );
	m_grillaC->SetColLabelValue( 1, wxT("Nombre y Apellido") );
	m_grillaC->SetColLabelValue( 2, wxT("Correo") );
	m_grillaC->SetColLabelValue( 3, wxT("Direccion") );
	m_grillaC->SetColLabelValue( 4, wxT("Estado") );
	m_grillaC->SetColLabelValue( 5, wxEmptyString );
	m_grillaC->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grillaC->EnableDragRowSize( true );
	m_grillaC->SetRowLabelSize( 0 );
	m_grillaC->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grillaC->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer11->Add( m_grillaC, 1, wxEXPAND|wxLEFT, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_BtnNuevo = new wxButton( this, wxID_ANY, wxT("Nuevo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnNuevo, 0, wxALL, 5 );

	m_BtnVE = new wxButton( this, wxID_ANY, wxT("Ver/Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnVE, 0, wxALL, 5 );

	m_BtnAB = new wxButton( this, wxID_ANY, wxT("Alta/Baja"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnAB, 0, wxALL, 5 );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );

	m_BtnPrestamos = new wxButton( this, wxID_ANY, wxT("Prestamos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_BtnPrestamos, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer12->Add( bSizer61, 1, wxEXPAND, 5 );


	bSizer11->Add( bSizer12, 0, wxEXPAND|wxLEFT, 5 );


	bSizer8->Add( bSizer11, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnNuevo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Clientes::ClickNuevoC ), NULL, this );
	m_BtnVE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Clientes::ClickVerEditC ), NULL, this );
	m_BtnAB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Clientes::ClickAltBajC ), NULL, this );
	m_BtnPrestamos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Clientes::ClickVolverA ), NULL, this );
}

V_Clientes::~V_Clientes()
{
	// Disconnect Events
	m_BtnNuevo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Clientes::ClickNuevoC ), NULL, this );
	m_BtnVE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Clientes::ClickVerEditC ), NULL, this );
	m_BtnAB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Clientes::ClickAltBajC ), NULL, this );
	m_BtnPrestamos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Clientes::ClickVolverA ), NULL, this );

}

D_GrillaC::D_GrillaC( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxVERTICAL );

	m_GrillaC = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_GrillaC->CreateGrid( 0, 4 );
	m_GrillaC->EnableEditing( true );
	m_GrillaC->EnableGridLines( true );
	m_GrillaC->EnableDragGridSize( false );
	m_GrillaC->SetMargins( 200, 200 );

	// Columns
	m_GrillaC->SetColSize( 0, 50 );
	m_GrillaC->SetColSize( 1, 200 );
	m_GrillaC->SetColSize( 2, 200 );
	m_GrillaC->SetColSize( 3, 80 );
	m_GrillaC->EnableDragColMove( false );
	m_GrillaC->EnableDragColSize( true );
	m_GrillaC->SetColLabelSize( 30 );
	m_GrillaC->SetColLabelValue( 0, wxT("Id") );
	m_GrillaC->SetColLabelValue( 1, wxT("Nombre y Apellido") );
	m_GrillaC->SetColLabelValue( 2, wxT("Correo") );
	m_GrillaC->SetColLabelValue( 3, wxT("Direccion") );
	m_GrillaC->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_GrillaC->EnableDragRowSize( true );
	m_GrillaC->SetRowLabelSize( 30 );
	m_GrillaC->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_GrillaC->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer58->Add( m_GrillaC, 0, wxALL, 5 );


	bSizer48->Add( bSizer58, 1, wxEXPAND, 5 );

	m_BtnElegir = new wxButton( this, wxID_ANY, wxT("Elegir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer48->Add( m_BtnElegir, 0, wxALL, 5 );


	this->SetSizer( bSizer48 );
	this->Layout();
	bSizer48->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnElegir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_GrillaC::ClickElegir ), NULL, this );
}

D_GrillaC::~D_GrillaC()
{
	// Disconnect Events
	m_BtnElegir->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_GrillaC::ClickElegir ), NULL, this );

}

D_Clientes::D_Clientes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Id"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer58->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextId = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_TextId, 0, wxALL, 5 );

	m_staticText36 = new wxStaticText( this, wxID_ANY, wxT("Clave"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	bSizer58->Add( m_staticText36, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextClave = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_TextClave, 1, wxALL, 5 );


	bSizer57->Add( bSizer58, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer59->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextNombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_TextNombre, 0, wxALL, 5 );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Apellido"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer59->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextApellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_TextApellido, 1, wxALL, 5 );


	bSizer57->Add( bSizer59, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Direccion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer60->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextDireccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer60->Add( m_TextDireccion, 1, wxALL, 5 );


	bSizer57->Add( bSizer60, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("DNI"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer61->Add( m_staticText26, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextDNI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_TextDNI, 1, wxALL, 5 );

	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Telefono"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	bSizer61->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextTelefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_TextTelefono, 1, wxALL, 5 );


	bSizer57->Add( bSizer61, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Correo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer62->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextCorreo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer62->Add( m_TextCorreo, 1, wxALL, 5 );


	bSizer57->Add( bSizer62, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxVERTICAL );

	m_BtnConfirmar = new wxButton( this, wxID_ANY, wxT("Confirmar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( m_BtnConfirmar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer57->Add( bSizer63, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer57 );
	this->Layout();
	bSizer57->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnConfirmar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Clientes::ClickConfirmar ), NULL, this );
}

D_Clientes::~D_Clientes()
{
	// Disconnect Events
	m_BtnConfirmar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Clientes::ClickConfirmar ), NULL, this );

}

V_Usuarios::V_Usuarios( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	m_grillaU = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grillaU->CreateGrid( 0, 5 );
	m_grillaU->EnableEditing( true );
	m_grillaU->EnableGridLines( true );
	m_grillaU->EnableDragGridSize( false );
	m_grillaU->SetMargins( 0, 0 );

	// Columns
	m_grillaU->SetColSize( 0, 50 );
	m_grillaU->SetColSize( 1, 200 );
	m_grillaU->SetColSize( 2, 120 );
	m_grillaU->SetColSize( 3, 120 );
	m_grillaU->SetColSize( 4, 80 );
	m_grillaU->EnableDragColMove( false );
	m_grillaU->EnableDragColSize( true );
	m_grillaU->SetColLabelSize( 30 );
	m_grillaU->SetColLabelValue( 0, wxT("Id") );
	m_grillaU->SetColLabelValue( 1, wxT("Nombre y Apellido") );
	m_grillaU->SetColLabelValue( 2, wxT("Usuario") );
	m_grillaU->SetColLabelValue( 3, wxT("Direccion") );
	m_grillaU->SetColLabelValue( 4, wxT("Estado") );
	m_grillaU->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grillaU->EnableDragRowSize( true );
	m_grillaU->SetRowLabelSize( 0 );
	m_grillaU->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grillaU->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer11->Add( m_grillaU, 1, wxEXPAND|wxLEFT, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_BtnNuevo = new wxButton( this, wxID_ANY, wxT("Nuevo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnNuevo, 0, wxALL, 5 );

	m_BtnVE = new wxButton( this, wxID_ANY, wxT("Ver/Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnVE, 0, wxALL, 5 );

	m_BtnAB = new wxButton( this, wxID_ANY, wxT("Alta/Baja"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_BtnAB, 0, wxALL, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_BtnPrestamos = new wxButton( this, wxID_ANY, wxT("Prestamos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_BtnPrestamos, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer12->Add( bSizer13, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer11->Add( bSizer12, 0, wxEXPAND|wxLEFT, 5 );


	bSizer8->Add( bSizer11, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_BtnNuevo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Usuarios::ClickNuevoU ), NULL, this );
	m_BtnVE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Usuarios::ClickVerEditU ), NULL, this );
	m_BtnAB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Usuarios::ClickAltaBajaU ), NULL, this );
	m_BtnPrestamos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Usuarios::ClickVolverP ), NULL, this );
}

V_Usuarios::~V_Usuarios()
{
	// Disconnect Events
	m_BtnNuevo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Usuarios::ClickNuevoU ), NULL, this );
	m_BtnVE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Usuarios::ClickVerEditU ), NULL, this );
	m_BtnAB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Usuarios::ClickAltaBajaU ), NULL, this );
	m_BtnPrestamos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( V_Usuarios::ClickVolverP ), NULL, this );

}

D_Usuarios::D_Usuarios( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Id"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer58->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextId = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_TextId, 0, wxALL, 5 );

	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer( wxVERTICAL );

	m_esAdmin = new wxCheckBox( this, wxID_ANY, wxT("Admin"), wxDefaultPosition, wxDefaultSize, 0 );
	m_esAdmin->SetValue(true);
	bSizer64->Add( m_esAdmin, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );


	bSizer58->Add( bSizer64, 1, wxALIGN_CENTER_VERTICAL, 5 );


	bSizer57->Add( bSizer58, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer581;
	bSizer581 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("Contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	bSizer581->Add( m_staticText51, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextContra = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer581->Add( m_TextContra, 0, wxALL, 5 );


	bSizer57->Add( bSizer581, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer601;
	bSizer601 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer601->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextNombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer601->Add( m_TextNombre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer59->Add( bSizer601, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer611;
	bSizer611 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Apellido"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer611->Add( m_staticText24, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextApellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer611->Add( m_TextApellido, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer59->Add( bSizer611, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer57->Add( bSizer59, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Direccion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer60->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextDireccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer60->Add( m_TextDireccion, 1, wxALL, 5 );


	bSizer57->Add( bSizer60, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("DNI"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer61->Add( m_staticText26, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_TextDNI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_TextDNI, 1, wxALL, 5 );


	bSizer57->Add( bSizer61, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxVERTICAL );

	m_BtnConfirmar = new wxButton( this, wxID_ANY, wxT("Confirmar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( m_BtnConfirmar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer57->Add( bSizer63, 1, wxEXPAND, 5 );

	m_radioBtn1 = new wxRadioButton( this, wxID_ANY, wxT("RadioBtn"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer57->Add( m_radioBtn1, 0, wxALL, 5 );


	this->SetSizer( bSizer57 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_esAdmin->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( D_Usuarios::esAdmin ), NULL, this );
	m_BtnConfirmar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Usuarios::ClickConfirmar ), NULL, this );
}

D_Usuarios::~D_Usuarios()
{
	// Disconnect Events
	m_esAdmin->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( D_Usuarios::esAdmin ), NULL, this );
	m_BtnConfirmar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( D_Usuarios::ClickConfirmar ), NULL, this );

}
