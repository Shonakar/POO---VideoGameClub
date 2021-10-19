#include "Usuario.h"
#include <cstring>
#include <string>
using namespace std;


Usuario::Usuario (unsigned int id,const char  nom[],const char  ape[],const char dire[], int dni,const char  pass[], bool adm):Persona(nom,ape,dire,dni) {
	string strnom(nom), strape(ape);// Paso nom y ape a strin para poder usarlos
	string strusu = strape.substr(0,3) + strnom.substr(0,3);//agarro primera 3 letras de apellido y nombre para generar nombre de Usuario
	for(size_t i=0;i<strusu.size();i++) { 
		strusu[i] = tolower(strusu[i]);//paso todo a minusculas
	}
	strcpy(m_nomusu,strusu.c_str());//c_str retorna char*
	m_admin = adm;
	m_id = id;
	strcpy(m_pass,pass);
}

char * Usuario::verNombreUsuario ( ) {
	return m_nomusu;
}

char * Usuario::verContra ( ) {
	return m_pass;
}

bool Usuario::esAdmin ( ) {
	return m_admin;
}

void Usuario::CambiarContra (const char  npass[]) {
	strcpy(m_pass,npass);
}

void Usuario::CambiarEstado () {
	if (m_admin == true)
		m_admin = false;
	else
		m_admin = true;
}


unsigned int Usuario::verId ( ) {
	return m_id;
}

Usuario::Usuario (char usu  [], char pass  [],bool adm):Persona(" "," "," ",-1) {
	strcpy(m_nomusu,usu);
	strcpy(m_pass,pass);
	m_admin = adm;
	m_id = 0;
}

void Usuario::CambiarEstado (bool estado) {
	m_admin = estado;
}

