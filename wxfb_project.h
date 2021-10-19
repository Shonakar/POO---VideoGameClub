///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class V_InicioS
///////////////////////////////////////////////////////////////////////////////
class V_InicioS : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_TextUser;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_TextPass;
		wxButton* m_BtnCerrar;
		wxButton* m_BtnIniciar;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickCerrar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickIniciar( wxCommandEvent& event ) { event.Skip(); }


	public:

		V_InicioS( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = 0|wxTAB_TRAVERSAL );

		~V_InicioS();

};

///////////////////////////////////////////////////////////////////////////////
/// Class V_Prestamos
///////////////////////////////////////////////////////////////////////////////
class V_Prestamos : public wxFrame
{
	private:

	protected:
		wxStaticText* m_FechaActual;
		wxGrid* m_GrillaA;
		wxButton* m_BtnNuevo;
		wxButton* m_BtnFin;
		wxButton* m_BtnInfUsu;
		wxButton* m_BtnInfClien;
		wxButton* m_BtnTodos;
		wxButton* m_BtnJuegos;
		wxButton* m_BtnClientes;
		wxButton* m_BtnUsuarios;
		wxButton* m_BtnCerrar;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickNuevoA( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickFinalizarA( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickInfUsuarioA( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickInfClienA( wxCommandEvent& event ) { event.Skip(); }
		virtual void MostraTodos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickListaJuegos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickListaClientes( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickListaUsuarios( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCerrarSesion( wxCommandEvent& event ) { event.Skip(); }


	public:

		V_Prestamos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,400 ), long style = 0|wxTAB_TRAVERSAL );

		~V_Prestamos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class D_Prestamos
///////////////////////////////////////////////////////////////////////////////
class D_Prestamos : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText33;
		wxStaticText* m_staticText14;
		wxTextCtrl* m_textNomyApe;
		wxButton* m_BtnBuscarC;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_TextId;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_TextCodigo;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_TextNomJ;
		wxButton* m_BtnBuscarJ;
		wxStaticText* m_staticText18;
		wxStaticText* m_staticText19;
		wxTextCtrl* m_TextFechI;
		wxStaticText* m_staticText20;
		wxTextCtrl* m_TextFechF;
		wxButton* m_BtnCrear;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickBuscarClientes( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscarJuegos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCrearA( wxCommandEvent& event ) { event.Skip(); }


	public:

		D_Prestamos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~D_Prestamos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class V_Juegos
///////////////////////////////////////////////////////////////////////////////
class V_Juegos : public wxFrame
{
	private:

	protected:
		wxGrid* m_grillaJ;
		wxButton* m_BtnNuevo;
		wxButton* m_BtnPrecio;
		wxButton* m_BtnTodos;
		wxButton* m_BtnAgregar;
		wxButton* m_BtnQuitar;
		wxButton* m_BtnPrestamos;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickNuevoJ( wxCommandEvent& event ) { event.Skip(); }
		virtual void CambiarPrecio( wxCommandEvent& event ) { event.Skip(); }
		virtual void MostrarTodos( wxCommandEvent& event ) { event.Skip(); }
		virtual void AgregarUno( wxCommandEvent& event ) { event.Skip(); }
		virtual void QuitarUno( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVolverA( wxCommandEvent& event ) { event.Skip(); }


	public:

		V_Juegos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,400 ), long style = 0|wxTAB_TRAVERSAL );

		~V_Juegos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class D_Juegos
///////////////////////////////////////////////////////////////////////////////
class D_Juegos : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText33;
		wxTextCtrl* m_TextNom;
		wxStaticText* m_staticText34;
		wxTextCtrl* m_TextPrecio;
		wxStaticText* m_staticText35;
		wxTextCtrl* m_TextCant;
		wxButton* m_BtnConfirmar;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickConfirmar( wxCommandEvent& event ) { event.Skip(); }


	public:

		D_Juegos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~D_Juegos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class D_GrillaJ
///////////////////////////////////////////////////////////////////////////////
class D_GrillaJ : public wxDialog
{
	private:

	protected:
		wxGrid* m_GrillaJ;
		wxButton* m_BtnElegir;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickElegir( wxCommandEvent& event ) { event.Skip(); }


	public:

		D_GrillaJ( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~D_GrillaJ();

};

///////////////////////////////////////////////////////////////////////////////
/// Class V_Clientes
///////////////////////////////////////////////////////////////////////////////
class V_Clientes : public wxFrame
{
	private:

	protected:
		wxGrid* m_grillaC;
		wxButton* m_BtnNuevo;
		wxButton* m_BtnVE;
		wxButton* m_BtnAB;
		wxButton* m_BtnPrestamos;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickNuevoC( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVerEditC( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAltBajC( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVolverA( wxCommandEvent& event ) { event.Skip(); }


	public:

		V_Clientes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,400 ), long style = 0|wxTAB_TRAVERSAL );

		~V_Clientes();

};

///////////////////////////////////////////////////////////////////////////////
/// Class D_GrillaC
///////////////////////////////////////////////////////////////////////////////
class D_GrillaC : public wxDialog
{
	private:

	protected:
		wxGrid* m_GrillaC;
		wxButton* m_BtnElegir;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickElegir( wxCommandEvent& event ) { event.Skip(); }


	public:

		D_GrillaC( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~D_GrillaC();

};

///////////////////////////////////////////////////////////////////////////////
/// Class D_Clientes
///////////////////////////////////////////////////////////////////////////////
class D_Clientes : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText22;
		wxTextCtrl* m_TextId;
		wxStaticText* m_staticText36;
		wxTextCtrl* m_TextClave;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_TextNombre;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_TextApellido;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_TextDireccion;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_TextDNI;
		wxStaticText* m_staticText27;
		wxTextCtrl* m_TextTelefono;
		wxStaticText* m_staticText28;
		wxTextCtrl* m_TextCorreo;
		wxButton* m_BtnConfirmar;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickConfirmar( wxCommandEvent& event ) { event.Skip(); }


	public:

		D_Clientes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~D_Clientes();

};

///////////////////////////////////////////////////////////////////////////////
/// Class V_Usuarios
///////////////////////////////////////////////////////////////////////////////
class V_Usuarios : public wxFrame
{
	private:

	protected:
		wxGrid* m_grillaU;
		wxButton* m_BtnNuevo;
		wxButton* m_BtnVE;
		wxButton* m_BtnAB;
		wxButton* m_BtnPrestamos;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickNuevoU( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVerEditU( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAltaBajaU( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVolverP( wxCommandEvent& event ) { event.Skip(); }


	public:

		V_Usuarios( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,400 ), long style = 0|wxTAB_TRAVERSAL );

		~V_Usuarios();

};

///////////////////////////////////////////////////////////////////////////////
/// Class D_Usuarios
///////////////////////////////////////////////////////////////////////////////
class D_Usuarios : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText22;
		wxTextCtrl* m_TextId;
		wxCheckBox* m_esAdmin;
		wxStaticText* m_staticText51;
		wxTextCtrl* m_TextContra;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_TextNombre;
		wxStaticText* m_staticText24;
		wxTextCtrl* m_TextApellido;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_TextDireccion;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_TextDNI;
		wxButton* m_BtnConfirmar;
		wxRadioButton* m_radioBtn1;

		// Virtual event handlers, overide them in your derived class
		virtual void esAdmin( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickConfirmar( wxCommandEvent& event ) { event.Skip(); }


	public:

		D_Usuarios( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 444,280 ), long style = wxDEFAULT_DIALOG_STYLE );
		~D_Usuarios();

};

