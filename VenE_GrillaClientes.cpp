#include "VenE_GrillaClientes.h"
#include <sstream>
#include "string_conv.h"
#include <wx/msgdlg.h>
using namespace std;

VenE_GrillaClientes::VenE_GrillaClientes(wxWindow *parent, Administradora *admin) : D_GrillaC(parent), m_Admin(admin) {
	for(unsigned int i=0;i<m_Admin->CantidadClientes();i++) { 
		Cliente &a = m_Admin->verClientesPosVector(i);
		m_GrillaC->AppendRows();
		
		stringstream id;
		id<<a.verId();
		m_GrillaC->SetCellValue(i,0,id.str());
		
		string nombreC(a.verNombre());
		string apellidoC(a.verApellido());
		m_GrillaC->SetCellValue(i,1, apellidoC + ", " + nombreC);
		
		string correoC(a.verCorreo());
		m_GrillaC->SetCellValue(i,2,correoC);
		
		string direccionC(a.verDireccion());
		m_GrillaC->SetCellValue(i,3,direccionC);
		if(!a.estaHabilitado()){
			m_GrillaC->SetCellBackgroundColour(i,0,wxColour(255,0,0,255));
		}
	}
}

VenE_GrillaClientes::~VenE_GrillaClientes() {
	
}

void VenE_GrillaClientes::ClickElegir( wxCommandEvent& event )  {
	string idStr = wx_to_std(m_GrillaC->GetCellValue(m_GrillaC->GetGridCursorRow(),0));
	if(m_Admin->BuscarClientePorId(atoi(idStr.c_str()))->estaHabilitado()){
		m_Admin->idClienteActual(atoi(m_GrillaC->GetCellValue(m_GrillaC->GetGridCursorRow(),0)));
		EndModal(1);
	}else{
		wxMessageBox(std_to_wx("Este cliente esta sancionado"),std_to_wx("Error"));
	}
}

