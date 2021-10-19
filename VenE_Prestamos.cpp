#include "VenE_Prestamos.h"
#include "Alquiler.h"
#include "Cliente.h"
#include "Usuario.h"
#include "VideoJuego.h"
#include <sstream>
#include "VenE_GrillaClientes.h"
#include "VenE_GrillaJuegos.h"
#include <ctime>
#include "string_conv.h"
#include <wx/msgdlg.h>
using namespace std;

VenE_Prestamos::VenE_Prestamos(wxWindow *parent, Administradora *admin) : D_Prestamos(parent), m_Admin(admin) {
	m_textNomyApe->Disable();
	m_TextId->Disable();
	m_TextNomJ->Disable();
	m_TextFechI->Disable();
	m_TextFechF->Disable();
	
	time_t actual;
	time(&actual);
	tm fecha_ini = *localtime(&actual);
	
	//Le sumo a los meses y anios para que muestre la fecha actual
	fecha_ini.tm_mon = fecha_ini.tm_mon + 1;
	fecha_ini.tm_year = fecha_ini.tm_year + 1900; 
	
	stringstream strFechaIni, strFechaFin;
	strFechaIni<<fecha_ini.tm_mday<<"/"<<fecha_ini.tm_mon<<"/"<<fecha_ini.tm_year;
	strFechaFin<<fecha_ini.tm_mday+3<<"/"<<fecha_ini.tm_mon<<"/"<<fecha_ini.tm_year;
	m_TextFechI->SetValue(strFechaIni.str());
	m_TextFechF->SetValue(strFechaFin.str());
}

VenE_Prestamos::~VenE_Prestamos() {
	
}

void VenE_Prestamos::ClickCrearA( wxCommandEvent& event )  {
	
	string errores;
	if(m_Admin->verIdClienteActual()==-1) errores+="Seleccione un Cliente\n";
	if(m_Admin->verIdJuegoActual()==-1) errores+="Seleccione un Juego\n";
	
	string contra = wx_to_std(m_TextCodigo->GetValue());
	if(errores.size()){
		wxMessageBox(std_to_wx(errores),"ERRORES",wxOK|wxICON_ERROR,this);
	}else{
		if (atoi(contra.c_str()) == m_Admin->BuscarClientePorId(m_Admin->verIdClienteActual())->verClave()){
			if(m_Admin->BuscarJuegoPorId(m_Admin->verIdJuegoActual())->verDisponibles() > 0){
				m_Admin->NuevoAlquiler(m_Admin->verIdClienteActual(),
									   m_Admin->verIdUsuarioActual(),
									   m_Admin->verIdJuegoActual(),
									   3
									   );
				m_Admin->GuardarListaAlquileres();
				m_Admin->GuardarListaJuegos();
				m_Admin->idClienteActual(-1);//Vuelvo a convertir en -1 porque ya los use
				m_Admin->idJuegoActual(-1);
				EndModal(1);
			}else{
				wxMessageBox(std_to_wx("No hay stock del juego"),std_to_wx("Error"));
			}
		}else{
			wxMessageBox(std_to_wx("Contraseña incorrecta o vacia"),std_to_wx("Error"));
		}
	}
}

void VenE_Prestamos::ClickBuscarClientes( wxCommandEvent& event )  {
	VenE_GrillaClientes *win = new VenE_GrillaClientes(this,m_Admin);
	if(win->ShowModal()){
		string nombre = m_Admin->BuscarClientePorId(m_Admin->verIdClienteActual())->verNombre();
		string apellido = m_Admin->BuscarClientePorId(m_Admin->verIdClienteActual())->verApellido();
		m_textNomyApe->SetValue(apellido + ", " + nombre);
		stringstream id; id<<m_Admin->BuscarClientePorId(m_Admin->verIdClienteActual())->verId();
		m_TextId->SetValue(id.str());
		
	}
	
}

void VenE_Prestamos::ClickBuscarJuegos( wxCommandEvent& event )  {
	VenE_GrillaJuegos *win = new VenE_GrillaJuegos(this,m_Admin);
	if(win->ShowModal()){
		m_TextNomJ->SetValue(m_Admin->BuscarJuegoPorId(m_Admin->verIdJuegoActual())->verNombre());
	}
}

