#include "Ven_Clientes.h"
#include "Ven_Prestamos.h"
#include "Cliente.h"
#include <sstream>
#include "VenE_Clientes.h"
#include "string_conv.h"
using namespace std;

Ven_Clientes::Ven_Clientes(Administradora *Admin) : V_Clientes(nullptr), m_Admin(Admin) {
	RefrescarGrilla();
}

Ven_Clientes::~Ven_Clientes() {
	
}

void Ven_Clientes::ClickNuevoC( wxCommandEvent& event )  {
	VenE_Clientes win(this,m_Admin);
	if (win.ShowModal());
		RefrescarGrilla();
}

void Ven_Clientes::ClickVerEditC( wxCommandEvent& event )  {
	string id = wx_to_std(m_grillaC->GetCellValue(m_grillaC->GetGridCursorRow(),0));
	VenE_Clientes win(this,m_Admin,atoi(id.c_str())-1,1);
	if (win.ShowModal());
		RefrescarGrilla();
}

void Ven_Clientes::ClickAltBajC( wxCommandEvent& event )  {
	m_Admin->verClientesPosVector(m_grillaC->GetGridCursorRow()).cambiar_estado();
	m_Admin->GuardarListaClientes();
	RefrescarGrilla();
}

void Ven_Clientes::ClickVolverA( wxCommandEvent& event )  {
	Ven_Prestamos *win = new Ven_Prestamos(m_Admin);
	win->Show();
	Close();
}

void Ven_Clientes::RefrescarGrilla ( ) {
	if (m_grillaC->GetNumberRows() != 0)
		m_grillaC->DeleteRows(0,m_grillaC->GetNumberRows());
	for(unsigned int i=0;i<m_Admin->CantidadClientes();i++) { 
		Cliente &c = m_Admin->verClientesPosVector(i);
		m_grillaC->AppendRows();
		
		stringstream id;
		id<<c.verId();
		m_grillaC->SetCellValue(i,0,id.str());
		
		string nombre(c.verNombre());
		string apellido(c.verApellido());
		m_grillaC->SetCellValue(i,1,apellido + ", " + nombre);
		
		string correo(c.verCorreo());
		m_grillaC->SetCellValue(i,2,correo);
		
		string direccion(c.verDireccion());
		m_grillaC->SetCellValue(i,3,direccion);
		
		if(c.estaHabilitado()){
			m_grillaC->SetCellValue(i,4,"Habilitado");
		}else{
			m_grillaC->SetCellValue(i,4,"No habilitado");
		}
		
		if(!c.estaHabilitado()){
			m_grillaC->SetCellBackgroundColour(i,0,wxColour(255,0,0,255));
//			m_grillaC->SetCellBackgroundColour(i,1,wxColour(255,0,0,255));
//			m_grillaC->SetCellBackgroundColour(i,2,wxColour(255,0,0,255));
//			m_grillaC->SetCellBackgroundColour(i,3,wxColour(255,0,0,255));
//			m_grillaC->SetCellBackgroundColour(i,4,wxColour(255,0,0,255));
		}
	}	
}

