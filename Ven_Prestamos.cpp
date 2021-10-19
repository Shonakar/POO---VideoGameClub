#include "Ven_Prestamos.h"
#include <sstream>
#include "VenE_Prestamos.h"
#include "Ven_Inicio.h"
#include "Ven_Juegos.h"
#include "Ven_Clientes.h"
#include "Ven_Usuarios.h"
#include "string_conv.h"
#include "VenE_Clientes.h"
#include "VenE_Usuarios.h"
#include <wx/msgdlg.h>
#include <wx/colour.h>
using namespace std;

Ven_Prestamos::Ven_Prestamos(Administradora *Admin) : V_Prestamos(nullptr), m_Admin(Admin) {
	m_Admin->CargarListaClientes();
	m_Admin->CargarListaJuegos();
	m_Admin->CargarListaAlquileres();
	
	m_FechaActual->SetLabel(m_Admin->verFechaActual());
	RefrescarGrilla(false);
	
	if (!m_Admin->verUsuarioActivo()->esAdmin()){
		m_BtnUsuarios->Disable();
	}
}

void Ven_Prestamos::ClickNuevoA( wxCommandEvent& event )  {
	VenE_Prestamos win(this,m_Admin);
	if (win.ShowModal()==1)
		RefrescarGrilla(false);
}

void Ven_Prestamos::ClickFinalizarA( wxCommandEvent& event )  {
	
	string idC = wx_to_std(m_GrillaA->GetCellValue(m_GrillaA->GetGridCursorRow(),0));
	string idJ = wx_to_std(m_GrillaA->GetCellValue(m_GrillaA->GetGridCursorRow(),4));
	int pos = m_Admin->buscarPosAlquilerPorIds(atoi(idC.c_str()),atoi(idJ.c_str()));
	int filaActual = m_GrillaA->GetGridCursorRow();
	if (m_Admin->verAlquileresPosVector(pos).verEstado() == Terminado){
		wxMessageBox(std_to_wx("Este prestamo ya esta finalizado"),std_to_wx("Error"));
	}
	else if(m_Admin->verAlquileresPosVector(pos).verEstado() == Vencido){
		int resultado = wxMessageBox(c_to_wx("El prestamo esta vencido \n¿Quiere sancionar al cliente?"),m_GrillaA->GetCellValue(filaActual,1),wxYES_NO);
		if (resultado == wxYES){
			m_Admin->TerminarAlquiler(pos);
			m_Admin->BuscarClientePorId(atoi(idC.c_str()))->cambiar_estado();
			m_Admin->GuardarListaAlquileres();
			m_Admin->GuardarListaJuegos();
			m_Admin->GuardarListaClientes();
			RefrescarGrilla(false);
		}else{
			m_Admin->TerminarAlquiler(pos);
			m_Admin->GuardarListaAlquileres();
			m_Admin->GuardarListaJuegos();
			RefrescarGrilla(false);
		}
	}
	else if(m_Admin->verAlquileresPosVector(pos).verEstado() == Activo){
		int resultado = wxMessageBox(c_to_wx("¿Desea finalizar el prestamo?"),m_GrillaA->GetCellValue(filaActual,1),wxYES_NO);
		if (resultado == wxYES){
			m_Admin->TerminarAlquiler(pos);
			m_Admin->GuardarListaAlquileres();
			m_Admin->GuardarListaJuegos();
			RefrescarGrilla(false);
		}
	}
}
void Ven_Prestamos::ClickInfUsuarioA( wxCommandEvent& event )  {
	string id = wx_to_std(m_GrillaA->GetCellValue(m_GrillaA->GetGridCursorRow(),2));
	VenE_Usuarios win(this,m_Admin,atoi(id.c_str())-1,2);
	win.ShowModal();
}

void Ven_Prestamos::ClickInfClienA( wxCommandEvent& event )  {
	string id = wx_to_std(m_GrillaA->GetCellValue(m_GrillaA->GetGridCursorRow(),0));
	VenE_Clientes win(this,m_Admin,atoi(id.c_str())-1,2);
	win.ShowModal();
}

void Ven_Prestamos::ClickListaJuegos( wxCommandEvent& event )  {
	Ven_Juegos *win = new Ven_Juegos(m_Admin);
	win->Show();
	Close(false);
}

void Ven_Prestamos::ClickListaClientes( wxCommandEvent& event )  {
	Ven_Clientes *win = new Ven_Clientes(m_Admin);
	win->Show();
	Close(false);
}

void Ven_Prestamos::ClickListaUsuarios( wxCommandEvent& event )  {
	Ven_Usuarios *win = new Ven_Usuarios(m_Admin);
	win->Show();
	Close(false);
}

void Ven_Prestamos::ClickCerrarSesion( wxCommandEvent& event )  {
	m_Admin->GuardarListaClientes();
	m_Admin->GuardarListaUsuarios();
	m_Admin->GuardarListaJuegos();
	m_Admin->GuardarListaAlquileres();
	Ven_Inicio *win = new Ven_Inicio(m_Admin);
	win->Show();
	Close(false);
}


void Ven_Prestamos::RefrescarGrilla ( bool todos ) {
	int cont = 0;
	if (m_GrillaA->GetNumberRows()!=0)
		m_GrillaA->DeleteRows(0,m_GrillaA->GetNumberRows());
	if (todos == true){
		for(int i=0;i<m_Admin->CantidadAlquileres();i++) { 
			Alquiler &a = m_Admin->verAlquileresPosVector(i);
			
			m_GrillaA->AppendRows();
			
			stringstream strIdCliente; strIdCliente<<a.verCliente()->verId();
			m_GrillaA->SetCellValue(i,0,strIdCliente.str());
			
			string nombreC(a.verCliente()->verNombre());
			string apellidoC(a.verCliente()->verApellido());
			m_GrillaA->SetCellValue(i,1, apellidoC + ", " + nombreC);
			
			stringstream strIdUsuario; strIdUsuario<<a.verUsuario()->verId();
			m_GrillaA->SetCellValue(i,2,strIdUsuario.str());
			
			string nombreU(a.verUsuario()->verNombre());
			string apellidoU(a.verUsuario()->verApellido());
			m_GrillaA->SetCellValue(i,3, apellidoU + ", " + nombreU);
			
			stringstream strIdJuego; strIdJuego<<a.verJuegoPrestado()->verId();
			m_GrillaA->SetCellValue(i,4,strIdJuego.str());
			
			string nombreJ(a.verJuegoPrestado()->verNombre());
			m_GrillaA->SetCellValue(i,5,nombreJ);
			
			stringstream FechaIni;
			FechaIni<<a.verFechaInicial().tm_mday<<"/"<<a.verFechaInicial().tm_mon+1<<"/"<<a.verFechaInicial().tm_year;
			m_GrillaA->SetCellValue(i,6,FechaIni.str());
			
			stringstream FechaFin;
			FechaFin<<a.verFechaFinal().tm_mday<<"/"<<a.verFechaFinal().tm_mon+1<<"/"<<a.verFechaFinal().tm_year;
			m_GrillaA->SetCellValue(i,7,FechaFin.str());
			
			switch(a.verEstado()){
			case Activo: m_GrillaA->SetCellValue(i,8,"Activo");
			break;
			case Terminado: m_GrillaA->SetCellValue(i,8,"Terminado");
			break;
			case Vencido: m_GrillaA->SetCellValue(i,8,"Vencido");
			break;
			}
			if (a.verEstado() == Vencido){
				m_GrillaA->SetCellBackgroundColour(i,0,wxColour(255,0,0,255));
			}
		}
	}
	else{
		for(int i=0;i<m_Admin->CantidadAlquileres();i++) { 
			Alquiler &a = m_Admin->verAlquileresPosVector(i);
			
			
			stringstream strIdCliente; strIdCliente<<a.verCliente()->verId();
			
			string nombreC(a.verCliente()->verNombre());
			string apellidoC(a.verCliente()->verApellido());
			
			stringstream strIdUsuario; strIdUsuario<<a.verUsuario()->verId();
			
			string nombreU(a.verUsuario()->verNombre());
			string apellidoU(a.verUsuario()->verApellido());
			
			stringstream strIdJuego; strIdJuego<<a.verJuegoPrestado()->verId();
			
			string nombreJ(a.verJuegoPrestado()->verNombre());
			
			stringstream FechaIni;
			
			stringstream FechaFin;
			FechaFin<<a.verFechaFinal().tm_mday<<"/"<<a.verFechaFinal().tm_mon+1<<"/"<<a.verFechaFinal().tm_year;
			
			if(a.verEstado()!=Terminado){
				
				m_GrillaA->AppendRows();
				FechaIni<<a.verFechaInicial().tm_mday<<"/"<<a.verFechaInicial().tm_mon+1<<"/"<<a.verFechaInicial().tm_year;
				m_GrillaA->SetCellValue(cont,0,strIdCliente.str());
				m_GrillaA->SetCellValue(cont,1, apellidoC + ", " + nombreC);
				m_GrillaA->SetCellValue(cont,2,strIdUsuario.str());
				m_GrillaA->SetCellValue(cont,3, apellidoU + ", " + nombreU);
				m_GrillaA->SetCellValue(cont,4,strIdJuego.str());
				m_GrillaA->SetCellValue(cont,5,nombreJ);
				m_GrillaA->SetCellValue(cont,6,FechaIni.str());
				m_GrillaA->SetCellValue(cont,7,FechaFin.str());
				
				switch(a.verEstado()){
				case Activo: m_GrillaA->SetCellValue(cont,8,"Activo");
				break;
				case Terminado: m_GrillaA->SetCellValue(cont,8,"Terminado");
				break;
				case Vencido: m_GrillaA->SetCellValue(cont,8,"Vencido");
				break;
				}
				cont++;
			}else{
				continue;
			}
			if (a.verEstado() == Vencido){
				m_GrillaA->SetCellBackgroundColour(i,0,wxColour(255,0,0,255));
			}
		}
	}
}
void Ven_Prestamos::MostraTodos( wxCommandEvent& event )  {
	if(todos == false){
		todos = true;
		RefrescarGrilla(todos);
	}else{
		todos = false;
		RefrescarGrilla(todos);
	}
}

