#include "VenE_Clientes.h"
#include "string_conv.h"
#include <sstream>
#include "Administradora.h"
#include <wx/msgdlg.h>
using namespace std;

VenE_Clientes::VenE_Clientes(wxWindow *parent, Administradora *admin) : D_Clientes(parent), m_Admin(admin) {
	stringstream str_id;
	str_id<<m_Admin->CantidadClientes()+1;
	m_TextId->SetValue(str_id.str());
	m_TextId->Disable();
}

VenE_Clientes::~VenE_Clientes() {
	
}


VenE_Clientes::VenE_Clientes (wxWindow * parent, Administradora * admin, unsigned int pos, int accion): D_Clientes(parent),m_Admin(admin),m_Pos(pos), m_Accion(accion) {
	if (m_Accion == 2){
		stringstream str_id; str_id<<m_Admin->verClientesPosVector(pos).verId();
		m_TextId->SetValue(str_id.str());
		m_TextId->Disable();
		
		stringstream str_clave; str_clave<<m_Admin->verClientesPosVector(pos).verClave();
		m_TextClave->SetValue(str_clave.str());
		m_TextClave->Disable();
		
		m_TextNombre->SetValue(m_Admin->verClientesPosVector(pos).verNombre());
		m_TextNombre->Disable();
		
		m_TextApellido->SetValue(m_Admin->verClientesPosVector(pos).verApellido());
		m_TextApellido->Disable();
		
		m_TextDireccion->SetValue(m_Admin->verClientesPosVector(pos).verDireccion());
		m_TextDireccion->Disable();
		
		stringstream str_dni; str_dni<<m_Admin->verClientesPosVector(pos).verDni();
		m_TextDNI->SetValue(str_dni.str());
		m_TextDNI->Disable();
		
		m_TextTelefono->SetValue(m_Admin->verClientesPosVector(pos).verTelefono());
		m_TextCorreo->SetValue(m_Admin->verClientesPosVector(pos).verCorreo());
		m_TextTelefono->Disable();
		m_TextCorreo->Disable();
		
	}else{
		stringstream str_id; str_id<<m_Admin->verClientesPosVector(pos).verId();
		m_TextId->SetValue(str_id.str());
		m_TextId->Disable();
		
		stringstream str_clave; str_clave<<m_Admin->verClientesPosVector(pos).verClave();
		m_TextClave->SetValue(str_clave.str());
		
		m_TextNombre->SetValue(m_Admin->verClientesPosVector(pos).verNombre());
		
		m_TextApellido->SetValue(m_Admin->verClientesPosVector(pos).verApellido());
		
		m_TextDireccion->SetValue(m_Admin->verClientesPosVector(pos).verDireccion());
		
		stringstream str_dni; str_dni<<m_Admin->verClientesPosVector(pos).verDni();
		m_TextDNI->SetValue(str_dni.str());
		
		m_TextTelefono->SetValue(m_Admin->verClientesPosVector(pos).verTelefono());
		m_TextCorreo->SetValue(m_Admin->verClientesPosVector(pos).verCorreo());
	}
}

void VenE_Clientes::ClickConfirmar( wxCommandEvent& event )  {
	switch(m_Accion){
		case 0:{
			unsigned int id = m_Admin->CantidadClientes()+1;
			string nom = wx_to_std(m_TextNombre->GetValue());
			string ape = wx_to_std(m_TextApellido->GetValue());
			string dire = wx_to_std(m_TextDireccion->GetValue());
			string dni = wx_to_std(m_TextDNI->GetValue()).c_str();//int
			string clave = wx_to_std(m_TextClave->GetValue()).c_str();//int
			string tel = wx_to_std(m_TextTelefono->GetValue());
			string correo = wx_to_std(m_TextCorreo->GetValue());
			
			//Validamos datos
			string errores;
			if (nom.size()==0) errores+="El nombre no puede estar vacio\n";
			if (nom.size()>20) errores+="El nombre es demasiado largo\n";
			if (ape.size()==0) errores+="El apellido no puede estar vacio\n";
			if (ape.size()>20) errores+="El apellido es demasiado largo\n";
			if (dire.size()==0) errores+="La direccion no puede estar vacio\n";
			if (dire.size()>50) errores+="La direccion es demasiado larga\n";
			
			if (dni.size()==0) errores+="El DNI no puede estar vacio\n";
			//verificamos que solo se ingresen numeros
			for(int i=0;i<dni.size();i++) { 
				if (!isdigit(dni[i])){
					errores+="En DNI solo puede haber datos numericos\n";
					break;//con encontrar un solo caracter que no sea numerico basta
				}
			}
			//verificamos que no este repetido
			for(int i=0;i<m_Admin->CantidadClientes();i++) { 
				if(atoi(dni.c_str()) == m_Admin->verClientesPosVector(i).verDni()){
					errores+="El DNI ingresado ya existe\n";
				}
			}
			
			if(clave.size()==0) errores+="La clave no puede estar vacia\n";
			for(int i=0;i<clave.size();i++) { 
				if(!isdigit(clave[i])){
					errores+="En Clave solo puede haber datos numericos\n";
					break;
				}
			}
			
			if(tel.size()==0) errores+="El Telefono no puede estar vacio\n";
			for(int i=0;i<tel.size();i++) { 
				if(!isdigit(tel[i])){
					errores+="En Telefono solo puede haber datos numericos\n";
					break;
				}
			}
			
			if (correo.size()==0) errores+="El correo no puede estar vacio\n";
			int contArroba = 0;//improvisacion de verificacion de correos
			for(int i=0;i<correo.size();i++) { 
				if(correo[i] == '@'){
					contArroba++;
				}
			}
			if (contArroba==0 || contArroba>1) errores+="El correo debe ser de formato correo@correo.com\n";
			if(errores.size()){
				wxMessageBox(std_to_wx(errores),"ERRORES",wxOK|wxICON_ERROR,this);
			}else{
				Cliente c(nom.c_str(),ape.c_str(),dire.c_str(),atoi(dni.c_str()),id,atoi(clave.c_str()),tel.c_str(),correo.c_str());
				m_Admin->NuevoCliente(c);
				m_Admin->GuardarListaClientes();
				EndModal(1);
			}
			break;
		}
		case 1:{
			string nom = wx_to_std(m_TextNombre->GetValue());
			string ape = wx_to_std(m_TextApellido->GetValue());
			string dire = wx_to_std(m_TextDireccion->GetValue());
			string dni = wx_to_std(m_TextDNI->GetValue());//int
			string clave = wx_to_std(m_TextClave->GetValue());//int
			string tel = wx_to_std(m_TextTelefono->GetValue());
			string correo = wx_to_std(m_TextCorreo->GetValue());
			
			//Validamos datos
			string errores;
			if (nom.size()==0) errores+="El nombre no puede estar vacio\n";
			if (nom.size()>20) errores+="El nombre es demasiado largo\n";
			if (ape.size()==0) errores+="El apellido no puede estar vacio\n";
			if (ape.size()>20) errores+="El apellido es demasiado largo\n";
			if (dire.size()==0) errores+="La direccion no puede estar vacio\n";
			if (dire.size()>50) errores+="La direccion es demasiado larga\n";
			
			if (dni.size()==0) errores+="El DNI no puede estar vacio\n";
			//verificamos que no este repetido

			if(clave.size()==0) errores+="La clave no puede estar vacia\n";
			for(int i=0;i<clave.size();i++) { 
				if(!isdigit(clave[i])){
					errores+="En Clave solo puede haber datos numericos\n";
					break;
				}
			}
			
			if(tel.size()==0) errores+="El Telefono no puede estar vacio\n";
			for(int i=0;i<tel.size();i++) { 
				if(!isdigit(tel[i])){
					errores+="En Telefono solo puede haber datos numericos\n";
					break;
				}
			}
			
			if (correo.size()==0) errores+="El correo no puede estar vacio\n";
			int contArroba = 0;//improvisacion de verificacion de correos
			for(int i=0;i<correo.size();i++) { 
				if(correo[i] == '@'){
					contArroba++;
				}
			}
			if (contArroba==0 || contArroba>1) errores+="El correo debe ser de formato correo@correo.com\n";
			//Fin de la verificacion
			
			if(errores.size()){
				wxMessageBox(std_to_wx(errores),"ERRORES",wxOK|wxICON_ERROR,this);
			}else{
				m_Admin->verClientesPosVector(m_Pos).modificarNombre(nom.c_str());
				m_Admin->verClientesPosVector(m_Pos).modificarApellido(ape.c_str());
				m_Admin->verClientesPosVector(m_Pos).modificarDireccion(dire.c_str());
				m_Admin->verClientesPosVector(m_Pos).modificarDni(atoi(dni.c_str()));
				m_Admin->verClientesPosVector(m_Pos).modificarClave(atoi(clave.c_str()));
				m_Admin->verClientesPosVector(m_Pos).modificarTelefono(tel.c_str());
				m_Admin->verClientesPosVector(m_Pos).modificarCorreo(correo.c_str());
				m_Admin->GuardarListaClientes();
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

