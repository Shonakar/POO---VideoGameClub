#include "VenE_Juegos.h"
#include "string_conv.h"
#include "VideoJuego.h"
#include <sstream>
#include <wx/msgdlg.h>
using namespace std;

VenE_Juegos::VenE_Juegos(wxWindow *parent,Administradora *admin) : D_Juegos(parent),m_Admin(admin) {
	
}

void VenE_Juegos::ClickConfirmar( wxCommandEvent& event )  {
	switch (m_Accion){
	case 0:{
		unsigned int id = m_Admin->CantidadJuegos()+1;
		string nom = wx_to_std(m_TextNom->GetValue());
		string precio = wx_to_std(m_TextPrecio->GetValue());
		string cantidad = wx_to_std(m_TextCant->GetValue());
		
		//validamos
		string errores;
		if (nom.size()==0) errores+="El nombre no puede estar vacio\n";
		if (nom.size()>30) errores+="El nombre es demasiado largo\n";
		if (precio.size()==0) errores+="El precio no puede estar vacio\n";
		for(int i=0;i<precio.size();i++) { 
			if(!isdigit(precio[i])){
				errores+="En precio solo puede haber caracteres numericos\n";
				break;
			}
		}
		if (cantidad.size()==0) errores+="La cantidad no puede estar vacia\n";
		for(int i=0;i<cantidad.size();i++) { 
			if(!isdigit(cantidad[i])){
				errores+="En cantidad solo puede haber caracteres numericos\n";
				break;
			}
		}
		//pasamos a int y validamos que sean positivos
		int intCantidad = atoi(cantidad.c_str()), intPrecio = atoi(precio.c_str());
		if (intCantidad<0) errores+="Cantidad en stock tiene que ser mayor o igual a 0\n";
		if (intPrecio<=0) errores+="El precio tiene que ser positivo\n";
		
		if(errores.size()){
			wxMessageBox(std_to_wx(errores),"ERRORES",wxOK|wxICON_ERROR,this);
		}else{
			VideoJuego j(id,nom.c_str(),intPrecio,intCantidad,0);
			m_Admin->NuevoVideoJuego(j);
			m_Admin->GuardarListaJuegos();
			EndModal(1);
		}
		break;
	}
	case 1:
		string precio = wx_to_std(m_TextPrecio->GetValue());
		string errores;
		if (precio.size()==0) errores+="El precio no puede estar vacio\n";
		for(int i=0;i<precio.size();i++) { 
			if(!isdigit(precio[i])){
				errores+="En precio solo puede haber caracteres numericos\n";
				break;
			}
		}
		int intPrecio = atoi(precio.c_str());
		if (intPrecio<=0) errores+="El precio tiene que ser positivo\n";
		if (errores.size()){
			wxMessageBox(std_to_wx(errores),"ERRORES",wxOK|wxICON_ERROR,this);
		}else{
			m_Admin->verJuegosPosVector(m_Pos).CambiarPrecio(intPrecio);
			m_Admin->GuardarListaJuegos();
			EndModal(1);
		}
		
		break;
	}	
}

//CONSTRUCTOR PARA EDITAR PRECIO
VenE_Juegos::VenE_Juegos (wxWindow *parent, Administradora * admin, unsigned int pos,int accion) : D_Juegos(parent),m_Admin(admin),m_Accion(accion),m_Pos(pos){
	m_TextNom->SetValue(m_Admin->verJuegosPosVector(pos).verNombre());
	m_TextNom->Disable();
	stringstream cant; cant<<m_Admin->verJuegosPosVector(pos).verStock();
	m_TextCant->SetValue(cant.str());
	m_TextCant->Disable();
	stringstream precio; precio<<m_Admin->verJuegosPosVector(pos).verPrecio();
	m_TextPrecio->SetValue(precio.str());
}

