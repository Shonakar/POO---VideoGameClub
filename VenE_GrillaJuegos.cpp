#include "VenE_GrillaJuegos.h"
#include <sstream>
#include "string_conv.h"
#include <wx/msgdlg.h>
using namespace std;

VenE_GrillaJuegos::VenE_GrillaJuegos(wxWindow *parent, Administradora *admin) : D_GrillaJ(parent), m_Admin(admin) {
	for(unsigned int i=0;i<m_Admin->CantidadJuegos();i++) { 
		VideoJuego &a = m_Admin->verJuegosPosVector(i);
		m_GrillaJ->AppendRows();
		
		stringstream id;
		id<<a.verId();
		m_GrillaJ->SetCellValue(i,0,id.str());
		
		string nombreJ(a.verNombre());
		m_GrillaJ->SetCellValue(i,1,nombreJ);
		
		stringstream precio;
		precio<<a.verPrecio();
		m_GrillaJ->SetCellValue(i,2,precio.str());
		
		stringstream cantidad;
		cantidad<<a.verStock();
		m_GrillaJ->SetCellValue(i,3,cantidad.str());
		
		stringstream disponible;
		disponible<<(a.verStock()-a.verPrestados());
		m_GrillaJ->SetCellValue(i,4,disponible.str());
		
		
		if((a.verStock()-a.verPrestados())==0){
			m_GrillaJ->SetCellBackgroundColour(i,0,wxColour(255,0,0,255));
		}
		
	}

}

VenE_GrillaJuegos::~VenE_GrillaJuegos() {
	
}

void VenE_GrillaJuegos::ClickElegir( wxCommandEvent& event )  {
	if( atoi(m_GrillaJ->GetCellValue(m_GrillaJ->GetGridCursorRow(),4)) > 0){
		m_Admin->idJuegoActual(atoi(m_GrillaJ->GetCellValue(m_GrillaJ->GetGridCursorRow(),0)));
		EndModal(1);
	}else{
		wxMessageBox(std_to_wx("No hay Stock"),std_to_wx("Error"));
	}
	
}

