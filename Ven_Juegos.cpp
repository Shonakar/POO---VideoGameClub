#include "Ven_Juegos.h"
#include "Ven_Prestamos.h"
#include <sstream>
#include "VenE_Juegos.h"
#include "string_conv.h"
#include <wx/msgdlg.h>
using namespace std;

Ven_Juegos::Ven_Juegos(Administradora *admin) : V_Juegos(nullptr),m_Admin(admin) {
	RefrescarGrilla(true);
	if(!m_Admin->verUsuarioActivo()->esAdmin()){
		m_BtnNuevo->Disable();
		m_BtnAgregar->Disable();
		m_BtnQuitar->Disable();
		m_BtnPrecio->Disable();
	}
}

Ven_Juegos::~Ven_Juegos() {
	
}

void Ven_Juegos::ClickNuevoJ( wxCommandEvent& event )  {
	VenE_Juegos win(this,m_Admin);
	if (win.ShowModal())
		RefrescarGrilla(true);
}
void Ven_Juegos::CambiarPrecio( wxCommandEvent& event )  {
	//pos es el id
	string str_pos = wx_to_std(m_grillaJ->GetCellValue(m_grillaJ->GetGridCursorRow(),0));
	VenE_Juegos win(this,m_Admin,atoi(str_pos.c_str())-1,1);
	if (win.ShowModal())
		RefrescarGrilla(true);
	
}

void Ven_Juegos::ClickVolverA( wxCommandEvent& event )  {
	Ven_Prestamos *win = new Ven_Prestamos(m_Admin);
	win->Show();
	Close();
}


void Ven_Juegos::RefrescarGrilla ( bool todos ) {
	int cont = 0;
	if (m_grillaJ->GetNumberRows()!=0)
		m_grillaJ->DeleteRows(0,m_grillaJ->GetNumberRows());
	if (todos == true ){
		for(int i=0;i<m_Admin->CantidadJuegos();i++) {
			VideoJuego &a = m_Admin->verJuegosPosVector(i);
			m_grillaJ->AppendRows();
			
			stringstream id;
			id<<a.verId();
			m_grillaJ->SetCellValue(i,0,id.str());
			
			string nombreJ(a.verNombre());
			m_grillaJ->SetCellValue(i,1,nombreJ);
			
			stringstream precio;
			precio<<a.verPrecio();
			m_grillaJ->SetCellValue(i,2,precio.str());
			
			stringstream cantidad;
			cantidad<<a.verStock();
			m_grillaJ->SetCellValue(i,3,cantidad.str());
			
			stringstream disponible;
			disponible<<(a.verStock()-a.verPrestados());
			m_grillaJ->SetCellValue(i,4,disponible.str());
			
			stringstream prestados;
			prestados<<a.verPrestados();
			m_grillaJ->SetCellValue(i,5,prestados.str());
			
			if((a.verStock()-a.verPrestados())==0){
				m_grillaJ->SetCellBackgroundColour(i,0,wxColour(255,0,0,255));
			}
		}
	}
	else{
		for(int i=0;i<m_Admin->CantidadJuegos();i++) { 
			
			VideoJuego &a = m_Admin->verJuegosPosVector(i);

			string nombreJ(a.verNombre());
			
			stringstream precio;
			precio<<a.verPrecio();
			
			stringstream cantidad;
			cantidad<<a.verStock();
			
			stringstream disponible;
			disponible<<(a.verStock()-a.verPrestados());
			
			stringstream prestados;
			prestados<<a.verPrestados();
			
			stringstream id;
			id<<a.verId();
			
			//Si todavia quedan stock los mostramos
			//el contador es el size de los juegos disponibles
			if((a.verStock()-a.verPrestados())!=0){
				m_grillaJ->AppendRows();
				m_grillaJ->SetCellValue(cont,0,id.str());
				m_grillaJ->SetCellValue(cont,1,nombreJ);
				m_grillaJ->SetCellValue(cont,2,precio.str());
				m_grillaJ->SetCellValue(cont,3,cantidad.str());
				m_grillaJ->SetCellValue(cont,4,disponible.str());
				m_grillaJ->SetCellValue(cont,5,prestados.str());
				cont++;
			}
			else{
				continue;
			}
		}
	}
}

void Ven_Juegos::AgregarUno( wxCommandEvent& event )  {
	m_Admin->verJuegosPosVector(m_grillaJ->GetGridCursorRow()).AgregarUno();
	m_Admin->GuardarListaJuegos();
	RefrescarGrilla(true);
}

void Ven_Juegos::QuitarUno( wxCommandEvent& event )  {
	if (m_Admin->verJuegosPosVector(m_grillaJ->GetGridCursorRow()).verDisponibles() > 0){
		m_Admin->verJuegosPosVector(m_grillaJ->GetGridCursorRow()).QuitarUno();
		m_Admin->GuardarListaJuegos();
		RefrescarGrilla(true);
	}
	else{
		wxMessageBox(std_to_wx("No se pueden quitar mas\nStock = 0 o Estan prestados"),std_to_wx("Error"));
	}
}

void Ven_Juegos::MostrarTodos( wxCommandEvent& event )  {
	if (Todos == false){
		Todos = true;
		RefrescarGrilla(Todos);
	}
	else{
		Todos = false;
		RefrescarGrilla(Todos);
	}
}


