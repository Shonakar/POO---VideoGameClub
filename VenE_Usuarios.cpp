#include "VenE_Usuarios.h"
#include <sstream>
#include "string_conv.h"
#include "Usuario.h"
#include <wx/msgdlg.h>
using namespace std;

VenE_Usuarios::VenE_Usuarios(wxWindow *parent, Administradora *admin) : D_Usuarios(parent), m_Admin(admin) {
	stringstream str_id;
	str_id<<m_Admin->CantidadUsuarios()+1;
	m_TextId->SetValue(str_id.str());
	m_TextId->Disable();
}

VenE_Usuarios::~VenE_Usuarios() {
	
}

void VenE_Usuarios::ClickConfirmar( wxCommandEvent& event )  {
	switch(m_Accion){
		case 0:{
			unsigned int id = m_Admin->CantidadUsuarios()+1;
			string nom = wx_to_std(m_TextNombre->GetValue());
			string ape = wx_to_std(m_TextApellido->GetValue());
			string dire = wx_to_std(m_TextDireccion->GetValue());
			string dni = wx_to_std(m_TextDNI->GetValue());
			string contra = wx_to_std(m_TextContra->GetValue());
			bool admin = m_esAdmin->GetValue();
			
			//Validacion de datos
			string errores;
			if (nom.size()==0) errores+="El nombre no puede estar vacio\n";
			if (nom.size()>20) errores+="El nombre es demasiado largo\n";
			if (ape.size()==0) errores+="El apellido no puede estar vacio\n";
			if (ape.size()>20) errores+="El apellido es demasiado largo\n";
			if (dire.size()==0) errores+="La direccion no puede estar vacio\n";
			if (dire.size()>50) errores+="La direccion es demasiado larga\n";
			if (dni.size()==0) errores+="El DNI no puede estar vacio\n";
			if (dni.size()==0) errores+="El DNI no puede estar vacio\n";
			//verificamos que solo se ingresen numeros
			for(int i=0;i<dni.size();i++) { 
				if (!isdigit(dni[i])){
					errores+="En DNI solo puede haber datos numericos\n";
					break;//con encontrar un solo caracter que no sea numerico basta
				}
			}
			//verificamos que no este repetido
			for(int i=0;i<m_Admin->CantidadUsuarios();i++) { 
				if(atoi(dni.c_str()) == m_Admin->verClientesPosVector(i).verDni()){
					errores+="El DNI ingresado ya existe\n";
				}
			}
			if(contra.size()==0) errores+="La contraseña no puede estar vacia\n";
			
			//Fin de la verificacion
			
			if(errores.size()){
				wxMessageBox(std_to_wx(errores),"ERRORES",wxOK|wxICON_ERROR,this);
			}else{
				Usuario u(id, nom.c_str(), ape.c_str(), dire.c_str(),atoi(dni.c_str()), contra.c_str(), admin);
				m_Admin->NuevoUsuario(u);
				m_Admin->GuardarListaUsuarios();
				EndModal(1);
			}
			break;
		}
		case 1:{
			
			
			string nom = wx_to_std(m_TextNombre->GetValue());
			string ape = wx_to_std(m_TextApellido->GetValue());
			string dire = wx_to_std(m_TextDireccion->GetValue());
			string dni = wx_to_std(m_TextDNI->GetValue());//int
			string clave = wx_to_std(m_TextContra->GetValue());//int
			bool est = m_esAdmin->GetValue();
			//Validacion de datos
			string errores;
			if (nom.size()==0) errores+="El nombre no puede estar vacio\n";
			if (nom.size()>20) errores+="El nombre es demasiado largo\n";
			if (ape.size()==0) errores+="El apellido no puede estar vacio\n";
			if (ape.size()>20) errores+="El apellido es demasiado largo\n";
			if (dire.size()==0) errores+="La direccion no puede estar vacio\n";
			if (dire.size()>50) errores+="La direccion es demasiado larga\n";
			if (dni.size()==0) errores+="El DNI no puede estar vacio\n";
			if (dni.size()==0) errores+="El DNI no puede estar vacio\n";
			//verificamos que solo se ingresen numeros
			for(int i=0;i<dni.size();i++) { 
				if (!isdigit(dni[i])){
					errores+="En DNI solo puede haber datos numericos\n";
					break;//con encontrar un solo caracter que no sea numerico basta
				}
			}
			//verificamos que no este repetido
			if(clave.size()==0) errores+="La contraseña no puede estar vacia\n";
			
			//Fin de la verificacion
			
			if(errores.size()){
				wxMessageBox(std_to_wx(errores),"ERRORES",wxOK|wxICON_ERROR,this);
			}else{
				m_Admin->verUsuariosPosVector(m_Pos).modificarNombre(nom.c_str());
				m_Admin->verUsuariosPosVector(m_Pos).modificarApellido(ape.c_str());
				m_Admin->verUsuariosPosVector(m_Pos).modificarDireccion(dire.c_str());
				m_Admin->verUsuariosPosVector(m_Pos).modificarDni(atoi(dni.c_str()));
				m_Admin->verUsuariosPosVector(m_Pos).CambiarContra(clave.c_str());
				m_Admin->verUsuariosPosVector(m_Pos).CambiarEstado(est);
				m_Admin->GuardarListaUsuarios();
				EndModal(1);
			}
			break;
		}
		case 2:{
			EndModal(1);
			break;
		};
	}
}

void VenE_Usuarios::esAdmin( wxCommandEvent& event )  {
	event.Skip();
}


VenE_Usuarios::VenE_Usuarios (wxWindow * parent, Administradora * admin, unsigned int pos, int accion): D_Usuarios(parent), m_Admin(admin), m_Pos(pos), m_Accion(accion){
	if (m_Accion==2){
		stringstream strId; strId<<m_Admin->verUsuariosPosVector(pos).verId();
		m_TextId->SetValue(strId.str());
		m_TextId->Disable();
		
		stringstream strContra; strContra<<m_Admin->verUsuariosPosVector(pos).verContra();
		m_TextContra->SetValue(strContra.str());
		m_TextContra->Disable();
		
		m_TextNombre->SetValue(m_Admin->verUsuariosPosVector(pos).verNombre());
		m_TextNombre->Disable();
		m_TextApellido->SetValue(m_Admin->verUsuariosPosVector(pos).verApellido());
		m_TextApellido->Disable();
		
		m_TextDireccion->SetValue(m_Admin->verUsuariosPosVector(pos).verDireccion());
		m_TextDireccion->Disable();
		
		stringstream strDni; strDni<<m_Admin->verUsuariosPosVector(pos).verDni();
		m_TextDNI->SetValue(strDni.str());
		m_TextDNI->Disable();
		m_esAdmin->Disable();
	}else{
		stringstream strId; strId<<m_Admin->verUsuariosPosVector(pos).verId();
		m_TextId->SetValue(strId.str());
		m_TextId->Disable();
		
		stringstream strContra; strContra<<m_Admin->verUsuariosPosVector(pos).verContra();
		m_TextContra->SetValue(strContra.str());
		
		m_TextNombre->SetValue(m_Admin->verUsuariosPosVector(pos).verNombre());
		m_TextApellido->SetValue(m_Admin->verUsuariosPosVector(pos).verApellido());
		
		m_TextDireccion->SetValue(m_Admin->verUsuariosPosVector(pos).verDireccion());
		
		stringstream strDni; strDni<<m_Admin->verUsuariosPosVector(pos).verDni();
		m_TextDNI->SetValue(strDni.str());
	}
}
