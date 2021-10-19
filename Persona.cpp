#include "Persona.h"
#include <cstring>
using namespace std;

Persona::Persona(const char nom[], const char ape[], const char dire[], int dni) {
	strcpy(m_nom,nom);
	strcpy(m_ape,ape);
	strcpy(m_direccion,dire);
	m_dni = dni;
}
char* Persona::verNombre ( ) {
	return m_nom;
}
char* Persona::verApellido ( ) {
	return m_ape;
}

int Persona::verDni ( ) {
	return m_dni;
}

char* Persona::verDireccion ( ) {
	return m_direccion;
}

void Persona::modificarNombre (const char nom[]) {
	strcpy(m_nom,nom);
}

void Persona::modificarApellido (const char ape[]) {
	strcpy(m_ape,ape);
}

void Persona::modificarDireccion (const char dire[]) {
	strcpy(m_direccion,dire);
}

void Persona::modificarDni (int dni) {
	m_dni = dni;
}

