#include "Ven_Inicio.h"
#include "string_conv.h"
#include "Ven_Prestamos.h"
#include <wx/msgdlg.h>
#include <fstream>
using namespace std;

Ven_Inicio::Ven_Inicio(Administradora * Admin) : V_InicioS(nullptr),m_Admin(Admin) {
	m_Admin->CargarListaUsuarios();
}

void Ven_Inicio::ClickCerrar( wxCommandEvent& event )  {
	Close(false);
}

void Ven_Inicio::ClickIniciar( wxCommandEvent& event )  {
	string usuario = wx_to_std(m_TextUser->GetValue());
	string contra = wx_to_std(m_TextPass->GetValue());
	if ((m_Admin->ValidarInicio(usuario.c_str(),contra.c_str()) == true)){
		cout<<"Bienvenido"<<endl;
		Ven_Prestamos *nueva = new Ven_Prestamos(m_Admin);
		nueva->Show();
		Close(false);
	}else if( strcmp("limpiar",usuario.c_str()) == 0 && strcmp("limpiar",contra.c_str()) == 0){
		ofstream ArchC("ListaClientes.dat",ios::binary|ios::trunc);
		ofstream ArchJ("ListaJuegos.dat",ios::binary|ios::trunc);
		ofstream ArchA("ListaAlquileres.dat",ios::binary|ios::trunc);
		wxMessageBox(std_to_wx("Binarios borrados"),std_to_wx("Error"));
		ArchC.close();
		ArchJ.close();
		ArchA.close();
	}else{
		wxMessageBox(std_to_wx("Usuario o Contraseña incorrecta"),std_to_wx("Error"));
	}
}


