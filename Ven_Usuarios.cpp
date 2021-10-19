#include "Ven_Usuarios.h"
#include "Ven_Prestamos.h"
#include <sstream>
#include "VenE_Usuarios.h"
#include "string_conv.h"
using namespace std;

Ven_Usuarios::Ven_Usuarios(Administradora *Admin) : V_Usuarios(nullptr), m_Admin(Admin) {
	RefrescarGrilla();
}

Ven_Usuarios::~Ven_Usuarios() {
	
}

void Ven_Usuarios::ClickNuevoU( wxCommandEvent& event )  {
	VenE_Usuarios win(this, m_Admin);
	if (win.ShowModal())
		RefrescarGrilla();
}

void Ven_Usuarios::ClickVerEditU( wxCommandEvent& event )  {
	//getCellValue sacamos un valor de 0(id) y la fila que tenemos fijada
	string id = wx_to_std(m_grillaU->GetCellValue(m_grillaU->GetGridCursorRow(),0));
	VenE_Usuarios win(this,m_Admin,atoi(id.c_str())-1,1);
	if(win.ShowModal())
		RefrescarGrilla();
}

void Ven_Usuarios::ClickAltaBajaU( wxCommandEvent& event )  {
	m_Admin->verUsuariosPosVector(m_grillaU->GetGridCursorRow()).CambiarEstado();
	m_Admin->GuardarListaUsuarios();
	RefrescarGrilla();
}


void Ven_Usuarios::ClickVolverP( wxCommandEvent& event )  {
	Ven_Prestamos *win = new Ven_Prestamos(m_Admin);
	win->Show();
	Close();
}

void Ven_Usuarios::RefrescarGrilla () {
	if (m_grillaU->GetNumberRows() != 0)
		m_grillaU->DeleteRows(0,m_grillaU->GetNumberRows());
	for(unsigned int i=0;i<m_Admin->CantidadUsuarios();i++) { 
		Usuario &u = m_Admin->verUsuariosPosVector(i);
		m_grillaU->AppendRows();
		
		stringstream id;
		id<<u.verId();
		m_grillaU->SetCellValue(i,0,id.str());
		
		string nombre(u.verNombre());
		string apellido(u.verApellido());
		m_grillaU->SetCellValue(i,1,apellido + ", " + nombre);
		
		string usuario(u.verNombreUsuario());
		m_grillaU->SetCellValue(i,2,usuario);
		
		string direccion(u.verDireccion());
		m_grillaU->SetCellValue(i,3,direccion);
		
		if(u.esAdmin()){
			m_grillaU->SetCellValue(i,4,"Admin");
		}else{
			m_grillaU->SetCellValue(i,4,"No Admin");
			m_grillaU->SetCellBackgroundColour(i,0,wxColour(255,0,0,255));
		}
	}
}

