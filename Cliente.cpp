#include "Cliente.h"
#include <cstring>
#include <iostream>
using namespace std;

Cliente::Cliente (const char nom[], const char ape[], const char dire[],int dni,unsigned int id, int clave, const char tel[], const char cor[]):Persona(nom,ape,dire,dni) {
	m_id = id;
	m_clave_prestamo = clave;
	habilitado = true;
	string aux(tel);
	strcpy(m_NumTel,aux.substr(0,9).c_str());
	strcpy(m_correo,cor);
}

unsigned int Cliente::verId ( ) {
	return m_id;
}

int Cliente::verClave ( ) {
	return m_clave_prestamo;
}

char * Cliente::verTelefono ( ) {
	return m_NumTel;
}

char * Cliente::verCorreo ( ) {
	return m_correo;
}
bool Cliente::estaHabilitado ( ) {
	return habilitado;
}


void Cliente::cambiar_estado ( ) {
	if (habilitado == true)
		habilitado = false;
	else
		habilitado = true;
}

void Cliente::modificarTelefono (const char  telefono[]) {
	strcpy(m_NumTel,telefono);
}

void Cliente::modificarCorreo (const char  correo[]) {
	strcpy(m_correo,correo);
}

void Cliente::modificarClave (int  clave) {
	m_clave_prestamo = clave;
}

Cliente::Cliente (const char  nom[], const char  ape[], const char  dire[], int dni, unsigned int id, int clave, const char  tel[], const char  cor[], bool Estado):Persona(nom,ape,dire,dni) {
	m_id = id;
	m_clave_prestamo = clave;
	habilitado = Estado;
	string aux(tel);
	strcpy(m_NumTel,aux.substr(0,9).c_str());
	strcpy(m_correo,cor);
}


